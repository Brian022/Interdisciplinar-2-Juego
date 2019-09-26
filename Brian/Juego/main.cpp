#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Character.h"
#include "Player.h"
#include "Player1.h"
#include "Platform.h"
#include "Bullet.h"
#include "Vida.h"
#include <SFML/Audio.hpp>
#include <Thread>
using namespace sf;
using namespace std;

static const float viewHeight = 1200;
void ResizeView(const RenderWindow& window, View& view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(viewHeight * aspectRatio, viewHeight);
}


int main()
{
    int vidap1=3;
    int vidap2=3;


    RenderWindow window(VideoMode(1200, 600), "El Juego", Style::Resize | Style::Close);
    View view(Vector2f(0.0f,0.0f), Vector2f(600, 600));
    view.setViewport(sf::FloatRect(0.f, 0.f, 0.5f, 1.f));

    View view1(Vector2f(0.0f,0.f), Vector2f(600, 600));
    view1.setViewport(sf::FloatRect(0.5f, 0.f, 0.5f, 1.f));
    //background sprite
    RectangleShape background(Vector2f(6000, 1200));
    background.setTextureRect(sf::IntRect(0, 0, 1200, 600));
    Texture backgroundtexture;
    backgroundtexture.loadFromFile("../cityArt.jpg");
    background.setTexture(&backgroundtexture);
    //TEXTURA DEL PRIMER JUGADOR
    Texture playerTexture;
    playerTexture.loadFromFile("../Boy1.png");
    //TEXTURA DE OTRO JUGADOR
    Texture player1Texture;
    player1Texture.loadFromFile("../Girl1.png");
    Texture ground;
    ground.loadFromFile("../ground.png");

    Player player(&playerTexture, Vector2u(4,4), 0.3, 200.0f, 150.0f);
    Player1 player1(&player1Texture, Vector2u(8,4), 0.3f, 200.0f, 150.0f);

    Texture ball;
    ball.loadFromFile("../bala.png");

    vector<Bullet> bulletvec;
    vector<Bullet> bulletvec1;


    Platform platform1(&ground, Vector2f(3000.0f, 25.0f), Vector2f(0.0f,500.0f));
    Platform platform2(&ground, Vector2f(600.0f,25.0f), Vector2f(200.0f, 400.0f));
    Platform platform3(&ground, Vector2f(600.0f,25.0f), Vector2f(200.0f, 300.0f));
    platform1.GetPosition();
    platform2.GetPosition();
    platform3.GetPosition();

    Bullet* bala = Bullet::getInstance();
    Bullet* bala1 = Bullet::getInstance();



    float deltaTime = 0.0f;
    Clock clock;


    while (window.isOpen() )
    {

        deltaTime = clock.restart().asSeconds();
        if(deltaTime > 1.0f/20.0f)
            deltaTime = 1.0f/20.0f;

        Event evnt;
        while (window.pollEvent(evnt))
        {
            switch(evnt.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::Resized:
                ResizeView(window, view);
                ResizeView(window, view1);
                break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                player.isFiring= true;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
                player1.isFiring1= true;
        }

        player.Update(deltaTime, platform1, platform2);
        player1.Update(deltaTime,platform1, platform2);
        bala->init(&ball,Vector2f(50.0f,50.0f),Vector2f(player.GetPosition()));
        bala1->init(&ball,Vector2f(50.0f,50.0f),Vector2f(player1.GetPosition()));

        window.clear();

        window.setView(view);
        view.setCenter(player.GetPosition());
        window.draw(background);
        player.Draw(window);
        player1.Draw(window);
        platform1.Draw(window);
        platform2.Draw(window);
        platform3.Draw(window);

        if (player.isFiring == true)
        {

            bulletvec.push_back(*bala);
            player.isFiring = false;
        }

        for (int i = 0; i < bulletvec.size(); i++)
        {
            bulletvec[i].Draw(window);
            if(player.faceRight == true)
            bulletvec[i].fire(0.5);
            if(bulletvec[i].body.getGlobalBounds().intersects(player1.body.getGlobalBounds())){
                bulletvec[i].init(&ball,Vector2f(0,0),Vector2f(player.GetPosition()));
                cout<<"Vida de Chica: "<<--vidap1<<endl;
                if(vidap1<=0){
                    cout<<"Niño gano!!!!!!";
                    window.close();
                }
            }
        }
        /////////////////////////////////////////
        if (player1.isFiring1 == true)
        {

            bulletvec1.push_back(*bala1);
            player1.isFiring1 = false;
        }

        for (int i = 0; i < bulletvec1.size(); i++)
        {
            bulletvec1[i].Draw(window);
            bulletvec1[i].fire(-0.5);
            if(bulletvec1[i].body.getGlobalBounds().intersects(player.body.getGlobalBounds())){
                bulletvec1[i].init(&ball,Vector2f(0,0),Vector2f(player1.GetPosition()));
                cout<<"Vida de niño: "<<--vidap2<<endl;
                if(vidap2<=0){
                    cout<<"Chica gano!!!!!!";
                    RenderWindow window1(VideoMode(1200, 600), "Victoria", Style::Resize | Style::Close);
                    window.close();
                }
            }
        }


        ////////////////////////////////////////////////////////////////////////////////////////

        window.setView(view1);
        view1.setCenter(player1.GetPosition());
        window.draw(background);
        player.Draw(window);
        player1.Draw(window);
        platform1.Draw(window);
        platform2.Draw(window);

        if (player.isFiring == true)
        {

            bulletvec.push_back(*bala);
            player.isFiring = false;
        }

        for (int i = 0; i < bulletvec.size(); i++)
        {
            bulletvec[i].Draw(window);
            bulletvec[i].fire(0.5);

        }
        /////////////////////////////////////////
        if (player1.isFiring1 == true)
        {


            bulletvec1.push_back(*bala1);
            player1.isFiring1 = false;
        }

        for (int i = 0; i < bulletvec1.size(); i++)
        {
            bulletvec1[i].Draw(window);
            bulletvec1[i].fire(-0.5);
        }


        ////////////////////////////////////////////////////////////////////////////////////////

        window.display();
    }
    /*
    for(int i=0; i<plataformas.size();i++)
    {
        delete plataformas[i];
    }
    */


    return 0;
}
