#include<iostream>

class Heapsort {
public:
	long *tablica,liczba;
	int ilosc, rozmiar, rozmiar_petla, ostatni_rodzic, zmiany;

	Heapsort() {
		ilosc = 0;
		liczba = 0;
		rozmiar = 0;
		rozmiar_petla = 0;
		ostatni_rodzic = 0;
		zmiany = 0;
	}

	void start() {
		std::cin >> ilosc;
		for (int i = 0; i < ilosc; i++) {

			std::cin >> rozmiar;
			tablica = new long[rozmiar];
			rozmiar_petla = rozmiar - 1;

			for (int i = 0; i < rozmiar; i++) {
				std::cin >> liczba;
				tablica[i] = liczba;
			}

			for (int a = 0; a < rozmiar_petla; a++) {

				ostatni_rodzic = (rozmiar-2) / 2;
				//std::cout << std::endl << "OSTATNI RODZIC: "<<ostatni_rodzic<<std::endl;
				//do {
					//zmiany = 0;
					for (int j = 0; j <= ostatni_rodzic; j++) {
						analiza(j);
					}
				//} while (zmiany != 0);
				for (int j = 0; j < rozmiar; j++) {
					std::cout << tablica[j] << " ";
				}
				std::cout << std::endl;

				liczba = tablica[rozmiar - 1];
				tablica[rozmiar - 1] = tablica[0];
				tablica[0] = liczba;
				rozmiar--;
			}
			for (int i = 0; i < rozmiar_petla+1; i++) {
				std::cout << tablica[i] << " ";
			}
			std::cout << std::endl << std::endl;

			delete[] tablica;
		}
	}

	void analiza(int pozycja) {
		if (tablica[2 * pozycja + 1] > tablica[pozycja]) {
			//std::cout << "ZAMIANA: "<<tablica[pozycja]<<" na "<<tablica[2*pozycja+1]<<std::endl;
			liczba = tablica[2 * pozycja + 1];
			tablica[2 * pozycja + 1] = tablica[pozycja];
			tablica[pozycja] = liczba;
			zmiany++;
			for (int k = (pozycja - 1) / 2; k >= 0; k = (k - 1) / 2) {

				if (k < 0) {
					break;
				}
				else if (k == 0) {
					analiza(k);
					//std::cout << "ZAMIANA" << std::endl;
					break;
				}
				else if (k > 0) {
					//std::cout << "ZAMIANA" << std::endl;
					analiza(k);
				}
			}
		}
		if (2 * pozycja + 2 < rozmiar) {
			if (tablica[2 * pozycja + 2] > tablica[pozycja]) {
				//std::cout << "ZAMIANA: " << tablica[pozycja] << " na " << tablica[2 * pozycja + 2] << std::endl;
				liczba = tablica[2 * pozycja + 2];
				tablica[2 * pozycja + 2] = tablica[pozycja];
				tablica[pozycja] = liczba;
				zmiany++;
				for (int k = (pozycja - 1) / 2; k >= 0; k = (k - 1) / 2) {

					if (k < 0) {
						break;
					}
					else if (k == 0) {
						analiza(k);
						//std::cout << "ZAMIANA" << std::endl;
						break;
					}
					else if (k > 0) {
						//std::cout << "ZAMIANA" << std::endl;
						analiza(k);
					}
				}
			}
		}

	}
};

int main() {
	Heapsort h;
	h.start();
	return 0;
}