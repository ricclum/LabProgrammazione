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
    std::shared_ptr<User> utente = std::make_shared<User>("testUser");
	std::shared_ptr<List> list = std::make_shared<List>("lista1");
	utente->add_list(list);

	EXPECT_EQ(utente->get_lists().size(), 1);

    //Rimuovo
    utente->remove_list(list);
    EXPECT_EQ(utente->get_lists().size(), 0);

}


// Classe di test derivata da User per verificare il meccanismo dell'Observer (update ecc..)
class TestObserverUser : public User {
public:
    TestObserverUser(const std::string& name) : User(name), update_count(0) {}

    //Qui il metodo update simula, agiornando un contatore per verificare il numero di chiamate
    void update(const std::string& list_name) override {
        update_count++;
        last_list_name = list_name;
    }

    int get_update_count() const {
        return update_count;
    }

    const std::string& get_last_list_name() const {
        return last_list_name;
    }

private:
    int update_count;
    std::string last_list_name;
};


// Test per verificare se l'Observer riceve una notifica quando il nome della lista cambia
TEST(UserTest, ObserverPatternTestChangeListName) {
    auto utente = std::make_shared<TestObserverUser>("testUser");
    auto list = std::make_shared<List>("Lista1");

    // Aggiunge la lista all'utente (e l'utente si sottoscrive alla lista)
    utente->add_list(list);

    // Cambia il nome della lista (dovrebbe notificare l'Observer)
    list->set_list_name("Lista2");

    // Verifica che il metodo update dell'utente sia stato chiamato una volta
    EXPECT_EQ(utente->get_update_count(), 1);

    // Verifica che l'ultimo nome ricevuto dall'Observer sia "Lista2"
    EXPECT_EQ(utente->get_last_list_name(), "Lista2");
}

// Test per verificare se l'Observer riceve una notifica quando viene aggiunto un elemento alla lista
TEST(UserTest, ObserverPatternTestAddItem) {
    auto utente = std::make_shared<TestObserverUser>("testUser");
    auto list = std::make_shared<List>("Lista1");

    // Aggiunge la lista all'utente (che si sottoscrive)
    utente->add_list(list);

    // Aggiunge un elemento alla lista
    list->add_item("Mela", Item("Mela", 3, false));

    // Verifica che il metodo update dell'utente sia stato chiamato una volta (per l'aggiunta)
    EXPECT_EQ(utente->get_update_count(), 1);

}

// Test per verificare se l'Observer riceve una notifica quando un elemento viene rimosso dalla lista
TEST(UserTest, ObserverPatternTestRemoveItem) {
    auto utente = std::make_shared<TestObserverUser>("testUser");
    auto list = std::make_shared<List>("Lista1");

    // Aggiunge la lista all'utente (che si sottoscrive)
    utente->add_list(list);

    // Aggiunge un elemento alla lista
    Item item("Sapone", 2, false);
    list->add_item("Sapone", item);

    // Rimuove l'elemento dalla lista
    list->remove_item("Sapone");

    // Verifica che il metodo update dell'utente sia stato chiamato due volte (una per l'aggiunta e una per la rimozione)
    EXPECT_EQ(utente->get_update_count(), 2);

}








