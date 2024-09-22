#include "gtest/gtest.h"
#include "../Item.h"

//Test per getter
TEST(ItemTest, TestGetters) {

    Item item("Mortadella", 1, false);

    EXPECT_EQ(item.getCategory(), "Mortadella");
    EXPECT_EQ(item.getQuantity(), 1);
    EXPECT_EQ(item.isPurchased(), false);
}

//Test per setter
TEST(ItemTest, TestSetters) {

    Item item("Mortadella", 1, false);
    item.setCategory("Bagno Schiuma");
    item.setQuantity(2);
    item.setPurchased(true);
    EXPECT_EQ(item.getCategory(), "Bagno Schiuma");
    EXPECT_EQ(item.getQuantity(), 2);
    EXPECT_EQ(item.isPurchased(), true);
    
}


TEST(ItemTest, TestSetQuantityNegative) {
    Item item("Mortadella", 1, false);

    // Verifica che il setter della quantità accetti valori positivi
    item.setQuantity(5);
    EXPECT_EQ(item.getQuantity(), 5);

    // Verifica che venga lanciata un'eccezione se si imposta una quantità negativa
    EXPECT_THROW(item.setQuantity(-3), std::invalid_argument);
}
