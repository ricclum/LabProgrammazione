#include "gtest/gtest.h"
#include "../List.h"

// Test fixture for the List class
class ListTest : public ::testing::Test {
protected:

    ListTest() : item1("prosciutto crudo", "gastronomia", "Citterio"),
                item2("prosciutto cotto", "gastronomia", "Citterio"),
              item3("Bagno schiuma", "igiene", "Nivea"),
              lista(new List("lista1")){}

    ~ListTest() override {
        delete lista;
    }

	void SetUp() override {

        lista->add_item(item1, 2);
        lista->add_item(item2, 3);
        lista->add_item(item3, 1);
    }

    List* lista;
    Item item1;
    Item item2;
    Item item3;
};


// Test per aggiunta
TEST_F(ListTest, AddTest) {
    Item item4 = Item("Hamburger", "macelleria", "Montana");
	lista->add_item(item4, 4);
	EXPECT_EQ(lista->get_total_size(), 10);
}


// Test per rimozione
TEST_F(ListTest, RemoveTest) {
    Item item = Item("Salame Milano", "gastronomia", "Beretta");
    lista->add_item(item, 2);
	lista->remove_item(item, 1);

	EXPECT_EQ(lista->get_quantity(item), 1);

    lista->remove_item(item, 1);
	EXPECT_EQ(lista->get_quantity(item), 0);
}
