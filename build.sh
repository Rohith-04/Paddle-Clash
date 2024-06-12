#g++ -o game main.cpp paddle.cpp -lraylib -lm && ./game
g++ -o game main.cpp src/paddle.cpp src/ball.cpp src/player.cpp -lraylib -lm -lGL -lglfw -lpthread -lrt -lX11 -ldl && ./game
