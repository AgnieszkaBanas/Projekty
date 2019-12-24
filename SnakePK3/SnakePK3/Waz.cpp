#include "Waz.h"
#include "Glowa.h"
#include "Ogon.h"

void Waz::idzWezem(string kierunek)
{
	float oldX, oldY;
	oldX = this->glowaWeza.getX();
	oldY = this->glowaWeza.getY();

	if (kierunek == "gora")
	{
		this->glowaWeza.idz("gora");
	}
	if (kierunek == "dol")
	{
		this->glowaWeza.idz("dol");
	}
	if (kierunek == "lewo")
	{
		this->glowaWeza.idz("lewo");
	}
	if(kierunek=="prawo")
	{
		this->glowaWeza.idz("prawo");
	}
	
	this->glowaWeza.setPosition(this->glowaWeza.getX() * this->glowaWeza.jakaSzerokosc(),this->glowaWeza.getY() * this->glowaWeza.jakaWysokosc());
	this->ogonWeza[0]->ustawNowaPozycje(oldX, oldY);
	
	if (this->ogonWeza.size() > 1)
	{
		for (unsigned int i = 1; i < ogonWeza.size(); i++)
			this->ogonWeza[i]->ustawNowaPozycje(this->ogonWeza[i - 1]->getOldX(), this->ogonWeza[i - 1]->getOldY());
	}
}

void Waz::dodajOgon()
{
	float x1, y1;
	if (ogonWeza.size() == 0)
	{
		x1 = this->glowaWeza.getX();
		y1 = this->glowaWeza.getY();
		this->ogonWeza.push_back(new Ogon(30.f, 30.f, Color::Green, x1-1.f,y1));
		return;
	}
	else
	{
		if (ogonWeza.size() == 1)
		{
			x1 = this->ogonWeza[ogonWeza.size() - 1]->getX();
			y1 = this->ogonWeza[ogonWeza.size() - 1]->getY();
			if (this->glowaWeza.getX() == x1)
			{
				if (this->glowaWeza.getY() > y1)
				{
					Ogon * nowy = new Ogon(30.f, 30.f, Color::Green, x1, y1 - 1.f);
					this->ogonWeza.push_back(nowy);
					return;
				}
				if (this->glowaWeza.getY() < y1)
				{
					Ogon * nowy = new Ogon(30.f, 30.f, Color::Green, x1, y1 + 1.f);
					this->ogonWeza.push_back(nowy);
					return;
				}
			}
			else
			{
				if (this->glowaWeza.getX() < x1)
				{
					Ogon * nowy = new Ogon(30.f, 30.f, Color::Green, x1 + 1.f, y1);
					this->ogonWeza.push_back(nowy);
					return;
				}
				if (this->glowaWeza.getX() > x1)
				{
					Ogon * nowy = new Ogon(30.f, 30.f, Color::Green, x1 - 1.f, y1);
					this->ogonWeza.push_back(nowy);
					return;
				}
			}
		}
		if(ogonWeza.size() != 1 && ogonWeza.size() != 0)
		{
			x1 = this->ogonWeza[ogonWeza.size() - 1]->getX();
			y1 = this->ogonWeza[ogonWeza.size() - 1]->getY();
			if (this->ogonWeza[ogonWeza.size() - 2]->getX() == x1)
			{
				if (this->ogonWeza[ogonWeza.size() - 2]->getY()> y1)
				{
					Ogon * nowy = new Ogon(30.f, 30.f, Color::Green, x1, y1 - 1.f);
					this->ogonWeza.push_back(nowy);
					return;
				}
				if (this->ogonWeza[ogonWeza.size() - 2]->getY() < y1)
				{
					Ogon * nowy = new Ogon(30.f, 30.f, Color::Green, x1, y1 + 1.f);
					this->ogonWeza.push_back(nowy);
					return;
				}
			}
			else
			{
				if (this->ogonWeza[ogonWeza.size() - 2]->getX() < x1)
				{
					Ogon * nowy = new Ogon(30.f, 30.f, Color::Green, x1 + 1.f, y1);
					this->ogonWeza.push_back(nowy);
					return;
				}
				if (this->ogonWeza[ogonWeza.size() - 2]->getX() > x1)
				{
					Ogon * nowy = new Ogon(30.f, 30.f, Color::Green, x1 - 1.f, y1);
					this->ogonWeza.push_back(nowy);
					return;
				}
			}
		}
	}
}

bool Waz::czyWazZjadlCiastko(ObiektGraficzny&ciastko)
{
	bool wynik;
	wynik=this->glowaWeza.sprawdzKolizje(ciastko);
	return wynik;
}

bool Waz::sprawdzKolizjeZOgonem()
{
	bool wynik;
	for (int i = 0; i < this->ogonWeza.size(); i++)
	{
		/*
		wynik=this->ogonWeza[i]->sprawdzKolizje(this->glowaWeza);
		if (wynik == true)
		{
			return true;
		}
		else
		{
			return false;
		}
		*/
		if (this->glowaWeza.getX() == this->ogonWeza[i]->getX() && this->glowaWeza.getY() == this->ogonWeza[i]->getY())
			return true;
	}
	return false;
}

bool Waz::sprawdzKolizjeZeSciana()
{
	if (this->glowaWeza.getX() == -1 && (this->glowaWeza.getY() >= 0 && this->glowaWeza.getY() <= 600))
	{
		return true;
	}
	if (this->glowaWeza.getX() == 27 && (this->glowaWeza.getY() >= 0 && this->glowaWeza.getY() <= 600))
	{
		return true;
	}
	if ((this->glowaWeza.getX()>=0&& this->glowaWeza.getX()<=27) && this->glowaWeza.getY()==20)
	{
		return true;
	}
	if ((this->glowaWeza.getX() >= 0 && this->glowaWeza.getX() <= 27) && this->glowaWeza.getY() == -1)
	{
		return true;
	}
}

void Waz::rysujWeza(RenderWindow &window)
{
	
	for (int i = 0; i < this->ogonWeza.size(); i++)
	{
		this->ogonWeza[i]->rysuj(window);
		//this->ogonWeza[i]->setPosition(this->ogonWeza[i]->getX() * this->ogonWeza[i]->jakaSzerokosc(), this->glowaWeza.getY() * this->glowaWeza.jakaWysokosc());
	}
	
	this->glowaWeza.rysuj(window);
}
