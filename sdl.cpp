#include <SDL_ttf.h>
#include "SDL.h"


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
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }
    return true;
}

bool SDL::OpenFont(int betumeret) {
    font = TTF_OpenFont("D:\\SDL\\SDL2_ttf-2.22.0\\Poppins-Regular.ttf", betumeret);
    if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        TTF_Quit();
        SDL_Quit();
        return false;
    }

    return true;
}

bool SDL::CreateWindow() {
    window = SDL_CreateWindow("Double slit simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
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
    sdl.font = TTF_OpenFont("D:\\SDL\\SDL2_ttf-2.22.0\\Poppins-Regular.ttf", 24);
    reszecskeszam = "Részecskék száma: " + std::to_string(kilott);
    textSurface = TTF_RenderText_Solid(sdl.font, reszecskeszam.c_str(), textColor);
    textTexture = SDL_CreateTextureFromSurface(sdl.renderer, textSurface);
    textRect = { 30, 30, textSurface->w, textSurface->h };
    SDL_RenderCopy(sdl.renderer, textTexture, NULL, &textRect);
    kilott++;
}

void Writer::hatter(SDL& sdl) {



    sdl.font = TTF_OpenFont("D:\\SDL\\SDL2_ttf-2.22.0\\Poppins-Regular.ttf", 24);

    std::string felirat = "Kétrés-kísérlet szimulációja";
    textSurface = TTF_RenderText_Solid(sdl.font, felirat.c_str(), textColor);
    textTexture = SDL_CreateTextureFromSurface(sdl.renderer, textSurface);
    textRect = { 440, 400, textSurface->w, textSurface->h };
    SDL_RenderCopy(sdl.renderer, textTexture, NULL, &textRect);

    std::string xten = "x";
    textSurface = TTF_RenderText_Solid(sdl.font, xten.c_str(), textColor);
    textTexture = SDL_CreateTextureFromSurface(sdl.renderer, textSurface);
    textRect = { 1175, 370, textSurface->w, textSurface->h };
    SDL_RenderCopy(sdl.renderer, textTexture, NULL, &textRect);

    std::string N = "N";
    textSurface = TTF_RenderText_Solid(sdl.font, N.c_str(), textColor);
    textTexture = SDL_CreateTextureFromSurface(sdl.renderer, textSurface);
    textRect = { 620, 20, textSurface->w, textSurface->h };
    SDL_RenderCopy(sdl.renderer, textTexture, NULL, &textRect);

    sdl.font = TTF_OpenFont("D:\\SDL\\SDL2_ttf-2.22.0\\Poppins-Regular.ttf", 9);
    std::string beutesek = "beütések száma";
    textSurface = TTF_RenderText_Solid(sdl.font, beutesek.c_str(), textColor);
    textTexture = SDL_CreateTextureFromSurface(sdl.renderer, textSurface);
    textRect = { 640, 40, textSurface->w, textSurface->h };
    SDL_RenderCopy(sdl.renderer, textTexture, NULL, &textRect);


    //kirajzolják a tengelyeket és a rések helyét 

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
