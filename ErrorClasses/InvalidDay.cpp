//
// Created by jekab on 10/22/2024.
//

#ifndef INVALIDDAY_H
#define INVALIDDAY_H
#include <string>

using namespace std;

class invalidDay: public exception {
public:
    invalidDay() { msg = "Invalid day format, please enter the day properly "; }

    //asked chatGPT how to override what method
    const char* what() const noexcept override {
        return msg.c_str();
    }

private:
    string msg;

};



#endif //INVALIDDAY_H
