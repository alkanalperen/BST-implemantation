//
// Created by Alperen Alkan on 19.03.2021.
//

#ifndef HW2_TREEEXCEPTION_H
#define HW2_TREEEXCEPTION_H
#include <iostream>
using namespace std;
class TreeException : public std::exception{

private:
    std::string msg;

public:
    virtual const char* what() const throw()
    {
        return msg.c_str();
    }
    TreeException(const string & message =""):
            exception(), msg(message) {};
    ~TreeException() throw() {};

}; // end TreeException

#endif //HW2_TREEEXCEPTION_H
