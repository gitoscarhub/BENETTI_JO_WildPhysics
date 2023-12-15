#pragma once

#include "stdafx.h"

using namespace sf;
using namespace std;

class inocente{

private:

	Texture _inocyTex;
	Sprite _inocente;

	bool _inoVivo;
	bool _inoVisible;
	sf::Clock _clock;
	int _tpoVisible;
	int _tpoApagado;

public:

	inocente(){

		_inocyTex.loadFromFile("inocencia.png");
		_inocente.setTexture(_inocyTex);
		_inocente.setScale(0.8f, 0.9f);
		
		
		_inoVivo = true;
		_inoVisible = false;
		_tpoVisible = 5;
		_tpoApagado = 1;

		
	}


	

int dibu()
{
		
		int saltar;
		saltar = rand() % 5;
		return(saltar);
	}

bool EstaVivo()
{
		return _inoVivo;

	}
bool EstaActivo()
{
	
		return _inoVivo && _inoVisible;
	}

bool EstaEncima(float x, float y)
{
		FloatRect bounds = _inocente.getGlobalBounds();
		
		return bounds.contains(x, y);
	}

bool ApagoI() { _inoVisible = false; return _inoVisible; }

void Dibujar(RenderWindow *wnd)
{
		wnd->draw(_inocente);	
}


	
void ActualizarI(RenderWindow *wnd)
{
		int a = 2;
		
		if (!_inoVivo)
			return;

		if (!_inoVisible){//tiramos una probabilidad para ver si lo activamos
			if (_clock.getElapsedTime().asSeconds() > _tpoApagado){
				_clock.restart();
				_inoVisible = true;
			  

				if (dibu() == 1) {
					_inocente.setPosition(561, 355);
				}
				else if (dibu() == 3) {
					_inocente.setPosition(365, 200);
				}
				else if (dibu() == 2) {
					_inocente.setPosition(181, 200);
				}
				else if (dibu() == 4) {
					_inocente.setPosition(365, 355);
				}
				else if (dibu() == 3) {
					_inocente.setPosition(181, 355);
				}
				else if (dibu() == 3) {
					_inocente.setPosition(365, 355);
				}
				else
					_inoVisible = false;

			}
		}

		else{
			if (_clock.getElapsedTime().asSeconds() > _tpoVisible){
			
				_inoVisible = false;
				_clock.restart();
				}
				}
			}
};
