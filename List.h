#ifndef LIST_H
#define LIST_H

#include "AbstractSubject.h"
#include <map>
#include "Item.h"

class List : public AbstractSubject {
public:

    List(std::string list_name) : list_name(list_name) {}

    void notify() override {
        for (Observer* observer : users) {
            observer->update();
        }
    }

    void subscribe(Observer* observer) override {
        users.push_back(observer);
    }

    void unsubscribe(Observer* observer) override {
        users.remove(observer);
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