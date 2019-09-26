    #include "Platform.h"

Platform::Platform(Texture* texture, Vector2f size, Vector2f position)
{
        body.setSize(size);
        body.setTexture(texture);
        body.setPosition(position);
}

Platform::~Platform()
{
    //dtor
}

Platform* Platform::Crear(int tipo,Texture* texture, Vector2f size, Vector2f position)
{
    if(tipo = 1)
    {
        return new Rojo(texture, size,position);

    }
    else if(tipo = 2)
        return new Verde(texture, size,position);
}

void Platform::Draw(RenderWindow& window)
{
    window.draw(body);
}
