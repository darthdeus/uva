CC=clang++ -std=c++11 -g -Wall

scramble:
	@$(CC) scramble.cpp -o bin/scramble
	@./bin/scramble
