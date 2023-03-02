#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "mylib.h"


struct studentas {
    string vardas = "", pavarde = "";
    int egz = 0;
    vector<int> paz;
    double galutinisVid = 0;
    double galutinisMed = 0;
};

bool arZodis (string tekstas);
void atsitiktinisEgz (int& egz);
void atsitiktiniaiPazymiai (studentas& temp, int s);
void galutinis(studentas& temp);
void lentele(std::ostream& output);
bool lyginam_vardus(studentas a, studentas b);
bool lyginam_pavardes(studentas a, studentas b);
void skaitymas(vector<studentas>& grupe, studentas& temp);
void rasytiIFaila(vector<studentas>& grupe, string pavadinimas);
void duomenys (studentas& temp, int s);

#endif