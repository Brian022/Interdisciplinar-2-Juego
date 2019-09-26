#ifndef PLATFORM_H
#define PLATFORM_H
#include <SFML\Graphics.hpp>
using namespace sf;
class Platform
{
    public:
        Platform(Texture* texture, Vector2f size, Vector2f position);
        ~Platform();
        void Draw(RenderWindow& window);
        static Platform* Crear(int tipo,Texture* texture, Vector2f size, Vector2f position);
        float arriba, abajo, izquierda, derecha;
        void GetPosition()
        {
            abajo =body.getPosition().y + body.getSize().y;
            arriba =body.getPosition().y;
            izquierda = body.getPosition().x;
            derecha = body.getPosition().x + body.getSize().x;
        }
    private:
        RectangleShape body;

    friend class Rojo;
    friend class Verde;
};


class Rojo : public Platform
{
    public:
    Rojo(Texture* texture, Vector2f size, Vector2f position):
        Platform(texture, size, position)
        {
            body.setSize(Vector2f(600.0f,25.0f));
            body.setTexture(texture);
            body.setPosition(Vector2f(200.0f, 400.0f));
        }

};

class Verde : public Platform
{
    public:
    Verde(Texture* texture, Vector2f size, Vector2f position):
        Platform(texture, size, position)
        {
            body.setSize(Vector2f(200.0f,25.0f));
            body.setTexture(texture);
            body.setPosition(Vector2f(0.0f, 200.0f));
        }
};




#endif // PLATFORM_H
