#include <iostream>
#include <cmath>
using namespace std;

char findSimbol(string x1, string x2, string x3, int x, int y)
{
    if ((x >= 0 && x < 3) && (y >= 0 && y < 3))
    {
        if (x == 0)
        {
            return x1[y];
        }
        else if (x == 1)
        {
            return x2[y];
        }
        else if (x == 2)
        {
            return x3[y];
        }
        else
        {
            return ' ';
        }
    }
    return ' ';
}

bool horizontX(string str)
{
    bool check = false;
    int count = 0;
    for (int y = 0; y < 3; y++)
    {
        if (str[y] == 'X')
        {
            check = true;
            count++;
        }
        else
        {
            check = false;
        }
    }
    if (count == 3)
        return check;
    else
        return false;
}
bool horizontO(string str)
{
    bool check = false;
    int count = 0;
    for (int y = 0; y < 3; y++)
    {
        if (str[y] == 'O')
        {
            check = true;
            count++;
        }
        else
        {
            check = false;
        }
    }
    if (count == 3)
        return check;
    else
        return false;
}
bool verticalX(string x1, string x2, string x3, int y)
{
    bool check = false;
    if ((x1[y] == 'X' && x2[y] == 'X') && x3[y] == 'X')
        check = true;
    else
        check = false;
    return check;
}
bool verticalO(string x1, string x2, string x3, int y)
{
    bool check = false;
    if ((x1[y] == 'O' && x2[y] == 'O') && x3[y] == 'O')
        check = true;
    else
        check = false;

    return check;
}
bool diagonalX(string x1, string x2, string x3, bool revers)
{
    bool check = false;
    if (revers)
    {
        if (x1[0] == 'X' && x2[1] == 'X' && x3[2] == 'X')
            check = true;
        else
            check = false;
        return check;
    }
    else
    {
        if (x1[2] == 'X' && x2[1] == 'X' && x3[0] == 'X')
            check = true;
        else
            check = false;
        return check;
    }
}
bool diagonalO(string x1, string x2, string x3, bool revers)
{
    bool check = false;
    if (revers)
    {
        if (x1[0] == 'O' && x2[1] == 'O' && x3[2] == 'O')
            check = true;
        else
            check = false;
        return check;
    }
    else
    {
        if (x1[2] == 'O' && x2[1] == 'O' && x3[0] == 'O')
            check = true;
        else
            check = false;
        return check;
    }
}

int countSimbol(string x1, string x2, string x3, char simbol)
{
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (findSimbol(x1, x2, x3, i, j) == simbol)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{

    string x1 = "OOX";
    string x2 = "OXX";
    string x3 = "X.O";
    bool vinX = false;
    bool vinO = false;
    for (int i = 1; i <= 3; i++)
    {
        string temp = "";
        if (i == 1)
            temp = x1;
        else if (i == 2)
            temp = x2;
        else if (i == 3)
            temp = x3;
        vinX = horizontX(temp);
        vinO = horizontO(temp);
        if (vinX || vinO)
            break;
    }
    if (!vinX && !vinO)
    {
        for (int j = 0; j < 3; j++)
        {
            vinX = verticalX(x1, x2, x3, j);
            vinO = verticalO(x1, x2, x3, j);
            if (vinX || vinO)
                break;
        }
        if (!vinX && !vinO)
        {
            vinX = diagonalX(x1, x2, x3, true);
            if (!vinX)
            {
                vinX = diagonalX(x1, x2, x3, false);
            }
            vinO = diagonalO(x1, x2, x3, true);
            if (!vinO)
            {
                vinO = diagonalO(x1, x2, x3, false);
            }
        }
    }
    if (vinX && (countSimbol(x1, x2, x3, 'X') - countSimbol(x1, x2, x3, 'O') == 1))
    {
        cout << "Petya won!\n";
    }
    else if (vinX && (countSimbol(x1, x2, x3, 'X') - countSimbol(x1, x2, x3, 'O') == 0))
    {
        cout << "Incorrect (потому что крестики выиграли за " << countSimbol(x1, x2, x3, 'X') << " хода, и на поле за это время не могло успеть появиться " << countSimbol(x1, x2, x3, 'O') << " ноликов)\n";
    }
    else if (vinO && (countSimbol(x1, x2, x3, 'O') - countSimbol(x1, x2, x3, 'X') == 1))
    {
        cout << "Vanya won!\n";
    }
    else if (vinO && (countSimbol(x1, x2, x3, 'O') - countSimbol(x1, x2, x3, 'X') == 0))
    {
        cout << "Incorrect (потому что нолики выиграли за " << countSimbol(x1, x2, x3, 'O') << " хода, и на поле за это время не могло успеть появиться " << countSimbol(x1, x2, x3, 'X') << " крестиков)\n";
    }
    else if ((vinX && vinO) && (countSimbol(x1, x2, x3, 'X') - countSimbol(x1, x2, x3, 'O') == 0))
    {
        cout << "Nobody (потому, что ничья)\n";
    }
    else if ((!vinX && !vinO) && (countSimbol(x1, x2, x3, 'X') - countSimbol(x1, x2, x3, 'O') == 0))
    {
        cout << "Incorrect (потому, что не доиграли)\n";
    }
    else if ((!vinX && !vinO) && abs((countSimbol(x1, x2, x3, 'X') - countSimbol(x1, x2, x3, 'O')) > 0))
    {
        cout << "Incorrect (потому, что не доиграли)\n";
    }
    else if ((!vinX && !vinO) && (countSimbol(x1, x2, x3, 'X') - countSimbol(x1, x2, x3, 'O') > 1))
    {
        cout << "Incorrect (потому, что X больше, чем доступно по правилам)\n";
    }
    else if ((!vinX && !vinO) && (countSimbol(x1, x2, x3, 'O') - countSimbol(x1, x2, x3, 'X') > 1))
    {
        cout << "Incorrect (потому, что O больше, чем доступно по правилам)\n";
    }
}
