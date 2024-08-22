#ifndef LIST_H
#define LIST_H

#include "AbstractSubject.h"
#include <map>

class List : public Subject {
public:
    void attach(Observer* observer) override {
        observers.push_back(observer);
    }

    void detach(Observer* observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify() override {
        for (Observer* observer : observers) {
            observer->update();
        }
    }

    void add_item(Item item) {
        //check if item is in the map
        if (items.find(item) == items.end()) {
            //add item to the map
            items[item] = 1;
        }
        else{
            //increment the item count
            items[item]++;
        }
        notify();
    }

    void remove_item(Item item) {
        if (items[item] > 0) {
            items[item]--;
            notify();
        }
    }


private:
    std::map<Item,int> items;
    std::string list_name;
};

#endif