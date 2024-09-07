#include "gtest/gtest.h"
#include "../User.h"


// Construttore
TEST(UserTest, ConstructorTest) {
    User utente("testUser");
	EXPECT_EQ(utente.get_name(), "testUser");
}

// Setter per username
TEST(UserTest, SetUsernameTest) {
    User utente("testUser");
	utente.set_name("tester2");
	EXPECT_EQ(utente.get_name(), "tester2");
}

// Test per aggiunta lista e rimozione
TEST(UserTest, AddRmListTest) {
    User utente("testUser");
	List*  list = new List("lista1");
	utente.add_list(list);

	EXPECT_EQ(utente.get_lists().size(), 1);

    //Rimuovo
    utente.remove_list(list);
    EXPECT_EQ(utente.get_lists().size(), 0);

    delete list;
}







