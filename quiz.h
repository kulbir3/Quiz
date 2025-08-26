#ifndef QUIZ_H
#define QUIZ_H

# include <iostream>
# include <vector>
# include <chrono>
# include <thread>
#include <sqlite3.h>
using namespace std;

class Question {
public:
    string questionText;
    vector<string> options;
    char correctOption;

    Question() {}
    Question(string q, vector<string> opts, char ans) {
        questionText = q;
        options = opts;
        correctOption = ans;
    }
};
class Quiz {
private:
    vector<Question> questions;
    int score;
    Mode gameMode;
    int numQuestions;

public:
    Quiz();

    void setMode(Mode m);
    void classic();
    void loadQuestions(sqlite3 *db, int limit);
    void startQuiz();
    void displayResult(chrono::duration<double> totalTime);
};
#endif
