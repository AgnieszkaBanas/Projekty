#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

struct Data
{
	int pBV1, pBC2, pBV3;
	string kindOfAnimal;
	int color;
};

class Repository
{
	Data data;
public:
	virtual void saveData() = 0;
	virtual Data readData() = 0;
};