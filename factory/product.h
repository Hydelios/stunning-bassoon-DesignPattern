//
// Created by Hydelios on 2021/3/26.
//

#ifndef DESIGNPATTERN_PRODUCT_H
#define DESIGNPATTERN_PRODUCT_H
#include <iostream>
using namespace std;

enum Producttype
{
    Product_typeA,
    Product_typeB
};

class Product
{
public:
    virtual void myproduct()=0;
};

class AProduct: public Product
{
public:
    virtual void myproduct() override {cout<<"this is A product.";}
};

class BProduct: public Product
{
public:
    virtual void myproduct() override {cout<<"this is B product.";}
};

#endif //DESIGNPATTERN_PRODUCT_H
