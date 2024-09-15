#ifndef OBSERVER_H
#define OBSERVER_H

#include <memory>
#include <string>


//Evita la inclusione circolare negli header
class Subject;


class Observer {
public:
    virtual ~Observer(){}
    virtual void update(const std::string& sub_name) = 0;
    virtual void attach(const std::shared_ptr<Subject>& sub) = 0;
    virtual void detach(const std::shared_ptr<Subject>& sub) = 0;
};

#endif