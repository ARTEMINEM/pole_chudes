#ifndef LOGIC_H
#define LOGIC_H

/*@brief PlayorExit - функция начала игры
 *@param reference &play - значение, получаемое от пользователя
 *@return - void
 */
int PlayorExit(int &play);
//прикольный этот комментарийБ у Стаса посмотрел

int chooseNum(int &numberPlayer);

void QuestionAnswer(char &question,char  &rightAnswer);  //крайне сыро, надо думать (но это уже когда функции будем писать)

int Alphabet(char &userAnswer);

bool CheckUserAnswer(char &userAnswer, char &rightAnswer, int &length, bool end);

void PlayerTurn(int &numberPlayer,int &turn, bool result);

bool FullWord(char &userAnswer);




#endif
//  ЕСЛИ ЧТО ТЫ ПОКА НИКАК СВОЮ ЛОГИКУ НЕ ПОДГОНЯЙ ПОД ТО, ЧТО Я НАПИСАЛ ИЛИ НАОБОРОТ МОЕ НИКАК НЕ МЕНЯЙ.
//  ПОТОМ КАК ВСТРЕТИМСЯ И ВСЕ ОБСУДИМ ТО СКОМБИНИРУЕМ ВСЕ (КАПСОМ ЧТОБЫ УВИДЕЛ)