#ifndef USER_H
#define USER_H

void ShowMenu(std::string &play);

void NumPlayers(std::string &numberPlayer);

void ShowQuestion(std::string &question, std::string &userAnswer, int &turn);  

void ShowWrongWord();

void ShowWord(std::vector<char>& letter);

void SayResult(bool step);

#endif