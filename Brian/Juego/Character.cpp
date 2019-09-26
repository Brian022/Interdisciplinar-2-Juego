#include "Character.h"
#include <iostream>
Character::Character(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpHeight):
    animation(texture, imageCount, switchTime)
{

}

void Character::Update(float deltaTime)
{

}
void Character::OnCollision(Platform x)
{

}

void Character::Draw(RenderWindow& window)
{
    window.draw(body);
}
