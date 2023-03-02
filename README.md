# Laboratorinis-1

## v0.3 ##
Programos funkcionalumas nepakito nuo 0.2 versijos (tik pridėtas exeption handling void skaitymas() funkcijoje).

### Programos struktūros pokyčiai ###
1. Programa išskaidyta į du .cpp tipo failus: "main.cpp" ir "funkcijos.cpp"
    - "main.cpp" faile palikta main() funkcija
    - į "funkcijos.cpp" perkeltos visos pagalbinės programos funkcijos
2. Sukurti du header tipo failai "mylib.h" ir "funkcijos.h"
    - "funkcijos.h" faile įrašyta programoje naudojama struktūra ir "funkcijos.cpp" faile esančių funkcijų deklaracijos
    - "mylib.h" faile aprašytos naudojamos bibliotekos 


## v0.2 ##

### Programos veikimas ###

1. Programos pradžioje vartotojas paklausiamas ar nori duomenis nuskaityti iš failo.<br>
    - Skaitymui iš failo vartotojas turi įvesti "t" <br>
    - Vedimui ranka vartotojas turi įvesti "n" <br>
2. Jei pirmame žingsnyje vartotojas pasirenka duomenis skaityti iš failo: <br>
   2.1. į konsolę išspausdinamas failų, iš kurių duomenis galima nuskaityti, sąrašas.<br>
   2.2. vartotojas turi įvesti pasirinkto failo numerį <br>
   2.3. vartotojas turi pasirinkti ar nori studentus surūšiuoti pagal pavardes. <br>
        - Rūšiavimui pagal pavardes vartotojas turi įvesti "t" <br>
        - Rūšiavimui pagal vardus vartotojas turi įvesti "n" <br>
   2.4. vartotojas turi pasirinkti ar failo nuskaitymo ir duomenų surūšiavimo rezultatus spausdinti konsolėje, ar įrašyti į failą. <br>
        - Spausdinimui konsolėje vartotojas turi įvesti "k" <br>
        - Duomenų įrašymui į failą vartotojas turi įvesti "f" <br>
   2.5. priklausomai nuo 2.3 ir 2.4. aprašytų pasirinkimų rezultatai bus surūšiuoti pagal vardus arba pavardes ir išspausdinti konsolėje arba įrašyti į                         "rezultatai.txt." failą kartu su galutiniais pažymiais (apskaičiuotais su vidurkiu ir mediana). <br>
3. Jei pirmame žingsnyje vartotojas pasirenka duomenis suvesti ranka: <br>
    3.1. vartotojas suveda maksimalų namų darbų pažymių kiekį, kuris bus taikomas visiems studentams. <br>
    3.2. studentų kiekis - nefiksuotas, tad norėdamas pridėti naują studentą vartotojas turi įvesti "1", jeigu naujo studento duomenų įvesti nenori turi įvesti "2".<br>
        - Vartotojui neįvedus nei vieno studento duomenų ir įvedus "2" programa baigia darbą. <br>
    3.3. paspaudus "1" vartotojas turi suvesti studento vardą ir pavardę. <br>
    3.4. vartotojas turi pasirinkti ar nori egzamino ir namų darbų įvertinimus generuoti atsitiktinai ar suvesti ranka. <br>
        - Pažymių generavimui vartotojas turi įvesti "t". Pažymiai sugeneruojami ir išspausdinami konsolėje. <br>
        - Pažymių vedimui ranka vartotojas turi įvesti "n". Programa leis įvedinėti pažymius tol, kol bus pasiektas anksčiau nurodytas maksimalus namų darbų įvertinimų         kiekis. Nepasiekus maksimalaus pažymių kiekio ir paspaudus "n" pažymių vedimas bus sustabdytas. Jei suvestas namų darbų įvertinimo kiekis nesieks anksčiau             nurodyto maksimalaus, programa likusius pažymius įves kaip "0". Tuomet vartotojas įveda egzamino įvertinimą. <br>
    3.5. Vartotojas vėl klausiamas ar nori įvesti dar vieno studento duomenis. Žingsniai 3.1. - 3.4. kartojasi, kol vartotojas paspaus "2" ir taip nurodys, kad duomenų vedimą baigė. <br>
    3.6. Vartotojui įvedus "2" ir taip nurodžius, kad duomenų įvedimą baigė, jis turi pasirinkti ar nori studentus surūšiuoti pagal pavardes. <br>
        - Rūšiavimui pagal pavardes vartotojas turi įvesti "t" <br>
        - Rūšiavimui pagal vardus vartotojas turi įvesti "n" <br>
    3.7. Priklausomai nuo 3.6. pasirinkimo rezultatai bus surūšiuoti pagal vardus arba pavardes ir išspausdinti konsolėje kartu su galutiniais pažymiais (apskaičiuotais su vidurkiu ir mediana). <br>

## v0.1 ##

### Programos veikimas ###

1. Programos pradžioje vartotojas įveda maksimalų namų darbų pažymių kiekį, kuris bus taikomas visiems studentams. <br>
2. Studentų kiekis - nefiksuotas, tad norėdamas pridėti naują studentą vartotojas turi įvesti "1", jeigu naujo studento duomenų įvesti nenori turi įvesti "2". <br>
   - Vartotojui neįvedus nei vieno studento duomenų ir įvedus "2" programa baigia darbą. <br>
3. Paspaudus "1" vartotojas turi suvesti studento vardą ir pavardę. Jie turi būti sudaryti tik iš raidžių, jei tekste bus kiti simboliai, ne tik raidės, programa prašys suvesti tekstą iš naujo. <br>
4. Vartotojas gali pasirinkti ar namų darbų įvertinimus nori generuoti atsititiktinai (paspaudus "t"), ar įvesti pats (paspaudus "n") <br>
   - pasirinkus "t" programa sugeneruoja anksčiau vartotojo nurodytą pažymių kiekį (pažymiai generuojami 1-10 intervale). <br>
   - pasirinkus "n" vartotojas gali vesti pažymius dešimtabelėje sistemoje. Programa leis įvedinėti pažymius tol, kol bus pasiektas anksčiau nurodytas maksimalus namų darbų įvertinimų kiekis. Nepasiekus maksimalaus pažymių kiekio ir paspaudus "0" pažymių vedimas bus sustabdytas. Jei suvestas namų darbų įvertinimo kiekis nesieks anksčiau nurodyto maksimalaus, programa likusius pažymius įves kaip "0". <br>
5. Vartotojas gali pasirinkti ar egzamino įvertinimą nori generuoti atsititiktinai (paspaudus "t"), ar įvesti pats (paspaudus "n") <br>
   - pasirinkus "t" programa sugeneruos atsitiktinį pažymį ir tęs darbą. <br>
   - pasirinkus "n" vartotojas pats turi įvesti egzamino įvertinimą (dešimtbalėje sistemoje). <br>
6. Tuomet vartotojas vėl klausiamas ar nori įvesti dar vieno studento duomenis. Žingsniai 2-6 kartojasi, kol vartotojas paspaus "2" ir taip nurodys, kad duomenų vedimą baigė. <br>
7. Vartotojas gali pasirinkti, ar galutinį pažymį programa turi skaičiuoti su pažymių vidurkiu (paspaudus "t"), ar su mediana (paspaudus "m"). <br>
   - pasirinkus "m" galutinis pažymys apskaičiuojamas su pažymių mediana ir duomenys atspausdinami lentelės pavidalu, kurioje pateikiami studentų vardai, pavardės bei galutinis pažymys. <br>
   - pasirinkus "v" galutinis pažymys apskaičiuojamas su pažymių vidurkiu ir duomenys atspausdinami lentelės pavidalu, kurioje pateikiami studentų vardai, pavardės bei galutinis pažymys. <br>

### Galutinio pažymio skaičiavimo formulė: ###
- Su pažymių vidurkiu: 0.4 * vidurkis + 0.6 * egzamino įvertinimas. <br>
- Su pažymių mediana: 0.4 * pažymių mediana + 0.6 * egzamino įvertinimas. <br>
