#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include "Repository.h"
using namespace std;
using namespace sf;


class CatRepository : public Repository
{
public:
	void saveData(int pPBV1, int pPBV2, int pPBV3, int pColor);
	Data readData();
};
