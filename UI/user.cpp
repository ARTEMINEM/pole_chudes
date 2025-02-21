#include <iostream>
#include <cstdio>
#include <string>
#include "user.h"
using namespace std;

void ShowMenu(string &play)
{
    cout << endl << "Field of miracles" << endl;
    cout << endl << "1)play\t\t2)exit" << endl;
    cin >> play;
}

void NumPlayers(string &numberPlayer)
{
    cout << endl << "Enter number of players (1-2):" << endl;
    cin >> numberPlayer;
}

void ShowQuestion(string &question, string &userAnswer, int &turn)
{
    cout << question << endl << "Player's turn " << turn << ": " << endl;
    cin >> userAnswer;
}

void ShowWrongWord()
{
    cout << endl << "Hmmm... Wrong word!" <<endl;
}

void ShowWord(vector<char>& letter)
{
    for (int i = 0; i < letter.size(); i++)
    {
        cout << letter[i] << " ";
    }
    cout << endl;
}

void SayResult(bool step)
{
    if (step)
        cout << endl << "Open up!" << endl;
    else
        cout << endl << "Open up! No, they don't open. Because it's not there." << endl;
}

