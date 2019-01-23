#include <iostream>
#include <cstdint>
#include <iomanip>
#include <cmath>
#include "const.h"
//using namespace std;

int main(void){
    //2.10 Quiz 3
    //arithmetic();
    //2.10 Quiz 4

    negativeModulus();


    //printConstants();
    //setBinary();
    //judgePrime();
    //sizeofBool();
    //nanAndInf();
    //compareFloatEqual();
    return 0;
}

void negativeModulus() {
    std::cout << "-5 % 2 = " << -5 % 2 << std::endl;
    std::cout << "5 % -2 = " << 5 % -2 << std::endl;
    std::cout << "5 / -2 = " << 5 / -2 << std::endl;
    std::cout << "-5 / 2 = " << -5 / 2 << std::endl;
}

void arithmetic() {
    double a;
    double b;
    std::cout << "Input first number: " ;
    std::cin >> a ;
    std::cout << "Input second number: " ;
    std::cin >> b ;

    char opt;
    double result(0.0);
    std::cout << "Input an operator of four arithmetics: " ;
    std::cin >> opt;
    switch (opt) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (apporximatelyEqualAbsRel(b, 0.0, 1e-12, 1e-8)) {
                std::cout << "The divisor is 0.0" << std::endl;
                return;
            } else {
                result = a / b;
            }
            break;
        default:
            std::cout << "Wrong operator " << opt << std::endl;
            return;
    }
    std::cout << "Result: of " << a << opt << b << " is " << result << std::endl;
}

void printConstants() {
    char a(97);
    std::cout << static_cast<int>(a) << std::endl;

    std::cout << "Pi: " << constants::Pi << std::endl;
    std::cout << "Avogadro: " << constants::Avogadro << std::endl;
}


void setBinary() {
    int binary;
    binary = 0b110'11001'0001'0101'1100;
    std::cout << "the value of " << std::bitset<30>(binary) << " is " << binary << std::endl;
}

void judgePrime() {
    int input;
    std::cout << "Enter a prime number:" << std::endl;
    std::cin >> input;
    bool isPrime = true;
    //check if it's prime number
    for (int i = 2; i<= sqrt(input) ; i++ ) {
       if (input % i == 0) {
           isPrime = false;
           break;
       }
    }
    if (isPrime) {
        std::cout << input << " is prime." << std::endl;
    } else {
        std::cout << input << " is not prime!" << std::endl;
    }
}

void sizeofBool() {
    bool flg = false;
    std::cout << "size of boolean is " << sizeof(bool) << " byte" << std::endl;
    std::cout << std::boolalpha;
    std::cout << flg << std::endl;
    std::cout << std::noboolalpha;
}

void nanAndInf() {
    double zero = 0.0;
    double positiveInf = 1.0 / zero; //positive infinity
    std::cout << "positive infinity is " << positiveInf << std::endl;
    double negativeInf = -1.0 / zero; //negative infinity
    std::cout << "negative infinity is " << negativeInf << std::endl;

    double nan = zero / zero; //not a number (mathematically invalid)
    std::cout << "NaN is " << nan << std::endl;
}

void compareFloatEqual() {
    std::cout << std::setprecision(20);
    float f = 0.123456789012f;
    double d = 0.1234567890123456789;
    std::cout << f << std::endl;
    std::cout << d << std::endl;

    double a = 0.1 + 0.1 + 0.1  + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1;
    double b = 1.0;
    if (apporximatelyEqualAbsRel(a, b, 1e-12, 1e-8)) {
        std::cout << "a ~= b" << std::endl;
    } else {
        std::cout << "a !~= b" << std::endl;
    }
}

bool apporximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon) {
    double diff = fabs(a-b);
    if (diff <= absEpsilon)
        return true;

    return diff <= ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * relEpsilon);
}

