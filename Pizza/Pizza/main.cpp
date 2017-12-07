//
//  main.cpp
//  Pizza
//
//  Created by Lara Kristinsdottir on 07/12/2017.
//  Copyright © 2017 Lara Kristinsdottir. All rights reserved.
//

#include <iostream>
#include <string>

int main(int argc, const char * argv[]) {
    // insert code here...
    if(1 == argc) {
        std::cout << "Vantar skipun.\n";
        return 1;
    }
    
    if(0 == strncmp("skra", argv[1], 4)) {
        return 0;
    }
    
    std::cout << "Skipun óþekkt.\n";
    return 2;
}
