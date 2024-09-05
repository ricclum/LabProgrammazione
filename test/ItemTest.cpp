#include "gtest/gtest.h"
#include "../Item.h"

TEST(ItemTest, TestGetters) {
    // Create an item object
    Item item("Shirt", "Clothing", "Nike");

    // Test the getters
    EXPECT_EQ(item.getName(), "Shirt");
    EXPECT_EQ(item.getCategory(), "Clothing");
    EXPECT_EQ(item.getBrand(), "Nike");
}

TEST(ItemTest, TestSetters) {
    // Create an item object
    Item item("Shirt", "Clothing", "Nike");

    // Test modifying the item
    item.setName("Pants");
    item.setCategory("Bottoms");
    item.setBrand("Adidas");

    // Test the modified values
    EXPECT_EQ(item.getName(), "Pants");
    EXPECT_EQ(item.getCategory(), "Bottoms");
    EXPECT_EQ(item.getBrand(), "Adidas");
}
