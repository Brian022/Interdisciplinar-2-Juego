#ifndef BULLET_H
#define BULLET_H
#include <SFML\Graphics.hpp>
#include "Character.h"
#include <vector>
#define LIMIT 2
using namespace sf;

class Bullet
{
    private:
        static std::vector<Bullet*> bullets;
        static int limiteJ;
        static int currentIndex;
        int bulletID;
        Bullet();

    public:
        ~Bullet();
        int getId()
        {
            return bulletID;
        }
        void fire(float deltaTime)
        {
                body.move(deltaTime,0);
        }
        int getRight()
        {
            return body.getPosition().x+body.getSize().x;
        }
        int getLeft() {
            return body.getPosition().x;
        }
        static int reserverSize()
        {
            Bullet::bullets.reserve(LIMIT);
            for(int i = 0; i < LIMIT; i++)
            {
                Bullet::bullets[i] = NULL;
            }
            return LIMIT;
        }

        void Draw(RenderWindow& window);
        void init(Texture* texture, Vector2f size, Vector2f position);

        static Bullet *getInstance()
        {

            currentIndex = currentIndex % LIMIT;

            if(!Bullet::bullets[currentIndex % limiteJ])
            {
                Bullet::bullets[currentIndex % limiteJ] = new Bullet();
            }
            return Bullet::bullets[currentIndex++ % limiteJ];
        }

        /*
        static Bullet *GetBullet()
        {
            if(!bullet1){
                bullet1 = new Bullet;
            }
            return bullet1;
        }
        */


    RectangleShape body;
};

#endif // BULLET_H
