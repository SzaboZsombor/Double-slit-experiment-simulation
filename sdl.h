#ifndef SDL_H
#define SDL_H

#include <SDL.h>
#include<iostream>
#include<stdexcept>
#include "valoszinuseg.h"
#include<string>

extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;
extern int DOT_SIZE;

typedef struct _TTF_Font TTF_Font;

class SDL {
    TTF_Font* font;
    SDL_Window* window;
    SDL_Renderer* renderer;


public:
    bool running;
    SDL_Event event;

    SDL(int wwidth = 1200, int wheight = 600, int dotsize = 1) : font(nullptr), window(nullptr), renderer(nullptr), running(true) {}

    ~SDL() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    bool Init();

    void WindowHeightSetter(int size) {
        WINDOW_HEIGHT = size;
    }

    void WindowWidthSetter(int size) {
        WINDOW_WIDTH = size;
    }

    void DotSizeSetter(int size) {
        DOT_SIZE = size;
    }

    bool CreateRenderer();

    bool OpenFont(int betumeret = 24);

    bool CreateWindow();

    void PresentFrame();

    void End();

    friend class Writer;
};



class Writer {
    SDL_Color textColor;
    SDL_Rect textRect;
    SDL_Rect dotRect;
    SDL_Texture* textTexture;
    SDL_Surface* textSurface;
    std::string reszecskeszam;
public:

    int kilott;

    Writer() :kilott(0), textTexture(nullptr), textSurface(nullptr) {
        //textRect = { 0, 0, textSurface->w, textSurface->h };

    }
    ~Writer() {
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);
    }

    void TextColorSetter(int a = 255, int b = 255, int c = 255) { //szinkod (alapbol feher)
        textColor = { static_cast<Uint8>(a), static_cast<Uint8>(b), static_cast<Uint8>(c) };
    }

    void ReszecskeSzamOut(SDL& sdl);

    void hatter(SDL& sdl);

    void clear(const SDL& sdl) {
        SDL_SetRenderDrawColor(sdl.renderer, 0, 0, 0, 0);
        SDL_RenderClear(sdl.renderer);
    }

    void pontokabrazolasa(SDL& sdl, const valoszinuseg& pontok);

    void Free() {
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);
    }
};
#endif