# Issues i faced when i was making the pt6-flappy bird
## First issue was linking SDL2.h file as it used to not link.

resolved by adding 
#include <SDL2/SDL.h>

I think its due to the path issue as
./pak64/include does not have SDL.h
./pak64/include/SDL2/ has it.

## Then using other flags like -SDLMain -lmingw32 -lSDL2 it was cleared

# Then when adding the SDL_image.h i faced another issue.
## as it said it can't find SDL_image.h

It was resolved after adding
#include <SDL2/SDL_image.h>

# But new issue came as it said 

In file included from f1.cpp:3:
pak64-img/include/SDL2/SDL_image.h:32:10: fatal error: SDL.h: No such file or directory
   32 | #include "SDL.h"
      |          ^~~~~~~
compilation terminated.

## Issue was resolved after adding 
-L ./pak64/include/SDL2

# final compilation command :
g++ f1.cpp -I pak64/include -I pak64/include/SDL2 -I pak64-img/include -L pak64-img/lib -L pak64/lib -m64 -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

# Why ? i don't know. 
## originally both SDL.h and SDL_image.h is supposed to be added by including the parent directories. 

# Note: modify more if more errors appear in the future.
## update

Found the issue (I think)
As SDL_image.h
internally adds SDL.h so it can't find in included directory ./pak64/include/
As it is in ./pak64/include/SDL2

So i need to either change SDL_image.h file
Or i need to add another incude path ./pak64/include/SDL2
So that SDL_image.h can find {path_to_SDL.h}/SDL.h