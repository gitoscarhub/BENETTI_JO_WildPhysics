
#include "stdafx.h"

using namespace sf;
using namespace std;

class enemigo{
	Sprite _enemigo;
	
	Texture _enemyTex;
	

	bool _estaVivo;
	bool _estaVisible;
	
	Clock _clock;
	int _tiempoVisible;
	int _tiempoApagado;
	

	

public:

	enemigo(){
		
		_enemyTex.loadFromFile("enemigo.png");
		_enemigo.setTexture(_enemyTex);
		_enemigo.setScale(0.8f, 0.8f);
	
				
		_estaVivo = true;
		_estaVisible = false;
		_tiempoVisible = 5;
		_tiempoApagado = 1;
		
	}
	
	

    int  dibu(){
	
		int saltar;
		saltar =  rand() %  5;
		return(saltar);
	}

	bool EstaVivo(){
		return _estaVivo;

	}
	bool EstaActivo(){
		return _estaVivo && _estaVisible;
	}

	


	void Dibujar(RenderWindow *wnd){
	
			wnd->draw(_enemigo);
			
			
	}
	
	void ActualizarE(RenderWindow* wnd){

		
		if (!_estaVivo)
			return;

		if (!_estaVisible){//tiramos una probabilidad para ver si lo activamos
			if (_clock.getElapsedTime().asSeconds() > _tiempoApagado){
				_clock.restart();
					_estaVisible = true;
					
					if (dibu() == 1){
						_enemigo.setPosition(561, 355);
						
					}
					else if (dibu() == 4) {
						_enemigo.setPosition(365, 200);
						
					}
					else if (dibu() == 1) {
						_enemigo.setPosition(181, 200);
						
					}
					else if (dibu() == 3) {
						_enemigo.setPosition(365, 355);
						
					}
					else if (dibu() == 2) {
						_enemigo.setPosition(181, 355);
						
					}
					else if (dibu() == 4) {
						_enemigo.setPosition(365, 355);
						
					}
					else
						_estaVisible = false;

			}
			
		}

		else{
			if (_clock.getElapsedTime().asSeconds() > _tiempoVisible){
				
				_estaVisible = false;
				_clock.restart();
			}
		}
	}

	

};