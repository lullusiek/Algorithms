#include <iostream>

#include "algorithms.h"

int main()
{
    Type tab[dimension][dimension] = {Type::NONE};
    int startXQueen;
    int startYQueen;
    std::cin >> startYQueen >> startXQueen;

    tab[startXQueen][startYQueen] = Type::QUEEN;
    Return ret = TryNQueens(tab, startXQueen, 0);
    if (ret == Return::FINISH)
    {
        ReturnTabForUpel(tab);
    }
    else
    {
        std::cout << "CANNOT";
    }
}