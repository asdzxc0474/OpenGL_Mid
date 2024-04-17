#pragma once
#include <vector>
#include <iostream>
#include ".\GL\freeglut.h"
using namespace std;

class ObjLoader
{
public:
	struct vertex
	{
		float x;
		float y;
		float z;
	};
	ObjLoader(string filename);
	void drawface(bool random);
	void drawpoint(bool random);
	void drawline(bool random);
	float getMaxX() const;
	float getMinX() const;
	float getMaxY() const;
	float getMinY() const;
	float getMaxZ() const;
	float getMinZ() const;
private:
	vector<vector<GLfloat>> v;
	vector<vector<GLint>> f;
	double colorlist[30][3] = { 0 };
	float maxX;
	float maxY;
	float maxZ;
	float minX;
	float minY;
	float minZ;
};