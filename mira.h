#pragma once
#include "stdafx.h"
using namespace sf;
class mira{
	Texture _crossTex;
	Sprite _crossSprite;
	Texture _pistolaTex;
	Sprite _pistolaSprite;
	Texture _fuegoTex;
	Sprite _fuegoPist;
	Texture _crosTex2;
public:

	mira() {

		_crossTex.loadFromFile("crooshair.png");
		_crossSprite.setTexture(_crossTex);
		_crossSprite.setScale(0.05f, 0.05f);
		Vector2u size = _crossTex.getSize();
		_crossSprite.setOrigin(size.x / 2.0f, size.y / 2.0f);
		_pistolaTex.loadFromFile("revolver.png");
		_pistolaSprite.setTexture(_pistolaTex);
		_pistolaSprite.setPosition(10, 500);
		_fuegoTex.loadFromFile("impacto2.png");
		_fuegoPist.setTexture(_fuegoTex);
		_crosTex2.loadFromFile("crooshair2.png");
		
	}
	

	void Dibujar(RenderWindow *wnd){
		//Cambiar el puntero del mouse->problemas con eso!
		Vector2i mousePosition = Mouse::getPosition(*wnd);
		_crossSprite.setPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
		wnd->draw(_crossSprite);
		wnd->draw(_pistolaSprite);
		wnd->draw(_fuegoPist);
	}

	void Posicionar(float x, float y){
		
		_crossSprite.setPosition(x, y);
		
	}

	Vector2f ObtenerPosicion(){
		return _crossSprite.getPosition();
	}
	void FuegoPistola() {
		_fuegoPist.setPosition(60,500);
		_fuegoTex.swap(_crosTex2);
	}
	
};