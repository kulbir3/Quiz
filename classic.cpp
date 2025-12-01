#include "quiz.h"
#include <iostream>
#include <string>
#include <sqlite3.h>
using namespace std;

void Quiz::mode(sqlite3 *db, const string &difficulty, const string &category) {
    reset();
    string name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    while(1){

    cout<<"Enter your name: "; 
     getline(cin, name);

    if(!isValidName(name)){
        cout<<"Invalid Name! Only alphabet allowed\n";
        continue;
    }           
       for (char &c : name)
        c = toupper(c);

    break; 
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

           while(1){
           cout << "Your answer(A-D): ";
           cin >> userans;

          if(!isValidOption(userans)){
          cout<<"Invalid options! Only A,B,C,D allowed.\n";
          continue;

    }
          userans = toupper(userans);
          break;
}

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
 