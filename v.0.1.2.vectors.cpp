#include <iostream> 
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <cctype>
#include <algorithm>
#include <vector>
#include <string>

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
    double galutinis = 0;
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
    int random_num = rand() % 10+1;
    cout << "Atsitiktinai sugeneruotas egzamino pazymys: " << random_num << endl;
    egz = random_num;
}

void atsitiktiniaiPazymiai (studentas& temp, int s) {
    int x;
    for (int i = 0; i < s; i++) {
        x = rand() % 10+1;
        temp.paz.push_back(x);
    }
    cout << "Atsitiktinai sugeneruoti studento namu darbu ivertinimai: ";
    for (int i = 0; i < s; i++) {
        cout << temp.paz[i] << " ";
    }
    cout << endl;
}

double namuDarbuVidurkis(studentas& temp, int s) {
    double sum = 0;
    for (int i = 0; i < s; i++) {
        sum += temp.paz.at(i);
    }
    double vidurkis = sum / s;
    return vidurkis;
}

double mediana(studentas& temp, int s) {
    std::sort(temp.paz.begin(), temp.paz.end());

    if (s % 2 == 0) {
        return (double)(temp.paz[s/2 - 1] + temp.paz[s/2]) / 2;
    } else {
        return (double)temp.paz[s/2];
    }

}

void lenteleVidurkis() {
    cout << left << setw(15) << "Vardas" << left << setw(15) << "Pavarde" << left << setw (15) << "Galutinis (Vid.)" << endl;
    cout << "----------------------------------------------------" << endl;
}

void lenteleMediana() {
    cout << left << setw(15) << "Vardas" << left << setw(15) << "Pavarde" << left << setw (15) << "Galutinis (Med.)" << endl;
    cout << "----------------------------------------------------" << endl;
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

    cout << "Ar norite namu darbu ivertinimus generuoti atsitiktinai? (t/n) ";
    char arAtsitiktinai;
    cin >> arAtsitiktinai;

    while (arAtsitiktinai != 't' && arAtsitiktinai != 'n') {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Jei namu darbu pazymius norite generuoti atsitiktinai spauskite t, jei norite suvesti patys spauskite n: ";
        cin >> arAtsitiktinai;
    }

    if (arAtsitiktinai == 't')
    {
        atsitiktiniaiPazymiai (temp, s);
    }
    else {
        bool stop = false;
        cout << "Iveskite pazymi (ivede pazymi paspauskite enter, jei norite baigti vesti, spauskite 0): ";
        int i = 0;
        for (; i < s; i++) {
            int pazymys;
            while (true) {
                if (cin >> pazymys) {
                    if (pazymys == 0) {
                        stop = true;
                        break;
                    } else if (pazymys >= 1 && pazymys <= 10) {
                        temp.paz.push_back(pazymys);
                        break;
                    } else {
                        cout << "Ivestas pazymys turi buti nuo 1 iki 10. Bandykite dar karta." << endl;
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                } else {
                    cout << "Ivestis turi buti sveikasis skaicius. Bandykite pazymi ivesti dar karta." << endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
            cout << "Pazymys " << j+1 << ": " << temp.paz[j] << endl;
        }

    }

    cout << "Ar norite egzamino pazymi generuoti atsitiktinai? (t/n) ";
    char arAtsitiktinis;
    cin >> arAtsitiktinis;
    
    while (arAtsitiktinis != 't' && arAtsitiktinis != 'n') {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Jei egzamino pazymi norite generuoti atsitiktinai spauskite t, jei norite suvesti patys spauskite n: ";
        cin >> arAtsitiktinis;
    }

    if (arAtsitiktinis == 't')
    {
       atsitiktinisEgz(temp.egz);
    }
    else {
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

    srand(time(NULL));

    int s;
    studentas T;

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

    vector <studentas> grupe;

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

		if (papildomasStud == 2)
			break;
		else
		{
            T.paz.clear();
            duomenys (T,s);
            grupe.push_back(T);
		}
	}

    if (grupe.empty())
    return 0;

    cout << "Jei norite galutini pazymi skaiciuoti su vidurkiu spauskite v, jei su mediana - spauskite m:";
    char kaipGalutinis;
    cin>> kaipGalutinis;

    while (kaipGalutinis != 'v' && kaipGalutinis != 'm'){
        cout << "Galutinio pazymio skaiciavimui su vidurkiu spauskite v, su mediana - m ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> kaipGalutinis;
        }

    if (kaipGalutinis == 'v'){
        lenteleVidurkis();
        for (int i=0; i < grupe.size();i++){
        double vidurkis = namuDarbuVidurkis(grupe[i], s);
        grupe[i].galutinis = 0.4 * vidurkis + 0.6 * grupe[i].egz;
        
        cout << left << setw(15) << grupe[i].vardas <<
		    left << setw(15) << grupe[i].pavarde <<
		    left << setw(15) << std::fixed << std::setprecision(2) << grupe[i].galutinis << endl;
        }
    }
    else {
        lenteleMediana();
        for (int i=0; i < grupe.size(); i++){
        double med = mediana(grupe[i], s);
        grupe[i].galutinis = 0.4 * med + 0.6 * grupe[i].egz;

        cout << left << setw(15) << grupe[i].vardas <<
		    left << setw(15) << grupe[i].pavarde <<
		    left << setw(15) << std::fixed << std::setprecision(2) << grupe[i].galutinis << endl;
            
        }
    }
    T.paz.clear();
    grupe.clear();
    
}

