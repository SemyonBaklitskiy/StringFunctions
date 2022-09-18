.PHONY: all clean puts strlen strchr strcpy strncpy strcat strncat fgets strdup getline

all: functions.o test.o
	g++ -Wall -Wextra -c main.cpp -o main.o
	g++ -Wall -Wextra main.o functions.o test.o -o start
	./start

functions.o: functions.cpp
	g++ -Wall -Wextra -c functions.cpp -o functions.o

test.o: test.cpp
	g++ -Wall -Wextra -c test.cpp -o test.o

puts: functions.o test.o
	g++ -Wall -Wextra -c -D PUTS main.cpp -o main.o
	g++ -Wall -Wextra main.o functions.o test.o -o start
	./start

strlen: functions.o test.o
	g++ -Wall -Wextra -c -D STRLEN main.cpp -o main.o
	g++ -Wall -Wextra main.o functions.o test.o -o start
	./start

strchr: functions.o test.o
	g++ -Wall -Wextra -c -D STRCHR main.cpp -o main.o
	g++ -Wall -Wextra main.o functions.o test.o -o start
	./start

strcpy: functions.o test.o
	g++ -Wall -Wextra -c -D STRCPY main.cpp -o main.o
	g++ -Wall -Wextra main.o functions.o test.o -o start
	./start

strncpy: functions.o test.o
	g++ -Wall -Wextra -c -D STRNCPY main.cpp -o main.o
	g++ -Wall -Wextra main.o functions.o test.o -o start
	./start

strcat: functions.o test.o
	g++ -Wall -Wextra -c -D STRCAT main.cpp -o main.o
	g++ -Wall -Wextra main.o functions.o test.o -o start
	./start

strncat: functions.o test.o
	g++ -Wall -Wextra -c -D STRNCAT main.cpp -o main.o
	g++ -Wall -Wextra main.o functions.o test.o -o start
	./start

fgets: functions.o test.o
	g++ -Wall -Wextra -c -D FGETS main.cpp -o main.o
	g++ -Wall -Wextra main.o functions.o test.o -o start
	./start

strdup: functions.o test.o
	g++ -Wall -Wextra -c -D STRDUP main.cpp -o main.o
	g++ -Wall -Wextra main.o functions.o test.o -o start
	./start

getline: functions.o test.o
	g++ -Wall -Wextra -c -D GETLINE main.cpp -o main.o
	g++ -Wall -Wextra main.o functions.o test.o -o start
	./start

clean: 
	rm main.o functions.o test.o start