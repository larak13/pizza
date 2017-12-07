//
//  gagnalag.h
//  Pizza
//
//  Created by Lara Kristinsdottir on 07/12/2017.
//  Copyright © 2017 Lara Kristinsdottir. All rights reserved.
//

#ifndef GAGNALAG_H
#define GAGNALAG_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#include "gagnaklasar.hpp"

void vista_voru(vara afhending) {
    ofstream myfile;
    myfile.open ("vorur.txt", ios::app);
    myfile << afhending.nafn << "\t" << afhending.verd << endl;
    myfile.close();
    return;
}

vector<vara> lesa_allar_vorur() {
    vara bull;
    bull.nafn = "Bara prufa";
    bull.verd = 42;
    vector<vara> vorur = vector<vara>();
    vorur.push_back(bull);
    vorur.push_back(bull);
    return vorur;
}

#endif /* GAGNALAG_H */
