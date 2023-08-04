#include <stdbool.h>
#include <SDL2/SDL.h>

#include "matrix.h"
#include "vector3.h"
#include "vector4.h"
#include "render2d.h"


int WINDOW_WIDTH;
int WINDOW_HEIGHT;
SDL_Window *WINDOW;
SDL_Renderer *RENDERER;
SDL_Event EVENT;
const Uint8 *KEYBOARD_STATE;
int R = 0, G = 0, B = 0, A = 255;


void Engine_init(int window_width, int window_height, char title[]) {
    SDL_Init(SDL_INIT_VIDEO);

    WINDOW = SDL_CreateWindow(title, 50, 50, window_width, window_height, SDL_WINDOW_SHOWN);
    RENDERER = SDL_CreateRenderer(WINDOW, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    WINDOW_WIDTH = window_width;
    WINDOW_HEIGHT = window_height;
    
    KEYBOARD_STATE = SDL_GetKeyboardState(NULL);

    SDL_SetRelativeMouseMode(SDL_TRUE);
}

void Engine_update(void) {
	SDL_RenderPresent(RENDERER);
}

bool Engine_event_status(void) {
    return SDL_PollEvent(&EVENT) != 0;
}

bool Engine_event_exit() {
    return !(EVENT.type == SDL_QUIT || KEYBOARD_STATE[SDL_SCANCODE_ESCAPE]);
}

void Engine_exit(void) {
	SDL_DestroyRenderer(RENDERER);
    SDL_DestroyWindow(WINDOW);
    SDL_Quit();
}


void set_color(int r, int g, int b) {
    R = r;
    G = g;
    B = b;
    SDL_SetRenderDrawColor(RENDERER, R, G, B, A);
}

void set_transparency(int a) {
    A = a;
    SDL_SetRenderDrawColor(RENDERER, R, G, B, A);
}

void fill(void) {
	SDL_RenderClear(RENDERER);
}

void draw_circle(double x, double y, double radius) {
	for (int i = y - radius; i <= y + radius; ++i) {
		for (int j = x - radius; j <= x + radius; ++j) {
    		if ((j - x) * (j - x) + (i - y) * (i - y) <= radius * radius) {
    			SDL_RenderDrawPoint(RENDERER, j, WINDOW_HEIGHT - i);
    		}
    	}
    }
}

void draw_line(double x1, double y1, double x2, double y2) {
    SDL_RenderDrawLine(RENDERER, x1, WINDOW_HEIGHT - y1, x2, WINDOW_HEIGHT - y2);
}

void draw_polygon_mesh(Vector4 **triangle) {
    set_color(255, 255, 255);
    for (int i = 0; i < 2; ++i) {
        draw_line(triangle[i]->x, triangle[i]->y, triangle[i + 1]->x, triangle[i + 1]->y);
    }
    draw_line(triangle[0]->x, triangle[0]->y, triangle[2]->x, triangle[2]->y);

    // set_color(255, 20, 40);
    // for (int i = 0; i < 3; ++i) {
    //     draw_circle(triangle[i]->x, triangle[i]->y, 3);
    // }
}