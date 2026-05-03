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
     
    if (hp > 0) {
        cout << "\nPo narocnem boji jsi dorazil do vesnice 'U Spateho Programatora'." << endl;
        cout << "Ve vesnici si muzes odpocinout a nakoupit." << endl;
        
        bool ve_vesnici = true;
        while (ve_vesnici) {
            cout << "\n--- VESNICE (Zlato: " << zlato << " | HP: " << hp << ") ---" << endl;
            cout << "1 - Leceni (stoji 5 zlata)" << endl;
            cout << "2 - Trenink utoku (stoji 10 zlata)" << endl;
            cout << "3 - Odejit z vesnice" << endl;
            cout << "Vase volba: ";
            cin >> volba;

            if (volba == 1) {
                if (zlato >= 5) {
                    hp = hp + 5;
                    zlato = zlato - 5;
                    cout << "Vylecil jsi se! Tvoje HP je nyni: " << hp << endl;
                } else {
                    cout << "Mas malo penez na leceni!" << endl;
                }
            } 
            else if (volba == 2) {
                if (zlato >= 10) {
                    utok = utok + 2;
                    zlato = zlato - 10;
                    cout << "Tve svaly rostou! Tvuj utok je ted: " << utok << endl;
                } else {
                    cout << "Chybi ti zlato na trenink!" << endl;
                }
            } 
            else {
                ve_vesnici = false;
                cout << "Odchazis z vesnice vstric dalsimu dobrodruzstvi..." << endl;
            }
        }

   
        cout << "\nUroven tve postavy se zvysila! Citit se silnejsi." << endl;
        int maxHP = 20; 
        hp = maxHP;
        cout << "Novy level postavy. Max zivoty se zvysily na: " << maxHP << endl;
        
        cout << "\nAle pozor! V krovi susti dalsi monstrum..." << endl;
   
    }