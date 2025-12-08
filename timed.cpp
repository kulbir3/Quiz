#include "quiz.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>

using namespace std;

void Quiz::Mode2(sqlite3 *db){
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

    atomic<bool> timeup(false);
    int timelimit = 30;

    thread timer([&] (){
        this_thread::sleep_for(chrono::seconds(timelimit));
        timeup = true;
    });

    set<int> askedIDs;
    while(!timeup){
        loadquestions1(db,askedIDs);
    if (questions.empty()) {
        cout << "All questions asked!\n" << endl;
        break;
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
if(timeup)
break;

 if (userAns == toupper(questions[0].correctOption)) {
        cout << "Correct!\n";
        score++;
    }else{
        cout<<"Wrong answer!\n";
    }
}
    timer.join();
    cout<<"Times over or all question finished!\n"; 
    displayscore();
    savescore(db, name, "TIMED","","", 30); 
}