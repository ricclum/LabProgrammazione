#ifndef USER_H
#define USER_H

#include "Observer.h"
#include "List.h"
#include <iostream>
#include <string>


class User : public Observer {
public:
    void update() override {
        // Do something
    }

private:
    std::string name;
    std:list<List*> lists;
};


#endif
