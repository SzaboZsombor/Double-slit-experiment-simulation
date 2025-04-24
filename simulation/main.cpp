#include<SDL.h>
#include<SDL_ttf.h>
#include<iostream>
#include<vector>
#include <string>
#include"valoszinuseg.h"
#include"sdl.h"
#include<stdexcept>
#include <cstdlib>
#include<fstream>

int WINDOW_WIDTH = 1200;
int WINDOW_HEIGHT = 600;
int DOT_SIZE = 1;

void sdlsetup(SDL& sdl) { //Itt az SDL tajgait inicializaljuk
    sdl.Init();

    if (!sdl.CreateWindow() || !sdl.CreateRenderer() || !sdl.OpenFont()) {

        std::exit(1);
    }
}

void indentalas(valoszinuseg& pontok) {//Itt a két-rés kísérlet elrendezését kérjük be az inputrol
    double d, l;
    std::cout << "Add meg a ket res tavolsagat: ";
    std::cin >> l;
    try {
        pontok.Setl(l);
    }
    catch (std::exception& err) {
        std::cerr << "Hiba: " << err.what();
    }
    std::cout << "Add meg a racs es az ernyo kozotti tavolsagot: ";
    std::cin >> d;
    try {
        pontok.Setd(d);
    }
    catch (std::exception& err) {
        std::cerr << "Hiba: " << err.what();

    }
    try {
        pontok.Setreszecskeszam();
    }
    catch (std::exception& err) {
        std::cerr << "Hiba: " << err.what();
    }

    pontok.Setvaloszinuseg();
    pontok.Seteloszlas();
    pontok.normalas();
    pontok.valeloszlassa();

}

int SDL_main(int argc, char* argv[]) {

    srand(static_cast<unsigned int>(time(nullptr)));

    valoszinuseg pontok;
    indentalas(pontok);

    SDL sdl;
    sdlsetup(sdl);

    Writer writer;

    writer.TextColorSetter(255, 255, 255);

    std::ofstream file("D:/Iskola/double_slit/mentes.txt", std::ofstream::trunc);//megnyitja a mentes.txt file-t es kitorli az eddigi tartalmat
    if (!file.is_open()) {
        std::cerr << "Nem talalhato a fajl" << std::endl;
    }
    else {
        file << pontok; //elmenti pontok adatait a mentes.txt file-ba
        file.close();
    }


    while (sdl.running && writer.kilott <= pontok.reszecskeszam) { //Eddig menjenek a frame-k

        while (SDL_PollEvent(&sdl.event)) {
            if (sdl.event.type == SDL_QUIT) {//Ha bezartuk az ablakot ne fusson tovabb a szimulacio
                sdl.running = false;
            }
        }

        pontok.sorsol(); //kisorsolja, hogy a reszecske melyik cellaba usson be (valoszinusegi gorbe szerint sorsol random)

        writer.clear(sdl); // kitorli a regi frame-t (feketere allitja vissza)

        writer.ReszecskeSzamOut(sdl); //kiirja a kilott reszecskek szamat az ablakra

        writer.hatter(sdl); //kiirja a a hatteret (tengelyek, stb.) az ablakra

        writer.pontokabrazolasa(sdl, pontok); //abrazolja, hogy melyik cellaban hany beutes volt




        sdl.PresentFrame(); //abrazolja az elobbi a dolgokat az ablakra


    }
    writer.Free();
    sdl.End();

    return 0;
}
