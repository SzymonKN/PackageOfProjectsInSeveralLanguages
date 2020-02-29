#pragma once
#include <wx/wx.h>
#include <string>

using namespace std;

class Point
{
public:
	Point() = default;

	float x = 0.0, y = 0.0, z = 0.0;
};

class Segment
{
public:
	Segment() = default;

	Point* begin;
	Point* end;
};

class Part
{
public:
	Part(const string& name);
	Part(const string& name, const string& side);

	~Part() = default;

	Point top1;
	Point top2;
	Point top3;
	Point top4;

	Point bot1;
	Point bot2;
	Point bot3;
	Point bot4;

	Segment lines[12];
};

class Skeleton
{
public:
	Skeleton();
	~Skeleton();

	Part* head;
	Part* left_shoulder;
	Part* right_shoulder;
	Part* left_forearm;
	Part* right_forearm;
	Part* left_arm;
	Part* right_arm;
	Part* chest;
	Part* stomach;
	Part* left_hip;
	Part* right_hip;
	Part* left_thigh;
	Part* right_thigh;
	Part* left_calf;
	Part* right_calf;
};
