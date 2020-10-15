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
