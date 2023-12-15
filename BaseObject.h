#pragma once
#include "stdafx.h"


using namespace std;
using namespace sf;

class BaseObject
{
private:
    
    Sprite _pSpr[10];
    Texture _pTex;
    Texture Timpacto;
    Vector2f _position;
    Vector2f _acceleration;
    Vector2f _velocity;
public:
  

    // Funciones para configurar las propiedades del objeto
    void SetScale(float uniformScale) { _pSpr[9].setScale(uniformScale, uniformScale); }//Sprite escalado de manera uniforme
    void SetPosition(Vector2f pos) { _position = pos; }
    void SetAcceleration(Vector2f acc) { _acceleration = acc; }
    void SetVelocity(Vector2f vel) { _velocity = vel; }
   
    // Funciones para obtener las propiedades del objeto
    Vector2f GetPosition() { return _position; }
    Vector2f GetAcceleration() { return _acceleration; }
    Vector2f GetVelocity() { return _velocity; }

    // Función para agregar una aceleración al objeto
    void AddAcceleration(Vector2f acc) {
        _acceleration.x += acc.x;
        _acceleration.y += acc.y;
    }

    // Constructor de la clase BaseObject que recibe el nombre del archivo de imagen como parámetro
    BaseObject()
    {
        
       
        _pTex.loadFromFile("rcircle.png");
        _pSpr[9].setTexture(_pTex);
        Timpacto.loadFromFile("impacto.png");
        // Inicialización de variables de posición, aceleración y velocidad
        _position.x = 0.0f;
        _position.y = 0.0f;
        _acceleration.x = 0.0f;
        _acceleration.y = 0.0f;
        _velocity.x = 0.0f;
        _velocity.y = 0.0f;
    }

    // Destructor de la clase BaseObject
    ~BaseObject(){}
   

    // Función para dibujar el objeto en una ventana RenderWindow
    void Draw(RenderWindow* pWnd)
    {

        // Se dibuja el Sprite en la ventana especificada
        for (int i = 0; i < 10; i++){
            pWnd->draw(_pSpr[9]);
    }
        
        
    }

    // Función para actualizar el objeto en función del tiempo transcurrido
    void Update(float dt)
    {
        // Actualización de la velocidad en función de la aceleración y el tiempo
        _velocity.x += _acceleration.x * dt;
        _velocity.y += _acceleration.y * dt;

        // Actualización de la posición en función de la velocidad y el tiempo
        _position.x += _velocity.x * dt;
        _position.y += _velocity.y * dt;

        // Se actualiza la posición del Sprite con la nueva posición calculada
        for (int i = 0; i < 10; i++) {
            _pSpr[9].setPosition(_position);
        }

        // Reinicio de las aceleraciones a 0 después de la actualización
        _acceleration.x = -250.0f;
        _acceleration.y = 200.0f;
    }
    bool CambioTextura(float x, float y, bool cambio) {
        _pSpr[9].setTexture(_pTex);
        if (cambio == true)
        {

            _pSpr[9].setTexture(Timpacto);

        }

        else  _pSpr[9].setTexture(_pTex);
        Timpacto.swap(_pTex);
        return cambio;
    }
    bool EstaEncima(float x, float y) {
        FloatRect bounds = _pSpr[9].getGlobalBounds();

        return bounds.contains(x, y);
    }
};

