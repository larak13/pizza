//
//  lykkjur.hpp
//  Pizza
//
//  Created by Lara Kristinsdottir on 07/12/2017.
//  Copyright © 2017 Lara Kristinsdottir. All rights reserved.
//

#ifndef lykkjur_h
#define lykkjur_h

void lesa_vorur(istream &inntak, void (*fall)(vara)) {
    string line;
    vara vara_innan_lykkju;
    while(getline(inntak, line)) {
        stringstream straumur(line);
        string nafn, verd_strengur;
        int verd;
        straumur >> nafn >> verd;
        vara_innan_lykkju.nafn = nafn;
        vara_innan_lykkju.verd = verd;
        fall(vara_innan_lykkju);
    }
}

#endif /* lykkjur_h */
