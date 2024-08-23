#ifndef OBSERVER_H
#define OBSERVER_H

#include "AbstractSubject.h"

class Observer {
public:
    virtual ~Observer() {};
    virtual void update() = 0;
    virtual void attach(AbstractSubject* sub) = 0;
    virtual void detach(AbstractSubject* sub) = 0;
};

#endif