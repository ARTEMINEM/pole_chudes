#ifndef LOGIC_H
#define LOGIC_H
#include <string>
/*@brief PlayorExit - функция начала игры
 *@param reference &play - значение, получаемое от пользователя
 *@return - void
 */
using namespace std;
template <typename T>
int PlayorExit(T play);

int chooseNum(int numberPlayer);

void QuestionAnswer(string &question, string &rightAnswer); 

int correctWord(string &rightAnswer, string &userAnswer, bool &checkLenWord);

bool CheckUserAnswer(string &userAnswer, string &rightAnswer, vector<char>& letter, int &quantity);

void PlayerTurn(int &numberPlayer,int &turn, bool step);

bool FullWord(string &userAnswer, string &rightAnswer);

void Letter(string &rightAnswer, vector<char>& letter);




#endif
//  ЕСЛИ ЧТО ТЫ ПОКА НИКАК СВОЮ ЛОГИКУ НЕ ПОДГОНЯЙ ПОД ТО, ЧТО Я НАПИСАЛ ИЛИ НАОБОРОТ МОЕ НИКАК НЕ МЕНЯЙ.
//  ПОТОМ КАК ВСТРЕТИМСЯ И ВСЕ ОБСУДИМ ТО СКОМБИНИРУЕМ ВСЕ (КАПСОМ ЧТОБЫ УВИДЕЛ)