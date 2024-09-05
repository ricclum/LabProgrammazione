#include "../User.h"
#include "gtest/gtest.h"

class ObTestUser : public User, public ::testing::Test {
protected:
    // Constructor for the test fixture
    ObTestUser() : User("testUser"), update_called_count(0) {}

    // Observer update method implementation
    void update(const std::string& list_name) override {
        update_called_count++;
        last_list_name = list_name;
    }

    // Accessor methods for tests
    int get_update_called_count() const {
        return update_called_count;
    }

    std::string get_last_list_name() const {
        return last_list_name;
    }

private:
    int update_called_count;
    std::string last_list_name;
};

// Test per verificare l'aggiunta
TEST_F(ObTestUser, ObserverPatternTestAdd) {
    List list("Lista1");
    list.subscribe(this);

    list.add_item(Item("item1", "category1", "brand1"), 1);

    EXPECT_EQ(get_update_called_count(), 1);
    EXPECT_EQ(get_last_list_name(), "Lista1");
}

// Test per verificare la rimozione
TEST_F(ObTestUser, ObserverPatternTestRemove) {
    List list("Lista1");
    list.subscribe(this);

    list.add_item(Item("item1", "category1", "brand1"), 1);
    list.remove_item(Item("item1", "category1", "brand1"));

    EXPECT_EQ(get_update_called_count(), 2); // Add and remove should both trigger update
    EXPECT_EQ(get_last_list_name(), "Lista1");
}

