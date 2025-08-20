#include "Item.hpp"
#include "gtest/gtest.h"

TEST(item, init) {
    std::string name = "Banana";
    double price = 4.50;
    IDiscount* categorie = new Categorie(8);
    Item* item = new Item(name, price, categorie, "");

    EXPECT_EQ(item->getName(), name);
    EXPECT_EQ(item->getPrice(), price);
    EXPECT_EQ(item->getCategorie(), categorie);
    delete(item);
    delete(categorie);
}

TEST(item, setters) {
    IDiscount* categorie = new Categorie(8);
    Item* item = new Item("Banana", 4.50, nullptr, "");

    item->setName("Uva");
    item->setPrice(3.8);
    item->setCategorie(categorie);

    EXPECT_EQ(item->getName(), "Uva");
    EXPECT_EQ(item->getPrice(), 3.8);
    EXPECT_EQ(item->getCategorie(), categorie);
    delete(item);
    delete(categorie);
}
