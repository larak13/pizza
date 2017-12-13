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

void birta_pantanalista() {
    auto pantanir = fa_allar_pantanir();
    for(pontun pontun: pantanir) {
        cout << pontun.vidskiptavinur.nafn << " pantaði:" << endl;
        for(vara vara: pontun.vorur) {
            cout << " * " << vara.nafn << endl;
        }
        cout << "Pöntunin, sem er númer " << pontun.numer << ", er " << pontun.stada << "." << endl;
    }
}

string spyrja_um_pontunarnumer() {
    birta_pantanalista();
    cerr << "Pöntun númer: ";
    string numer;
    cin >> numer;
    return numer;
}

bool halda_afram() {
    cerr << "Má bjóða þér fleira? [já/nei]" << endl;
    string whether;
    cin >> whether;
    if ("nei" == whether) {
        return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    
    if(1 == argc) {
        cerr << "Skipun vantar." << endl;
        cerr << "Vinsamlegast kallið á Pizza <skipun> þar sem <skipun> er ein af eftirfarandi:" << endl;
        cout << "vara, panta, pantanir, byrjuð, tilbúin, greidd, afhent" << endl;
        return 1;
    }
    
    if(0 == strncmp("vara", argv[1], 5)) {
        lesa_vorur(cin, skra_voru);
        return 0;
    }
    else if (0 == strncmp("panta", argv[1], 6)) {
        pontun pontun_vidskiptavinar;
        pontun_vidskiptavinar.vidskiptavinur = spyrja_til_nafns();
        pontun_vidskiptavinar.vorur = vector<vara>();
        do {
            pontun_vidskiptavinar.vorur.push_back(taka_vid_pontun());
        } while(halda_afram());
        
        pontun_vidskiptavinar.numer = "1";
        pontun_vidskiptavinar.stada = "ný";
        panta(pontun_vidskiptavinar);
        return 0;
    }
    else if (0 == strncmp("pantanir", argv[1], 9)) {
        birta_pantanalista();
        return 0;
    }
    else if (0 == strncmp("byrjuð", argv[1], 8)) {
        cout << "Hvaða pöntun viltu merkja sem byrjaða í vinnslu?" << endl;
        string numer = spyrja_um_pontunarnumer();
        merkja_sem_byrjada(numer);
        return 0;
    }
    else if (0 == strncmp("tilbúin", argv[1], 8)) {
        cout << "Hvaða pöntun viltu merkja sem tilbúna?" << endl;
        string numer = spyrja_um_pontunarnumer();
        merkja_sem_tilbuna(numer);
        return 0;
    }
    else if (0 == strncmp("greidd", argv[1], 7)) {
        cout << "Hvaða pöntun viltu merkja sem greidda?" << endl;
        string numer = spyrja_um_pontunarnumer();
        merkja_sem_greidd(numer);
        return 0;
    }
    else if (0 == strncmp("afhent", argv[1], 8)) {
        cout << "Hvaða pöntun viltu merkja sem afhenta?" << endl;
        string numer = spyrja_um_pontunarnumer();
        merkja_sem_afhenta(numer);
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
