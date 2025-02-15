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
        bool game = true;
        int play = 0, numberPlayer = 0, turn = 0;
        int size;                               //длина слова (может и не надо, пока хз)
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
                while (game)
                {
                    PlayerTurn(numberPlayer, turn);                     // устанавливает очередь человека    
                    ShowQuestion(question, userAnswer, turn);           // показывает пользователю вопрос (скорее всего она же и просит ввести букву или слово)          
                    
                }
                
            case 2: // это если выйти из игры

        }
    }
}

