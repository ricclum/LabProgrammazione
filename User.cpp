#include "User.h"

User::~User() {
    for (auto& list : lists) {
        detach(list);
    }
}

void User::update(const std::string& sub_name){
    std::cout << "User " << this->name<< " received an update from the list: " << sub_name << std::endl;
}

void User::attach(const std::shared_ptr<Subject>& list) {
    list->subscribe(shared_from_this());
}

void User::detach(const std::shared_ptr<Subject>& list) {
    list->unsubscribe(shared_from_this());
}

void User::add_list(const std::shared_ptr<List>& list) {
    lists.push_back(list);
    attach(list);
}

bool User::remove_list(const std::shared_ptr<List>&  list) {
    for (auto it = lists.begin(); it != lists.end(); ++it) {
        if (*it == list) {
            lists.erase(it);
            return true;
        }
    }
    return false;
}

std::string User::get_name() const {
    return name;
}

void User::set_name(const std::string& name) {
    this->name = name;
}

const std::list<std::shared_ptr<List>>& User::get_lists() const {
    return lists;
}