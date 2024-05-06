#pragma once

#include <iostream>

using namespace std;

class Boat
{
private:
	int speed;
	int distance;
	int nitro;
	string name;
public:
	int getSpeed();
	void setSpeed(int pSpeed);

	int getDist();
	void setDist(int pDist);

	int getNitro();
	void setNitro(int pNitro);

	string getName();
	void setName(string pName);

	void getParams();

	string DistancePrint();
	void nitroFunc();
	static int playerQuantity();

	void printSlowly(const string& message, unsigned int millisecondsPerCharacter);

	Boat(int pSpeed, int pDist, int pNitro, string pName);
};	