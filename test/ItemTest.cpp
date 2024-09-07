#include "gtest/gtest.h"
#include "../Item.h"

//Test per getter
TEST(ItemTest, TestGetters) {

    Item item("Mortadella Bologna", "Gastronomia", "Beretta");

    EXPECT_EQ(item.getName(), "Mortadella Bologna");
    EXPECT_EQ(item.getCategory(), "Gastronomia");
    EXPECT_EQ(item.getBrand(), "Beretta");
}

//Test per setter
TEST(ItemTest, TestSetters) {

    Item item("Mortadella Bologna", "Gastronomia", "Beretta");



    item.setName("Bagno Schiuma");
    item.setCategory("Igiene Personale");
    item.setBrand("Adidas");

    EXPECT_EQ(item.getName(), "Bagno Schiuma");
    EXPECT_EQ(item.getCategory(), "Igiene Personale");
    EXPECT_EQ(item.getBrand(), "Adidas");
}
