#include <iostream>
#include <random>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <string>
#include <algorithm>
#include "logic.h"

using namespace std;

int PlayorExit(string play) {
    if ((play[0] == '1' || play[0] == '2') && play[1] == '\0') {
        return 0;
    }
    return 1;
}

int chooseNum(int numberPlayer) {
    if (numberPlayer == 1 || numberPlayer == 2) {
        return 0;
    }
    return 1;
}

// Функция выбирает случайный вопрос и ответ
void QuestionAnswer(string &question, string &rightAnswer) {
    vector<string> questions = {
        "Which planet is the largest in the solar system?",
        "What is the name of the capital of France?",
        "Which animal is the symbol of Australia?",
        "What is the name of the longest river in the world?",
        "Who wrote 'Crime and Punishment'?"
    };

    vector<string> answers = {
        "Jupiter",
        "Paris",
        "Kangaroo",
        "Amazon",
        "Dostoevsky"
    };

    //Определение вопроса и ответа для пользователя
    int index = rand() % questions.size();
    question = questions[index];
    rightAnswer = answers[index];
}

//Функция проверяющая правильность ввода буквы
int correctWord(string &rightAnswer, string &userAnswer, bool &checkLenWord) {
    int num = userAnswer[0]; //Первеод буквы в код ASCII

    if (rightAnswer.length() == userAnswer.length())
    {
        checkLenWord = true;
        return 0;
    }

    if (userAnswer.length() > 1) return 1;

    //Проверка на букву английского алфавита
    if ((65 <= num && num <= 90) || (97 <= num && num <= 122)) {
        return 0;
    }
    else {
        return 1;
    }

    //ДОБАВИТЬ ЕЩЕ ОДНО УСЛОВИЕ С ВВОДОМ ТОЙ ЖЕ БУКВЫ 

}

void Letter(string &rightAnswer, vector<char>& letter) {
    for (int i = 0; i < rightAnswer.length(); i++) {
        letter.push_back('_');
    }
}

bool CheckUserAnswer(string &userAnswer, string &rightAnswer, vector<char>& letter, int &quantity) {
    bool result = false;
    vector<char> charArray(rightAnswer.begin(), rightAnswer.end());            //Разбииение слова по частям
    for (int i = 0; i < rightAnswer.length(); i++) {                           //Подстановка буквы вместо символа "_"
        if (userAnswer[0] == charArray[i]) {
            letter[i] = userAnswer[0];
            result = true;
            quantity++;
        }
    }
    return result;
}

void PlayerTurn(int &numberPlayer,int &turn, bool step) {
    if (!step) turn++;

    if (turn > numberPlayer) turn = 1;
}

bool FullWord(string &userAnswer, string &rightAnswer) {
    std::sort(userAnswer.begin(), userAnswer.end());
    std::sort(rightAnswer.begin(), rightAnswer.end());

    return userAnswer == rightAnswer;
}

//Генерирование случайных очков для пользователя
int Wheel(int point) {
    int pt[] = {0, 5, 10, 25, 50, 100, 150, 200, 250, 300, 500, 650, 700, 750, 1000};      //Массив очков
    int size = sizeof(pt) / sizeof(pt[0]);                                                 //Определение размера массива
    random_device rd;                                                                      //Генерирование случайного числа
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, size - 1);                                       //Определяем диапазон случайных чисел
    point = pt[dist(gen)];                                                                 //Выбор случайного элемента из массива
    return point;
}