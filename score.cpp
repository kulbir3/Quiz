# include "quiz.h"
#include <iostream>
#include <sqlite3.h>
void Quiz::savescore(sqlite3* db, const string& name, const string& modename, const string& difficulty, const string& category, int time) {

    string sql = 
           "INSERT INTO Score1 (player_name, mode, difficulty, category, score, time)"
           "VALUES (?, ?, ?, ?, ?, ?)"
           "ON CONFLICT(player_name, mode, difficulty, category) DO UPDATE SET "
           "mode = excluded.mode, "
           "score = excluded.score, "
           "time = excluded.time, "
           "date_played = CURRENT_TIMESTAMP;";

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        cout << "Score save failed: " << sqlite3_errmsg(db) << endl;
        return;
    }

    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, modename.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, difficulty.empty() ? nullptr : difficulty.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, category.empty() ? nullptr : category.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 5, score);
    sqlite3_bind_int(stmt, 6, time);
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        cout << "Failed to store score\n";
    } else {
        cout << "Score saved successfully\n";
    }

    sqlite3_finalize(stmt);
}
