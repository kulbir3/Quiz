#include <iostream>
#include <sqlite3.h>
# include "quiz.h"
using namespace std;

void Quiz::savescore(sqlite3 *db, const string &playername, const string &difficulty, const string &category ){
   sqlite3_stmt *stmt;
   string sql = "INSERT INTO Score (player_name, score, difficulty, category)"
   "VALUES (?, ?, ?, ?)"
   "ON CONFLICT(player_name) DO UPDATE SET "
    "score = excluded.score, "
    "difficulty = excluded.difficulty, "
    "category = excluded.category, "
    "date_played = CURRENT_TIMESTAMP;";

   if(sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) != SQLITE_OK){
   cerr <<"Failed to prepare statement"<<sqlite3_errmsg(db)<<endl;
}
   sqlite3_bind_text(stmt, 1, playername.c_str(), -1, SQLITE_STATIC);
   sqlite3_bind_int(stmt, 2, score);
   sqlite3_bind_text(stmt, 3, difficulty.c_str(), -1, SQLITE_TRANSIENT);
   sqlite3_bind_text(stmt, 4, category.c_str(), -1, SQLITE_TRANSIENT);

if(sqlite3_step(stmt) != SQLITE_DONE){
      cerr <<"Failed to step statement"<<sqlite3_errmsg(db)<<endl;
}else{
cerr <<"Successfully stored score"<<endl;
}
sqlite3_finalize(stmt);
}