#include "Categorie.hpp"
#include "gtest/gtest.h"

TEST(categories, init) {
    int discount = 10;
    Categorie* categorie = new Categorie(10);

    EXPECT_EQ(categorie->getDiscount(), discount);
    delete(categorie);
}

TEST(categories, set_children) {
    int discount_a = 12;
    int discount_b = 15;
    int discount_c = 10;

    Categorie* grandparent = new Categorie(discount_a);
    Categorie* parent = new Categorie(discount_b, grandparent);
    Categorie* categorie = new Categorie(discount_c, parent);

    EXPECT_EQ(grandparent->getParent(), nullptr);
    EXPECT_EQ(parent->getParent(), grandparent);
    EXPECT_EQ(categorie->getParent(), parent);
    delete(categorie);
}

TEST(categories, get_best_discount) {
    int discount_a = 12;
    int discount_b = 15;
    int discount_c = 10;

    Categorie* grandparent = new Categorie(discount_a);
    Categorie* parent = new Categorie(discount_b, grandparent);
    Categorie* categorie = new Categorie(discount_c, parent);

    int bestDiscount = std::max(discount_a, std::max(discount_b, discount_c));

    EXPECT_EQ(categorie->getBestDiscount(), bestDiscount);
    delete(categorie);
}