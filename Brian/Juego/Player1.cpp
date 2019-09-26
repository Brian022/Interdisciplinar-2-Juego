#include "Player1.h"
#include <iostream>
Player1::Player1(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpHeight):
    Character(texture, imageCount, switchTime, speed, jumpHeight)
{
    cout<<"constructor de player"<<endl;
    this->speed = speed;
    this->jumpHeight = jumpHeight;
    row = 0;
    faceRight= true;
    body.setSize(Vector2f(100.0f, 100.0f));
    body.setPosition(900.0f, 200.0f);
    body.setTexture(texture);
}

bool Player1::Colisionando(Platform x)
{
    if(derecha < x.izquierda || izquierda > x.derecha || arriba > x.abajo || abajo < x.arriba)
        return false;
    return true;
}

bool Player1::Colisionando1(Platform* x)
{
    if(derecha < x->izquierda || izquierda > x->derecha || arriba > x->abajo || abajo < x->arriba)
        return false;
    return true;
}

void Player1::Update(float deltaTime, Platform x, Platform y)
{
    velocity.x = 0.0f;

    abajo =body.getPosition().y + body.getSize().y;
    arriba =body.getPosition().y;
    izquierda = body.getPosition().x;
    derecha = body.getPosition().x + body.getSize().x;

    if(Keyboard::isKeyPressed(Keyboard::Left))
        velocity.x -= speed;
    if(Keyboard::isKeyPressed(Keyboard::Right))
        velocity.x += speed;

    if(Colisionando(x)==true)
    {
        velocity.y = 0.0f;
        if(Keyboard::isKeyPressed(Keyboard::Up)&& jump)
        {
            velocity.y = -sqrt(2.0f* 981.0f * jumpHeight);
            jump = true;

        }
    }

    if(Colisionando(x)==false)
    {
        velocity.y += 981.0f * deltaTime;
    }
    if(Colisionando(y)==true )
    {
            velocity.y = 0.0f;
        if(Keyboard::isKeyPressed(Keyboard::Up)&& jump)
        {
            velocity.y = -sqrt(2.0f* 981.0f * jumpHeight);
            jump = true;
        }
    }

    if(Colisionando(y)==false)
    {
        velocity.y += 981.0f * deltaTime;
    }


    if(velocity.x == 0.0f)
    {
        row = 0;
    }
    else
    {
        row = 2;
        if(velocity.x > 0.0f)
            faceRight = true;
        else
            faceRight = false;
    }

    animation.Update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(velocity * deltaTime);
}
