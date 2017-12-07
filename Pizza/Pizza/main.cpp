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
using namespace std;
#include "gagnaklasar.hpp"
#include "vinnslulag.hpp"

int main(int argc, const char * argv[]) {
    vara vara_innan_lykkju;
    
    if(1 == argc) {
        cout << "Vantar skipun.\n";
        return 1;
    }
    
    if(0 == strncmp("vara", argv[1], 4)) {
        string line;
        while(getline(cin, line)) {
            stringstream straumur(line);
            string nafn, verd_strengur;
            int verd;
            straumur >> nafn >> verd;
            vara_innan_lykkju.nafn = nafn;
            vara_innan_lykkju.verd = verd;
            skra_voru(vara_innan_lykkju);
        }
        
        return 0;
    }
    else if (0 == strncmp("panta", argv[1], 5)) {
        vector<vara> vorur = fa_allar_vorur();
        int vorunumer = 1;
        for (auto valmoguleiki : vorur) {
            cout << "[" << vorunumer++ << "] " << valmoguleiki.nafn << " kostar " << valmoguleiki.verd << "kr." << endl;
        }
        cerr << "Hvaða vöru má bjóða þér?" << endl;
        cerr << "Sláðu inn vörunúmer (og ýttu á enter): ";
        unsigned int val;
        cin >> val;
        cerr << "Þú valdir: " << val << endl;
        vara valin_vara = vorur[val-1];
        cerr << valin_vara.nafn << endl;
        return 0;
    }
    
    cout << "Skipun óþekkt.\n";
    return 2;
}
