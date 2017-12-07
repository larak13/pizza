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
#include "lykkjur.hpp"

void vista_voru(vara afhending) {
    ofstream myfile;
    myfile.open ("vorur.txt", ios::app);
    myfile << afhending.nafn << "\t" << afhending.verd << endl;
    myfile.close();
    return;
}

vector<vara> vorur = vector<vara>();

void baeta_vid_voru_i_vorur(vara vara) {
    vorur.push_back(vara);
}

vector<vara> lesa_allar_vorur() {
    ifstream myfile;
    myfile.open("vorur.txt");
    lesa_vorur(myfile, baeta_vid_voru_i_vorur);
    myfile.close();
    return vorur;
}

void vista_pontun(pontun pontun) {
    vidskiptavinur kunni = pontun.vidskiptavinur;
    vara vara = pontun.vorur[0];
    ofstream myfile;
    myfile.open ("pantanir.txt", ios::app);
    myfile << kunni.nafn << "\t" << kunni.simanumer << "\t" << kunni.heimilisfang << "\t" <<
    vara.nafn << "\t" << vara.verd << endl;
    myfile.close();
    return;
}

#endif /* GAGNALAG_H */
