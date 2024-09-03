#include <string>

class Item {

public:
    // Constructor
    Item(std::string name, std::string category, std::string brand)
            : name(this->name), category(this->category), brand(this->brand) {}

    // Getters
    std::string getName() const;
    std::string getCategory() const;
    std::string getBrand() const;

    // Setters
    void setName(const std::string& name);
    void setCategory(const std::string& category);
    void setBrand(const std::string& brand);


private:
    std::string name;
    std::string category;
    std::string brand;

};
