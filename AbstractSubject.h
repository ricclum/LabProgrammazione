#ifndef ABSTRACTSUBJECT_H
#define ABSTRACTSUBJECT_H

#include "Observer.h"
#include <list>

class AbstractSubject {
public:
    virtual ~AbstractSubject() {}; 
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify() = 0;
private:
    std::list<Observer*> observers;
};

#endif 