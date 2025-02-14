#include <iostream>

int main()
{
    while(true)
    {
        /*переменные будут*/
        int ErrCode = 0;
        int play = 0, numberPlayer = 0;
        do
        {
            system("cls");              
            ShowMenu(&play);                 //Сэта штука выводит надпись поле чудес и кнопки играть или выйти, и пользователь выбирает (юзер)
            ErrCode = PlayorExit(&play);     // эта штука проверяет что пользователь ввелс (логика)
            CheckError(ErrCode);               // если была ошибка (ErrCode != 0), проверяет что за ошибка
        }
        while (ErrCode != 0);

        do
        {
            system("cls");
            NumPlayers(&numberPlayer);               // эта штука спрашивает сколько людей играет, и пользователь вводит
            ErrCode = chooseNum(&numberPlayer);      // эта штука проверяет что пользователь ввел
            CheckError(ErrCode);                     // если была ошибка (ErrCode != 0), проверяет что за ошибка
        }
        while (ErrCode != 0);

    }
}

