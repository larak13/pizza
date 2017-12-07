//
//  main.cpp
//  Pizza
//
//  Created by Lara Kristinsdottir on 07/12/2017.
//  Copyright © 2017 Lara Kristinsdottir. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include "gagnaklasar.hpp"

int main(int argc, const char * argv[]) {
    vara vara_innan_lykkju;
    
    if(1 == argc) {
        std::cout << "Vantar skipun.\n";
        return 1;
    }
    
    if(0 == strncmp("skra", argv[1], 4)) {
        std::string line;
        while(std::getline(std::cin, line)) {
            std::stringstream straumur(line);
            std::string nafn, verd_strengur;
            straumur >> nafn >> verd_strengur;
            vara_innan_lykkju.nafn = nafn;
        }
        
        std::cout << vara_innan_lykkju.nafn << std::endl;
        
        return 0;
    }
    
    std::cout << "Skipun óþekkt.\n";
    return 2;
}
