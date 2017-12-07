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
using namespace std;
#include "gagnaklasar.hpp"

void vista_voru(vara afhending) {
    ofstream myfile;
    myfile.open ("vorur.txt", ios::app);
    myfile << afhending.nafn << "\t" << afhending.verd << endl;
    myfile.close();
    return;
}

#endif /* GAGNALAG_H */
