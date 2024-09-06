#include "gtest/gtest.h"
#include "../User.h"


class UserTest : public ::testing::Test {
protected:
	UserTest() :user("testUser"){}
    User user;
};

// Construttore
TEST_F(UserTest, ConstructorTest) {
	EXPECT_EQ(user.get_name(), "testUser");
}

// Setter per username
TEST_F(UserTest, SetUsernameTest) {
	user.set_name("JaneDoe");
	EXPECT_EQ(user.get_name(), "JaneDoe");
}

// Test per aggiunta lista e rimozione a utente
TEST_F(UserTest, AddRmListTest) {
	List*  list = new List("lista1");
	user.add_list(list);

	EXPECT_EQ(user.get_lists().size(), 1);

    //Rimuovo
    user.remove_list(list);
    EXPECT_EQ(user.get_lists().size(), 0);

    delete list;
}







