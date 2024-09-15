#ifndef USER_H
#define USER_H

#include <string>
#include <list>
#include "List.h"
#include "Subject.h"
#include <iostream>

//Derivare da enable_shared_from_this permette di ottenere un shared_ptr da un puntatore this
//questo ci serve ad esempio nell'attach e detach per passare un shared_ptr di this
class User : public Observer, public std::enable_shared_from_this<User>{
public:
    User(){}
    User(const std::string& name) : name(name) {};
    ~User() override;

    //Lascio virtual perchè una classe tester deve poter fare l'override
    virtual void update(const std::string& sub_name) override;

    void attach(const std::shared_ptr<Subject>& sub) override;
    void detach(const std::shared_ptr<Subject>& sub) override;
    void add_list(const std::shared_ptr<List>& list);

    bool remove_list(const std::shared_ptr<List>& list);

    std::string get_name() const;
    void set_name(const std::string& name);

    const std::list<std::shared_ptr<List>>& get_lists() const;


private:
    std::string name;
    std::list<std::shared_ptr<List>> lists;
};


#endif
