#include "valoszinuseg.h"

int valoszinuseg::kereso(const std::vector<double>& valel, double random) {/*binaris kereso ami megkeresi a sorsolt valoszinuseget es annak a
tombnek megnoveli az erteket 1-el (beut az 1 ik cellaba a reszecske)*/

	int also = 0;
	int felso = valel.size() - 1;
	while (also <= felso) {
		int kozepso = (also + felso) / 2;

		if (valel[kozepso] >= random && (kozepso == 0 || valel[kozepso - 1] < random)) {
			return kozepso;
		}
		else if (valel[kozepso] > random) {
			felso = kozepso - 1;
		}
		else if (valel[kozepso] < random) {
			also = kozepso + 1;
		}
	}

	return -1;

}

void valoszinuseg::Setreszecskeszam() {
	std::cout << "Kerlek add meg hany reszecsket szeretnel kiloni: ";
	std::cin >> reszecskeszam;
	if (reszecskeszam < 0) {
		throw std::domain_error("A kilonni kivant reszecskek szama nem lehet negativ");
	}
}

void valoszinuseg::Setvaloszinuseg() {
	std::cout << "Add meg annak a valoszinuseget amellyel megtudjuk allapitani, hogy a reszecske melyik lyukon ment keresztul: ";
	std::cin >> valmelyik;
	while (valmelyik > 1 || valmelyik < 0) {
		std::cout << std::endl << "Kerlek addj meg egy uj valoszinuseget 0 es 1 kozott: ";
		std::cin >> valmelyik;

	}
	valmelyik = 1 - valmelyik;
}

void valoszinuseg::Seteloszlas() {
	int i = 0;
	for (double k = -8 * l; k <= 8 * l && i < int(WINDOW_WIDTH / DOT_SIZE); k += 16 * l / double(WINDOW_WIDTH / DOT_SIZE)) {

		valeloszlas[i] = 1 / (d * d + (k - l / 2) * (k - l / 2)) + 1 / (d * d + (k + l / 2) * (k + l / 2)) + valmelyik * (2 / sqrt((d * d + (k - l / 2) * (k - l / 2)) * (d * d + (k + l / 2) * (k + l / 2)))) * cos(rplancksconst * (sqrt((d * d + (k - l / 2) * (k - l / 2))) - sqrt((d * d + (k + l / 2) * (k + l / 2)))));

		i++;

	}
}

void valoszinuseg::normalas() {

	for (std::vector <double>::iterator it = valeloszlas.begin(); it != valeloszlas.end(); it++) {
		norma += *it;


	}
	for (std::vector <double>::iterator it = valeloszlas.begin(); it != valeloszlas.end(); it++) {
		*it /= norma;
	}
}

void valoszinuseg::valeloszlassa() {//felosztja cellakat valoszinuseg szerint 0-tol 1-ig
	double elozo = 0;
	for (std::vector<double>::iterator it = valeloszlas.begin(); it != valeloszlas.end(); it++) {
		*it += elozo;
		elozo = *it;

	}
}

void valoszinuseg::sorsol() { // random sorsol egy szamot es eszerint sorsolja, hogy melyik cellaba utkozzon be az elektron
	double random = static_cast<double>(rand()) / RAND_MAX;

	int i = kereso(valeloszlas, random);
	if (i == -1) {
		std::cout << "Nem talalhato a valoszinuseg!";
		std::exit(1);
	}
	pixelek[i] -= 2; //egy beuteskor ket pixellek megy feljebb a pont az animacioban

}
