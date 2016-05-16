#include "HugeInt.h"
#include <iostream>
#include <string>
#include <sstream>

istream & operator>>(istream &in, HugeInt &input){
    in >> input.numString;
    return in;
}

ostream & operator<<(ostream &out, const HugeInt &output){
    out << output.numString;
    return out;
}

HugeInt::HugeInt(int i){
    stringstream ss;
    ss << i;
    numString = ss.str();
}

void HugeInt::operator=(HugeInt right){
    numString = right.numString;
}

string HugeInt::operator+(HugeInt right){
    string numString1 = numString;
    string numString2 = right.numString;
    string sum = "";
    int i, tmp;

    int size_difference = numString1.length() - numString2.length();
    if(size_difference < 0) size_difference *= -1;

    if(numString1.length() > numString2.length())
        for(i=0; i<size_difference; ++i) numString2 = '0' + numString2;
    else
        for(i=0; i<size_difference; ++i) numString1 = '0' + numString1;

    int carry = 0;
    for(i=numString1.length()-1; i>=0; --i){
        tmp = (numString1[i] - '0') + (numString2[i] - '0') + carry;
        sum = static_cast<char>((tmp % 10 + '0')) + sum;
        carry = tmp / 10;
    }

    if(carry) sum = static_cast<char>(carry + '0') + sum;

    return sum;
}

string HugeInt::operator-(HugeInt right){
    string numString1 = numString;
    string numString2 = right.numString;
    string subtract = "";
    int i, tmp;

    int size_difference = numString1.length() - numString2.length();
    if(size_difference < 0) size_difference *= -1;

    if(numString1.length() > numString2.length())
        for(i=0; i<size_difference; ++i) numString2 = '0' + numString2;
    else
        for(i=0; i<size_difference; ++i) numString1 = '0' + numString1;

    int borrow = 0;
    string big, small;

    for(i=0; i<=numString1.length()-1; ++i){
        if((numString1[i] - '0') > (numString2[i] - '0')){
            big = numString1;  small = numString2;
            break;
        }
        else if((numString1[i] - '0') < (numString2[i] - '0')){
            big = numString2;  small = numString1;
            break;
        }
        else{
            if(i==numString1.length()-1){
                big = numString1;  small = numString2;
            }
        }
    }

    for(i=numString1.length()-1; i>=0; --i){
        tmp = (big[i] - '0') - (small[i] - '0') - borrow;
        if(tmp<0){
            subtract = static_cast<char>(((tmp+10) + '0')) + subtract;
            borrow = 1;
        }
        else{
            subtract = static_cast<char>((tmp + '0')) + subtract;
            borrow = 0;
        }
    }

    int zero=0;
    for(i=0; i<=numString1.length()-1; ++i){
        if(subtract[i]=='0') zero++;
        else break;
    }
    if(zero!=0){
        if(zero == numString1.length()) subtract = "0";
        else{
            for(i=0; i<numString1.length(); ++i){
                if(i<numString1.length()-zero) subtract[i] = subtract[i+zero];
                else subtract[i] = '\0';
            }
        }
    }

    if(big==numString2 && numString1!=numString2)  return ('-' + subtract);
    else  return subtract;
}
