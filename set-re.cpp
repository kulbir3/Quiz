# include "quiz.h"
# include<iostream>
using namespace std;

 void Quiz::reset(){
      score = 0;
      questions.clear();
}
Quiz::Quiz(){
     score = 0;
     gamemode = CLASSIC;
};

void Quiz::displayscore(){
     cout << "\nYour Score: " << score << "/" << questions.size() << endl;
};

void Quiz::setmode(GameMode gm){
gamemode = gm;
}