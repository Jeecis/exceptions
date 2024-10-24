#include <iostream>
#include <vector>
#include <sstream>
#include <bits/chrono.h>

#include "ErrorClasses/InvalidDay.cpp"
#include "ErrorClasses/InvalidMonth.cpp"
#include "ErrorClasses/InvalidYear.cpp"
using namespace std;

void printDate(vector<int> date) {
    // using vector to easily access a month name
    vector<string> months = {"January", "February",
    "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December"};

    // calculating what kind of suffix is needed
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

    //formatting and printing date
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

    //we initialize the maximum day array for each month so its easier work with them
    vector maxDays = {31,28,31,30,31,30,31,31,30,31,30,31};

    vector<string> tokens = split(date, '-');

    //Didnt really know what to throw if the whole date is incoreectly formatted
    if (tokens.size() != 3) {
        throw invalid_argument("Invalid date format");
    }

    // Since stoi can throw an error we put the whole expression in try - catch
     try {
         year = stoi(tokens[2]);

         // copilot wrote this line
        bool isLeap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

         // in case it is a leap year we re-initialize the february max date
        if (isLeap) {
            maxDays[1] =29;
        }
    }catch (const exception &e) {
        throw invalidMonth();
    }

    // I kept the invalid month check inside the try-catch block because it makes it a bit easier to read
    // comparing to when it is put outside the try catch block
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

    //Decided to return a 3 entry long vector so its easier to work with in printDate function
    return vector{month, day, year};

}

int main(){
    string date;
    std::cout << "Enter a date in format dd-mm-yyyy " << std::endl;

    std::cin >> date;

    // Date partitions consists of 3 ints month, day, year
    vector<int> datePartitions;

    try {
        datePartitions = validateDate(date);
    }catch (const exception& e) {
        cout << e.what() << endl;
        return 1;
    }

    // technically can throw an error, but in our program it shouldn't due to previous validation
    try {
        printDate(datePartitions);
    }catch (const exception& e) {
        cout << e.what() << endl;
        return 1;
    }



    return 0;
}
