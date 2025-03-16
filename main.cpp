#include <SDL3/SDL.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_video.h>
#include <string>
constexpr int kScreenWidth{640};
constexpr int kScreenHeight{480};

bool init();
bool loadMedia();
void close();
SDL_Window *gWindow{nullptr};
SDL_Surface *gScreenSurface{nullptr};
SDL_Surface *gHelloWorld{nullptr};
// Initialize SDL
bool init() {
  bool success{true};
  // Init SDL, close if fails
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("SDL could not initialize! SDL error: %s\n", SDL_GetError());
    success = false;
  } else {
    if (gWindow =
            SDL_CreateWindow("SDL3 Tutorial", kScreenWidth, kScreenHeight, 0);
        gWindow == nullptr) {
      SDL_Log("Failed to create window: %s\n", SDL_GetError());
      success = false;

    } else {
      gScreenSurface = SDL_GetWindowSurface(gWindow);
    }
  }
  return success;
}
// cleanup the mess
void close() {
  // Clean up surface
  SDL_DestroySurface(gHelloWorld);
  gHelloWorld = nullptr;

  // Destroy window
  SDL_DestroyWindow(gWindow);
  gWindow = nullptr;
  gScreenSurface = nullptr;

  // Quit SDL subsystems
  SDL_Quit();
}
int main() {
  int exitCode{0};

  // Initialize
  if (!init()) {
    SDL_Log("Unable to initialize program!\n");
    exitCode = 1;
  } else {
    // Load media
    // if (!loadMedia()) {
    //  SDL_Log("Unable to load media!\n");
    //  exitCode = 2;
    //}
    // The quit flag
    bool quit{false};
    SDL_Event e;
    SDL_zero(e);
    while (quit == false) {
      while (SDL_PollEvent(&e)) {
        if (e.type == SDL_EVENT_QUIT) {
          quit = true;
        }
      }
    }
  }

  close();
  return exitCode;
}
