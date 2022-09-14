.PHONY: all clean puts strlen strchr strcpy strncpy strcat strncat fgets strdup getline

all: functions.o 
	g++ -Wall -Wextra -c main.cpp -o main.o
	g++ -Wall -Wextra main.o functions.o -o start
	./start

functions.o: functions.cpp
	g++ -Wall -Wextra -c functions.cpp -o functions.o

puts: functions.o
	g++ -Wall -Wextra -c -D PUTS main.cpp -o main.o
	g++ -Wall -Wextra main.o functions.o -o start
	./start

strlen: functions.o
	g++ -Wall -Wextra -c -D STRLEN main.cpp -o main.o
	g++ -Wall -Wextra main.o functions.o -o start
	./start

strchr: functions.o 
	g++ -Wall -Wextra -c -D STRCHR main.cpp -o main.o
	g++ -Wall -Wextra main.o functions.o -o start
	./start

strcpy: functions.o 
	g++ -Wall -Wextra -c -D STRCPY main.cpp -o main.o
	g++ -Wall -Wextra main.o functions.o -o start
	./start

strncpy: functions.o 
	g++ -Wall -Wextra -c -D STRNCPY main.cpp -o main.o
	g++ -Wall -Wextra main.o functions.o -o start
	./start

strcat: functions.o 
	g++ -Wall -Wextra -c -D STRCAT main.cpp -o main.o
	g++ -Wall -Wextra main.o functions.o -o start
	./start

strncat: functions.o 
	g++ -Wall -Wextra -c -D STRNCAT main.cpp -o main.o
	g++ -Wall -Wextra main.o functions.o -o start
	./start

fgets: functions.o 
	g++ -Wall -Wextra -c -D FGETS main.cpp -o main.o
	g++ -Wall -Wextra main.o functions.o -o start
	./start

strdup: functions.o 
	g++ -Wall -Wextra -c -D STRDUP main.cpp -o main.o
	g++ -Wall -Wextra main.o functions.o -o start
	./start

getline: functions.o
	g++ -Wall -Wextra -c -D GETLINE main.cpp -o main.o
	g++ -Wall -Wextra main.o functions.o -o start
	./start

clean: 
	rm main.o functions.o start