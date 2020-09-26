#include <iostream>
#include <limits.h>
#include <float.h>
#include <bitset>

void main()
{
    std::cout << "Zmiev Aleksandr Yurievich, 201-352" << std::endl;

    std::cout << std::endl;

    std::cout << "min int = " << INT_MIN
        << ", max int = " << INT_MAX
        << ", size of int = " << sizeof(int) << std::endl;

    std::cout << "min uint = " << 0
        << ", max uint = " << UINT_MAX
        << ", size of uint = " << sizeof(unsigned int) << std::endl;

    std::cout << "min short = " << SHRT_MIN
        << ", max short = " << SHRT_MAX
        << ", size of short = " << sizeof(short) << std::endl;

    std::cout << "min ushort = " << 0
        << ", max ushort = " << USHRT_MAX
        << ", size of ushort = " << sizeof(unsigned short) << std::endl;

    std::cout << "min long = " << LONG_MIN
        << ", max long = " << LONG_MIN
        << ", size of long = " << sizeof(long) << std::endl;

    std::cout << "min long long = " << LLONG_MIN
        << ", max long long = " << LLONG_MAX
        << ", size of long long = " << sizeof(long long) << std::endl;

    std::cout << "min double = " << DBL_MIN
        << ", max double = " << DBL_MAX
        << ", size of double = " << sizeof(double) << std::endl;

    std::cout << "min char = " << CHAR_MIN
        << ", max char = " << CHAR_MAX
        << ", size of char = " << sizeof(char) << std::endl;

    std::cout << "min bool = " << bool(0)
        << ", max bool = " << bool(1)
        << ", size of bool = " << sizeof(bool) << std::endl;

    std::cout << std::endl;

    int digit;
    std::cout << "input: ";
    std::cin >> digit;
    std::cout << "bin: " << std::bitset<16>(digit) << "\n"
        << "hex: " << std::hex << digit << "\n"
        << "bool: " << bool(digit) << "\n"
        << "double: " << double(digit) << "\n"
        << "char: " << char(digit) << std::endl;

    std::cout << std::endl;

    int a, b;
    std::cout << "enter a and b: a * x = b: ";
    std::cin >> a >> b;
    std::cout << "x: " << float(b) / float(a) << std::endl;

    std::cout << std::endl;

    int x1, x2;
    std::cout << "enter coordinates: ";
    std::cin >> x1 >> x2;
    std::cout << "centre: " << float(x1 + x2) / 2 << std::endl;
}