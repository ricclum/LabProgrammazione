#include "Item.h"

// Getters
const std::string& Item::getName() const {
    return name;
}

int Item::getQuantity() const {
    return quantity;
}

bool Item::isPurchased() const {
    return purchased;
}

// Setters
void Item::setName(const std::string& name) {
    this->name = name;
}

void Item::setQuantity(int quantity) {
    if (quantity < 0) {
        throw std::invalid_argument("La quantità non può essere negativa");
    }

    this->quantity = quantity;
}

void Item::setPurchased(bool purchased) {
    this->purchased = purchased;
}
