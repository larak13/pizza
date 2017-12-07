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

void skra_voru(vara afhending) {
    vista_voru(afhending);
}

vector<vara> fa_allar_vorur() {
    return lesa_allar_vorur();
}

void panta(pontun pontun) {
    vista_pontun(pontun);	
}


#endif /* VINNSLULAG_H */
