# Objektinio programavimo kurso 1-oji užduotis

## Užduotis

Sukurti programą, kuri nuskaito studentų vardus, pavardes, namų darbų pažymius ir egzamino įvertinimą bei suskačiuoja galutinį balą. Taikoma formulė GALUTINIS = 0,4×VIDURKIS + 0,6×EGZAMINAS. 

## v0.1 (09-27)

- Nuskaitomi duomenys (vardas, pavardė, egzamino įvertinimas, namų darbai).
- Galutinis balas skaičiuojamas pasirinktinai pagal namų darbų vidurkį arba medianą.
- Įvedant duomenis nebūtina žinoti namų darbų kiekio, tačiau negali viršyti 20 (įprastai semestre tiek nebūna).
- Galimybė namų darbus ir egzaminus generuoti atsitiktinai.
- Du *.cpp* failai: vienas su masyvais, kitas su vektoriais (bus naudojamas tolimesniam kūrimui).

## v0.2 (09-27)

**Nauja**
- Pasirinkimas skaityti duomenis iš failo kursiokai.txt (5 namų darbai).
- Kai duomenys nuskaitomi iš failo, rezultatai išvedami surikiuotų studentų vardų (ir pavardžių) tvarka.
- Kai duomenys nuskaitomi iš failo, rezultatuose išvedami galutiniai pažymiai ir pagal namų darbų vidurkį, ir pagal medianą.

**Koreguota**
- Pašalintos nereikalingos eilutės, paliktos per neapsižiūrėjimą (kintamas *sum* ir veiksmai su juo).
- Pakeista struktūra.
- Sukurta funkcija galutiniui pažymiui skaičiuoti.

## Pastaba. (10-15)
Sutvarkyta repozitorija. Koreguotos šakos, pakeisti failai, tačiau nekeistas jų turinys.

## v0.3 (10-15)

**Nauja**
- Funkcijos ir struktūra iškeltos į *header* failus.
- *Exception handling*. Įvedant duomenis (pasirinkimus, studentų skaičių, pažymius), tikrinama, ar reikšmė teisinga: pasirinkimai tik 1 arba 2, studentų skaičius didesnis nei 1, pažymiai intervale 0-10 (0 paliekamas kaip pasirinkimas, kai yra neatsiskaita).

**Koreguota**
- Keista struktūra; kintamasis *homework* iš masyvo pakeistas į vektorių.
- Namų darbų įvedimas - baigus užtenka paspausti *enter*.
- Funkcijoje *findMedian* pakeistas rūšiavimas.
- Funkcijos *countMean* ir *findMedian* pakeistos į atitinkamai *finalByMean* ir *finalByMedian*, jose iškart skaičiuojami galutiniai pažymiai, o ne namų darbų vidurkis ar mediana, todėl panaikinta ir ankstesnė galutinį pažymį skaičiuojanti funkcija.

**Galima keisti**
- Rezultatų išvedimo kodo dalį padaryti atskiroje funkcijoje.
- Galbūt kaip nors optimizuoti pasirinkimus.
- Namų darbų įvedimas vis tiek lieka neidealus – netyčia paspaudus *enter* dar nepradėjus vesti namų darbų (įvedus tik egzaminą), neskaičiuojami vidurkiai, nes nėra dalies duomenų.
- Nuskaitymą iš failo pritaikyti bet kuriam turiniui. T.y. namų darbų kiekio nežinant iš anksto, o tik nuskaičius pirmąją failo eilutę.
- KOMENTUOTI programos kodą!

## v0.4

**Nauja**
- Programos pradžioje galima pasirinkti failų generavimą: jie sugeneruojami, nuskaitomi, studentai suskirstomi į dvi grupes: *kietuoliai*, kurių galutinis balas >= 5 ir *vargšiukai*, kurių galutinis < 5, grupės įrašomos į atskirus failus. Visų procesų metu skaičiuojamas laikas.

**Koreguota**
- Atsitiktiniai skaičiai generuojami naudojant *chrono*, nebe *rand()*.
- Galutiniui balui skaičiuoti pridėta funkcija *final*.
- Rezultatų išvedimui parašyta atskira funkcija.
- Programa gana smulkiai komentuojama.

**Galima keisti**
- Vis dar daug *if*'ų *if*'e ir pasikartojančio kodo.
- Visiškai nekeistas *kursiokai.txt* nuskaitymas.
