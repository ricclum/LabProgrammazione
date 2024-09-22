#include "Item.h"

// Getters
const std::string& Item::getCategory() const {
    return category;
}

int Item::getQuantity() const {
    return quantity;
}

bool Item::isPurchased() const {
    return purchased;
}

// Setters
void Item::setCategory(const std::string& category) {
    this->category = category;
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
