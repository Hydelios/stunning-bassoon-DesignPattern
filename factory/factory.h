//
// Created by Hydelios on 2021/3/26.
//

#ifndef DESIGNPATTERN_FACTORY_H
#define DESIGNPATTERN_FACTORY_H
#include "product.h"

class Factory
{
public:
    static Product* creatProduct(Producttype type)
    {
        switch (type)
        {
            case Product_typeA:
                return new AProduct;
            case Product_typeB:
                return new BProduct;
            default:
                return nullptr;
        }
    }
};

#endif //DESIGNPATTERN_FACTORY_H
