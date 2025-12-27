#include "quiz.h"
#include "quiz_ui.h"
using namespace std;

void Quiz::showscore(sqlite3 *db, const string& mode){
    string sql= 
                "SELECT player_name, score, time, date_played " 
                "FROM score "
                "WHERE mode =? "
                "ORDER BY score DESC, time ASC;";

                sqlite3_stmt *stmt;

   if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
    cout << "Prepare failed: " << sqlite3_errmsg(db) << endl;
    return;
}

    sqlite3_bind_text(stmt, 1, mode.c_str(), -1, SQLITE_TRANSIENT);

    printLeaderboardHeader(mode);
    
    while(sqlite3_step(stmt)== SQLITE_ROW){
        cout<<sqlite3_column_text(stmt,0)
            <<" | Score: "<<sqlite3_column_int(stmt, 1)
            <<" | Time: "<<sqlite3_column_int(stmt, 2)
            <<" | Date: "<<sqlite3_column_text(stmt, 3)
            <<endl;
    }
    printLeaderboardFooter();
    sqlite3_finalize(stmt);
}