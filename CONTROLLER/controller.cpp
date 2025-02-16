#include <iostream>
#include "logic.h"
#include "user.h"
#include "error.h"

//  ЕСЛИ ЧТО ТЫ ПОКА НИКАК СВОЮ ЛОГИКУ НЕ ПОДГОНЯЙ ПОД ТО, ЧТО Я НАПИСАЛ ИЛИ НАОБОРОТ МОЕ НИКАК НЕ МЕНЯЙ.
//  ПОТОМ КАК ВСТРЕТИМСЯ И ВСЕ ОБСУДИМ ТО СКОМБИНИРУЕМ ВСЕ (КАПСОМ ЧТОБЫ УВИДЕЛ)

int main()
{
    while(true)
    {
        /*переменные будут*/
        int ErrCode = 0;
        int length[100];                // ОБГОВОРИТЬ!!! объясню как встретимся, 100 эта рандомно написал
        bool step = false, end = false;
        int play = 0, numberPlayer = 0, turn = 1;
        int size, quantity = 0;                               //длина слова (может и не надо, пока хз) //колличество угаданных букв
        char question, rightAnswer, userAnswer;                  /*пока чисто записал чтобы не забыть; вообще должно быть чето типо массивов, котторые вопрос 
                                                                  и ответ записывают в себе; короче подумаем как лучше*/
        do
        {
            system("cls");              
            ShowMenu(play);                    // эта штука выводит надпись поле чудес и кнопки играть или выйти, и пользователь выбирает (юзер)
            ErrCode = PlayorExit(play);        // эта штука проверяет что пользователь ввел (логика)
            CheckError(ErrCode);                // если была ошибка (ErrCode != 0), проверяет что за ошибка
        }
        while (ErrCode != 0);
        

        /* над ошибками тут вообще пока не думал*/
        switch(play)
        {
            case 1: // это если играть нажал
                do
                {
                    system("cls");
                    NumPlayers(numberPlayer);              // эта штука спрашивает сколько людей играет, и пользователь вводит
                    ErrCode = chooseNum(numberPlayer);     // эта штука проверяет что пользователь ввел
                    CheckError(ErrCode);                    // если была ошибка (ErrCode != 0), проверяет что за ошибка
                }
                while (ErrCode != 0);

                QuestionAnswer(question, rightAnswer);         // выбирает вопрос и ответ (указатели наверн нужны, а не ссылки для массива)
                while (true)
                {    
                    do
                    {
                        ShowWord(rightAnswer, *length);      //  показывает слово в виде _ _ _ _ _ _ или  _ А _ _ _ А (это для примера)                                 
                        ShowQuestion(question, userAnswer, turn);     // показывает пользователю (пишет номер пользователя) вопрос (скорее всего она же и просит ввести букву или слово)          
                        ErrCode = Alphabet(userAnswer/*для вычисления кое какой ошибки походу еще нужно длину массива с ответом*/);               // будет массив букв из которого вычеркиваются буквы которые использовались плюс проверка на некоректный ввод (и еще если слово вводится то просто выход из функции, даже если слово из говна состоит думаю)
                        CheckError(ErrCode);
                    }                                                  
                    while (ErrCode != 0);
                    if (FullWord(userAnswer))         // проверяет правильное слово ввел игрок
                    {
                        break;
                    }                                                
                    else
                    {
                        PlayerTurn(numberPlayer,turn,false);
                        ShowWrongWord();                      // сообщение о введении неправильного слова
                        continue;
                    }                     
                    step = CheckUserAnswer(userAnswer, rightAnswer, *length, end);                // проверяет букву на правильность
                    SayResult(step);                      // выводит: ОТКРОЙТЕ! или Нет такой буквы(                          
                    PlayerTurn(numberPlayer,turn,step);    // устанавливает очередь человека //CheckUserAnswer выдает true если угадал и false если нет
                    if (end)
                    {
                        break;
                    }
                }
                
            case 2: // это если выйти из игры
        }
    }
}

