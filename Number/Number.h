//
//  Number.h
//  Number
//
//  Created by Sergey Rump (SPHERE) on 10.03.2016.
//  Copyright © 2016 marasm. All rights reserved.
//

#ifndef Number_h
#define Number_h
#include <string>
typedef std::string String;
class Number
{
    int64_t m;
    int64_t e;
    bool nan=false;
public:
    static String delimiter;
    
    Number(int64_t newValue=0);
    Number(int newValue);
    Number(double d);
    Number(const Number& n);
    Number(const int64_t& M,const int64_t& E);
    Number(String num);
    virtual ~Number(void);
    
    Number operator-()const;
    
    Number operator+(const Number&)const;
    Number operator-(const Number&)const;
    Number operator*(const Number&)const;
    Number operator/(const Number&)const;
    
    Number operator+=(const Number&);
    Number operator-=(const Number&);
    Number operator*=(const Number&);
    Number operator/=(const Number&);
    
    Number floor()const;
    Number ceiling()const;
    
    bool operator==(const Number&) const;
    bool operator!=(const Number&) const;
    bool operator<(const Number&) const;
    bool operator<=(const Number&) const;
    bool operator>(const Number&) const;
    bool operator>=(const Number&) const;
    
    void trim(void);
    
    String toString(void) const;
    double toDouble(void) const;
    
    static Number ZERO;
    static Number ONE;
private:
};
#endif /* Number_h */
