#ifndef ANIMATION_H
#define ANIMATION_H

#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
 class Animation
 {
 public:
 	 Animation(Texture* texture, Vector2u imageCount, float switchTime);
 	 void Update(int row, float deltaTime, bool faceRight);
 	 IntRect uvRect;

 private:
 	Vector2u imageCount;
 	Vector2u currentImage;

 	float totalTime;
 	float switchTime;

 };

#endif // ANIMATION_H
