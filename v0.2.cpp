#include <iostream> 
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cctype>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <numeric>

using std::cout;
using std::cin;
using std::setw;
using std::string;
using std::left;
using std::endl;
using std::vector;



struct studentas {
    string vardas = "", pavarde = "";
    int egz = 0;
    vector<int> paz;
    double galutinisVid = 0;
    double galutinisMed = 0;
};

bool arZodis (string tekstas) {
    for (char i : tekstas)
        {
        if (!isalpha(i))
        {
            cout << "Teksto ivedimui naudokite tik raides. Iveskite is naujo: " << endl;
            return false;
        }
    }
    return true;
}   

void atsitiktinisEgz (int& egz){
    using hrClock = std::chrono::high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> dist(0, 10);
    int random_num = dist(mt);
    cout << "Atsitiktinai sugeneruotas egzamino pazymys: " << random_num << endl;
    egz = random_num;
}

void atsitiktiniaiPazymiai (studentas& temp, int s) {
    
    using hrClock = std::chrono::high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> dist(0, 10);

    for (int i = 0; i < s; ++i) {
        int x = dist(mt);
        temp.paz.push_back(x);
    }

    cout << "Atsitiktinai sugeneruoti studento namu darbu ivertinimai: ";
    for (int i = 0; i < s; i++) {
        cout << temp.paz.at(i) << " ";
    }
    cout << endl;
}

void galutinis(studentas& temp) {
    int s = temp.paz.size();
    temp.galutinisVid = std::accumulate(&temp.paz[0], &temp.paz[s], 0.);
    temp.galutinisVid = 0.4 * (temp.galutinisVid/(s*1.0)) + 0.6 * temp.egz;

    std::sort(temp.paz.begin(), temp.paz.end());
    if (s % 2 == 0) {
        temp.galutinisMed = (double)(temp.paz[s/2 - 1] + temp.paz[s/2]) / 2;
    } else {
       temp.galutinisMed  = (double)temp.paz[s/2];
    }
    temp.galutinisMed = 0.4 * temp.galutinisMed  + 0.6 * temp.egz;
    temp.paz.clear();
}

void lentele(std::ostream& output) {
    output << left << setw(15) << "Vardas" << left << setw(15) << "Pavarde" << left << setw (20) << "Galutinis (Vid.)" << left << setw (20) << "Galutinis (Med.)" << endl;
    output << "--------------------------------------------------------------------------------" << endl;
}

bool lyginam_vardus(studentas a, studentas b) {
    return a.vardas < b.vardas;
}

bool lyginam_pavardes(studentas a, studentas b) {
    return a.pavarde < b.pavarde;
}

void skaitymas(string pavadinimas, vector<studentas>& grupe, studentas& temp){
     auto start = std::chrono::high_resolution_clock::now();
    std::ifstream in(pavadinimas);
    if (!in.is_open()) {
        cout << "Failo " << pavadinimas << " nepavyko atidaryti." << endl;
    } else {
        cout << "Palaukite, kol bus nuskaitytas failas." << endl;
        int kiekis = -3;
        string eil;
        getline(in, eil);
        std::istringstream ss(eil);
        while (ss>>eil) {kiekis++;}
        temp.paz.reserve(kiekis);

        int p;
        while (std::getline(in, eil)) {
            std::istringstream ss(eil);
            ss >> temp.vardas >> temp.pavarde;
            for (int i = 0; i < kiekis; i++) {

                ss >> p;
                temp.paz.push_back(p);
            }
            ss >> temp.egz;
            galutinis(temp);
           
            grupe.push_back(temp);
        }
        in.close();
        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
        std::cout << "Duomenu nuskaitymas ir apdorojimas uztruko " << diff.count() << " sekundziu." << endl;
    }  
}

void rasytiIFaila(vector<studentas>& grupe, string pavadinimas) {
    std::ofstream out(pavadinimas);
    if (!out.is_open()) {
        cout << "Failo " << pavadinimas << " nepavyko sukurti." << endl;
    } else {
        lentele(out);
        for (auto& i : grupe) {
            out << left << setw(15) << i.vardas << left << setw(15) << i.pavarde;
            out << std::fixed << std::setprecision(2) << left << setw(20) << i.galutinisVid << left << setw(20) << i.galutinisMed << endl;
        }
        out.close();
        cout << "Rezultatai irasyti i faila " << pavadinimas << endl;
    }
}

void duomenys (studentas& temp, int s){
    cout << "Iveskite studento varda: ";
    do {
           cin >> temp.vardas;
        }
        while(!arZodis(temp.vardas));


    cout << "Iveskite studento pavarde: ";
    do {
           cin >> temp.pavarde;
        }
        while(!arZodis(temp.pavarde));

    cout << "Ar norite namu darbu ir egzamino ivertinimus generuoti atsitiktinai? (t/n) ";
    char arAtsitiktinai;
    cin >> arAtsitiktinai;

    while (arAtsitiktinai != 't' && arAtsitiktinai != 'n') {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Jei namu darbu ir egzamino pazymius norite generuoti atsitiktinai spauskite t, jei norite suvesti patys spauskite n: ";
        cin >> arAtsitiktinai;
    }

    if (arAtsitiktinai == 't')
    {
        atsitiktiniaiPazymiai (temp, s);
        atsitiktinisEgz(temp.egz);
       
    }
    else {
        bool stop = false;
        cout << "Iveskite pazymi (ivede pazymi paspauskite enter, jei norite baigti vesti, spauskite n): ";

        int i = 0;
        for (; i < s; i++) {
            int pazymys;
            while (true) {
                if (cin >> pazymys) {
                    if (pazymys >= 0 && pazymys <= 10) {
                        temp.paz.push_back(pazymys);
                    } else {
                        cout << "Ivestas pazymys turi buti nuo 0 iki 10. Bandykite dar karta." << endl;
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                } else {
                    char c;
                    std::cin.clear();
                    cin >> c;
                    if (c == 'n') {
                        stop = true;
                        break;
                } else {
                    cout << "Ivestis turi buti sveikasis skaicius. Bandykite pazymi ivesti dar karta." << endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }  
            }
            }
             if (stop) {
                break;
            }
            
        }
        for (int j = i; j < s; j++) { 
            temp.paz.push_back(0);
        }
        for (int j = 0; j < s; j++) {
            cout << "Pazymys " << j+1 << ": " << temp.paz.at(j)<< endl;
        }

        while (true) {
        cout << "Iveskite egzamino ivertinima: ";
        if (cin >> temp.egz) { 
            if (temp.egz >= 1 && temp.egz <= 10) {
                break;
            } else {
                cout << "Ivertinimas turi buti tarp 1 ir 10. Bandykite dar karta." << endl;
            }    
        } else { 
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Iveskite tik sveikaji skaiciu." <<endl;
        }
        } 

    }
}

int main () {

    int s;
    studentas T;
    vector <studentas> grupe;
    
    char arFailas;
    cout << "Ar duomenis norite skaityti is failo (t/n): ";
    cin >> arFailas;

    while (arFailas != 't' && arFailas != 'n'){
        cout << "Duomenu skaitymui is failo spauskite t, duomenu ivedimui ranka spauskite n: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> arFailas;
    }

    if (arFailas == 'n') {
        while (true) {
        cout << "Iveskite koks koks yra maksimalus namu darbu ivertinimu kiekis: ";
        if (cin >> s && s > 0) { 
            T.paz.reserve(s);
            break;
        } else { 
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Iveskite tik sveikaji skaiciu." <<endl;
        }
        }

        while (true)
	    {
		    cout << "Studento duomenu ivedimui spauskite 1, baigti ivedima spauskite 2: ";
            int papildomasStud;
            cin >> papildomasStud;

            while (papildomasStud != 1 && papildomasStud != 2) {
                cout << "Paspauskite 1, jei norite itraukti studenta ir 2, jei norite baigti ivesti: ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin >> papildomasStud;
            }

		    if (papildomasStud == 2){
                break;
            }
		    else
		    {
                T.paz.clear();
                duomenys (T,s);
                grupe.push_back(T);
		    }
	    }

        if (grupe.empty())
        return 0;

        char arVardas;
        cout << "Ar norite studentus rusiuoti pagal pavardes? (t/n): ";
        cin >> arVardas;

        while (arVardas != 't' && arVardas != 'n'){
            cout << "Jei norite studentus rusiuoti pagal pavardes spauskite 't', jei pagal vardus, spauskite 'n' ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> arVardas;
        }

        if (arVardas == 't') {
            sort(grupe.begin(), grupe.end(), lyginam_pavardes);
        }
        else {
            sort(grupe.begin(), grupe.end(), lyginam_vardus);
        }

        lentele(cout);
        for (auto &i:grupe){    
            galutinis (i);
            cout << left << setw(15) << i.vardas <<
		        left << setw(15) << i.pavarde <<
		        left << setw(20) << std::fixed << std::setprecision(2) << i.galutinisVid << left << setw(20) << std::fixed << std::setprecision(2) << i.galutinisMed<< endl;
        }   

        T.paz.clear();
        grupe.clear();
    }
    else {
    
        vector<std::string> failai = {"studentai10000.txt", "studentai100000.txt", "studentai1000000.txt", "kursiokai.txt"};
        cout << "Galimi failai:" << endl;
        for (int i = 0; i < failai.size(); ++i) {
            cout << i+1 << ". " << failai[i] << endl;
        }

        int failoPasirinkimas;
        while (true) {
        cout << "Nurodykite failo, is kurio norite nuskaityti duomenis, numeri: ";
        if (!(cin >> failoPasirinkimas)) {
            cout << "Bloga ivestis. " << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (failoPasirinkimas < 1 || failoPasirinkimas > failai.size()) {
            cout << "Netinkamas pasirinkimas" << endl;
            continue;
        }
        break;
        }
        
        string pavadinimas = failai[failoPasirinkimas-1];
        skaitymas (pavadinimas, grupe, T);

        char arVardas;
        cout << "Ar norite studentus rusiuoti pagal pavardes? (t/n): ";
        cin >> arVardas;

        while (arVardas != 't' && arVardas != 'n'){
            cout << "Jei norite studentus rusiuoti pagal pavardes spauskite 't', jei pagal vardus, spauskite 'n' ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> arVardas;
        }

        if (arVardas == 't') {
            sort(grupe.begin(), grupe.end(), lyginam_pavardes);
        }
        else {
            sort(grupe.begin(), grupe.end(), lyginam_vardus);
        }

        char arKonsole;
        do{
        cout << "Jei rezultatus norite isspausdinti konsoleje spauskite k, jei norite, kad rezultatai butu irasyti faile spauskite - f: " << endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> arKonsole;
        }while (arKonsole != 'k' && arKonsole != 'f');

        if (arKonsole == 'k'){
        lentele(cout);
        for (auto &i:grupe){    
            cout << left << setw(15) << i.vardas <<
		        left << setw(15) << i.pavarde <<
		        left << setw(20) << std::fixed << std::setprecision(2) << i.galutinisVid << left << setw(20) << std::fixed << std::setprecision(2) << i.galutinisMed<< endl;
        }
        }
        else {
            rasytiIFaila(grupe, "rezultatai.txt");
        }

        grupe.clear();
        }

    }