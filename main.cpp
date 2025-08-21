#include "Categorie.hpp"
#include "Item.hpp"
#include <unordered_map>
#include <sstream>
#include <iostream>

int main() {
    Categorie* Produce = new Categorie(10);
    Categorie* Fruits = new Categorie(18, Produce);
    Categorie* Veg = new Categorie(5, Produce);

    Categorie* Dairy = new Categorie(15);
    Categorie* Milk = new Categorie(20, Produce);
    Categorie* Cheese = new Categorie(20, Produce);

    std::unordered_map<std::string, Item> itens = {
        {"Apple", Item("Apple", 50, Fruits, "3+1")},
        {"Orange", Item("Orange", 80, Fruits, "20%")},
        {"Potato", Item("Potato", 30, Veg, "5+2")},
        {"Tomato", Item("Tomato", 70, Veg, "10%")},
        {"Cow_Milk", Item("Cow_Milk", 50, Milk, "3+1")},
        {"Soy_Milk", Item("Soy_Milk", 40, Milk, "10%")},
        {"Cheddar", Item("Cheddar", 50, Cheese, "2+1")},
        {"Gouda", Item("Gouda", 80, Cheese, "10%")}
    };

    std::unordered_map<std::string, double> bought_itens;
    std::stringstream ss;
    std::string token;

    ss << "Apple 6Kg, Orange 2Kg, Potato 14Kg, Tomato 3Kg, Cow_Milk 8Lt, Gouda 2Kg";
    
    while(std::getline(ss, token, ' ')) {
        std::string item = token;
        std::getline(ss, token, ' ');

        int quantity = std::stoi(token.substr(0, token.find_last_of("0123456789")+1));
        bought_itens[item] = quantity;
    }

    double total_price = 0;
    double total_saved = 0;

    for (const auto &[name, quantity] : bought_itens) {
        Item& item = itens.at(name);
        total_price += item.getFinalPrice(quantity);
        total_saved += item.getFinalDiscount(quantity);
        std::cout << name << "price: " << (item.getPrice() * quantity) << " (-" << item.getFinalDiscount(quantity) << ")" << std::endl;
    }
    std::cout << "-----------------" << std::endl;
    std::cout << "price: " << total_price << std::endl;
    std::cout << "saved: " << total_saved << std::endl;

    return (0);
}

// TO-DO: fazer testes com o _discount do item
