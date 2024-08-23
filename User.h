#ifndef USER_H
#define USER_H

#include "Observer.h"
#include <string>
#include <list>
#include "List.h"
#include "AbstractSubject.h"

class User : public Observer {
public:
    User(const std::string& name) : name(name) {}
    ~User() {
        for (List* list : lists) {
            detach(list);
        }
    }

    void update() override {
        // Do something
    }

    void attach(AbstractSubject* list) override{
        list->subscribe(this);
    }

    void detach(AbstractSubject* list) override {
        list->unsubscribe(this);
    }

    void add_list(List* list) {
        lists.push_back(list);
        attach(list);
    }



private:
    std::string name;
    std::list<List*> lists;
};


#endif
