#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

//пока чисто для работы
//на английском чтобы не обосралось ниче, но на русском смешнее фразы у него
void ShowMenu(int &play)
{
    cout << endl << "Field of miracles" << endl;
    cout << endl << "1)play\t\t2)exit" << endl;
    cin >> play;
}

void NumPlayers(int &numberPlayer)
{
    cout << endl << "Enter number of players (1-2):" << endl;
    cin >> numberPlayer;
}

void ShowQuestion(string &question, string &userAnswer, int &turn)
{
    // вывод вопроса и номер игрока который отвечает
    // пользовательский ввод
}

void ShowWrongWord()
{
    cout << endl << "Hmmm... Wrong word!" <<endl;
}

void ShowWord(char &rightAnswer, int &length)
{
    /*for (int i = 0; i < strlen(length); i++)
    {
        if (lengt[i] == *)
            cout << rightAnswer[i] << " ";
        else
            cout << "_ ";  
    }*/
}

void SayResult(bool step)
{
    if (step)
        cout << endl << "Open up!" << endl;
    else
        cout << endl << "Open up! No, they don't open. Because it's not there.";
}

