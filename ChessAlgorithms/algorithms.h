#pragma once

#define dimension 6

enum class Type
{
    NONE = 0,
    QUEEN,
    DANGER,
    PROMISING,
};

enum class Return
{
    FINISH = 0,
    CANNOT,
};

Return TryNQueens(Type tab[dimension][dimension], int LastXQueen, int LastYQueen);

void ReturnTabForUpel (Type tab[dimension][dimension]);


