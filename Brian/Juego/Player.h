#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Animation.h"
#include "Platform.h"


class Player : public Character
{
    public:
        Player(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpHeight);
        void Update(float deltaTime, Platform x, Platform y);
        bool Colisionando(Platform x);
        bool Colisionando1(Platform* x);

};

#endif // PLAYER_H
