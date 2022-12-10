//
// Created by lucas on 09/12/22.
//

#include "StringHelper.h"

using namespace std;

std::vector<string> StringHelper::Split(string text, string delimiter) {
    size_t start = 0, end = 0, delimeterLength = delimiter.length();
    string token;
    vector<string> stringSplitted;

    while ((end = text.find(delimiter, start)) != string::npos) {
        token = text.substr(start, end - start);
        stringSplitted.push_back(token);

        start = end + delimeterLength;
    }

    string lastString = text.substr(start);
    ::printf("last %d = %s\n", start, lastString.c_str());

    if (!lastString.empty()) {
        stringSplitted.push_back(text.substr(start));
    }

    return stringSplitted;
}

std::string StringHelper::LTrim(std::string text) {
    string trimmed;
    for (int i = 0; i < text.size(); i++) {
        if (!isspace(text[i])) {
            trimmed = text.substr(i, text.size());
            break;
        }
    }

    return trimmed;
}

std::string StringHelper::RTrim(std::string text) {
    string trimmed;
    for (long i = text.size() - 1; i >= 0; i--) {
        if (!isspace(text[i])) {
            trimmed = text.substr(0, i + 1);
            break;
        }
    }

    return trimmed;
}

string StringHelper::Trim(string text) {
    string trimmed = LTrim(text);
    trimmed = RTrim(trimmed);
    return trimmed;
}

