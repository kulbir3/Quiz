#ifndef QUIZ_H
#define QUIZ_H
#include <set>
#include <iostream>
#include <regex>
#include <sqlite3.h>
#include <vector>
#include <string>
#include <limits>
#include <sqlite3.h>

using namespace std;

typedef enum GameMode{
CLASSIC=1,
TIMED,
SURVIVAL,
}GameMode;

class Question{
public:
int id;
string questionText;
vector<string> options;
char correctOption;
string difficulty;
string category;

Question(){};
 Question(int qid,string q, vector<string> opts, char ans)
        : id(qid),questionText(q), options(opts), correctOption(ans){}

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
  void loadquestions1(sqlite3 *db,const std::set<int> &askedIDs = std::set<int>()); 
  void savescore(sqlite3* db, const string& name, const string& modename, const string& difficulty, const string& category, int time);
  void mode(sqlite3 *db, const string &difficulty,const string &category);
  void Mode1(sqlite3 *db);
  void Mode2(sqlite3 *db);
  bool isValidOption(char ans);
  bool isValidName(const string &name);  
};
#endif


