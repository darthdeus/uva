CC=clang++ -std=c++11 -g -Wall

decoder:
	@$(CC) decoder.cpp -o bin/decoder
	@./bin/decoder

scramble:
	@$(CC) scramble.cpp -o bin/scramble
	@./bin/scramble

jolly:
	@$(CC) jolly.cpp -o bin/jolly
	@./bin/jolly
