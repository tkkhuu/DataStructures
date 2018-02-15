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
    
    string zeroth_in_string[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string tenth_in_string[] = {"ten", "eleven", "twelve","thirteen", "fourteenth", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string unit_string[] = {"hundred", "thousand"};
    
    string result = "";
    
    uint64_t temp_value = _value;
    uint64_t zeroth_unit = (temp_value / 1) % 10;
    uint64_t tenth_unit = (temp_value / 10) % 10;

    if (tenth_unit != 0)
    {
        switch (tenth_unit)
        {
            case 1:
                result = tenth_in_string[zeroth_unit];
                break;
            case 2:
                result = "twenty" + ((zeroth_unit == 0) ? "" : "-" + zeroth_in_string[zeroth_unit]);
                break;
            case 3:
                result = "thirty" + ((zeroth_unit == 0) ? "" : "-" + zeroth_in_string[zeroth_unit]);
                break;
            case 4:
                result = "fourty" + ((zeroth_unit == 0) ? "" : "-" + zeroth_in_string[zeroth_unit]);
                break;
            case 5:
                result = "fifty" + ((zeroth_unit == 0) ? "" : "-" + zeroth_in_string[zeroth_unit]);
                break;
            case 6:
                result = "sixty" + ((zeroth_unit == 0) ? "" : "-" + zeroth_in_string[zeroth_unit]);
                break;
            case 7:
                result = "seventy" + ((zeroth_unit == 0) ? "" : "-" + zeroth_in_string[zeroth_unit]);
                break;
            case 8:
                result = "eighty" + ((zeroth_unit == 0) ? "" : "-" + zeroth_in_string[zeroth_unit]);
                break;
            case 9:
                result = "ninety" + ((zeroth_unit == 0) ? "" : "-" + zeroth_in_string[zeroth_unit]);
        }
        
    }
    else
    {
        result = zeroth_in_string[zeroth_unit] + result;
    }
    
    uint64_t unit_counter = 100;
    int unit_int_string = 0;
    while (temp_value / unit_counter > 0)
    {
        if (unit_counter == 100 && (zeroth_unit || tenth_unit)) result = "and " + result;
        int unit_value = (temp_value / unit_counter) % 10;
        if(unit_value > 0) result = zeroth_in_string[unit_value] + " " + unit_string[unit_int_string] + " " + result;
        unit_counter *= 10;
        unit_int_string++;
    }
    
    return result;
}
