#include <string>
#ifndef ITEM_H
#define ITEM_H

//Questa classe rappresenta un item di una lista in stile Listonic.
//Non ha un nome specifico ma bensì solo la categoria del prodotto.
//Le liste di Listonic infatti hanno come chiavi il nome della categoria del prodotto.
//Esempio: Birra con quantità 1 è una possibile voce di Listonic
//Birra Moretti 66cl, Birra Heineken 66cl non sono possibili voci ma rientrano
//entrambe nella categoria generica Birra.

class Item {

public:
    // Default Constructor
    Item():category(""), quantity(0), purchased(false) {}

    Item(const std::string& category, int quantity = 0, bool purchased = false) : category(category), purchased(purchased) {
        if (quantity < 0) {
            throw std::invalid_argument("Quantity must be greater than or equal to 0");
        }
        this->quantity = quantity;
    }

    //Overload per permettere il confronto tra elementi
    bool operator<(const Item& other) const {
        return category < other.getCategory();
    }

    bool operator>(const Item& other) const {
        return category > other.getCategory();
    }

    bool operator==(const Item& other) const {
        return category == other.getCategory();
    }


    // Getters
    const std::string& getCategory() const;
    int getQuantity() const;
    bool isPurchased() const;

    // Setters
    void setCategory(const std::string& category);
    void setQuantity(int quantity);
    void setPurchased(bool purchased);
   


private:
    std::string category;
    int quantity;
    bool purchased;

};

#endif  // ITEM_H
