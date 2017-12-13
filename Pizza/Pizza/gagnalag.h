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

bool vorur_lesnar = false;
vector<vara> vorur = vector<vara>();

void baeta_vid_voru_i_vorur(vara vara) {
    vorur.push_back(vara);
}

bool pantanir_lesnar = false;
vector<pontun> pantanir = vector<pontun>();

void baeta_vid_pontun_i_pantanir(pontun pontun) {
    pantanir.push_back(pontun);
}

vector<vara> lesa_allar_vorur() {
    if(vorur_lesnar) {
        return vorur;
    }
    else {
        vorur_lesnar = true;
    }
    ifstream myfile;
    myfile.open("vorur.txt");
    lesa_vorur(myfile, baeta_vid_voru_i_vorur);
    myfile.close();
    return vorur;
}

void vista_pontun(pontun pontun) {
    vidskiptavinur kunni = pontun.vidskiptavinur;
    ofstream myfile;
    myfile.open ("pantanir.txt", ios::app);
    myfile << pontun.numer << "\t" << pontun.stada << "\t" <<
    kunni.nafn << "\t" << kunni.simanumer << "\t" << kunni.heimilisfang;
    
    for(vara vara: pontun.vorur) {
        myfile << "\t" << vara.nafn << "\t" << vara.verd;
    }
    myfile << endl;
    myfile.close();
    return;
}

vector<pontun> lesa_allar_pantanir() {
    if(pantanir_lesnar) {
        return pantanir;
    }
    else {
        pantanir_lesnar = true;
    }
    ifstream myfile;
    myfile.open("pantanir.txt");
    lesa_pantanir(myfile, baeta_vid_pontun_i_pantanir);
    myfile.close();
    return pantanir;
}

void yfirskrifa_pantanalista(vector<pontun> pantanir) {
    ofstream myfile;
    myfile.open("pantanir.txt", ios::trunc);
    myfile.close();
    for(pontun pontun: pantanir) {
        vista_pontun(pontun);
    }
}

#endif /* GAGNALAG_H */
