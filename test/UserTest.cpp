#include "gtest/gtest.h"
#include "../User.h"


// Test fixture
class UserTest : public ::testing::Test {
protected:
	UserTest() :user("testUser"){}
    User user;
};

// Constructor
TEST_F(UserTest, ConstructorTest) {
	EXPECT_EQ(user.get_name(), "testUser");
}

// Setter for the username
TEST_F(UserTest, SetUsernameTest) {
	user.set_name("JaneDoe");
	EXPECT_EQ(user.get_name(), "JaneDoe");
}

// Test for adding a list to the user
TEST_F(UserTest, AddListTest) {
	List list("Lista1");
	user.add_list(&list);
	EXPECT_EQ(user.get_lists().size(), 1);
}





