# This one works with int main() function
g++ f1.cpp -I pak64/include -I pak64/include/SDL2 -I pak64-img/include -L pak64-img/lib -L pak64/lib -m64 -lmingw32 -lSDL2main -lSDL2 -lSDL2_image      # 64 bit .exe compilation # pak64 is 64 bit library and header files of SDL2
