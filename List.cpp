#include "List.h"


const std::string& List::get_list_name() const {
    return list_name;
}


void List::set_list_name(const std::string& name) {
    list_name = name;
    notify();
}

void List::add_item(const Item&  item, int quantity) {
    //check if item is not in the map
    if (items.find(item) == items.end()) {
        //add item to the map
        items[item] = quantity;
    }
    else{
        //increment the item count
        items[item] += quantity;
    }
    notify();
}

bool List::check_item(const Item&  item) const{
    //check if item is in the map
    if (items.find(item) == items.end()) {
        return false;
    }
    return true;
}

void List::remove_item(const Item& item, int quantity) {
    if (items[item] >= quantity) {
        items[item]-=quantity;
        if (items[item]==0)
            items.erase(item);
        notify();
    }
}

void List::notify(){
    for (Observer* observer : users) {
        observer->update(this->list_name);
    }
}

void List::subscribe(Observer* observer){
    users.push_back(observer);
}

void List::unsubscribe(Observer* observer){
    users.remove(observer);
}

int List::get_total_size() const {
    int total = 0;
    for (auto item : items) {
        total += item.second;
    }
    return total;
}


int List::get_quantity(const Item& item) const {
    if (items.find(item) != items.end()) {
        return items.at(item);
    }
    return 0;
}

