#include "List.h"


const std::string& List::get_list_name() const {
    return list_name;
}


void List::set_list_name(const std::string& name) {
    list_name = name;
    notify();
}

bool List::is_completed() const {
    return completed;
}

void List::add_item(const std::string& category_name, const Item& item) {
    items[category_name] = item;
    notify();
}

void List::set_quantity(const std::string&  category_name, int quantity) {
    items[category_name].setQuantity(quantity);
    notify();
}

int List::get_quantity(const std::string& category_name) const {
    if (items.find(category_name) != items.end()) {
        return items.at(category_name).getQuantity();
    }
    return 0;
}

bool List::is_purchased(const std::string& category_name) const {
    if (items.find(category_name) != items.end()) {
        return items.at(category_name).isPurchased();
    }
    return false;
}

void List::set_purchased(const std::string& category_name, bool purchased) {
    items[category_name].setPurchased(purchased);
    if (purchased) {
        for (auto& item : items) {
            if (!item.second.isPurchased()) {
                return;
            }
        }
        completed = true;
    }
    notify();
}


bool List::check_item(const std::string&  category_name) const {
    //check if item is in the map
    if (items.find(category_name) == items.end()) {
        return false;
    }
    return true;
}

void List::remove_item(const std::string& category_name) {
    items.erase(category_name);
    notify();
}

void List::subscribe(const std::shared_ptr<Observer>& observer) {
    users.push_back(observer);
}


void List::unsubscribe(const std::shared_ptr<Observer>& observer) {
    auto it = std::find(users.begin(), users.end(), observer);
    if (it != users.end()) {
        users.erase(it);
    }
}


// Notify all observers
void List::notify() {
    for (const auto& user : users) {
        user->update(this->list_name);
    }
}


int List::get_total_size() const {
    int total = 0;
    for (auto& item : items) {
        total += item.second.getQuantity();
    }
    return total;
}


