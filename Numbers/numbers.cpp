//
//  numbers.cpp
//  DataStructures
//
//  Created by Tri Khuu on 2/14/18.
//  Copyright © 2018 TK. All rights reserved.
//

#include "numbers.hpp"
using namespace Number;

UnsignedInteger::UnsignedInteger() : _value(0){}

UnsignedInteger::UnsignedInteger(const uint64_t& value) : _value(value){}

UnsignedInteger::UnsignedInteger(const UnsignedInteger& rhs) : _value(rhs._value){}

UnsignedInteger& UnsignedInteger::operator = (const UnsignedInteger& rhs)
{
    if(this != &rhs)
    {
        _value = rhs._value;
    }
    return *this;
}

UnsignedInteger::~UnsignedInteger(){};

string UnsignedInteger::ToWord() const
{
    if (_value == 0) return "zero";
    if (_value > _max_unsigned_int_word) return "Number too big to be represented in word";
    uint64_t num = _value;
    
    unsigned char power_id = 0;
    
    string result = "";
    
    while(num > 0)
    {
        uint64_t next_three_digit = (num % 1000);
        if (next_three_digit)
        {
            result = _ToWord3Digits(next_three_digit) + _space + _power_num_words[power_id] + _space + result;
        }
        power_id++;
        num /= 1000;
        
    }
    
    return result;
}

// ======== Private Functions ========
string UnsignedInteger::_ToWord3Digits(uint64_t& num) const
{
    if (num > 999) return ""; // TODO: Create custom exception
    
    string result = "";
    
    uint64_t temp_value = num;
    uint64_t single_unit = (temp_value / 1) % 10;
    uint64_t double_unit = (temp_value / 10) % 10;
    uint64_t hundred_unit = (temp_value / 100) % 10;
    
    if (hundred_unit)
    {
        result += _single_num_words[hundred_unit] + " hundred";
    }
    if (double_unit)
    {
        if (hundred_unit) result += _space;
        if(double_unit == 1)
        {
            result += _teen_num_words[single_unit];
            return result;
        }
        else
        {
            result += _double_num_words[double_unit];
        }
    }
    if (single_unit)
    {
        if(double_unit) result +=  _hyphen;
        else if (hundred_unit) result += " and ";
        result += _single_num_words[single_unit];
    }
    
    return result;
}
