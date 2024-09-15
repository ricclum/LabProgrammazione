#ifndef SUBJECT_H
#define SUBJECT_H
#include <list>
#include <memory>
#include "Observer.h"


class Subject {
public:
    virtual ~Subject() {};
    virtual void notify() = 0;

    virtual void subscribe(const std::shared_ptr<Observer>& observer) = 0;
    virtual void unsubscribe(const std::shared_ptr<Observer>& observer) = 0;

protected:
    std::list<std::shared_ptr<Observer>> users;
};

#endif