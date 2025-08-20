#include "Item.hpp"

Item::Item(std::string name, double price, IDiscount* categorie, std::string discount) 
    : _name(name), _price(price), _categorie(categorie), _discount(discount) {}

std::string Item::getName() const {
    return this->_name;
}

double Item::getPrice() const {
    return this->_price;
}

double Item::getBestDiscount() const {
    // if (this->_categorie == nullptr)
    //     return std::stoi(_discount.substr(0, _discount.find_last_of("0123456789")+1));
    return 0;
}

IDiscount* Item::getCategorie() const {
    return this->_categorie;
}

void Item::setName(std::string newName) {
    this->_name = newName;
}

void Item::setPrice(double newPrice) {
    this->_price = newPrice;
}

void Item::setCategorie(IDiscount* newCategorie) {
    this->_categorie = newCategorie;
}