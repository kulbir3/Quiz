#ifndef QUIZ_H
#define QUIZ_H

# include <iostream>
# include <fstream>
# include <vector>
# include <chrono>
# include <thread>
using namespace std;

enum Mod{
Classic=1,
Timed,
Survival
};
class Question{
   public:
   string question;
   vector<string> options;
   char Answer;
   string difficulty;
   Question(){
 };
   Question(string quest, vector<string> opt, char ans, string dif){
 };
};

class Quiz{
public:
vector<Question> questions;
int score;
int timelimit;
string difficultylevel;
Mode gamemode;

Quiz(){
    void reset();
    void setDifficulty(string level);
    void setTimeLimit(int seconds);
    void setMode(Mode m);
    void displayScore();
    void loadQuest(sqlite3 *db);
    void saveScore(sqlite3 *db, const string &playerName);
    void startQuiz();
 };
};
#endif
