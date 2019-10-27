#include <iostream>
#include <fstream>
#include <string>

const int SIZE = 50;

struct name
{
	char *imie = new char[SIZE];
	char *stanowisko = new char[SIZE];
	char * pseudo = new char[SIZE];
	int preferencja;
};
struct namee
{
	std::string imie;
	std::string stanowisko;
	std::string pseudo;
	int preferencja;
};

name wpisywanie();
namee wpisywaniee();
void wys(name);
void wys(namee);

int main()
{
	char nazwa_pliku[SIZE];
	std::cout << "Podaj nazwe pliku: ";
	std::cin.getline(nazwa_pliku, SIZE);

	if(0)	//tworzenie pliku tekstowego
	{

		int ilosc,i=0;
		std::ofstream out_file;
		out_file.open(nazwa_pliku);

		std::cout << "Pobieranie danych.\nIlu czlonkow ma klub: ";
		std::cin >> ilosc;
		std::cin.get();
		out_file << ilosc << "\n";
		namee * tablica = new namee[ilosc];
		while (i < ilosc)
		{
			tablica[i] = wpisywaniee();
			out_file<< tablica[i].imie << "\t" << tablica[i].stanowisko << "\t" << tablica[i].pseudo
				 << "\t" << tablica[i].preferencja << "\n";
			i++;
		}
		i = 0;

		while (i < ilosc)
		{
			wys(tablica[i]);
			i++;
		}

		out_file.close();

	}

	if (1)	// pobieranie danych z pliku tekstowego
	{
		int ilosc, i = 0;
		std::fstream out_file;
		out_file.open(nazwa_pliku);
		if (out_file.is_open())
		{
			
			(out_file >> ilosc).get();
			namee * tablica = new namee[ilosc];
			while (i < ilosc)	//tworzenie tablicy wewnatrzprogramowej na podstawie danych z pliku;
			{
				char ch;
				out_file.get(ch);
				while (ch != '\t')
				{
					tablica[i].imie += ch;
					out_file.get(ch);
				}
				out_file.get(ch);
				while (ch != '\t')
				{
					tablica[i].stanowisko += ch;
					out_file.get(ch);
				}
				out_file.get(ch);
				while (ch != '\t')
				{
					tablica[i].pseudo += ch;
					out_file.get(ch);
				}
				out_file >> tablica[i].preferencja;
				//while (out_file.get() != '\n')
				//	continue;
				//out_file.get();


				if (0)
					std::cout << tablica[i].imie << "\t" << tablica[i].stanowisko << "\t" << tablica[i].pseudo
					<< "\t" << tablica[i].preferencja << "\n";
				i++;
			}

			std::cout << "\a\n\nLista osob:\na) imie\tb) stanowisko\tc) pseudonim\nd) preferencja\tq) wyjscie\ntwoj wybor: ";
			char ch;

			while (std::cin.get(ch) && ch != 'q')
			{
				int i = 0;
				switch (ch)
				{
				case 'a':
				case 'A':
					std::cout << "\nlista wedlug imion\n";
					while (i < ilosc)
					{
						std::cout << tablica[i].imie;// << std::endl;
						i++;
					}
					break;
				case 'b':
				case 'B':
					std::cout << "\nlista wedlug stanowisk\n";
					while (i < ilosc)
					{
						std::cout << tablica[i].stanowisko << std::endl;
						i++;
					}
					break;
				case 'c':
				case 'C':
					std::cout << "\nlista wedlug pseudonimow\n";
					while (i < ilosc)
					{
						std::cout << tablica[i].pseudo << std::endl;
						i++;
					}
					break;
				case 'd':
				case 'D':
					std::cout << "\nlista wedlug preferencji\n";
					while (i < ilosc)
					{
						switch (tablica[i].preferencja)
						{
						case 0:
							std::cout << "imie:\t\t" << tablica[i].imie << std::endl;
							break;
						case 1:
							std::cout << "stanowisko:\t" << tablica[i].stanowisko << std::endl;
							break;
						case 2:
							std::cout << "pseudonim:\t\t" << tablica[i].pseudo << std::endl;
							break;
						}
						i++;

					}
					break;
				default:
					std::cout << "\nzly znak\n";


				}
				while (std::cin.get() != '\n')
					continue;

				std::cout << "\a\n\nLista osob:\na) imie\tb) stanowisko\tc) pseudonim\nd) preferencja\tq) wyjscie\ntwoj wybor: ";
			}
		}
		else
		{
			ilosc = 0;
			std::cout << "Nie udalo sie otworzyc pliku";
		}
	}

	std::cin.get();
	return 0;
}


name wpisywanie()
{
	name tymczas;
	std::cout << "Podaj imie: ";
	std::cin.getline(tymczas.imie,SIZE);
	std::cout << "Podaj stanowisko: ";
	std::cin.getline(tymczas.stanowisko, SIZE);
	std::cout << "Podaj pseudonim: ";
	std::cin.getline(tymczas.pseudo, SIZE);
	std::cout << "Podaj preferencje\n 0-imie\t1-stanowisko\t2-pseudonim\n: ";
	std::cin >> tymczas.preferencja;
	std::cin.get();
	return tymczas;
}

namee wpisywaniee()
{
	namee tymczas;
	std::cout << "Podaj imie: ";
	std::getline(std::cin,tymczas.imie);
	std::cout << "Podaj stanowisko: ";
	std::getline(std::cin, tymczas.stanowisko);
	std::cout << "Podaj pseudonim: ";
	std::getline(std::cin, tymczas.pseudo);
	std::cout << "Podaj preferencje\n 0-imie\t1-stanowisko\t2-pseudonim\n: ";
	std::cin >> tymczas.preferencja;
	std::cin.get();
	return tymczas;
}

void wys(name tymczas)
{
	std::cout << tymczas.imie << "\t" << tymczas.stanowisko << "\t" << tymczas.pseudo 
		<< "\t" << tymczas.stanowisko << "\t" << tymczas.preferencja << "\n";
}

void wys(namee tymczas)
{
	std::cout << tymczas.imie << "\t" << tymczas.stanowisko << "\t" << tymczas.pseudo
		<< "\t" << tymczas.stanowisko << "\t" << tymczas.preferencja << "\n";
}