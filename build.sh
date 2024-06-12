#g++ -o game main.cpp paddle.cpp -lraylib -lm && ./game
g++ -o game main.cpp paddle.cpp ball.cpp player.cpp -lraylib -lm -lGL -lglfw -lpthread -lrt -lX11 -ldl && ./game
