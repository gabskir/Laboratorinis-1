#include "funkcijos.h"

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

void skaitymas(vector<studentas>& grupe, studentas& temp){
    
    vector<std::string> failai = {"studentai10000.txt", "studentai100000.txt", "studentai1000000.txt", "kursiokai.txt"};
    cout << "Galimi failai:" << endl;
    for (int i = 0; i < failai.size(); ++i) {
        cout << i+1 << ". " << failai[i] << endl;
    }

    int failoPasirinkimas;
    while (true) {
        try {
            cout << "Nurodykite failo, is kurio norite nuskaityti duomenis, numeri: ";
            if (!(cin >> failoPasirinkimas) || failoPasirinkimas < 1 || failoPasirinkimas > failai.size()) {
                throw "Bloga ivestis.";
            }
            break;
        }catch (const char* erroras) {
            cout << erroras << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    string pavadinimas = failai[failoPasirinkimas-1];
    auto start = std::chrono::high_resolution_clock::now();
    std::ifstream in(pavadinimas);
    while (true) {
    try{
        if (!in.is_open()) {
            throw "Failo nepavyko atidaryti.";
        } else{
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
            break;
        }
    }catch (const char* zinute) {
        cout << zinute << " Pabandykite atidaryti kita faila: " << endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        while (true) {
            try {
                if (!(cin >> failoPasirinkimas) || failoPasirinkimas < 1 || failoPasirinkimas > failai.size())
                throw "Bloga ivestis.";
                in.open(failai[failoPasirinkimas-1]);
                break;
            }
            catch (const char* erroras) {
                cout << erroras << endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
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
    string vardas;
    do {
           cin >> vardas;
        }
        while(!arZodis(vardas));
    temp.vardas = vardas;


    cout << "Iveskite studento pavarde: ";
    string pavarde;
    do {
           cin >> pavarde;
        }
        while(!arZodis(pavarde));
    temp.pavarde = pavarde;

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
