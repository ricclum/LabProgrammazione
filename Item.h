#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
	// Constructor
	Item(const std::string& name, const std::string& category, const std::string& brand)
		: name(name), category(category), brand(brand) {}

	// Getters
	std::string getName() const {
		return name;
	}

	std::string getCategory() const {
		return category;
	}

	std::string getBrand() const {
		return brand;
	}

	// Setters
	void setName(const std::string& name) {
		this->name = name;
	}

	void setCategory(const std::string& category) {
		this->category = category;
	}

	void setBrand(const std::string& brand) {
		this->brand = brand;
	}

private:
	std::string name;
	std::string category;
	std::string brand;
};

#endif