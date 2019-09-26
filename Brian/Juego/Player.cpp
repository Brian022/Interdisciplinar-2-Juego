#include "Player.h"
#include <iostream>
Player::Player(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpHeight):
    Character(texture, imageCount, switchTime, speed, jumpHeight)
{
    cout<<"constructor de player"<<endl;
    this->speed = speed;
    this->jumpHeight = jumpHeight;
    row = 0;
    faceRight= true;
    body.setSize(Vector2f(50.0f, 100.0f));
    body.setPosition(0.0f, 200.0f);
    body.setTexture(texture);
}

bool Player::Colisionando(Platform x)
{
    if(derecha < x.izquierda || izquierda > x.derecha || arriba > x.abajo || abajo < x.arriba)
        return false;
    return true;
}

bool Player::Colisionando1(Platform* x)
{
    if(derecha < x->izquierda || izquierda > x->derecha || arriba > x->abajo || abajo < x->arriba)
        return false;
    return true;
}

void Player::Update(float deltaTime, Platform x, Platform y)
{
    velocity.x = 0.0f;

    abajo =body.getPosition().y + body.getSize().y;
    arriba =body.getPosition().y;
    izquierda = body.getPosition().x;
    derecha = body.getPosition().x + body.getSize().x;

    if(Keyboard::isKeyPressed(Keyboard::A))
        velocity.x -= speed;
    if(Keyboard::isKeyPressed(Keyboard::D))
        velocity.x += speed;

    if(Colisionando(x)==true )
    {
        velocity.y = 0.0f;
        if(Keyboard::isKeyPressed(Keyboard::W)&& jump)
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
        if(Keyboard::isKeyPressed(Keyboard::W)&& jump)
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
        row = 3;
        if(velocity.x > 0.0f)
            faceRight = true;
        else
            faceRight = false;
    }

    animation.Update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(velocity * deltaTime);
}


