#include "quiz.h"
#include <iostream>
#include "quiz_ui.h"
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
        printHeader("QUIZ GAME MAIN MENU");
        cout << "Select Game Mode:\n1. Classic\n2. Timed";
        cout << "\n3. Survival\n4. SHOW SCORE\n5. Exit \nEnter choice (1-5): ";
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

          case TIMED:{
             qz.Mode2(db);
          break;
          }

          case SURVIVAL:{
             qz.Mode1(db);
          break;
          }
            
          case SHOW_SCORE:{
            string mode;
            cout<<"Enter mode(CLASSIC / SURVIVAL/ TIMED): ";
            cin>>mode;
            
            for(char &c: mode)c = toupper(c);
            if(mode != "CLASSIC"&& mode != "SURVIVAL"&& mode != "TIMED"){
               cout<<"Invalid choice!\n";
               break;
            }
            qz.showscore(db, mode);
            break;
          }
          case Exit:{
            return 0;
          }

          default: cout<<"Wrong Choice!"<<endl;
}
        cout << "Do you want to play again?(y/n):";
        cin >> playAgain;
        if (playAgain == 'n' || playAgain == 'N')break;
}

  sqlite3_close(db);
   cout<<"Thanks for playing!"<<endl;
      
 return 0;
}
