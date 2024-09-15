#ifndef LIST_H
#define LIST_H

#include "Subject.h"
#include <map>
#include "Item.h"


class List : public Subject {
public:

    List(const std::string& list_name, bool is_completed = false) : list_name(list_name), completed(completed) {}

    const std::string& get_list_name() const;
    void set_list_name(const std::string& name);
    void add_item(const std::string& category_name, const Item& item);
    void set_quantity(const std::string&  category_name, int quantity);
    void remove_item(const std::string& category_name);
    bool is_purchased(const std::string& category_name) const;
    void set_purchased(const std::string& category_name, bool purchased);
    bool is_completed() const;

    void notify() override;
    void subscribe(const std::shared_ptr<Observer>& observer) override;
    void unsubscribe(const std::shared_ptr<Observer>& observer) override;
    int get_total_size() const;
    int get_quantity(const std::string& category_name) const;
    bool check_item(const std::string&  category_name) const;

private:
    std::map<std::string, Item> items;
    std::string list_name;
    bool completed;
};

#endif