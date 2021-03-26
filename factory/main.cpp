#include <iostream>
#include "factory.h"

int main() {
    Factory factory;
    Product* productA;
    Product* productB;
    productA=factory.creatProduct(Product_typeA);
    productA->myproduct();

    productB=factory.creatProduct(Product_typeB);
    productB->myproduct();

    return 0;
}
