#include <iostream>
#include "type-deduction/include/typededuction.h"
int main (int argc, char *argv[]) {
    int x = 27;
    const int y = x;
    const int &z = x;

    TypeDeduction::funcPassByRef(x);
    TypeDeduction::funcPassByRef(y);
    TypeDeduction::funcPassByRef(z);

    std::cout << "Pass by Universal Ref" << std::endl;
    TypeDeduction::funcPassByUniversalRef(x);
    TypeDeduction::funcPassByUniversalRef(y);
    TypeDeduction::funcPassByUniversalRef(z);
    TypeDeduction::funcPassByUniversalRef(27);

    std::cout << "Pass by value" << std::endl;
    TypeDeduction::funcPassByValue(x);
    TypeDeduction::funcPassByValue(y);
    TypeDeduction::funcPassByValue(z);

    TypeDeduction::funcPassByValue("string");
    TypeDeduction::funcPassByRef("string");


}
