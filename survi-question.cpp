#include "quiz.h"
using namespace std;

 void Quiz::loadquestions1(sqlite3 *db,const set<int> &askedIDs){
   questions.clear();
   string sql = "SELECT question_id,question_text, A, B, C, D, correct_option "
             "FROM Questions";

 if (!askedIDs.empty()) {
        sql += " WHERE question_id NOT IN (";
        bool first = true;
        for (int id : askedIDs) {
            if (!first) sql += ",";
            sql += to_string(id);
            first = false;
        }
        sql += ")";
    }

sql += " ORDER BY RANDOM() LIMIT 1";
     sqlite3_stmt *stmt;

     if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        cerr << "Failed to fetch questions: " << sqlite3_errmsg(db) << endl;
        return;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
         int qid = sqlite3_column_int(stmt, 0);
        string q = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        vector<string> opts = {
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)),
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)),
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)),
            reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5))
        };
        char ans = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6))[0];

       questions.push_back(Question(qid,q, opts, ans));
    }

    sqlite3_finalize(stmt);
}