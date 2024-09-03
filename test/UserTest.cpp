#include "gtest/gtest.h"
#include "../User.h"
#include "../List.h"

// Test fixture
class UserTest : public ::testing::Test {
protected:
	User user;

	void SetUp() override {
		user = User("JohnDoe");
	}

	void TearDown() override {
		// Clean up if necessary
	}
};

// Constructor
TEST_F(UserTest, ConstructorTest) {
	EXPECT_EQ(user.get_name(), "JohnDoe");
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



//Per testare funzionamento Observer pattern
class ObTestUser : public User {
public:
    ObTestUser(const std::string& name) : User(name), update_called_count(0) {}

    void update(const std::string& list_name) override {
        update_called_count++;
        last_list_name = list_name;
    }

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
TEST_F(UserTest, ObserverPatternTestAdd) {
    ObTestUser test_user("testUser");
    List list("Lista1");
    list.subscribe(&test_user);

    list.add_item(Item("item1", "category1", "brand1"), 1);

    EXPECT_EQ(test_user.get_update_called_count(), 1);
    EXPECT_EQ(test_user.get_last_list_name(), "Lista1");
}

//Test per verificare la rimozione
TEST_F(UserTest, ObserverPatternTestRemove) {
    ObTestUser test_user("testUser");
    List list("Lista1");
    list.subscribe(&test_user);

    list.add_item(Item("item1", "category1", "brand1"), 1);
    list.remove_item(Item("item1", "category1", "brand1"));

    EXPECT_EQ(test_user.get_update_called_count(), 2);
    EXPECT_EQ(test_user.get_last_list_name(), "Lista1");
}