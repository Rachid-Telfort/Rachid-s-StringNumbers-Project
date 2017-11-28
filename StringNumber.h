#ifndef STRINGNUMBER_H_INCLUDED
#define STRINGNUMBER_H_INCLUDED

#include<cctype>
#include<cstring>
#include<iostream>
#include<stdexcept>
#include<string>
#include<utility>

class StringNumber
{
    private:
        std::string operand;

    public:
        StringNumber();
        StringNumber(const long long int);
        StringNumber(const char* const);
        StringNumber(const std::string&);
        StringNumber(const StringNumber&);
        ~StringNumber();
        const std::string toBinary() const;
        const std::string toOctal() const;
        const std::string toHex() const;
        const StringNumber operator++(int);///Postfix increment operator.
        const StringNumber operator--(int);///Postfix decrement operator.
        const StringNumber& operator++();
        const StringNumber& operator--();
        const StringNumber operator+() const;
        const StringNumber operator-() const;
        const StringNumber operator~() const;
        const StringNumber operator*(const StringNumber&) const;
        const StringNumber operator/(const StringNumber&) const;
        const StringNumber operator%(const StringNumber&) const;
        const StringNumber operator+(const StringNumber&) const;
        const StringNumber operator-(const StringNumber&) const;
        friend std::istream& operator>>(std::istream&, StringNumber&);
        friend std::ostream& operator<<(std::ostream&, const StringNumber&);
        const StringNumber operator<<(const StringNumber&) const;///Bitwise left shift operator.
        const StringNumber operator>>(const StringNumber&) const;///Bitwise right shift operator.
        const bool operator<(const StringNumber&) const;
        const bool operator>(const StringNumber&) const;
        const bool operator<=(const StringNumber&) const;
        const bool operator>=(const StringNumber&) const;
        const bool operator==(const StringNumber&) const;
        const bool operator!=(const StringNumber&) const;
        const StringNumber operator&(const StringNumber&) const;
        const StringNumber operator^(const StringNumber&) const;
        const StringNumber operator|(const StringNumber&) const;
        const StringNumber& operator=(const StringNumber&);
        const StringNumber& operator*=(const StringNumber&);
        const StringNumber& operator/=(const StringNumber&);
        const StringNumber& operator%=(const StringNumber&);
        const StringNumber& operator+=(const StringNumber&);
        const StringNumber& operator-=(const StringNumber&);
        const StringNumber& operator<<=(const StringNumber&);
        const StringNumber& operator>>=(const StringNumber&);
        const StringNumber& operator&=(const StringNumber&);
        const StringNumber& operator^=(const StringNumber&);
        const StringNumber& operator|=(const StringNumber&);
};

const StringNumber absoluteValue(const StringNumber&);
const StringNumber exponent(const StringNumber&, const long long int);
const StringNumber exponent(const StringNumber&, const char* const);
const StringNumber exponent(const StringNumber&, const std::string&);
const StringNumber exponent(const StringNumber&, const StringNumber&);
const std::pair<const StringNumber, const StringNumber> nthRoot(const StringNumber&, const long long int);///The nth root function returns the floor of the nth root of the first argument. A pair is returned because for even roots, both the positive and negative root can get to the original String Number by exponentiation.
const std::pair<const StringNumber, const StringNumber> nthRoot(const StringNumber&, const char* const);///The nth root function returns the floor of the nth root of the first argument. A pair is returned because for even roots, both the positive and negative root can get to the original String Number by exponentiation.
const std::pair<const StringNumber, const StringNumber> nthRoot(const StringNumber&, const std::string&);///The nth root function returns the floor of the nth root of the first argument. A pair is returned because for even roots, both the positive and negative root can get to the original String Number by exponentiation.
const std::pair<const StringNumber, const StringNumber> nthRoot(const StringNumber&, const StringNumber&);///The nth root function returns the floor of the nth root of the first argument. A pair is returned because for even roots, both the positive and negative root can get to the original String Number by exponentiation.
const StringNumber factorial(const StringNumber&);

#endif///STRINGNUMBER_H_INCLUDED
