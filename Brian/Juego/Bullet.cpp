#include "Bullet.h"
#include "Character.h"
#include <vector>

Bullet::Bullet()
{
    bulletID = currentIndex +1;
}
std::vector<Bullet *> Bullet::bullets;
int Bullet::limiteJ = Bullet::reserverSize();
int Bullet::currentIndex =  0;

Bullet::~Bullet()
{
    //dtor
}

void Bullet::init(Texture* texture, Vector2f size, Vector2f position)
{
    body.setSize(size);
        body.setTexture(texture);
        body.setPosition(position);
}

void Bullet::Draw(RenderWindow& window)
{
    window.draw(body);
}

