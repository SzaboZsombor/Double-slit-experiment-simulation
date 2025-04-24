#ifndef VALOSZINUSEG_H
#define VALOSZINUSEG_H
#include<vector>
#include<stdexcept>
#include<iostream>
#include<cmath>
#include<fstream>

extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;
extern int DOT_SIZE;


class valoszinuseg {
	double l; //a ket racs tavolsaga (pontszerunek tekintjuk oket)
	double d; //az ernyo es a racs tavolsaga
	double valmelyik; //annak a valoszinusege, hogy megtudjuk allapitani, hogy melyik lyukon ment at a reszecske
	double norma; //a valoszinuseg eloszlás alatti terulet
	double rplancksconst; //reduced Planck's constant
	std::vector <double> valeloszlas;

	int kereso(const std::vector<double>& valel, double random);


public:

	int reszecskeszam;
	std::vector <int> pixelek;

	valoszinuseg() : pixelek(int(WINDOW_WIDTH / DOT_SIZE), int(0.6 * WINDOW_HEIGHT)), l(0), d(0), valmelyik(0), norma(0), valeloszlas(int(WINDOW_WIDTH / DOT_SIZE), 0), rplancksconst(7), reszecskeszam(0) {}

	~valoszinuseg() {
		pixelek.clear();
	}
	void Setreszecskeszam();

	void Setd(double k) {
		if (k <= 0) {
			throw std::domain_error("Az ernyo es a racs tavolsaganak nullanal nagyobbnak kell lennie");
		}
		d = k;
	}
	void Setl(double k) {
		if (k <= 0) {
			throw std::domain_error("A ket racs tavolsaganak nullanal nagyobbnak kene lennie");
		}
		l = k;
	}

	void Setvaloszinuseg();

	void Seteloszlas();

	void normalas();

	void valeloszlassa();

	void sorsol();
	double getlper2() const {
		return (l / 2);
	}

	friend std::ofstream& operator<< (std::ofstream& o, const valoszinuseg& v) { //kiirja a fájlba v tartalmat (save)
		o << v.l << "  " << v.d << "  " << v.valmelyik << "  " << v.norma << "  " << v.rplancksconst << "  " << v.reszecskeszam << std::endl;

		for (int i = 0; i < int(WINDOW_WIDTH / DOT_SIZE); i++) {
			o << v.valeloszlas[i] << "  " << v.pixelek[i] << std::endl;
		}

		return o;
	}
	friend std::ifstream& operator>> (std::ifstream& i, valoszinuseg& v) { //beolvassa a fájlbol v-be tartalmat ami ki volt savelve a fajlba (load)
		i >> v.l >> v.d >> v.valmelyik >> v.norma >> v.rplancksconst >> v.reszecskeszam;

		int meret = int(WINDOW_WIDTH / DOT_SIZE);
		v.valeloszlas.resize(meret);
		v.pixelek.resize(meret);

		for (int k = 0; k < meret; k++) {
			i >> v.valeloszlas[k] >> v.pixelek[k];
		}
		return i;
	}

};

#endif
