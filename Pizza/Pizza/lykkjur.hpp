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

void lesa_pantanir(istream &inntak, void (*fall)(pontun)) {
    string line;
    pontun pontun;
    while(getline(inntak, line)) {
        stringstream straumur(line);
        string numer;
        string stada;
        straumur >> numer >> stada;
        pontun.numer = numer;
        pontun.stada = stada;
        string nafn, simanumer, heimilisfang;
        straumur >> nafn >> simanumer >> heimilisfang;
        vidskiptavinur kunni;
        kunni.nafn = nafn;
        kunni.simanumer = simanumer;
        kunni.heimilisfang = heimilisfang;
        pontun.vidskiptavinur = kunni;
        
        pontun.vorur = vector<vara>();

        while(straumur.rdbuf()->in_avail()) {
            string vorunafn;
            int voruverd;
            straumur >> vorunafn >> voruverd;
            vara vara;
            vara.nafn = vorunafn;
            vara.verd = voruverd;
            pontun.vorur.push_back(vara);
        }
        
        fall(pontun);
    }
}

vector<pontun> merkja_pontun(vector<pontun> pantanir, string numer, string stada) {
    // Hver thessara pantana er með númerið $numer?
    // Breyta stöðu hennar í "tilbúin"
    for(int i=0; i<pantanir.size(); i++) {
        if(pantanir[i].numer == numer){
            pantanir[i].stada = stada;
            break;
        }
    }
    return pantanir;
}

#endif /* lykkjur_h */
