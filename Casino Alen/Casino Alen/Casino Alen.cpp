// Casino Alen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

void menu();
void uplata_novca(int &novac, int &chipovi);
void isplata_novca(int &novac, int &chipovi);
void stanje(string ime, int novac, int chipovi);
void jednoruki_jack(int &novac, int &chipovi, string ime);
void bacanje_kockica(int &novac, int &chipovi, string ime);
void duplo_ili_nista(int &novac, int &chipovi, string ime);
void spremanje_scorea(int chipovi, string stanje, string ime);
void igre_menu();

int main()
{
	srand(time(NULL));
	int novac, chipovi = 0, izbor, izbor_igre;
	string ime;

	cout << "\t** Dobrodosli u C++ Casino **" << endl;
	cout << "\n\t   Unesite vase ime:   ";
	cin >> ime;
	cout << "\n\t Unesite vas ulog u kunama: ";
	cin >> novac;

	do {
		system("cls");
		stanje(ime, novac, chipovi);
		menu();
		cin >> izbor;
		switch (izbor) {
		case 1: system("cls"); //uplata
				stanje(ime, novac, chipovi);
				uplata_novca(novac, chipovi);
			    break;
		case 2: system("cls"); // isplata
				stanje(ime, novac, chipovi);
				isplata_novca(novac, chipovi);
				break;
		case 3: system("cls"); //igre
				stanje(ime, novac, chipovi);
				igre_menu();
				
				do {
					cin >> izbor_igre;
					switch (izbor_igre) {
					case 1: system("cls");
							stanje(ime, novac, chipovi);
							jednoruki_jack(novac, chipovi, ime);
							igre_menu();
							break;
					case 2: system("cls");
							bacanje_kockica(novac, chipovi, ime);
							igre_menu();
							break;
					case 3: system("cls");
							igre_menu();
							duplo_ili_nista(novac, chipovi, ime);
							break;
					case 4:
						system("cls");
						break;
					case 5: 
						break;
					default: cout << "krivi broj";
					}
					

				} while (izbor_igre != 4);
				system("pause");
				break;
				
		
		}

	} while (izbor != 5);

	return 0;
}

void isplata_novca(int &novac, int &chipovi) {
	cout << "\n\tKoliko cipova zelite zamijeniti za novac (1 chip = 5kn) : ";
	int kolicina_cipova;
	string odgovor;
	cin >> kolicina_cipova;
	cout << "\n\n\tJeste li sigurni da zelite unovciti " << kolicina_cipova << " cipova za novac? Da/Ne ";
	cin >> odgovor;
	if (kolicina_cipova <= chipovi) {
		if (odgovor == "da" || odgovor == "DA" || odgovor == "Da") {
			novac += kolicina_cipova * 5;
			chipovi = chipovi - kolicina_cipova;
			cout << "\n\n\tCestitamo, unovcili ste " << kolicina_cipova * 5 << "kn za " << kolicina_cipova << " cipova.\n";
		}
		else if (odgovor == "ne" || odgovor == "NE" || odgovor == "Ne") {
			cout << "Niste isplatili nista\n";
		}
	}
	else if (kolicina_cipova > chipovi) {
		cout << "\n\n\tNemate toliko chipova!\n";

	}

	system("pause");
}

void uplata_novca(int &novac, int &chipovi) {
	int ulog;
	cout << "\n\tKoliko novaca zelite zamijeniti za cipove? ";
	cin >> ulog;

	if (ulog <= novac) {
		chipovi += (ulog - (ulog % 5)) / 5;
		novac -= ulog - (ulog % 5);
		cout << "\n\n\tPotrosio si " << ulog - (ulog % 5) << " kuna i kupio si " << (ulog - (ulog % 5)) / 5 << " cipa/cipova.\n";
	}
	else if (ulog > novac) {
		chipovi += (novac - (novac % 5)) / 5;
		cout << "\n\n\t** Nedovoljno novaca!! ** ";
		cout << "\n\n\tPotrosio si " << novac - (novac % 5) << " kuna i kupio si " << (novac - (novac % 5)) / 5 << " cipa/cipova.\n";
		novac = novac % 5;
	}

	system("pause");
}

void menu() {
	cout << "\t** C++ CASINO IZBORNIK **" << endl;
	cout << "\n\n\t   1. Uplata novca(zamjena za chip-ove) - 1 chip = 5kn";
	cout << "\n\n\t   2. Isplata novca";
	cout << "\n\n\t   3. Odabir igre";
	cout << "\n\n\t   4. High score";
	cout << "\n\n\t   5. Izlaz iz programa";
	cout << "\n\n\n\t   Vas izbor: ";
}

void igre_menu() {
	cout << "\t** ODABIR IGRE **" << endl;
	cout << "\n\n\t   1. Jednoruki Jack (slot machine)";
	cout << "\n\n\t   2. Bacanje kockica";
	cout << "\n\n\t   3. Duplo ili nista";
	cout << "\n\n\t   4. Izlaz\n\n";
	cout << "\n\n\n\t   Vas izbor: ";
}

void stanje(string ime, int novac, int chipovi) {
	cout << "\n\t\t\t\t\t\t\t\t\tIme: " << ime << "\tNovac: " << novac << "kn \tChipovi: " << chipovi << "\n";
}

void jednoruki_jack(int &novac, int &chipovi, string ime) {
	srand(time(NULL));
	int pocetni_chipovi = chipovi;
	int a, b, c, rucka;
	char b1, b2, b3;
	cout << "\t** JEDNORUKI JACK(slot machine) **";
	cout << "\n\n\t1. Zavrti (1 chip - 1 igra)";
	cout << "\n\n\t0. Izlaz\n";
	cout << "\n\n\t ROLAJ  ";
	

	do {
		cin >> rucka;
		system("cls");
		
		switch (rucka) {
		case 1:
			if (chipovi > 0) {
				a = rand() % 4 + 1;
				b = rand() % 4 + 1;
				c = rand() % 4 + 1;
				if (a == 1) {
					b1 = '+';
				}
				else if (a == 2) {
					b1 = 'X';
				}
				else if (a == 3) {
					b1 = 'O';
				}
				else if (a == 4) {
					b1 = '*';
				}
				if (b == 1) {
					b2 = '+';
				}
				else if (b == 2) {
					b2 = 'X';
				}
				else if (b == 3) {
					b2 = 'O';
				}
				else if (b == 4) {
					b2 = '*';
				}
				if (c == 1) {
					b3 = '+';
				}
				else if (c == 2) {
					b3 = 'X';
				}
				else if (c == 3) {
					b3 = 'O';
				}
				else if (c == 4) {
					b3 = '*';
				}


				if (a == b && a == c) {
					chipovi += 16;
					stanje(ime, novac, chipovi);
					cout << "\t** JEDNORUKI JACK(slot machine) **";
					cout << "\n\n\t1. Zavrti (1 chip - 1 igra)";
					cout << "\n\n\t0. Izlaz\n";

					cout << "\n\t| " << b1 << " | " << b2 << " | " << b3 << " |";
					cout << "\t** DOBITAK **      16 chipova!!!" << endl;
				}
				else {
					chipovi--;
					stanje(ime, novac, chipovi);
					cout << "\t** JEDNORUKI JACK(slot machine) **";
					cout << "\n\n\t1. Zavrti (1 chip - 1 igra)";
					cout << "\n\n\t0. Izlaz\n";

					cout << "\n\t| " << b1 << " | " << b2 << " | " << b3 << " |";
					cout << "\t--  NISTA  --" << endl;
				} 
				cout << "\n\nROLAJ \n";
			}
			else {
				cout << "\n\tNemas novaca\n";
				cout << "\n\tStisni 0 za izlaz\n";
				

			}
			break;
		case 0:
			break;
		default: cout << "Odaberi 1 ili 0";
		}
			 
	} while (rucka != 0);
	int zavrsni_chipovi = chipovi;
	spremanje_scorea(zavrsni_chipovi - pocetni_chipovi, "jack.txt", ime);
};

void bacanje_kockica(int &novac, int &chipovi, string ime) {
	srand(time(NULL));
	int korisnik_score, racunalo_score, baci_kocku, ulog_kocke;
	int pocetni_chipovi = chipovi;
	
	cout << "\t** BACANJE KOCKICA **";
	cout << "\n\n\tJednom baca korisnik, jednom racunalo, opet korisnik, opet racunalo te se onda gleda tko ima veci zbroj.\n";
	cout << "\n\tVas ulog: ";
	cin >> ulog_kocke;

	if (ulog_kocke <= chipovi) {
		cout << "\n\n\tBaci kocku s 1: ";
		cin >> baci_kocku;
		int k1 = rand() % 6 + 1;
		cout << "\n\t" << ime << " - kocka: " << k1;
		korisnik_score = k1;

		cout << "\n\n\tRacunalo ";
		int k2 = rand() % 6 + 1;
		cout << "Kocka " << k2;
		racunalo_score = k2;

		cout << "\n\n\tBaci kocku s 1: ";
		cin >> baci_kocku;
		int k3 = rand() % 6 + 1;
		cout << "\n\t" << ime << " - kocka: " << k3;
		if (k3 > korisnik_score) {
			korisnik_score = k3;
		}

		cout << "\n\n\tRacunalo ";
		int k4 = rand() % 6 + 1;
		cout << "Kocka " << k4;
		if (k4 > racunalo_score) {
			racunalo_score = k4;
		}

		if (korisnik_score > racunalo_score) {
			cout << "\n\n\t** Pobjedio je " << ime << " sa kockicom " << korisnik_score << endl;
			chipovi += ulog_kocke;
		}
		else if (racunalo_score > korisnik_score) {
			cout << "\n\n\t** Pobjedilo je Racunalo sa kockicom " << racunalo_score << endl;
			chipovi -= ulog_kocke;
		}
		else {
			cout << "\n\n\tIzjednaceno je" << endl;
		}
		stanje(ime, novac, chipovi);
	}
	else {
	cout << "\nNemate dovoljno chipova" << endl;
	}
	int zavrsni_chipovi = chipovi;
	spremanje_scorea(zavrsni_chipovi - pocetni_chipovi, "kockice.txt", ime);
}

void duplo_ili_nista(int &novac, int &chipovi, string ime) {
	srand(time(NULL));
	int ulog, racunalo_karta, korisnik_karta, vuci_kartu = 0, spil_karata = 52, duplo;
	int pocetni_chipovi = chipovi;
	vector <int> karte;
	for (int i = 1; i <= 52; i++) {
		karte.push_back(i);
	}
	
	system("cls");
	cout << "\t** DUPLO ILI NISTA **";
	cout << "\n\n\tNasumicno se izvlaci jedna karta za korisnika i jedna za racunalo, veca karta pobjedjuje,\n\tnakon zavrsenog kruga postavlja se pitanje duplo ili nista";
	cout << "\n\tVas ulog: ";
	cin >> ulog;

	do {
		if (ulog < 0) {
			cout << "\n\tNemate dovoljno cipova";
			cout << "\n\tVas ulog: ";
			cin >> ulog;
		}
		else {
			while (spil_karata != 0) {
				cout << "\n\tOdaberite 1 za kartu: ";
				cin >> vuci_kartu;
				korisnik_karta = rand() % spil_karata + 1;
				cout << "\n\tKorisnik vuce kartu: " << korisnik_karta % 13 + 1;
				karte.erase(karte.begin() + korisnik_karta -1);
				spil_karata--;
				racunalo_karta = rand() % spil_karata + 1;
				cout << "\n\tRacunalo vuce kartu: " << racunalo_karta % 13 + 1;
				karte.erase(karte.begin() + racunalo_karta - 1);
				spil_karata--;
				if (korisnik_karta > racunalo_karta) {
					cout << "\n\t** POBJEDIO je " << ime << " s kartom " << korisnik_karta % 13 + 1 << " - " << racunalo_karta % 13 + 1 << endl;
					chipovi+= ulog;
				}
				else if (korisnik_karta < racunalo_karta) {
					cout << "\n\t-- RACUNALO je pobijedilo s kartom " << racunalo_karta % 13 + 1 << " - " << korisnik_karta % 13 + 1 << endl;
					chipovi-= ulog;
				}
				stanje(ime, novac, chipovi);
				cout << "\n\tDUPLO ili nista(1 za duplo ili 0 za nista)? ";
				cin >> duplo;
				if (duplo <= chipovi) {
					if (duplo == 1) {
						cout << "\n\tOdaberite 1 za kartu: ";
						cin >> vuci_kartu;
						korisnik_karta = rand() % spil_karata + 1;
						cout << "\n\tKorisnik vuce kartu: " << korisnik_karta % 13 + 1;
						karte.erase(karte.begin() + korisnik_karta - 1);
						spil_karata--;
						racunalo_karta = rand() % spil_karata + 1;
						cout << "\n\tRacunalo vuce kartu: " << racunalo_karta % 13 + 1;
						karte.erase(karte.begin() + racunalo_karta - 1);
						spil_karata--;
						if (korisnik_karta > racunalo_karta) {
							cout << "\n\t** POBJEDIO je " << ime << " s kartom " << korisnik_karta % 13 + 1 << " - " << racunalo_karta % 13 + 1 << endl;
							chipovi = chipovi + (ulog * 2);
						}
						else if (korisnik_karta < racunalo_karta) {
							cout << "\n\t-- RACUNALO je pobijedilo s kartom " << racunalo_karta % 13 + 1 << " - " << korisnik_karta % 13 + 1 << endl;
							chipovi = chipovi - (ulog * 2);
						}
						
					}
					else if (duplo == 0) {
						
					}
				}
				else {
					cout << ime << " je ostao bez chipova!\n";
				}
				stanje(ime, novac, chipovi);
			} 

		}
	} while (ulog != 0);
	int zavrsni_chipovi = chipovi;
	spremanje_scorea(zavrsni_chipovi - pocetni_chipovi, "duplo.txt", ime);
}

void spremanje_scorea(int chipovi, string stanje, string ime) {
	ofstream output;
	string spremanje;
	output.open(stanje, ios::app);
	spremanje = ime + " " + to_string(chipovi) + "\n";
	output << spremanje;
	output.close();
}

void highscore() {

}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
