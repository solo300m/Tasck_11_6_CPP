#include <iostream>
using namespace std;

string getFirstPast(string str)
{
    string rez = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '@')
        {
            break;
        }
        else if (str[i] != '@')
        {
            rez += str[i];
        }
    }
    return rez;
}

string getSecondPast(string str)
{
    string rez = "";
    int startPos = 0;
    int i = 0;
    while (str[i] != '@')
    {
        startPos++;
        i++;
    }
    for (int j = startPos; j < str.length(); j++)
    {
        rez += str[j];
    }
    return rez;
}
bool checkFirst(string str)
{
    string simbols = "!#$%&'*+-/=?^_`{|}~-.";
    bool check = true;
    int limit = 64;
    if (str.length() > 0 && str.length() <= limit)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if ((((int)str[i] >= 65 && (int)str[i] <= 90) || ((int)str[i] >= 97 && (int)str[i] <= 122)) || ((int)str[i] >= 48 && (int)str[i] <= 57))
            {
                check = true;
            }
            else if ((int)str[i] == 46 && i == str.length() - 1)
            {
                check = false;
                break;
            }
            else if (((int)str[i] == 46 && (int)str[i + 1] == 46) && (i <= str.length() - 2))
            {
                check = false;
                break;
            }
            else
            {
                for (int j = 0; j < simbols.length(); j++)
                {
                    if (str[i] == simbols[j])
                    {
                        check = true;
                        break;
                    }
                    else
                    {
                        check = false;
                    }
                }
                if (!check)
                    return check;
            }
        }
        return check;
    }
    else
    {
        check = false;
        return check;
    }
}
bool checkSecond(string str)
{
    int limit = 63;
    bool check = true;
    if (str.length() > 0 && str.length() <= limit)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if ((((int)str[i] >= 65 && (int)str[i] <= 90) || ((int)str[i] >= 97 && (int)str[i] <= 122)) || ((int)str[i] >= 48 && (int)str[i] <= 57))
            {
                check = true;
            }
            else if ((int)str[i] == 46 && i == str.length() - 1)
            {
                check = false;
                break;
            }
            else if (((int)str[i] == 46 && (int)str[i + 1] == 46) && (i <= str.length() - 2))
            {
                check = false;
                break;
            }
            else if ((int)str[0] != 64)
            {
                check = false;
                break;
            }
        }
        return check;
    }
    else
    {
        check = false;
        return check;
    }
}
int main()
{
    string email = "";
    string firstPast = "";
    string secondPast = "";
    cout << "Введите Ваш email: \n";
    cout << "Ввод: ";
    cin >> email;
    firstPast = getFirstPast(email);
    secondPast = getSecondPast(email);
    bool chFirst = checkFirst(firstPast);
    bool chSecond = checkSecond(secondPast);
    //cout << "Первая часть: " << firstPast << " Проверка: " << (bool)chFirst << "\nВторая часть: " << secondPast << " Проверка: " << chSecond << "\n";
    if (chFirst && chSecond)
    {
        cout << "Yes!\n";
    }
    else
    {
        cout << "NO!\n";
    }
}