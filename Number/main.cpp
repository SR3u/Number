//
//  main.cpp
//  Number
//
//  Created by Sergey Rump (SPHERE) on 10.03.2016.
//  Copyright © 2016 marasm. All rights reserved.
//

#include <iostream>
#include "Number.h"

int main(int argc, const char * argv[])
{
    Number n(0.1),m("100.09");
    m++;
    // insert code here...
    std::cout <<++m<<"\n";
    m--;
    std::cout <<--m<<"\n";
    return 0;
}
