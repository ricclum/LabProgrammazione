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

void List::add_item(const Item& item) {
    items[item.getCategory()] = item;
    notify();
}

void List::set_quantity(const std::string& cat_name, int quantity) {

    if (quantity < 0) {
        throw std::invalid_argument("Quantity must be greater than or equal to 0");
    }

    if (items.find(cat_name) == items.end()) {
        throw std::invalid_argument("Item not found");
    }
    items[cat_name].setQuantity(quantity);
    notify();
}

void List::remove_item(const Item& item) {
    if (items.find(item.getCategory()) == items.end()) {
        throw std::invalid_argument("Item not found");
    }
    items.erase(item.getCategory());
    notify();
}

bool List::is_purchased(const std::string& cat_name) const {
    if (items.find(cat_name) == items.end()) {
        throw std::invalid_argument("Item not found");
    }
    return items.at(cat_name).isPurchased();
}

void List::set_purchased(const std::string& cat_name, bool purchased) {
    if (items.find(cat_name) == items.end()) {
        throw std::invalid_argument("Item not found");
    }
    items[cat_name].setPurchased(purchased);
    notify();
    if (purchased){
        for (const auto& pair : items) {
            if (!pair.second.isPurchased()) {
               return;
            }
        }
        completed = true;
    }
}

int List::get_quantity(const Item& item) const {
    if (items.find(item.getCategory()) == items.end()) {
        throw std::invalid_argument("Item not found");
    }
    return items.at(item.getCategory()).getQuantity();
}

bool List::check_item(const Item& item) const {
    return items.find(item.getCategory()) != items.end();
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

int List::get_total_remaining() const {
    int total = 0;
    for (auto& item : items) {
        if (!item.second.isPurchased()) {
            total += item.second.getQuantity();
        }
    }
    return total;
}
