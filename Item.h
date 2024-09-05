#include <string>
#ifndef ITEM_H
#define ITEM_H


class Item {

public:
    // Constructor
    Item(const std::string& name, const std::string& category, const std::string& brand)
            : name(name), category(category), brand(brand) {}

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
    const std::string& getName() const ;
    const std::string& getCategory() const ;
    const std::string& getBrand() const ;

    // Setters
    void setName(const std::string& name);
    void setCategory(const std::string& category);
    void setBrand(const std::string& brand);


private:
    std::string name;
    std::string category;
    std::string brand;

};

#endif  // ITEM_H
