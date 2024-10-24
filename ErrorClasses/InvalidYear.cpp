//
// Created by jekab on 10/22/2024.
//

#ifndef INVALIDYEAR_H
#define INVALIDYEAR_H
#include <string>

using namespace std;

class invalidYear :public exception{
public:
    invalidYear() { msg = "Invalid year format, please enter the year properly "; }

    //asked chatGPT how to override what method
    const char* what() const noexcept override {
        return msg.c_str();
    }

private:
    string msg;

};



#endif //INVALIDYEAR_H
