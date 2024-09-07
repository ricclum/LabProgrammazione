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


//Test per cambio del nome
TEST_F(ListTest, ChangeNameTest) {
    lista->set_list_name("lista2");
    EXPECT_EQ(lista->get_list_name(), "lista2");
}

//Test per total size della lista
TEST_F(ListTest, TotalSizeTest) {
    EXPECT_EQ(lista->get_total_size(), 6);
}

// Test per aggiunta e quantity
TEST_F(ListTest, AddTest) {
    Item item4 = Item("Hamburger", "macelleria", "Montana");
	lista->add_item(item4, 4);
	EXPECT_EQ(lista->get_quantity(item4), 4);
}


// Test per rimozione
TEST_F(ListTest, RemoveTest) {

    lista->remove_item(item1, 1);
    EXPECT_EQ(lista->get_quantity(item1), 1);

    lista->remove_item(item1, 1);
    EXPECT_EQ(lista->get_quantity(item1), 0);

}

//Test per ricerca elementi nella lista
TEST_F(ListTest, CheckTest) {

    //Elimino item1
    lista->remove_item(item1, 2);
    EXPECT_FALSE(lista->check_item(item1));

    EXPECT_TRUE(lista->check_item(item2));
}
