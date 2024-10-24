#include <iostream>
#include <vector>
#include <sstream>
#include <bits/chrono.h>

#include "ErrorClasses/InvalidDay.cpp"
#include "ErrorClasses/InvalidMonth.cpp"
#include "ErrorClasses/InvalidYear.cpp"
using namespace std;

void printDate(vector<int> date) {
vector<string> months = {"January", "February",
    "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December"};

    string suffix;
    if (date[1]==1) {
        suffix = "st";
    }else if (date[1]==2) {
        suffix = "nd";
    }else if (date[1]==3) {
        suffix = "rd";
    }else {
        suffix = "th";
    }

    string fullDate = months[date[0] - 1]+", "+to_string(date[1])+suffix+", "+to_string(date[2]);
    cout << fullDate << "\n";
}

//Asked chatgpt how to split a string in cpp and it provided the following function that does it
vector<string> split(const string &str, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);

    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

vector<int> validateDate(string date) {
    int year, month, day;
    vector maxDays = {31,28,31,30,31,30,31,31,30,31,30,31};

    vector<string> tokens = split(date, '-');

    if (tokens.size() != 3) {
        throw invalid_argument("Invalid date format");
    }


     try {
         year = stoi(tokens[2]);
        bool isLeap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
        if (isLeap) {
            maxDays[1] =29;
        }
    }catch (const exception &e) {
        throw invalidMonth();
    }

    try {
        month = stoi(tokens[1]);
        if (month < 1 || month > 12) {
            throw invalidMonth();
        }
    }catch (const exception &e) {
        throw invalidMonth();
    }

    try {
        day = stoi(tokens[0]);
        if (day < 1 || day > maxDays[month - 1]) {
            throw invalidDay();
        }
    }catch (const exception &e) {
        throw invalidDay();
    }


    return vector{month, day, year};

}

int main(){
    string date;
    std::cout << "Enter a date in format dd-mm-yyyy " << std::endl;

    std::cin >> date;

    vector<int> datePartitions;
    try {
        datePartitions = validateDate(date);
    }catch (const exception& e) {
        cout << e.what() << endl;
        return 1;
    }

    try {
        printDate(datePartitions);
    }catch (const exception& e) {
        cout << e.what() << endl;
        return 1;
    }



    return 0;
}
