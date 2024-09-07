#include "../User.h"
#include "gtest/gtest.h"

class ObTestUser : public User, public ::testing::Test {
protected:

    ObTestUser() : User("testUser"), update_called_count(0) {}

    // Implementa l'update per fini di test
    void update(const std::string& list_name) override {
        update_called_count++;
        last_list_name = list_name;
    }

    // Ottiene il numero di chiamate
    int get_update_called_count() const {
        return update_called_count;
    }

    std::string get_last_list_name() const {
        return last_list_name;
    }

    int update_called_count;
    std::string last_list_name;
};

//Test per verificare la chiamate di update sulla modifica del nome di una lista
TEST_F(ObTestUser, ObserverPatternTestChangeName) {
    List* list = new List("Lista1");
    list->subscribe(this);

    list->set_list_name("Lista2");

    EXPECT_EQ(get_update_called_count(), 1);

    delete list;
}

// Test per verificare update sull'aggiunta di un nuovo elemento
TEST_F(ObTestUser, ObserverPatternTestAdd) {
    List* list = new List("Lista1");
    list->subscribe(this);

    list->add_item(Item("item1", "category1", "brand1"), 1);

    EXPECT_EQ(get_update_called_count(), 1);

    delete list;
}

// Test per verificare la chiamate di update durante la rimozione di un elemento
TEST_F(ObTestUser, ObserverPatternTestRemove) {

    List* list = new List("Lista1");
    list->subscribe(this);

    Item item("item1", "category1", "brand1");
    list->add_item(item, 1);
    list->remove_item(item, 1);

    EXPECT_EQ(get_update_called_count(), 2);

    delete list;
}

