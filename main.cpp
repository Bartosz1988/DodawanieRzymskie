#include <iostream>
#include <map>
#include <string>
#include <conio.h>
#include <algorithm>

using namespace std;

int rzymskieNaArabskie(string liczbaRzymska)
{
    map<char, int> rzymskie;
    rzymskie['I'] = 1;
    rzymskie['V'] = 5;
    rzymskie['X'] = 10;
    rzymskie['L'] = 50;
    rzymskie['C'] = 100;
    rzymskie['D'] = 500;
    rzymskie['M'] = 1000;

    int liczbaArabska = 0;

    for(int i=0; i<liczbaRzymska.length(); i++)
    {
        int symbolA = 0;
        int symbolB = 0;

        symbolA = rzymskie[liczbaRzymska[i]];

        if(i<liczbaRzymska.length()-1)
        {
            symbolB = rzymskie[liczbaRzymska[i+1]];

            if(symbolA >= symbolB)
                liczbaArabska += symbolA;
            else
            {
                liczbaArabska += symbolB - symbolA;
                i++;
            }
        }
        else
        {
            liczbaArabska += symbolA;
            i++;
        }
    }
    return liczbaArabska;
}

string translateToLatin(int a)
{
    string digit = "";
    if (a == 2000)
    {
        digit += 'M';
        a -= 1000;
    }
    if (a >= 1000)
    {
        digit += 'M';
        a -= 1000;
    }
    if (a >= 900)
    {
        digit += 'C';
        digit += 'M';
        a -= 900;
    }
    else if (a >= 500)
    {
        digit += 'D';
        int howbiggur = int((a - 500) / 100);
        for (int i = 0; i < howbiggur; i++)
        {
            digit += 'C';
        }
        a -= 500 + howbiggur * 100;
    }
    else if (a >= 400)
    {
        digit += 'C';
        digit += 'D';
        a -= 400;
    }
    else if (a >= 100)
    {
        int howbiggur = int((a) / 100);
        for (int i = 0; i < howbiggur; i++)
        {
            digit += 'C';
        }
        a -= howbiggur * 100;
    }
    if (a >= 90)
    {
        digit += 'X';
        digit += 'C';
        a -= 90;
    }
    else if (a >= 50)
    {
        digit += 'L';
        int howbiggur = int((a - 50) / 10);
        for (int i = 0; i < howbiggur; i++)
        {
            digit += 'X';
        }
        a -= 50 + howbiggur * 10;
    }
    else if (a >= 40)
    {
        digit += 'X';
        digit += 'L';
        a -= 40;
    }
    else if (a >= 10)
    {
        int howbiggur = int((a) / 10);
        for (int i = 0; i < howbiggur; i++)
        {
            digit += 'X';
        }
        a -= howbiggur * 10;
    }
    if (a == 9)
    {
        digit += 'I';
        digit += 'X';
    }
    else if (a >= 5)
    {
        digit += 'V';
        int howbiggur = a - 5;
        for (int i = 0; i < howbiggur; i++)
        {
            digit += 'I';
        }

    }
    else if (a == 4)
    {
        digit += 'I';
        digit += 'V';
    }
    else
    {
        for (int i = 0; i < a; i++)
        {
            digit += 'I';
        }
    }
    return digit;
}

int main()
{
    string liczbaRzymska[2];//1 >> liczbaRzymska2;
    int liczbaArabska[2];
    int sumaArabskie = 0;
    //int liczbaArabska2 = 0;

    cin >> liczbaRzymska[0] >> liczbaRzymska[1];// >> liczba2;

    for(int i=0; i<2; i++)
    {
        liczbaArabska[i] = rzymskieNaArabskie(liczbaRzymska[i]);
        cout << liczbaArabska[i] << endl;
        sumaArabskie += liczbaArabska[i];
    }
    cout << sumaArabskie << endl;

    cout << translateToLatin(sumaArabskie);


    //cout << liczbaArabska1 << endl;
    //cout << liczbaArabska2 << endl;
    //cout << rzymskieNaArabskie(liczbaRzymska);

    /*for(int i=0; i<liczbaRzymska.length(); i++)
    {
        int symbolA = 0;
        int symbolB = 0;

        symbolA = rzymskie[liczbaRzymska[i]];

        if(i<liczbaRzymska.length()-1)
        {
            symbolB = rzymskie[liczbaRzymska[i+1]];

            if(symbolA >= symbolB)
                liczbaArabska += symbolA;
            else
            {
                liczbaArabska += symbolB - symbolA;
                i++;
            }
        }
        else
        {
            liczbaArabska += symbolA;
            i++;
        }
    }
    cout << liczbaArabska << endl;*/

    return 0;
}
