scrat: orario.o main.o
        g++ -o scrat orario.o main.o
orario.o: orario.cpp
        g++ -c orario.cpp
main.o: main.cpp
        g++ -c main.cpp
