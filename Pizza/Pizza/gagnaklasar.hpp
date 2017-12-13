#ifndef GAGNAKLASAR_H
#define GAGNAKLASAR_H

#include <string>
#include <vector>
using namespace std;

struct vara {
    string nafn;
    int verd;
};

struct vidskiptavinur {
    string nafn;
    string simanumer;
    string heimilisfang;
};

struct pontun {
    string numer;
    string stada;
    vector<vara> vorur;
    vidskiptavinur vidskiptavinur;
};

#endif /* GAGNAKLASAR_H */
