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

double Item::getFinalDiscount(int quantity) const {
    std::string dis = _discount;

    if (dis.find('+') != dis.npos) {
        int bought = stoi(dis.substr(0, dis.find('+')));
        int promo = stoi(dis.substr(dis.find('+') + 1));
        int extra = (quantity / (bought + promo)) * promo;
        return extra * _price;
    }

    int percent = stoi(dis.substr(0, dis.find('%')));
    int discount = std::max(percent, _categorie->getBestDiscount());
    return ((quantity * _price * discount)/100);
}

double Item::getFinalPrice(int quantity) const {
    std::string dis = _discount;

    if (dis.find('+') != dis.npos) {
        int bought = stoi(dis.substr(0, dis.find('+')));
        int promo = stoi(dis.substr(dis.find('+') + 1));
        int extra = (quantity / (bought + promo)) * promo;
        return (quantity * _price) - (extra * _price);
    }

    int percent = stoi(dis.substr(0, dis.find('%')));
    int discount = std::max(percent, _categorie->getBestDiscount());
    return ((quantity * _price) - ((quantity * _price * discount)/100));
}


