#include "quiz.h"
#include  "quiz_ui.h"
#include <iostream>

using namespace std;

void Quiz::Mode1(sqlite3 *db){
    reset();
    printHeader("SURVIAL MODE");

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

        set<int> askedIDs;
while(1){
    loadquestions1(db, askedIDs);
    if (questions.empty()) {
        cout << "No questions found" << endl;
        return;
    }
        askedIDs.insert(questions[0].id);

    cout << "\nQ: " << questions[0].questionText << endl;
    for (int j = 0; j < 4; j++)
        cout << char('A' + j) << ". " << questions[0].options[j] << endl;

    char userAns;
    while(1){
    cout << "Your answer(A-D): ";
    cin >> userAns;

    if(!isValidOption(userAns)){
        cout<<"Invalid options! Only A,B,C,D allowed.\n";
        continue;

    }
    userAns = toupper(userAns);
    break;
}

    if (userAns == toupper(questions[0].correctOption)) {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Wrong! Correct answer: " << questions[0].correctOption << endl;
        cout << "\nGAME OVER!\n";
        displayscore();
        savescore(db, name, "SURVIVAL","","", 0);
        return;
}
     printScoreBox(score);
     displayscore();
     savescore(db, name, "SURVIVAL","","",0); 
}
}
