#ifndef USER_H
#define USER_H

void ShowMenu(int &play);

void NumPlayers(int &numberPlayer);

void ShowQuestion(char &question, char &userAnswer, int &turn);  

void ShowWrongWord();

void ShowWord(char &rightAnswer, int &length);

void ShowResult(bool step);

#endif