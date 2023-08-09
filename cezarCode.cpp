#include <iostream>
using namespace std;

string encryptCaesar(string str, int shift)
{
    string rez = "";
    for (int i = 0; i < str.length(); i++)
    {
        if ((shift > 0 && (bool)islower(str[i])) && str[i] != ' ')
        {
            if (((int)(str[i] + shift) > (int)'z') && str[i] != 'z')
            {
                int temp = ((int)(str[i] + shift) - (int)'z');
                rez += 'a' + temp;
            }
            else if (str[i] == 'z')
            {
                // int temp = ((int)(str[i] + shift) - (int)'z');
                rez += 'a';
            }
            else
            {
                rez += str[i] + shift;
            }
        }
        else if ((shift < 0 && (bool)islower(str[i])) && str[i] != ' ')
        {
            if (((int)(str[i] + shift) < (int)'a') && str[i] != 'a')
            {
                int temp = ((int)'a' - (int)(str[i] + shift));
                rez += 'z' - temp;
            }
            else if (str[i] == 'a')
            {
                rez = 'z';
            }
            else
            {
                rez += str[i] + shift;
            }
        }
        else if ((shift > 0 && (bool)isupper(str[i])) && str[i] != ' ')
        {
            if (((int)(str[i] + shift) > (int)'Z') && str[i] != 'Z')
            {
                int temp = ((int)(str[i] + shift) - (int)'Z');
                rez += 'A' + temp;
            }
            else if (str[i] == 'Z')
            {
                // int temp = ((int)(str[i] + shift) - (int)'Z');
                rez += 'A';
            }
            else
            {
                rez += str[i] + shift;
            }
        }
        else if ((shift < 0 && (bool)isupper(str[i])) && str[i] != ' ')
        {
            if (((int)(str[i] + shift) < (int)'A') && str[i] != 'A')
            {
                int temp = ((int)'A' - (int)(str[i] + shift));
                rez += 'Z' - temp;
            }
            else if (str[i] == 'A')
            {
                rez += 'Z';
            }
            else
            {
                rez += str[i] + shift;
            }
        }
    }
    return rez;
};
string decryptCaesar(string str, int shift)
{
    string rez = "";
    for (int i = 0; i < str.length(); i++)
    {
        int delta = (int)(str[i] - shift);
        if ((shift > 0 && (bool)islower(str[i])) && str[i] != ' ')
        {
            if ((str[i] - shift) < 'a' && str[i] != 'a')
            {
                int temp = ('a' - (str[i] - shift));
                rez += 'z' - temp;
            }
            else if (str[i] == 'a')
            {
                rez += 'z';
            }
            else
            {
                rez += (str[i] - shift);
            }
        }
        else if ((shift < 0 && (bool)islower(str[i])) && str[i] != ' ')
        {
            if (((int)(str[i] - shift) > (int)'z') && str[i] != 'z')
            {
                int temp = ((int)'z' - (int)(str[i] - shift));
                rez += 'a' - temp;
            }
            else if (str[i] == 'z')
            {
                rez += 'a';
            }
            else
            {
                rez += str[i] - shift;
            }
        }
        else if ((shift > 0 && (bool)isupper(str[i])) && str[i] != ' ')
        {
            if ((int)(str[i] - shift) < (int)'A' && str[i] != 'A')
            {
                int temp = ((int)'A' - (int)(str[i] - shift));
                rez += 'Z' - temp;
            }
            else if (str[i] == 'A')
            {
                rez += 'Z';
            }
            else
            {
                rez += str[i] - shift;
            }
        }
        else if ((shift < 0 && (bool)isupper(str[i])) && str[i] != ' ')
        {
            if ((int)(str[i] - shift) > (int)'Z' && str[i] != 'Z')
            {
                int temp = ((int)'Z' - (int)(str[i] - shift));
                rez += 'A' - temp;
            }
            else if (str[i] == 'Z')
            {
                rez += 'A';
            }
            else
            {
                rez += str[i] - shift;
            }
        }
    }
    return rez;
}

int main()
{
    string str = "";
    string codeStr = "";
    string codeDestr = "";
    int shift = 0;
    cout << "Введите строку для шифрования: \n";
    getline(cin, str);
    cout << "Введите целочисленный ключ для шифрования: ";
    cin >> shift;
    codeStr = encryptCaesar(str, shift);
    cout << codeStr << "\n";
    codeDestr = decryptCaesar(codeStr, shift);
    cout << codeDestr << "\n";
}