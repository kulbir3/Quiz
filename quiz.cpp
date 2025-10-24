#include "quiz.h"
#include <iostream>
using namespace std;

using namespace std;
int main() {
sqlite3 *db;
    if (sqlite3_open("quiz.db", &db)) {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return 1;
    }
      Quiz qz;
      int modeChoice;
      char playAgain;
      while(1){
        cout << "Select Game Mode:\n1. Classic\n2. Timed";
        cout << "\n3. Survival\nEnter choice (1-3): ";
        cin >> modeChoice;
        switch (modeChoice) {
          case CLASSIC:{
            string difficulty, category;
             cout << "Enter Difficulty (Easy/Medium/Hard): ";
             cin >> difficulty;
             cout << "Enter Category (Math/Science/General): ";
             cin >> category;
             qz.mode(db, difficulty, category);
          break;
          }

          case TIMED: cout<<"Comming soon!"<<endl;
          break;

          case SURVIVAL: cout<<"Comming soon!"<<endl;
          break;

          default: cout<<"Wrong Choice!"<<endl;
}
        cout << "Do you want to play again?(y/n):";
        cin >> playAgain;
        if (playAgain == 'y' || playAgain == 'Y')break;
}
  sqlite3_close(db);
   cout<<"Thanks for playing!"<<endl;
      
 return 0;
}