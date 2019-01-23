#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants {
    constexpr double Pi (3.14159);
    constexpr double Avogadro(6.0221413e23);
}

bool apporximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon);
void compareFloatEqual();
void nanAndInf();
void sizeofBool();
void judgePrime();
void setBinary();
void printConstants();
void arithmetic();
void negativeModulus();

#endif
