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
    Number n(0.03),m(2);
    // insert code here...
    std::cout <<(n*m).toString()<<"\n";
    return 0;
}
