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
#include "vinnslulag.hpp"

int main(int argc, const char * argv[]) {
    vara vara_innan_lykkju;
    
    if(1 == argc) {
        std::cout << "Vantar skipun.\n";
        return 1;
    }
    
    if(0 == strncmp("vara", argv[1], 4)) {
        std::string line;
        while(std::getline(std::cin, line)) {
            std::stringstream straumur(line);
            std::string nafn, verd_strengur;
            int verd;
            straumur >> nafn >> verd;
            vara_innan_lykkju.nafn = nafn;
            vara_innan_lykkju.verd = verd;
            skra_voru(vara_innan_lykkju);
        }
        
        return 0;
    }
    else if (0 == strncmp("panta", argv[1], 5)) {
        return 0;
    }
    
    std::cout << "Skipun óþekkt.\n";
    return 2;
}
