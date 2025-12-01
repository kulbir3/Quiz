# include "quiz.h"
# include <regex>

bool Quiz::isValidOption(char ans) {
     ans = toupper(ans);
    return ans == 'A' || ans == 'B' || ans == 'C' || ans == 'D';
}

bool Quiz::isValidName(const string &name) {

    regex nameRegex("^[A-Za-z]{2,20}$");
    return regex_match(name, nameRegex);
}