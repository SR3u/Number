//
//  Number.cpp
//  Number
//
//  Created by Sergey Rump (SPHERE) on 10.03.2016.
//  Copyright © 2016 marasm. All rights reserved.
//
#include "Number.h"
#include <math.h>
#include <sstream>
#include <float.h>
String Number::delimiter=".";
Number::~Number(void){}
Number::Number(int newValue)
{
    m=newValue;
    e=0;
    trim();
}
Number::Number(int64_t newValue)
{
    m=newValue;
    e=0;
    trim();
}
Number::Number(const int64_t& M,const int64_t& E){m=M;e=E;trim();}
Number::Number(double d)
{
    std::stringstream ss;
    ss<<d;
    Number n=Number(ss.str());
    m=n.m;
    e=n.e;
}
Number::Number(const Number& n){m=n.m;e=n.e;}
String Number::toString(void) const
{
    std::stringstream ss;
    ss<<m;
    if(e!=0){ss<<"e"<<e;}
    return ss.str();
}
Number::Number(String num)
{
    std::transform(num.begin(), num.end(), num.begin(), ::tolower);
    if(num.find('e')!=String::npos)
    {
        size_t eidx=num.find('e');
        String N,E;
        N=num.substr(0,eidx);
        E=num.substr(eidx+1,num.length()-1);
        Number n(N);
        m=n.m;
        e=n.e+std::stoll(E);
    }
    else
    {
        size_t dotidx=num.find(delimiter);
        String R,D="";
        if(dotidx!=String::npos && dotidx<(num.length()-1))
        {
            R=num.substr(0,dotidx);
            D=num.substr(dotidx+1,num.length()-1);
        }else{R=num;}
        D.erase ( D.find_last_not_of('0') + 1, std::string::npos );
        if(D.length()==0)
        {
            size_t oldLen=R.length();
            R.erase ( R.find_last_not_of('0') + 1, std::string::npos );
            e=oldLen-R.length();
            m=std::stoll(R);
        }
        else
        {
            R=R+D;
            e=-D.length();
            m=std::stoll(R);
        }
    }
}
void Number::trim()
{
    if(m==0){return;}
    while(m%10==0)
    {
        m/=10;
        e++;
    }
}
bool Number::operator==(const Number&n)const{return m==n.m&&e==n.e;}
bool Number::operator!=(const Number&n)const{return m!=n.m||e!=n.e;}
bool Number::operator<(const Number&n) const
{
    if(n.e>e){return true;}
    if(n.m>m)
    {
        if(n.e==e){return true;}
    }
    return false;
}
bool Number::operator>(const Number&n) const
{
    if(n.e<e){return true;}
    if(n.m<m)
    {
        if(n.e==e){return true;}
    }
    return false;
}
bool Number::operator<=(const Number&n)const{return!((*this)>n);}
bool Number::operator>=(const Number&n)const{return!((*this)<n);}
Number Number::operator*(const Number&n)const
{
    Number r;
    r.e=e+n.e;
    r.m=m*n.m;
    r.trim();
    return r;
}