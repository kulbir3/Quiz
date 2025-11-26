#include "quiz.h"
#include <iostream>
#include <string>
#include <sqlite3.h>
using namespace std;

void Quiz::mode(sqlite3 *db, const string &difficulty, const string &category) {
    reset();
    string name;
    cout<<"Enter your name: ";
    cin>>name;           
    for(int i = 0; i<name.length(); i++){
        name[i]=toupper(name[i]);
        }

   if (name.empty()) {
    cout << "Name cannot be empty!\n";
    return;
}

    loadquestions(db, 5, difficulty, category);

    if (questions.empty()) {
        cout << "No questions found" << endl;
        return;
    }

    char userans;
    for (int i = 0; i < questions.size(); i++) {
        cout << "\nQ" << i + 1 << ": " << questions[i].questionText << endl;

        for (int j = 0; j < 4; j++) {
            cout << char('A' + j) << ". " << questions[i].options[j] << endl;
        }

        cout << "Your answer: ";
        cin >> userans;

        if (toupper(userans) == toupper(questions[i].correctOption)) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Wrong! Correct answer: " << questions[i].correctOption << endl;
        }
    }

    displayscore();
    savescore(db, name, difficulty, category);
}
