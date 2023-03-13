#include <iostream>
#include "Dual.h"

ad::Dual f(ad::Dual x) {
    ad::Dual c(0.5, 0.0);
    return x^c;
}

int main() {
    ad::Dual x(2.0, 1.0); 
    auto y = f(x);

    std::cout << "Value for f(x): " << y.value << std::endl;
    std::cout << "f'(x) at x = 2: " << y.derivative << std::endl;
    return 0;
}