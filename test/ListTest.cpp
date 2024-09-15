#include "gtest/gtest.h"
#include "../List.h"

// Test fixture for the List class
class ListTest : public ::testing::Test {
protected:

    ListTest() : item1("prosciutto crudo", 1, false),
                item2("prosciutto cotto", 2, false),
              item3("Bagno schiuma", 2, false),
              lista(std::make_shared<List> ("lista1")){}

	void SetUp() override {

        lista->add_item("prosciutto crudo", item1);
        lista->add_item("prosciutto cotto", item2);
        lista->add_item("Bagno schiuma", item3);
    }

    std::shared_ptr<List> lista;
    Item item1;
    Item item2;
    Item item3;
};


//Test per cambio del nome
TEST_F(ListTest, ChangeNameTest) {
    lista->set_list_name("lista2");
    EXPECT_EQ(lista->get_list_name(), "lista2");
}

//Test per total size della lista
TEST_F(ListTest, TotalSizeTest) {
    EXPECT_EQ(lista->get_total_size(), 5);
}

// Test per aggiunta e quantity
TEST_F(ListTest, AddTest) {
    Item item4 = Item("Hamburger", 2, false);
	lista->add_item("Hamburger", item4);
	EXPECT_EQ(lista->get_quantity("Hamburger"), 2);
}


// Test per rimozione
TEST_F(ListTest, RemoveTest) {

    lista->remove_item("prosciutto crudo");
    EXPECT_EQ(lista->get_quantity("prosciutto crudo"), 0);

}

//Test per ricerca elementi nella lista
TEST_F(ListTest, CheckTest) {

    EXPECT_FALSE(lista->check_item("Panna da cucina"));
    EXPECT_TRUE(lista->check_item("prosciutto crudo"));
}

//Test per set purchased
TEST_F(ListTest, SetPurchasedTest) {

    lista->set_purchased("prosciutto crudo", true);
    EXPECT_TRUE(lista->is_purchased("prosciutto crudo"));
}

//Test per quantity
TEST_F(ListTest, QuantityTest) {

    lista->set_quantity("prosciutto crudo", 2);
    EXPECT_EQ(lista->get_quantity("prosciutto crudo"), 2);
}

//Test per lista completata
TEST_F(ListTest, CompletedTest) {

    lista->set_purchased("prosciutto crudo", true);
    lista->set_purchased("prosciutto cotto", true);
    lista->set_purchased("Bagno schiuma", true);
    EXPECT_TRUE(lista->is_completed());
}
