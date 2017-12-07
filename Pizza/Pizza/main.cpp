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
#include "lykkjur.hpp"

vara taka_vid_pontun();
vidskiptavinur spyrja_til_nafns();

int main(int argc, const char * argv[]) {
    
    if(1 == argc) {
        cout << "Vantar skipun.\n";
        return 1;
    }
    
    if(0 == strncmp("vara", argv[1], 4)) {
        lesa_vorur(cin, skra_voru);
        
        return 0;
    }
    else if (0 == strncmp("panta", argv[1], 5)) {
        pontun pontun_vidskiptavinar;
        pontun_vidskiptavinar.vidskiptavinur = spyrja_til_nafns();
        pontun_vidskiptavinar.vorur = vector<vara> { taka_vid_pontun() };
        
        panta(pontun_vidskiptavinar);
        return 0;
    }
    
    cout << "Skipun óþekkt.\n";
    return 2;
}

vidskiptavinur spyrja_til_nafns() {
    vidskiptavinur kunni;
    string nafn, simanumer, heimilisfang;
    
    cerr << "Nafn: ";
    cin >> nafn;
    kunni.nafn = nafn;
    
    cerr << "Símanúmer: ";
    cin >> simanumer;
    kunni.simanumer = simanumer;
    
    cerr << "Heimilisfang: ";
    cin >> heimilisfang;
    kunni.heimilisfang = heimilisfang;
    
    return kunni;
}

vara taka_vid_pontun() {
    vector<vara> vorur = fa_allar_vorur();
    cerr << endl;
    int vorunumer = 1;
    for (auto valmoguleiki : vorur) {
        cout << "[" << vorunumer++ << "] " << valmoguleiki.nafn << " kostar " << valmoguleiki.verd << "kr." << endl;
    }
    cerr << endl;
    cerr << "Hvaða vöru má bjóða þér?" << endl;
    cerr << "Sláðu inn vörunúmer (og ýttu á enter): ";
    unsigned int val;
    cin >> val;
    cerr << "Þú valdir vöru númer " << val << ". ";
    vara valin_vara = vorur[val-1];
    cerr << "Hún heitir " << valin_vara.nafn << "." << endl;
    return valin_vara;
}
