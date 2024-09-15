#include <string>
#ifndef ITEM_H
#define ITEM_H


class Item {

public:
    // Constructor
    Item(){}
    Item(const std::string& name, int quantity = 1, bool purchased = false) : name(name), quantity(quantity), purchased(purchased) {}

    //Overload per permettere il confronto tra elementi
    bool operator<(const Item& other) const {
        return name < other.getName();
    }

    bool operator>(const Item& other) const {
        return name > other.getName();
    }

    bool operator==(const Item& other) const {
        return name == other.getName();
    }


    // Getters
    const std::string& getName() const;
    int getQuantity() const;
    bool isPurchased() const;

    // Setters
    void setName(const std::string& name);
    void setQuantity(int quantity);
    void setPurchased(bool purchased);
   


private:
    std::string name;
    int quantity;
    bool purchased;

};

#endif  // ITEM_H
