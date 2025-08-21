#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Categorie.hpp"

class IItem
{
public:
    virtual ~IItem() = default;

    virtual std::string getName() const = 0;
    virtual IDiscount* getCategorie() const = 0;
    virtual double getPrice() const = 0;
    virtual void setName(std::string newName) = 0;
    virtual void setPrice(double newPrice) = 0;
    virtual void setCategorie(IDiscount* newCategorie) = 0;
    virtual double getBestDiscount() const = 0;
    virtual double getFinalPrice(int quantity) const = 0;
    virtual double getFinalDiscount(int quantity) const = 0;
};

class Item : public IItem
{
private:
    double _price;
    std::string _name;
    std::string _discount;
    IDiscount* _categorie;

public:
    Item(std::string name, double price, IDiscount* categorie, std::string discount);
    ~Item() override = default;

    std::string getName() const override;
    IDiscount* getCategorie() const override;
    double getPrice() const override;
    void setName(std::string newName) override;
    void setPrice(double newPrice) override;
    void setCategorie(IDiscount* newCategorie) override;
    double getBestDiscount() const override;
    double getFinalPrice(int quantity) const override;
    double getFinalDiscount(int quantity) const override;
};
