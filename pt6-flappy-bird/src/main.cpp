#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

// Define screen dimensions
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Initialize SDL_image
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        std::cerr << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow("Flappy Bird Clone",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // Load Background (PNG)
    SDL_Surface* bgSurface = IMG_Load("textures/images/background.png");
    if (!bgSurface) {
        std::cerr << "Failed to load background image! SDL_image Error: " << IMG_GetError() << std::endl;
    }
    SDL_Texture* background = SDL_CreateTextureFromSurface(renderer, bgSurface);
    SDL_FreeSurface(bgSurface);
    if (!background) {
        std::cerr << "Failed to create background texture! SDL_Error: " << SDL_GetError() << std::endl;
    }

    // Load Flappy Bird (PNG)
    SDL_Surface* birdSurface = IMG_Load("textures/images/plane.png");
    if (!birdSurface) {
        std::cerr << "Failed to load bird image! SDL_image Error: " << IMG_GetError() << std::endl;
    }
    SDL_Texture* birdTexture = SDL_CreateTextureFromSurface(renderer, birdSurface);
    SDL_FreeSurface(birdSurface);
    if (!birdTexture) {
        std::cerr << "Failed to create bird texture! SDL_Error: " << SDL_GetError() << std::endl;
    }
    SDL_Rect birdRect = { 100, SCREEN_HEIGHT / 2 - 25, 50, 50 }; // Initial position and size

    // Load Ground (PNG)
    SDL_Surface* groundSurface = IMG_Load("textures/images/ground.png");
    if (!groundSurface) {
        std::cerr << "Failed to load ground image! SDL_image Error: " << IMG_GetError() << std::endl;
    }
    SDL_Texture* groundTexture = SDL_CreateTextureFromSurface(renderer, groundSurface);
    SDL_FreeSurface(groundSurface);
    if (!groundTexture) {
        std::cerr << "Failed to create ground texture! SDL_Error: " << SDL_GetError() << std::endl;
    }
    SDL_Rect groundRect = { 0, SCREEN_HEIGHT - 100, SCREEN_WIDTH, 100 }; // Position at bottom

    // Load Obstacle (Tower PNG)
    SDL_Surface* obstacleSurface = IMG_Load("textures/images/tower.png");
    if (!obstacleSurface) {
        std::cerr << "Failed to load obstacle image! SDL_image Error: " << IMG_GetError() << std::endl;
    }
    SDL_Texture* obstacleTexture = SDL_CreateTextureFromSurface(renderer, obstacleSurface);
    SDL_FreeSurface(obstacleSurface);
    if (!obstacleTexture) {
        std::cerr << "Failed to create obstacle texture! SDL_Error: " << SDL_GetError() << std::endl;
    }
    SDL_Rect obstacleRect = { SCREEN_WIDTH, SCREEN_HEIGHT - 150, 50, 150 }; // Initial obstacle position

    bool running = true;
    SDL_Event event;

    // Ground movement variables
    int groundSpeed = 5;

    // Obstacle movement variables
    int obstacleSpeed = 5;

    // Main game loop
    while (running) {
        // Event handling
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            // Handle space or left mouse click for flapping
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_SPACE) {
                    // Implement flapping logic here
                }
            }
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    // Implement flapping logic here
                }
            }
        }

        // Update obstacle position
        obstacleRect.x -= obstacleSpeed;
        if (obstacleRect.x < -50) { // If obstacle moves off screen
            obstacleRect.x = SCREEN_WIDTH;
            // Randomize obstacle height here
            obstacleRect.y = SCREEN_HEIGHT - 150; // Example fixed position
        }

        // Update ground position
        groundRect.x -= groundSpeed;
        if (groundRect.x <= -SCREEN_WIDTH) {
            groundRect.x = 0;
        }

        // Render
        SDL_RenderClear(renderer);

        // Render background
        SDL_RenderCopy(renderer, background, NULL, NULL);

        // Render obstacles
        SDL_RenderCopy(renderer, obstacleTexture, NULL, &obstacleRect);

        // Render ground
        SDL_RenderCopy(renderer, groundTexture, NULL, &groundRect);
        SDL_Rect groundRectDuplicate = groundRect;
        groundRectDuplicate.x += SCREEN_WIDTH;
        SDL_RenderCopy(renderer, groundTexture, NULL, &groundRectDuplicate);

        // Render flappy bird
        SDL_RenderCopy(renderer, birdTexture, NULL, &birdRect);

        SDL_RenderPresent(renderer);

        // Delay to control frame rate
        SDL_Delay(16); // Approximately 60 FPS
    }

    // Clean up
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(birdTexture);
    SDL_DestroyTexture(groundTexture);
    SDL_DestroyTexture(obstacleTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}