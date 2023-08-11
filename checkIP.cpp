#include <iostream>
#include <cmath>
using namespace std;
bool blockCheck(string str)
{
    bool check = true;
    if (str.length() > 1 && str[0] == '0')
    {
        return check = false;
    }

    if (str.length() < 4)
    {
        int temp = 0;
        int rang = str.length() - 1;
        for (int i = 0; i < str.length(); i++)
        {
            temp += (str[i] - '0') * (int)pow(10, rang);
            rang--;
        }
        // cout << "temp: " << temp << "\n";
        if (temp <= 255)
        {
            check = true;
        }
        else
        {
            check = false;
        }
        return check;
    }
    else
    {
        return check = false;
    }
}

bool checkIp(string str)
{
    string one = "";
    string two = "";
    string three = "";
    string four = "";
    int countPoint = 0;
    bool check = true;
    for (int i = 0; i < str.length(); i++)
    {
        if ((isdigit(str[i]) || str[i] == '.') && str[str.length() - 1] != '.')
        {
            switch (countPoint)
            {
            case 0:
            {
                if (str[i] != '.')
                {
                    one += str[i];
                }
                break;
            }
            case 1:
            {
                if (str[i] != '.')
                {
                    two += str[i];
                }
                break;
            }
            case 2:
            {
                if (str[i] != '.')
                {
                    three += str[i];
                }
                break;
            }
            case 3:
            {
                if (str[i] != '.')
                {
                    four += str[i];
                }
                break;
            }
            }
        }
        else
        {
            return check = false;
        }

        if (str[i] == '.')
        {
            countPoint++;
        }
    }
    if ((!blockCheck(one) || !blockCheck(two)) || (!blockCheck(three) || !blockCheck(four)))
    {
        check = false;
    }
    else
    {
        check = true;
    }
    // cout << one << "\n"
    //      << two << "\n"
    //      << three << "\n"
    //      << four << "\n";
    return check;
}

int main()
{
    string ipAdress = "";
    string answer = "";
    cout << "Ввести IP-адрес: ";
    cin >> ipAdress;
    answer = checkIp(ipAdress) ? "Yes!" : "No!";
    cout << "Проверка: " << answer << "\n";
}