#include <iostream>
#include <string>

using namespace std;

int main() {

    string jmeno;
    int hp = 10;
    int utok = 3;
    int zlato = 0;
    int volba;

    cout << "Vitej v RPG hre! Jak se jmenuje tvuj hrdina?" << endl;
    cin >> jmeno;

    cout << "Vyber si zbran: 1 - Mec (utok 5), 2 - Hulka (utok 4)" << endl;
    cin >> volba;

    if (volba == 1) {
        utok = 5;
        cout << "Vzal jsi mec. Tvuj utok je: " << utok << endl;
    } else {
        utok = 4;
        cout << "Vzal jsi hulku. Tva sila je: " << utok << endl;
    }

    int potvoraHP = 8;
    cout << "\n--- POTKAl JSI MONSTRUM (HP: " << potvoraHP << ") ---" << endl;

    while (potvoraHP > 0 && hp > 0) {
        cout << "Utocis na priseru!" << endl;
        potvoraHP = potvoraHP - utok;
        cout << "Prisere zbyva: " << potvoraHP << " HP" << endl;

        if (potvoraHP > 0) {
            cout << "Prisera te kousla za 2 HP!" << endl;
            hp = hp - 2;
            cout << "Tvoje HP: " << hp << endl;
        }