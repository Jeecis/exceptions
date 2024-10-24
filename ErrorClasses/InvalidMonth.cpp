//
// Created by jekab on 10/22/2024.
//

#ifndef INVALIDMONTH_H
#define INVALIDMONTH_H
#include <string>

using namespace std;

class invalidMonth: public exception {
public:
    invalidMonth() { msg = "Invalid year format, please enter the year properly "; }

    //asked chatGPT how to override what method
    const char* what() const noexcept override {
        return msg.c_str();
    }

private:
    string msg;

};




#endif //INVALIDMONTH_H
