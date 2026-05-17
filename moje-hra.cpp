#include <iostream>
#include <string>

using namespace std;

int main() {
    string jmeno;
    int hp = 15; // Zvýšený základ, abys přežil k vesnici
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
    cout << "\n--- POTKAL JSI MONSTRUM (HP: " << potvoraHP << ") ---" << endl;

    while (potvoraHP > 0 && hp > 0) {
        cout << "Utocis na priseru!" << endl;
        potvoraHP = potvoraHP - utok;
        cout << "Prisere zbyva: " << potvoraHP << " HP" << endl;

        if (potvoraHP > 0) {
            cout << "Prisera te kousla za 2 HP!" << endl;
            hp = hp - 2;
            cout << "Tvoje HP: " << hp << endl;
        }
    } 
     
    if (hp > 0) {
        cout << "\nPorazil jsi prvni priseru! Ziskavas 15 zlata." << endl;
        zlato = zlato + 15;

        cout << "\nPo narocnem boji jsi dorazil do vesnice 'U Spateho Programatora'." << endl;
        cout << "Ve vesnici si muzes odpocinout a nakoupit." << endl;
        
        bool ve_vesnici = true;
        while (ve_vesnici) {
            cout << "\n--- VESNICE (Zlato: " << zlato << " | HP: " << hp << ") ---" << endl;
            cout << "1 - Leceni +5 HP (stoji 5 zlata)" << endl;
            cout << "2 - Trenink utoku +2 (stoji 10 zlata)" << endl;
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
   
        cout << "\nUroven tve postavy se zvysila! Citis se silnejsi." << endl;
        int maxHP = 35; // Vybalancované maximum zdraví
        hp = maxHP;
        cout << "Novy level postavy. Zivoty se doplnily na: " << maxHP << endl;
        
        cout << "\nAle pozor! V krovi susti dalsi monstra..." << endl;
   
        // SOUBOJ SE DVĚMA MONSTRY 
        int vlk1_HP = 12;
        int vlk2_HP = 12;
        cout << "Vyskocili na tebe dva vlci najednou!" << endl;

        while ((vlk1_HP > 0 || vlk2_HP > 0) && hp > 0) {
            cout << "\nNa koho zautocis? 1 - Prvni vlk (" << vlk1_HP << " HP), 2 - Druhy vlk (" << vlk2_HP << " HP)" << endl;
            cin >> volba;

            if (volba == 1 && vlk1_HP > 0) {
                vlk1_HP = vlk1_HP - utok;
                cout << "Zasahnes prvniho vlka!" << endl;
            } else if (volba == 2 && vlk2_HP > 0) {
                vlk2_HP = vlk2_HP - utok;
                cout << "Zasahnes druheho vlka!" << endl;
            } else {
                cout << "Ten uz je mrtvy nebo jsi minul!" << endl;
            }

            if (vlk1_HP > 0) {
                cout << "Prvni vlk te kousl za 2 HP!" << endl;
                hp = hp - 2;
            }
            if (vlk2_HP > 0) {
                cout << "Druhy vlk te kousl za 2 HP!" << endl;
                hp = hp - 2;
            }
            cout << "Tvoje zbyvajici HP: " << hp << endl;
        }

        if (hp > 0) {
            cout << "\nZvladl jsi to! Oba vlci jsou pryc." << endl;
            // Místo nesmyslného plného vyléčení dostaneš jen malou lékárničku
            hp = hp + 10;
            cout << "Nasel jsi u nich maly lektvar. Dopinil ti 10 HP. (Tvoje HP: " << hp << ")" << endl;
            
            // --- FINÁLNÍ BOSS: CHRONOBOT ---
            cout << "\n=========================================" << endl;
            cout << "   [ERROR] NARUSENI CASOPROSTORU!" << endl;
            cout << "  *** VAROVANI: PRICHAZI CHRONOBOT *** " << endl;
            cout << "=========================================" << endl;
            
            int bossHP = 40; 
            int kolo = 1;
            int posledniSkodaBosse = 0;

            while (bossHP > 0 && hp > 0) {
                cout << "\n--- KOLO " << kolo << " ---" << endl;
                cout << "Utocis na Chronobota!" << endl;
                bossHP = bossHP - utok;
                cout << "Chronobotovi zbyva HP: " << bossHP << endl;

                if (bossHP <= 0) {
                    break; 
                }

                int skodaBosse = 0;
                int vzor = kolo % 4; 

                if (vzor == 1) { 
                    cout << "Chronobot pouzil SLABY utok." << endl; 
                    skodaBosse = 2; 
                } else if (vzor == 2) { 
                    cout << "Chronobot pouzil STREDNI utok." << endl; 
                    skodaBosse = 4; 
                } else if (vzor == 3) { 
                    cout << "Chronobot pouzil SILNY utok." << endl; 
                    skodaBosse = 6; 
                } else { 
                    cout << "!!! Chronobot pouzil KRITICKY utok !!!" << endl; 
                    skodaBosse = 10; 
                }

                hp = hp - skodaBosse;
                posledniSkodaBosse = skodaBosse; 

                if (kolo % 5 == 0) {
                    cout << "\nChronobot PRESKOCIL CAS a utoci znovu stejnou silou!" << endl;
                    hp = hp - posledniSkodaBosse;
                }

                cout << "Tvoje zbyvajici HP: " << hp << endl;
                kolo = kolo + 1;
            }

            if (hp > 0) {
                cout << "\nGRATULUJEME! Porazil jsi Chronobota a zachranil casovou osu!" << endl;
                cout << "=== VYHRAL JSI HRU ===" << endl;
            } else {
                cout << "\nChronobot te vymazal z historie. KONEC HRY." << endl;
            }

        } else {
            cout << "\nVlci te roztrhali. Hra konci." << endl;
        }
    } 

    return 0;
}