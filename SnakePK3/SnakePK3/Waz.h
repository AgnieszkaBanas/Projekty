#pragma once
#include "Glowa.h"
#include "Ogon.h"
#include "ObiektGraficzny.h"
#include <vector>

class Waz
{
	Glowa glowaWeza;
	vector<Ogon*> ogonWeza;
public:
	
	Waz(float szerokosc, float wysokosc, Color pKolorGlowy, float pozycjaX, float pozycjaY): glowaWeza(szerokosc,wysokosc,pKolorGlowy,pozycjaX,pozycjaY)
	{

	};
	void rysujWeza(RenderWindow &window);
	void idzWezem(string kierunek);
	void dodajOgon();
	bool czyWazZjadlCiastko(ObiektGraficzny&ciastko);
	bool sprawdzKolizjeZOgonem();
	bool sprawdzKolizjeZeSciana();
};