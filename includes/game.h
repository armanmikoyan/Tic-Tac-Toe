#ifndef GAME_H
#define GAME_H

#include "board.h"
#include <thread>
#include <chrono>

#define SIZE 3


struct Player {
    std::string name;
    bool turn;
};

class Game {
public:
    Game();

public:
    void draw_table();
    void step();
    void start();
    void syncronization();
private:

    Board board;
    Player p1;
    Player p2;
};


#endif //GAME_H