#ifndef USER_H
#define USER_H

#include <string>
#include <list>
#include "List.h"
#include "AbstractSubject.h"
#include <iostream>

class User : public Observer {
public:
    User(const std::string& name) : name(name) {};
    ~User() override;

    //Lascio virtual perchè una classe tester deve poter fare l'override
    virtual void update(const std::string& sub_name) override;

    void attach(AbstractSubject* sub) override;
    void detach(AbstractSubject* sub) override;
    void add_list(List* list);

    bool remove_list(List* list);

    std::string get_name() const;
    void set_name(const std::string& name);

    std::list<List*> get_lists() const;


private:
    std::string name;
    std::list<List*> lists;
};


#endif
