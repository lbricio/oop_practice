#pragma once

#include <math.h>
#include <stdlib.h>

class IDiscount {
public:
    virtual ~IDiscount() = default;

    virtual int getDiscount() const = 0;
    virtual int getBestDiscount() const = 0;
    virtual IDiscount* getParent() const = 0;
    virtual void setDiscount(int newDiscount) = 0;
};


class Categorie : public IDiscount
{
private:
    int _discount;
    IDiscount* _parentCategorie;

public:
    Categorie(int discount);
    Categorie(int discount, IDiscount* parent);
    ~Categorie() override = default;

    IDiscount* getParent() const override;
    int getBestDiscount() const override ;

    int getDiscount() const override;
    void setDiscount(int newDiscount) override;
};
