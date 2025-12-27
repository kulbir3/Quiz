#ifndef QUIZ_UI_H
#define QUIZ_UI_H

#include "quiz.h"
#include <iostream>
#include <iomanip>
using namespace std;

inline void printHeader(const string &title) {
    cout << "\n====================================================\n";
    cout << "                 " << title << endl;
    cout << "====================================================\n\n";
}

inline void printQuestion(const Question &q, int qNo = 0) {
    cout << "\n----------------------------------------------------\n";
    if (qNo > 0) cout << "Question " << qNo << ":\n";
    cout << q.questionText << "\n";
    for (int i = 0; i < 4; ++i) {
        cout << "  " << char('A' + i) << ". " << q.options[i] << "\n";
    }
    cout << "----------------------------------------------------\n";
}

inline void printScoreBox(int score = 0) {
    cout << "\n+-----------------+\n";
    cout << "| Current Score: " << setw(3) << score << " |\n";
    cout << "+-----------------+\n\n";
}

inline void printLeaderboardHeader(const string &mode) {
    cout << "\n==================== " << mode << " SCORES ====================\n";
    cout << left
         << setw(20) << "NAME" 
         << setw(10) << "SCORE" 
         << setw(10) << "TIME" 
         << setw(20) << "DATE" << endl;
    cout << "------------------------------------------------------------\n";
}

inline void printLeaderboardFooter() {
    cout << "============================================================\n\n";
}

#endif
