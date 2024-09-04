#ifndef OBSERVER_H
#define OBSERVER_H


#include <string>

//Evita la inclusione circolare negli header
class AbstractSubject;

class Observer {
public:
    virtual ~Observer(){}
    virtual void update(const std::string& sub_name) = 0;
    virtual void attach(AbstractSubject* sub) = 0;
    virtual void detach(AbstractSubject* sub) = 0;
};

#endif