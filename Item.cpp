#include "Item.h"

// Getters
const std::string& Item::getName() const {
    return name;
}

const std::string& Item::getCategory() const {
    return category;
}

const std::string& Item::getBrand() const{
    return brand;
}

// Setters
void Item::setName(const std::string& name) {
    this->name = name;
}

void Item::setCategory(const std::string& category) {
    this->category = category;
}

void Item::setBrand(const std::string& brand) {
    this->brand = brand;
}
