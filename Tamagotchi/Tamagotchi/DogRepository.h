#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include "Repository.h"
using namespace std;
using namespace sf;


class DogRepository: public Repository
{
public:
	void saveData();
	Data readData();
};