#ifndef LIST_H
#define LIST_H

#include "Subject.h"
#include <map>
#include "Item.h"


class List : public Subject {
public:

    List(const std::string& list_name, bool is_completed = false) : list_name(list_name), completed(is_completed) {}

    const std::string& get_list_name() const;
    void set_list_name(const std::string& name);
    void add_item(const Item& item);
    void set_quantity(const std::string& cat_name, int quantity);
    void remove_item(const Item& item);
    bool is_purchased(const std::string &cat_name) const;
    void set_purchased(const std::string& cat_name, bool purchased);
    bool is_completed() const;

    void notify() override;
    void subscribe(const std::shared_ptr<Observer>& observer) override;
    void unsubscribe(const std::shared_ptr<Observer>& observer) override;
    int get_total_size() const;
    int get_total_remaining() const;
    int get_quantity(const Item& item) const;
    bool check_item(const Item& item) const;

private:
    std::map<std::string, Item> items;
    std::string list_name;
    bool completed;


};

#endif