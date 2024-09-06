#ifndef LIST_H
#define LIST_H

#include "AbstractSubject.h"
#include <map>
#include "Item.h"
#include "Observer.h"
class List : public AbstractSubject {
public:

    List(std::string list_name) : list_name(list_name) {}

    const std::string& get_list_name() const;
    void set_list_name(const std::string& name);
    void add_item(const Item& item, int quantity);
    void remove_item(const Item& item, int quantity);
    void notify() override;
    void subscribe(Observer* observer) override;
    void unsubscribe(Observer* observer) override;
    int get_total_size() const;
    int get_quantity(const Item& item) const;
    bool check_item(const Item&  item) const;

private:
    std::map<Item, int> items;
    std::string list_name;
};

#endif