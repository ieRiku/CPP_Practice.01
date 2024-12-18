# 64bit g++ compiler
#g++ f1.cpp -I pak1/include -L pak1/lib -lSDL2   # so basically its the 64 bit library version.

# this command for 32 bit lib,include and compiler compiles but a.exe doesn't run.
#g++ f1.cpp -I pak32/include -L pak32/lib -m32 -lmingw32 -lSDL2main -lSDL2    # the current compiler(mingw64 bit version) doesn't work with 32bit

# This one works with int WinMain() function
#g++ f1.cpp -I pak64/include -L pak64/lib -m64 -lSDL2       # 64 bit .exe compilation # pak64 is 64 bit library and header files of SDL2

# This one works with int main() function
g++ f1.cpp -I pak64/include -L pak64/lib -m64 -lmingw32 -lSDL2main -lSDL2      # 64 bit .exe compilation # pak64 is 64 bit library and header files of SDL2
