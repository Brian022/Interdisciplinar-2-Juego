#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Platform.h"


class Character
{
    public:
        Character();
        Character(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpHeight);
        virtual void Update(float deltaTime);
        virtual void OnCollision(Platform x);

        void Draw(RenderWindow& window);

        Vector2f GetPosition() {return body.getPosition();}

    public:
        Animation animation;
        float speed, arriba, abajo, izquierda, derecha;
        RectangleShape body;
        bool exist;
        unsigned int row;
        bool faceRight;
        bool isFiring;
        bool isFiring1;
        Vector2f velocity;
        bool jump;
        float jumpHeight;

};

#endif // CHARACTER_H
