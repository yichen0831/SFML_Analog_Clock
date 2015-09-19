CC = g++
target = SFML_Analog_Clock
c++11 = -std=c++11
SFML = -lsfml-graphics -lsfml-window -lsfml-system

all: $(target)

$(target): main.o Clock.o
	$(CC) Clock.o main.o $(SFML) -o SFML_Analog_Clock

main.o: main.cpp
	$(CC) -c main.cpp $(c++11)

Clock.o: Clock.cpp Clock.hpp
	$(CC) -c Clock.cpp $(c++11)

clean:
	rm $(target) main.o Clock.o
