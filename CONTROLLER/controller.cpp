#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "../LOGIC/logic.h"
#include "../UI/user.h"
#include "../ERROR/error.h"



int main()
{   
    srand(0);
    while(true)
    {
        /*переменные будут*/
        int ErrCode = 0;
        bool step = false, end = false, checkLenWord = false;
        int quantity = 0, turn = 1;                              
        std::string question, rightAnswer, userAnswer, play, numberPlayer;
        std::vector<char> letter;

        do
        {
            //system("cls");              
            ShowMenu(play);                    // эта штука выводит надпись поле чудес и кнопки играть или выйти, и пользователь выбирает (юзер)
            ErrCode = PlayorExit(play);        // эта штука проверяет что пользователь ввел (логика)
            //CheckError(ErrCode);                // если была ошибка (ErrCode != 0), проверяет что за ошибка
        }
        while (ErrCode != 0);
        

        switch(play[0])
        {
            case '1': // это если играть нажал
                do
                {
                    //system("cls");
                    NumPlayers(numberPlayer);              // эта штука спрашивает сколько людей играет, и пользователь вводит
                    ErrCode = chooseNum(numberPlayer);     // эта штука проверяет что пользователь ввел
                    //CheckError(ErrCode);                    // если была ошибка (ErrCode != 0), проверяет что за ошибка
                }
                while (ErrCode != 0);

                QuestionAnswer(question, rightAnswer);         // выбирает вопрос и ответ (указатели наверн нужны, а не ссылки для массива)
                Letter(rightAnswer,letter);
                while (true)
                {    
                    do
                    {
                        ShowWord(letter);      //  показывает слово в виде _ _ _ _ _ _ или  _ А _ _ _ А (это для примера)                                 
                        ShowQuestion(question, userAnswer, turn);     // показывает пользователю (пишет номер пользователя) вопрос (скорее всего она же и просит ввести букву или слово)          
                        ErrCode = correctWord(rightAnswer, userAnswer, checkLenWord);               // будет массив букв из которого вычеркиваются буквы которые использовались плюс проверка на некоректный ввод (и еще если слово вводится то просто выход из функции, даже если слово из говна состоит думаю)
                        //CheckError(ErrCode);
                    }                                                  
                    while (ErrCode != 0);
                    if (checkLenWord)         // проверяет правильное слово ввел игрок
                    {
                        if (FullWord(userAnswer,rightAnswer)) break;
                        else
                        {
                            PlayerTurn(numberPlayer,turn,false);    // устанавливает очередь человека
                            ShowWrongWord();                        // сообщение о введении неправильного слова
                            continue;
                        }
                    }                                                      
                    step = CheckUserAnswer(userAnswer, rightAnswer, letter, quantity);                // проверяет букву на правильность
                    SayResult(step);                      // выводит: ОТКРОЙТЕ! или Нет такой буквы(                          
                    PlayerTurn(numberPlayer,turn,step);    // устанавливает очередь человека //CheckUserAnswer выдает true если угадал и false если нет
                    if (end) // наверн нужно отдельную функцию хотя и хз
                    {
                        break;
                    }
                }
                break;
                
            case '2': // это если выйти из игры
                return 0;
        }
    }
}
