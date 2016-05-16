#ifndef HUGEINT_H
#define HUGEINT_H
#include <iostream>
#include <string>

using namespace std;

class HugeInt {
    friend istream & operator>>(istream &, HugeInt &);
    friend ostream & operator<<(ostream &, const HugeInt &);
public:
    HugeInt():numString("0") {}
    HugeInt(string s):numString(s) {}
    HugeInt(int);
    void operator=(HugeInt);
    string operator+(HugeInt);
    string operator-(HugeInt);
private:
    string numString;
};

#endif
