@echo off
g++ -Isrc/include -c main.cpp

g++ main.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

start main.exe
