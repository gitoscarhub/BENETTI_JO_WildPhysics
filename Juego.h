//#pragma once : es una directiva del preprocesador en los lenguajes de C y C++ que se utiliza
//para asegurarse de que un archivo de encabezado se incluya una sola vez en un programa. (Introducción a la programacion)
#pragma once
#include "stdafx.h"

using namespace sf;
class Juego
{
private:
	RenderWindow *_wnd;
	mira *_disparo;
	enemigo *_enemigo;
	inocente *_inocente;
	fondo   *_fondo;
	
	
	Text _puntaje;
	Font _fuente;
	BaseObject *_bombardeo;
	int _puntos, derrotas, inocentes,aux;
	
	Sprite impacto;
	
	Texture Timpacto;
	Sprite inocente1;
	Sprite inocente2;
	Sprite inocente3;
	Texture _inocente1;
	Texture _inocente2;
	Texture _inocente3;
	Sprite inicio;
	Texture _inicio;
	
	Clock _reloj;
	Time dt;
	int x = 0;
	int disparo;
	bool Entrar;
	float deltaT;

	void _actualizarPuntaje() 
	{
		char pts[100];
		_itoa_s((_puntos * 10), pts, 10);
		_puntaje.setString(pts);
	}


    public:

	Juego() {
		_wnd = new RenderWindow(VideoMode(800, 600), "Wild physics Benetti");
		_wnd->setFramerateLimit(60);
		_disparo = new mira();
		_enemigo = new enemigo;
		_inocente = new inocente;
		_fondo = new fondo;
		
		_bombardeo = new BaseObject;
		_puntos = 0;
		inocentes = 0;
		
		_actualizarPuntaje();
		_fuente.loadFromFile("arial.ttf");
		_puntaje.setFont(_fuente);
		_puntaje.setPosition(0.0f, 0.0f);
		_puntaje.setCharacterSize(50);
		_puntaje.setFillColor(Color::Blue);
		
		_inicio.loadFromFile("fondo.png");
		inicio.setTexture(_inicio);
		
		
		_inocente1.loadFromFile("inocente.png");
		inocente1.setTexture(_inocente1);
		inocente1.setPosition(400, 450);
		_inocente2.loadFromFile("inocente2.png");
		inocente2.setTexture(_inocente2);
		inocente2.setPosition(400, 450);
		Timpacto.loadFromFile("impacto.png");
		impacto.setTexture(Timpacto);
		Vector2i mousePosition = Mouse::getPosition(*_wnd);
		_disparo->Posicionar(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
		_bombardeo->SetScale(0.50f);
		_bombardeo->SetPosition(Vector2f(380.0f,200.0f));

	}
		

	void Loop() {
		Clock clock;
		clock.restart();
		float dt = 0.0f;
		while (_wnd->isOpen()) {
			// Calcula el tiempo transcurrido desde la última iteración del bucle
			float deltaT = clock.restart().asSeconds();
		//	_wnd->clear();
			
			ProcesarEventos();
			Actualizar(deltaT);
			Dibujar();
			
		}

	}
	void ProcesarEventos() {
		Event evt;
		_wnd->setMouseCursorVisible(false);
	
		while (_wnd->pollEvent(evt)) {
			switch (evt.type) {
			case Event::Closed:
				_wnd->close();
				break;

			case Event::MouseMoved:
				_disparo->Posicionar(evt.mouseMove.x, evt.mouseMove.y);
				break;

			case Event::MouseButtonPressed:
				if (evt.mouseButton.button == Mouse::Button::Left)
					//dt = _reloj.getElapsedTime();
					 Disparar(); 
					_disparo->FuegoPistola();
				break;
			}
		}
		
	}


	void Actualizar(float deltaT) {


		for (size_t i = 0; i < 1; i++) {
			
			_inocente[i].ApagoI();
			_enemigo[i].ActualizarE(_wnd);
			_inocente[i].ActualizarI(_wnd);

		}
			// Aplicar velocidad al objeto
			_bombardeo->AddAcceleration(Vector2f(0.0f, 9.8f));

			//porcentaje gravedad 
			float aux = _bombardeo->GetVelocity().y;
			aux = aux * (80.0f / 100.0f);

			// Chequea si el objeto ha salido de la ventana
			if (_bombardeo->GetPosition().y > 500.0f)
			{

				_bombardeo->SetVelocity(Vector2f(0.0f, -aux));

			}
		
		_bombardeo->Update(deltaT);
	}



	void Disparar() {
		
		//chequeamos colisiones con el disparo
		Vector2f playerPos = _disparo->ObtenerPosicion();
		
		disparo =5;
		aux = 0;
		
		for (int i = 0; i < 1; i++) {
			
			if (_enemigo[i].EstaActivo()) {

				_bombardeo[i].CambioTextura(playerPos.x, playerPos.y, false);
			

				if (_bombardeo[i].EstaEncima(playerPos.x, playerPos.y))
				{
						_puntos++; aux++; 
				}
			}
			
			if (aux == _puntos) {
				_bombardeo[i].CambioTextura(playerPos.x, playerPos.y, true);
			}
			
			_actualizarPuntaje();
			_reloj.restart();
			x = x + 1 * dt.asMilliseconds();
			
		}
		
	}

	void Dibujar() {

		_wnd->clear();

		_wnd->draw(inicio);
		
		_bombardeo->Draw(_wnd);
	
	
		for (int i = 0; i < 1; i++) {

			if (_enemigo[i].EstaActivo())
			{
				_enemigo[i].Dibujar(_wnd);
			}
		}
			_disparo->Dibujar(_wnd);

			_wnd->draw(_puntaje);
			_wnd->display();
	}


	~Juego() {
		delete _wnd;
		delete _disparo;
		delete _enemigo;
		delete _inocente;
		delete _fondo;
		delete _bombardeo;
	}

};

