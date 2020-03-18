#include "DogRepository.h"

void DogRepository::saveData(int pPBV1, int pPBV2, int pPBV3, int pColor)
{
	fstream plik("dogFile.txt", ios::out);
	if (plik.good())
	{
		plik << pPBV1 << " " << pPBV2 << " " << pPBV3 << " " << pColor;
		plik.close();
	}
}

Data DogRepository::readData()
{
	return Data();
}
