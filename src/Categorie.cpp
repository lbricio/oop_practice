#include "Categorie.hpp"

Categorie::Categorie(int discount) : _discount(discount), _parentCategorie(nullptr) {}

Categorie::Categorie(int discount, IDiscount* parent) : _discount(discount), _parentCategorie(parent) {}

IDiscount* Categorie::getParent() const {
    return _parentCategorie;
}
 
int Categorie::getDiscount() const {
    return _discount;
}

int Categorie::getBestDiscount() const {
    int bestDiscount = this->getDiscount();
    const IDiscount* curr = this;

    while(curr != nullptr) {
        bestDiscount = std::max(bestDiscount, curr->getDiscount());
        curr = curr->getParent();
    }
    return bestDiscount;
}

void Categorie::setDiscount(int newDiscount) {
    _discount = newDiscount;
}