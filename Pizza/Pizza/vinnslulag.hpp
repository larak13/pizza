//
//  vinnslulag.hpp
//  Pizza
//
//  Created by Lara Kristinsdottir on 07/12/2017.
//  Copyright © 2017 Lara Kristinsdottir. All rights reserved.
//

#ifndef VINNSLULAG_H
#define VINNSLULAG_H

#include "gagnaklasar.hpp"
#include "gagnalag.h"
#include "lykkjur.hpp"

void skra_voru(vara afhending) {
    vista_voru(afhending);
}

vector<vara> fa_allar_vorur() {
    return lesa_allar_vorur();
}

void panta(pontun pontun) {
    vista_pontun(pontun);	
}

vector<pontun> fa_allar_pantanir() {
    return lesa_allar_pantanir();
}

void merkja(string numer, string stada) {
    auto pantanir = lesa_allar_pantanir();
    pantanir = merkja_pontun(pantanir, numer, stada);
    yfirskrifa_pantanalista(pantanir);
}

void merkja_sem_tilbuna(string numer) {
    merkja(numer, "tilbúin");
}

void merkja_sem_greidd(string numer) {
    merkja(numer, "greidd");
}

void merkja_sem_afhenta(string numer) {
    merkja(numer, "afhent");
}

void merkja_sem_byrjada(string numer) {
    merkja(numer, "byrjuð");
}

#endif /* VINNSLULAG_H */
