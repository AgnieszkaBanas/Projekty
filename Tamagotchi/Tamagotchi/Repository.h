#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

struct Data
{
	int pBV1, pBV2, pBV3;
	string kindOfAnimal;
	int color;
};

class Repository
{
protected:
	Data data;
public:
	virtual void saveData(int pPBV1, int pPBV2, int pPBV3,int pColor) = 0;
	virtual Data readData() = 0;
};