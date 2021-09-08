#include "chess.h"
using namespace std;

chess::chess()
{
    init();
}

void chess::init()
{
    for(int x = 0; x < dim-1; x++)
    {
        for(int y = 0; y<dim-1; y++)
        {
            board[x][y] = 0;
        }
    }
    cout << "Board initialized!"<<endl;
}

bool chess::TryNextSteps(int i, int max)
{
    Coord coords = {0,0};
    bool success = false;


    do
    {
        if(validPosition(coords))
        {
            place(coords);
            success = true;

            if(i+1 < max) // Check for next damedane,dameyo,dame-damoyo,antaga,sugite-sugi,sugite,doredake,tsuyi-e-sakette-mo
            {
                success = TryNextSteps(i+1, max);
                if(!success)
                {
                    remove(coords);
                }
            }
        }

        if(!success && coords.x != -1 && coords.y != -1) // wenn man noch nicht alles probiert hat
        {
            coords = nextPos(coords); // Get the next position to try uwu
        }

    }while(!success && coords.x != -1 && coords.y != -1 );
    return success;
}

bool chess::validPosition(Coord coords)
{
    for(int x = 0; x<dim-1; x++) // Check for x placement
    {
        if(board[x][coords.y] == 1)
        {
            cout << "Placement test failed for: "<<x<< ", "<<coords.y << "."<<endl;
            return false;
        }
    }

    for(int y = 0; y<dim-1; y++) // Check for y placement
    {
        if(board[coords.x][y] == 1)
        {
            cout << "Placement test failed for: "<<coords.x<< ", "<<y << "."<<endl;
            return false;
        }
    }

    return true;

}

void chess::place(chess::Coord coords)
{
    board[coords.x][coords.y] = 1;
    cout << "Successfully placed."<<endl;
}

void chess::remove(chess::Coord coords)
{
    board[coords.x][coords.y] = 0;
    cout << "Removed from pos: "<<coords.x<<","<<coords.y <<endl;
}

void chess::damedaneDameyoDameDamoyo(int maxnum)
{
    TryNextSteps(0, maxnum);
}

chess::Coord chess::nextPos(chess::Coord coords)
{
    if(coords.x < dim)
    {
        Coord ret = {coords.x+1,coords.y};
        return ret;
    }
    else
    if(coords.y < dim)
    {
        Coord ret = {0,coords.y+1};
        return ret;
    }
    else
    {
        Coord ret = {-1,-1}; // all are full
        cout << "All coords are checked or full."<<endl;
        return ret;
    }
}


