#include "User.h"

User::~User() {
    for (List* list : lists) {
        detach(list);
    }
}

void User::update(const std::string& sub_name){
    std::cout << "User " << this->name<< " received an update from the list: " << sub_name << std::endl;
}

void User::attach(AbstractSubject* list) {
    list->subscribe(this);
}

void User::detach(AbstractSubject* list) {
    list->unsubscribe(this);
}

void User::add_list(List* list) {
    lists.push_back(list);
    attach(list);
}

std::string User::get_name() const {
    return name;
}

void User::set_name(const std::string& name) {
    this->name = name;
}

std::list<List*> User::get_lists() const {
    return lists;
}