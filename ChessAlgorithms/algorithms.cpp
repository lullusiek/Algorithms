#include "algorithms.h"
#include <iostream>
#include <string.h>


void ReturnTab (Type tab[dimension][dimension])
{
    for (int y = 0; y < dimension; y++)
    {
        for (int x = 0; x < dimension; x++)
        {
            std::cout << (int) tab[x][y] << " ";
        }
        std::cout << "\n";
    }
}

void SetDanger(Type tab[dimension][dimension], int xQueen, int yQueen)
{
    //SetColumn
    for (int y = (yQueen + 1); y < dimension; y++)
    {
        tab[xQueen][y] = Type::DANGER;
    }
    //SetRow
    if (((xQueen - 1) >= 0) && ((yQueen + 1) < dimension))
    {
        tab[xQueen - 1][yQueen + 1] = Type::DANGER;
    }
    if (((xQueen + 1) < dimension) && ((yQueen + 1) < dimension))
    {
        tab[xQueen + 1][yQueen + 1] = Type::DANGER;
    }
}

void SetPromising(Type tab[dimension][dimension], int yQueen)
{
    for (int x = 0; x < dimension; x++)
    {
        if ((tab[x][yQueen+1] != Type::DANGER)  && ((yQueen + 1) < dimension))
        {
            tab[x][yQueen + 1] = Type::PROMISING;
        }
    }
}

int SetNewQueen(Type tab[dimension][dimension], int lastYQeen)
{
    for (int x = 0; x < dimension; x++)
    {
        if ((tab[x][lastYQeen + 1] == Type::PROMISING) && ((lastYQeen + 1) < dimension))
        {
            tab[x][lastYQeen + 1] = Type::QUEEN;
            return x;
        }
    }
    return -1;
}



Return TryNQueens(Type tab[dimension][dimension], int LastXQueen, int LastYQueen)
{
    //ReturnTab(tab);
    //std::cout << std::endl;
    if (LastYQueen == (dimension - 1))
    {
        return Return::FINISH;
    }
    Type copy[dimension][dimension];
    memcpy(copy, tab, sizeof(Type) * dimension * dimension);
    SetDanger(tab, LastXQueen, LastYQueen);
    SetPromising(tab, LastYQueen);
    while (true)
    {
        int NewXQueen = SetNewQueen(tab, LastYQueen);
        if (NewXQueen != -1)
        {
            Return ret = TryNQueens(tab, NewXQueen, LastYQueen + 1);
            if (ret == Return::FINISH)
            {
                return Return::FINISH;
            }
        }
        else
        {
            memcpy(tab, copy, sizeof(Type) * dimension * dimension);
            tab[LastXQueen][LastYQueen] = Type::DANGER;

            return Return::CANNOT;
        }
    }
}

void ReturnTabForUpel (Type tab[dimension][dimension])
{
    for (int y = 0; y < dimension; y++)
    {
        for (int x = 0; x < dimension; x++)
        {
            if (tab[x][y] != Type::QUEEN)
            {
                tab[x][y] = Type::NONE;
            }
            std::cout << (int)tab[x][y] << " ";
        }
        std::cout << "\n";
    }
}
