#include <SDL.h>
#include <iostream>

int main() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create an SDL Window
    SDL_Window* win = SDL_CreateWindow("Red Block Drawer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (win == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create an SDL Renderer
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    // Get block dimensions from user
    int width, height;
    std::cout << "Enter the width of the block: ";
    std::cin >> width;
    std::cout << "Enter the height of the block: ";
    std::cin >> height;

    // Block position
    int x = (800 - width) / 2; // Center the block horizontally
    int y = (600 - height) / 2; // Center the block vertically

    bool running = true;
    SDL_Event event;

    while (running) {
        // Event handling
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
                running = false;
            }
        }

        // Clear the screen
        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255); // Black background
        SDL_RenderClear(ren);

        // Draw the red block
        SDL_Rect rect = {x, y, width, height};
        SDL_SetRenderDrawColor(ren, 255, 0, 0, 255); // Red color
        SDL_RenderFillRect(ren, &rect);

        // Present the renderer
        SDL_RenderPresent(ren);
    }

    // Cleanup
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}