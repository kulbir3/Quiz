#include "quiz.h"
using namespace std;

 void Quiz::loadquestions(sqlite3 *db,int limit, const string &difficulty, const string &category){
   questions.clear();
   string sql = "SELECT question_text, A, B, C, D, correct_option, difficulty, category "
                  "FROM Questions WHERE difficulty = ? AND category = ? "
                  "ORDER BY RANDOM() LIMIT ?";

    
     sqlite3_stmt *stmt;

     if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        cerr << "Failed to fetch questions: " << sqlite3_errmsg(db) << endl;
        return;
    }
    sqlite3_bind_text(stmt, 1, difficulty.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, category.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, limit);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        string q = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        vector<string> opts = {
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)),
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)),
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4))
        };
        char ans = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5))[0];
        string diff = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
        string cat = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));

       questions.push_back(Question(q, opts, ans, diff, cat));
    }

    sqlite3_finalize(stmt);
}