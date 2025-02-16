#include <iostream>
#include <random>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <string>

using namespace std;

// Функция выбирает случайный вопрос и ответ
void getRandomQuestion(string &question, string &answer) {
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
    answer = answers[index];
}



//Функция проверяющая правильность ввода буквы
int correctWord(char &word) {
    int num = word; //Первеод буквы в код ASCII

    //Проверка на букву английского алфавита
    if ((65 <= num && num <= 90) || (97 <= num && num <= 122)) {
        return 1;
    }
    else {
        return 0;
    }
}

//Функция угадывания слова
void playGame(char &word, string &question, string &answer) {
    cout << question << endl;
    char wd[answer.length() + 1];                                    //Массив для угадывания слова
    for (int i = 0; i < answer.length(); i++) {
        wd[i] = '_';
    }
    vector<char> charArray(answer.begin(), answer.end());            //Разбииение слова по частям
    while (true) {
        cout << "Enter a letter: ";
        cin >> word;
        if (correctWord(word) == 1) {
            for (int i = 0; i < answer.length(); i++) {              //Подстановка буквы вместо символа "_"
                if (word == charArray[i]) {
                    wd[i] = word;
                }
            }
            for (int i = 0; i < answer.length(); i++) {              //Вывод слова
                cout << wd[i] << ' ';
            }
            cout << endl;
        }
        else {
            cout << "Error: you entered the wrong letter, try again!" << endl;
            continue;
        }
    }
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

int main() {
    srand(time(0));
    
    int num = 1, point;

    //Генерация вопроса и ответа
    string question, answer;
    getRandomQuestion(question, answer);

    char word;
    playGame(word, question, answer);

    //Часть кода для UI и Controller
    char ent;
    cout << "Player namber " << num << " it's your turn to spin, press 'O' to start spinning the wheel: ";
    while(true) {
        cin >> ent;
        if (ent == 'O') {
            cout << Wheel(point);
            break;
        }
        else {
            cout << "Please, press 'O' to start spinning the wheel:";
        }
    }

}