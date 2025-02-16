#ifndef LOGIC_H
#define LOGIC_H
#include <string>
/*@brief PlayorExit - функция начала игры
 *@param reference &play - значение, получаемое от пользователя
 *@return - void
 */
using namespace std;
int PlayorExit(int play);
//прикольный этот комментарийБ у Стаса посмотрел

int chooseNum(int numberPlayer);

void QuestionAnswer(string &question, string &rightAnswer);  //крайне сыро, надо думать (но это уже когда функции будем писать)

int correctWord(string &rightAnswer, string &userAnswer);

bool CheckUserAnswer(string &userAnswer, string &rightAnswer, vector<char>& letter, int &quantity);

void PlayerTurn(int &numberPlayer,int &turn, bool step);

bool FullWord(string &userAnswer, string &rightAnswer);




#endif
//  ЕСЛИ ЧТО ТЫ ПОКА НИКАК СВОЮ ЛОГИКУ НЕ ПОДГОНЯЙ ПОД ТО, ЧТО Я НАПИСАЛ ИЛИ НАОБОРОТ МОЕ НИКАК НЕ МЕНЯЙ.
//  ПОТОМ КАК ВСТРЕТИМСЯ И ВСЕ ОБСУДИМ ТО СКОМБИНИРУЕМ ВСЕ (КАПСОМ ЧТОБЫ УВИДЕЛ)