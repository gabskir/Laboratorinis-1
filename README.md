# Laboratorinis-1

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
