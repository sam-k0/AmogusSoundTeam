#ifndef CHESS_H
#define CHESS_H
#include <iostream>

class chess
{
private:
    int board[5][5];
    int dim = 5;

    struct Coord
    {
        int x;
        int y;
    };


public:
    chess();

    void init();
    bool TryNextSteps(int i, int max);
    bool validPosition(Coord coords);
    void place(Coord coords);
    void remove(Coord coords);
    void damedaneDameyoDameDamoyo(int maxnum);
    Coord nextPos(Coord coords);
    void print();
};

#endif // CHESS_H
