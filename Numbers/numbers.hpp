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

namespace Number {
    class AbsNumber
    {
    public:
        virtual string ToWord() const = 0;
    };
    
    class UnsignedInteger : public Number::AbsNumber
    {
        uint64_t _value;
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
