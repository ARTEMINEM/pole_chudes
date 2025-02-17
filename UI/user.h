#ifndef USER_H
#define USER_H

void ShowMenu(int &play);

void NumPlayers(int &numberPlayer);

void ShowQuestion(std::string &question, std::string &userAnswer, int &turn);  

void ShowWrongWord();

void ShowWord(std::vector<char>& letter);

void SayResult(bool step);

#endif