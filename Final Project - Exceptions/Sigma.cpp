#include "Sigma.h"
#include <stdexcept>
#include <iostream>
#include <string>

unsigned long sigma(unsigned long n) {
    unsigned long sum = 0;
    
    try {
        if (n < 1) {
            std::string errMsg = "Precondition n>=1 violated; invalid value for argument n: " 
                                 + std::to_string(n) + " (Loc: " + __FILE__ + ":" 
                                 + std::to_string(__LINE__) + ")";
            throw std::runtime_error(errMsg);
        }

        for (unsigned long i = 1; i < n; ++i) {  
            sum += i;
        }

        if (sum != n * (n + 1) / 2) {
            std::string errMsg = "Postcondition sum == (n(n+1)/2) violated: sum: " 
                                 + std::to_string(sum) + "; n(n+1)/2: " + std::to_string(n * (n + 1) / 2)
                                 + " (Loc: " + __FILE__ + ":" + std::to_string(__LINE__) + ")";
            throw std::runtime_error(errMsg);
        }
    } catch (const std::runtime_error& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
        std::cerr << "Cannot compute sum, returning 0" << std::endl;
        sum = 0;  
    }

    return sum;
}
