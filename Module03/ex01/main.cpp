

#include <iostream>

#include "Command.hpp"
#include "TuesdayDiscount.hpp"
#include "PackageReductionDiscount.hpp"
int main()
{
    // Command test(1, "03/11/2025", "Immersiv", "Apple", 2);

    TuesdayDiscountCommand test(1, "04/11/2025", "Immersiv", "Apple", 2);
    PackageReductionDiscountCommand test1(1, "04/11/2025", "Immersiv", "Apple", 200);

    test.getTotalPrice();
    test1.getTotalPrice();

    return (0);
}