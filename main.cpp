#include "funkcijos.h"

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
        
        skaitymas(grupe, T);

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