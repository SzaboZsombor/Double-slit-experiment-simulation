#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <iostream>
#include "sdl.h"


bool SDL::Init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    }

    if (TTF_Init() < 0) {
        return false;
    }
    return true;
}


bool SDL::CreateRenderer() {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Nem sikerult a renderer letrehozasa: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }
    return true;
}

bool SDL::OpenFont(int betumeret) {
    font = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", betumeret);
    if (!font) {
        std::cerr << "Nem sikerult a betutipus megnyitasa: " << TTF_GetError() << std::endl;
        TTF_Quit();
        SDL_Quit();
        return false;
    }

    return true;
}

bool SDL::CreateWindow() {
    window = SDL_CreateWindow("Double slit simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Nem sikerult az ablak letrehozasa: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    return true;
}

void SDL::PresentFrame() {
    SDL_RenderPresent(renderer);
    SDL_Delay(static_cast<Uint32>(0.001 * 1000));
}

void SDL::End() {

    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}


void Writer::ReszecskeSzamOut(SDL& sdl) {
    sdl.font = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", 24);
    if (!sdl.font) {
        std::cerr << "Nem sikerult a betutipus megnyitasa: " << TTF_GetError() << std::endl;
        return;
    }
    reszecskeszam = "Részecskék száma: " + std::to_string(kilott);
    textSurface = TTF_RenderUTF8_Solid(sdl.font, reszecskeszam.c_str(), textColor);
    if (!textSurface) {
        std::cerr << "Nem sikerult a szoveg megjelenitese: " << TTF_GetError() << std::endl;
        TTF_CloseFont(sdl.font);
        sdl.font = nullptr;
        return;
    }
    textTexture = SDL_CreateTextureFromSurface(sdl.renderer, textSurface);
    textRect = { 30, 30, textSurface->w, textSurface->h };
    SDL_RenderCopy(sdl.renderer, textTexture, NULL, &textRect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(sdl.font);
    sdl.font = nullptr;
    kilott++;
}

void Writer::hatter(SDL& sdl) {
    sdl.font = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", 24);
    if (!sdl.font) {
        std::cerr << "Nem sikerult a betutipus megnyitasa: " << TTF_GetError() << std::endl;
        return;
    }

    std::string felirat = "Kétrés-kísérlet szimulációja";
    textSurface = TTF_RenderUTF8_Solid(sdl.font, felirat.c_str(), textColor);
    if (textSurface) {
        textTexture = SDL_CreateTextureFromSurface(sdl.renderer, textSurface);
        textRect = { 440, 400, textSurface->w, textSurface->h };
        SDL_RenderCopy(sdl.renderer, textTexture, NULL, &textRect);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);
    }

    std::string xten = "x";
    textSurface = TTF_RenderUTF8_Solid(sdl.font, xten.c_str(), textColor);
    if (textSurface) {
        textTexture = SDL_CreateTextureFromSurface(sdl.renderer, textSurface);
        textRect = { 1175, 370, textSurface->w, textSurface->h };
        SDL_RenderCopy(sdl.renderer, textTexture, NULL, &textRect);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);
    }

    std::string N = "N";
    textSurface = TTF_RenderUTF8_Solid(sdl.font, N.c_str(), textColor);
    if (textSurface) {
        textTexture = SDL_CreateTextureFromSurface(sdl.renderer, textSurface);
        textRect = { 620, 20, textSurface->w, textSurface->h };
        SDL_RenderCopy(sdl.renderer, textTexture, NULL, &textRect);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);
    }

    TTF_CloseFont(sdl.font);
    sdl.font = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", 9);
    if (!sdl.font) {
        std::cerr << "Nem sikerult a betutipus megnyitasa: " << TTF_GetError() << std::endl;
        return;
    }
    std::string beutesek = "beütések száma";
    textSurface = TTF_RenderUTF8_Solid(sdl.font, beutesek.c_str(), textColor);
    if (textSurface) {
        textTexture = SDL_CreateTextureFromSurface(sdl.renderer, textSurface);
        textRect = { 640, 40, textSurface->w, textSurface->h };
        SDL_RenderCopy(sdl.renderer, textTexture, NULL, &textRect);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);
    }
    TTF_CloseFont(sdl.font);
    sdl.font = nullptr;


    //kirajzolj�k a tengelyeket �s a r�sek hely�t 

    SDL_SetRenderDrawColor(sdl.renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(sdl.renderer, 0, int(0.6 * WINDOW_HEIGHT), WINDOW_WIDTH, int(0.6 * WINDOW_HEIGHT));

    SDL_RenderDrawLine(sdl.renderer, int(9 * WINDOW_WIDTH / 16), int(0.6 * WINDOW_HEIGHT) - 10, int(9 * WINDOW_WIDTH / 16), int(0.6 * WINDOW_HEIGHT) + 10);
    SDL_RenderDrawLine(sdl.renderer, int(7 * WINDOW_WIDTH / 16), int(0.6 * WINDOW_HEIGHT) - 10, int(7 * WINDOW_WIDTH / 16), int(0.6 * WINDOW_HEIGHT) + 10);

    SDL_RenderDrawLine(sdl.renderer, WINDOW_WIDTH / 2, int(0.6 * WINDOW_HEIGHT), WINDOW_WIDTH / 2, 0);
    SDL_RenderDrawLine(sdl.renderer, 590, 25, 600, 0);
    SDL_RenderDrawLine(sdl.renderer, 610, 25, 600, 0);
    SDL_RenderDrawLine(sdl.renderer, WINDOW_WIDTH - 25, int(0.6 * WINDOW_HEIGHT) - 10, WINDOW_WIDTH, int(0.6 * WINDOW_HEIGHT));
    SDL_RenderDrawLine(sdl.renderer, WINDOW_WIDTH - 25, int(0.6 * WINDOW_HEIGHT) + 10, WINDOW_WIDTH, int(0.6 * WINDOW_HEIGHT));


    SDL_SetRenderDrawColor(sdl.renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(sdl.renderer, 0, int(0.6 * WINDOW_HEIGHT), WINDOW_WIDTH, int(0.6 * WINDOW_HEIGHT));

    SDL_RenderDrawLine(sdl.renderer, int(9 * WINDOW_WIDTH / 16), int(0.6 * WINDOW_HEIGHT) - 10, int(9 * WINDOW_WIDTH / 16), int(0.6 * WINDOW_HEIGHT) + 10);
    SDL_RenderDrawLine(sdl.renderer, int(7 * WINDOW_WIDTH / 16), int(0.6 * WINDOW_HEIGHT) - 10, int(7 * WINDOW_WIDTH / 16), int(0.6 * WINDOW_HEIGHT) + 10);

    SDL_RenderDrawLine(sdl.renderer, WINDOW_WIDTH / 2, int(0.6 * WINDOW_HEIGHT), WINDOW_WIDTH / 2, 0);


    SDL_RenderDrawLine(sdl.renderer, 590, 25, 600, 0);
    SDL_RenderDrawLine(sdl.renderer, 610, 25, 600, 0);


    SDL_RenderDrawLine(sdl.renderer, WINDOW_WIDTH - 25, int(0.6 * WINDOW_HEIGHT) - 10, WINDOW_WIDTH, int(0.6 * WINDOW_HEIGHT));
    SDL_RenderDrawLine(sdl.renderer, WINDOW_WIDTH - 25, int(0.6 * WINDOW_HEIGHT) + 10, WINDOW_WIDTH, int(0.6 * WINDOW_HEIGHT));

}


void Writer::pontokabrazolasa(SDL& sdl, const valoszinuseg& pontok) {
    for (int i = 0; i < int(WINDOW_WIDTH / DOT_SIZE); i++) { // abrazolja pontonkent a beutesek szamat
        dotRect = { i * DOT_SIZE, pontok.pixelek[i], DOT_SIZE, DOT_SIZE };
        SDL_RenderFillRect(sdl.renderer, &dotRect);

    }
}
