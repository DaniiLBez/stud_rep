#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "observable.hpp"

class Player:public Observable{

public:

    Player(int HP = 100, int points = 0, int power = 20):_hitPoints(HP), _points(points), _power(power){}
    Player(const Player& obj):_hitPoints(obj._hitPoints), _points(obj._points), _power(obj._power){}
    Player& operator=(const Player& obj);

    enum command{
        UP = 0,
        DOWN = 1,
        LEFT = 2,
        RIGHT = 3, 
        QUIT = 4,
        NOTHING = 5
    };

    int getPower() const;

    void setPower(int power);

    int getHP() const;

    void setHP(int hp);

    int getPoints() const;

    void addPoints(int points);

private:
    int _hitPoints;
    int _points;
    int _power;
};

#endif