#include "gtest/gtest.h"
#include "../Item.h"

//Test per getter
TEST(ItemTest, TestGetters) {

    Item item("Shirt", "Clothing", "Nike");

    EXPECT_EQ(item.getName(), "Shirt");
    EXPECT_EQ(item.getCategory(), "Clothing");
    EXPECT_EQ(item.getBrand(), "Nike");
}

//Test per setter
TEST(ItemTest, TestSetters) {

    Item item("Shirt", "Clothing", "Nike");


    item.setName("Pants");
    item.setCategory("Bottoms");
    item.setBrand("Adidas");

    EXPECT_EQ(item.getName(), "Pants");
    EXPECT_EQ(item.getCategory(), "Bottoms");
    EXPECT_EQ(item.getBrand(), "Adidas");
}
