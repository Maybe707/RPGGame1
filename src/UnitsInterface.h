#ifndef RPGGAME_UNITSINTERFACE_H
#define RPGGAME_UNITSINTERFACE_H

#include <SFML/Graphics.hpp>

class UnitsInterface : public sf::Drawable
{
    virtual void unitUpdate(float gameTime) = 0;

    virtual void unitAnimation(float gameTime) = 0;
};

#endif
