#include "CatRepository.h"

void CatRepository::saveData(int pPBV1, int pPBV2, int pPBV3, int pColor)
{
	fstream plik("catFile.txt", ios::out);
	if (plik.good())
	{
		plik << pPBV1 << " " << pPBV2 << " " << pPBV3 << " " << pColor;
		plik.close();
	}
}

Data CatRepository::readData()
{
	fstream plik;
	plik.open("catFile.txt", ios::in);
	if (plik.good())
	{
		while (!plik.eof())
		{
			plik >> data.pBV1;
			plik >> data.pBV2;
			plik >> data.pBV3;
			plik >> data.color;
		}
		plik.close();
	}
	else cout << "Error! Nie udalo otworzyc sie pliku!" << endl;
	return data;
}
