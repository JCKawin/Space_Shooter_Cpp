rm -rf bin
mkdir bin
g++ src/main.cpp -o bin/mygame -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
