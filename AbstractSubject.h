#ifndef ABSTRACTSUBJECT_H
#define ABSTRACTSUBJECT_H

#include "Observer.h"
#include <list>

class AbstractSubject {
public:
    virtual ~AbstractSubject() {};
    virtual void notify() = 0;
    virtual void subscribe(Observer* observer) = 0;
    virtual void unsubscribe(Observer* observer) = 0;
protected:
    std::list<Observer*> users;
};

#endif