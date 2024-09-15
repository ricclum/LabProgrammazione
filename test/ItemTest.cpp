#include "gtest/gtest.h"
#include "../Item.h"

//Test per getter
TEST(ItemTest, TestGetters) {

    Item item("Mortadella Bologna", 1, false);

    EXPECT_EQ(item.getName(), "Mortadella Bologna");
    EXPECT_EQ(item.getQuantity(), 1);
    EXPECT_EQ(item.isPurchased(), false);
}

//Test per setter
TEST(ItemTest, TestSetters) {

    Item item("Mortadella Bologna", 1, false);
    item.setName("Bagno Schiuma");
    item.setQuantity(2);
    item.setPurchased(true);
    EXPECT_EQ(item.getName(), "Bagno Schiuma");
    EXPECT_EQ(item.getQuantity(), 2);
    EXPECT_EQ(item.isPurchased(), true);
    
}
