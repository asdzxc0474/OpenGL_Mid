#include <fstream>
#include <iostream>
#include<sstream> 
#include <vector>
#include ".\GL\freeglut.h"
#include "ObjLoader.h"
using namespace std;

ObjLoader::ObjLoader(string filename)
{
	ifstream file(filename);
	string line;
	while (getline(file, line))
	{
		if (line.substr(0, 1) == "v")
		{
			vector<GLfloat> Point;
			GLfloat x, y, z;
			istringstream s(line.substr(2));
			s >> x; s >> y; s >> z;
			Point.push_back(x);
			Point.push_back(y);
			Point.push_back(z);
			v.push_back(Point);

			maxX = max(maxX, x);
			minX = min(minX, x);
			maxY = max(maxY, y);
			minY = min(minY, y);
			maxZ = max(maxZ, z);
			minZ = min(minZ, z);

		}

		else if (line.substr(0, 1) == "f")
		{
			vector<GLint> vIndexSets;
			GLint u, v, w;
			istringstream vtns(line.substr(2));
			vtns >> u; vtns >> v; vtns >> w;
			vIndexSets.push_back(u - 1);
			vIndexSets.push_back(v - 1);
			vIndexSets.push_back(w - 1);
			f.push_back(vIndexSets);
		}
	}
	srand(time(0));
	file.close();
	for (int i = 0; i < 30; i++)
	{
		colorlist[i][0] = (double)(rand()) / RAND_MAX;
		colorlist[i][1] = (double)(rand()) / RAND_MAX;
		colorlist[i][2] = (double)(rand()) / RAND_MAX;
	}
}
void ObjLoader::drawface(bool random)
{
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < f.size(); i++) {
		GLfloat VN[3];
		vertex a, b, c, normal;

		if ((f[i]).size() != 3) {
			cout << "ERRER::THE SIZE OF f IS NOT 3!" << endl;
		}
		else {
			GLint firstVertexIndex = (f[i])[0];
			GLint secondVertexIndex = (f[i])[1];
			GLint thirdVertexIndex = (f[i])[2];

			a.x = (v[firstVertexIndex])[0];
			a.y = (v[firstVertexIndex])[1];
			a.z = (v[firstVertexIndex])[2];

			b.x = (v[secondVertexIndex])[0];
			b.y = (v[secondVertexIndex])[1];
			b.z = (v[secondVertexIndex])[2];

			c.x = (v[thirdVertexIndex])[0];
			c.y = (v[thirdVertexIndex])[1];
			c.z = (v[thirdVertexIndex])[2];

			GLfloat vec1[3], vec2[3], vec3[3];
			//(x2-x1,y2-y1,z2-z1)
			vec1[0] = a.x - b.x;
			vec1[1] = a.y - b.y;
			vec1[2] = a.z - b.z;

			//(x3-x2,y3-y2,z3-z2)
			vec2[0] = a.x - c.x;
			vec2[1] = a.y - c.y;
			vec2[2] = a.z - c.z;

			//(x3-x1,y3-y1,z3-z1)
			vec3[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
			vec3[1] = vec2[0] * vec1[2] - vec2[2] * vec1[0];
			vec3[2] = vec2[1] * vec1[0] - vec2[0] * vec1[1];

			GLfloat D = sqrt(pow(vec3[0], 2) + pow(vec3[1], 2) + pow(vec3[2], 2));

			VN[0] = vec3[0] / D;
			VN[1] = vec3[1] / D;
			VN[2] = vec3[2] / D;

			glNormal3f(VN[0], VN[1], VN[2]);
			if (random)
			{
				glColor3f(colorlist[i%30][0], colorlist[i % 30][1], colorlist[i % 30][2]);
			}
			else
			{
				glColor3f(1, 0, 1);
			}
			glVertex3f(a.x, a.y, a.z);
			glVertex3f(b.x, b.y, b.z);
			glVertex3f(c.x, c.y, c.z);
		}
	}
	glEnd();
}
void ObjLoader::drawpoint(bool random)
{
	glPointSize(5.0f);
	glBegin(GL_POINTS);
	for (int i = 0; i < v.size(); i++) {
		if (random)
		{
			glColor3f(colorlist[i % 30][0], colorlist[i % 30][1], colorlist[i % 30][2]);
		}
		else
		{
			glColor3f(1, 0, 1);
		}
		glVertex3f(v[i][0], v[i][1], v[i][2]);
	}
	glEnd();
}
void ObjLoader::drawline(bool random)
{
	glBegin(GL_LINES);
	for (int i = 0; i < f.size(); i++) {
		if ((f[i]).size() != 3) {
			cout << "ERROR: THE SIZE OF f IS NOT 3!" << endl;
		}
		else {
			for (int j = 0; j < 3; j++) {
				GLint firstVertexIndex = (f[i])[j];
				GLint secondVertexIndex = (f[i])[(j + 1)%1]; // Connect the last vertex with the first one

				vertex a, b;

				a.x = v[firstVertexIndex][0];
				a.y = v[firstVertexIndex][1];
				a.z = v[firstVertexIndex][2];

				b.x = v[secondVertexIndex][0];
				b.y = v[secondVertexIndex][1];
				b.z = v[secondVertexIndex][2];
				if (random)
				{
					glColor3f(colorlist[i % 30][0], colorlist[i % 30][1], colorlist[i % 30][2]);
				}
				else
				{
					glColor3f(1, 0, 1);
				}
				glVertex3f(a.x, a.y, a.z);
				glVertex3f(b.x, b.y, b.z);
			}
		}
	}
	glEnd();
}
float ObjLoader::getMaxX() const {
	return maxX;
}

float ObjLoader::getMinX() const {
	return minX;
}

float ObjLoader::getMaxY() const {
	return maxY;
}

float ObjLoader::getMinY() const {
	return minY;
}

float ObjLoader::getMaxZ() const {
	return maxZ;
}

float ObjLoader::getMinZ() const {
	return minZ;
}