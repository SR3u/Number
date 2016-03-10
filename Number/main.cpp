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
    Number n(.9),m("13");
    std::cout <<(m%n)<<'\n';
    return 0;
}
