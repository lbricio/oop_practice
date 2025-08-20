all:
	g++ main.cpp src/* -Iinclude -pthread -lgtest -lgtest_main -o main
	./main && rm main

test:
	g++ test.cpp src/* tests/* -Iinclude -pthread -lgtest -lgtest_main -o test
	./test && rm test
