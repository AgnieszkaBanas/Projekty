#include "DogRepository.h"

void DogRepository::saveData()
{
	fstream plik("dogFile.txt", ios::out);
	if (plik.good())
	{
		for (int i = 1; i <= 100; i++)
		{
			plik << i << ", ";
			plik.flush();
		}
		plik.close();
	}
}

Data DogRepository::readData()
{
	return Data();
}
