#ifndef QUIZ_H
#define QUIZ_H
#include <iostream>
#include <sqlite3.h>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;

typedef enum GameMode{
CLASSIC=1,
SURVIVAL,
TIMED
}GameMode;

class Question{
public:
string questionText;
vector<string> options;
char correctOption;
string difficulty;
string category;

Question(){};
 Question(string q, vector<string> opts, char ans, string diff, string cat)
        : questionText(q), options(opts), correctOption(ans), difficulty(diff), category(cat) {}
};

class Quiz{
public:
vector<Question> questions;
int score;
GameMode gamemode;
Quiz();
  void reset();
  void displayscore();
  void setmode(GameMode gm);
  void loadquestions(sqlite3 *db, int limit, const string &difficulty="", const string &category="");
  void savescore(sqlite3 *db, const string &playername, const string &difficulty, const string &category);
  void mode(sqlite3 *db, const string &difficulty,const string &category);
};
#endif


