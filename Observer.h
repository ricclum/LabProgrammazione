#ifndef OBSERVER_H
#define OBSERVER_H

#include "AbstractSubject.h"

class Observer {
public:
    virtual ~Observer() {};
    virtual void update(const std::string& sub_name) = 0;
};

#endif