#include "gtest/gtest.h"
#include "../List.h"

// Test fixture for the List class
class ListTest : public ::testing::Test {
protected:

	// Set up 
	void SetUp() override {
         //Create some items
        item1 = Item("prosciutto crudo", "gastronomia", "Citterio");
        item2 = Item("prosciutto cotto", "gastronomia", "Citterio");
        item3 = Item("Bagno schiuma", "igiene", "Nivea");

        lista.add_item(item1, 2);
        lista.add_item(item2, 3);
        lista.add_item(item3, 1);

    }

    List lista;
    Item item1;
    Item item2;
    Item item3;
};


// Test case for adding elements to the list
TEST_F(ListTest, AddTest) {
    Item item4 = Item("Hamburger", "macelleria", "Montana");
	lista.add_item(item4, 4);
	EXPECT_EQ(lista.get_total_size(), 10);
}


// Test case for removing elements from the list
TEST_F(ListTest, RemoveTest) {
    Item item = Item("Salame Milano", "gastronomia", "Beretta");
    lista.add_item(item, 2);
	lista.remove_item(item, 1);

	EXPECT_EQ(lista.get_quantity(item), 1);

    lista.remove_item(item, 1);
	EXPECT_EQ(lista.get_quantity(item), 0);
}
