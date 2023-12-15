#pragma once

#include "stdafx.h"
using namespace sf;

class fondo{
	Texture  fondoTex;
	Sprite   fondoSprite;
	bool fonVivo;
	bool fonVisible;
	float tpoVisible;
	float tpoApagado;
	sf::Clock _clock;
	




public:

	fondo(){
        
		     fondoTex.loadFromFile("fondo.png");

	         fondoSprite.setTexture(fondoTex);

			 fonVivo = true;
			 fonVisible = false;
			 tpoVisible = 1.f;
			 tpoApagado = 1.f;
	}


		     bool EstaEncimaF(float x, float y){
			      FloatRect bounds = fondoSprite.getGlobalBounds();
			      return bounds.contains(x, y); }

			 void Dibujar(RenderWindow *wnd){

				  wnd->draw(fondoSprite);}

			 bool EstaVivo(){
				 return fonVivo;}

			 bool EstaActivo(){
				 return fonVivo && fonVisible; }

			 bool EstaEncima(float x, float y){
				 FloatRect bounds = fondoSprite.getGlobalBounds();
				 return bounds.contains(x, y); }
			 
			 void ActualizarF(RenderWindow* wnd){

				 if (!fonVivo)
					 return;
				 
				 if (!fonVisible){//tiramos una probabilidad para ver si lo activamos

					 if (_clock.getElapsedTime().asSeconds() > tpoApagado){
						 _clock.restart();
						 fonVisible = true;

						 fondoSprite.setPosition(0, 0); } }

					else{
					 if (_clock.getElapsedTime().asSeconds() > tpoVisible){

						 fonVisible = false;
						 _clock.restart(); }
				 }
			 }
			
			




};
