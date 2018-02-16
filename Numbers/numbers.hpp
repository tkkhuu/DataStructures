//
//  numbers.hpp
//  DataStructures
//
//  Created by Tri Khuu on 2/14/18.
//  Copyright © 2018 TK. All rights reserved.
//

#ifndef numbers_hpp
#define numbers_hpp

#include <cstdint>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

namespace Number
{
    static const uint64_t _max_unsigned_int_word = 999999999999999999;
    
    static const string _single_num_words[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    static const string _teen_num_words[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    
    static const string _double_num_words[] = {"", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    
    static const string _power_num_words[] = {"", "thousand", "million", "billion", "trillion", "quadrillion"};
    
    static const string _hyphen = "-";
    
    static const string _space = " ";
    
    class AbsNumber
    {
    public:
        virtual string ToWord() const = 0;
    };
    
    class UnsignedInteger : public Number::AbsNumber
    {
        uint64_t _value;
        
        // Convert a number with less than or equal to 3 digits to words
        string _ToWord3Digits(uint64_t&) const;
    public:
        UnsignedInteger();
        UnsignedInteger(const uint64_t&);
        UnsignedInteger(const UnsignedInteger&);
        ~UnsignedInteger();
        
        UnsignedInteger& operator = (const UnsignedInteger&);
        string ToWord() const;
        
    };
};

#endif /* numbers_hpp */
