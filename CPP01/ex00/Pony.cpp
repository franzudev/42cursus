//
// Created by Federico François on 20/05/21.
//

#include "Pony.hpp"

Pony::Pony(): legs(4), age(10), height(120) {}

Pony::Pony(int ponyType): legs(4), age(10), height(120){
	type = ponyType;
}

void Pony::ponyEat() {
	if (type && age && legs && height)
		std::cout << "Pony on the heap is eating" << std::endl;
	else
		std::cout << "Pony on the stack is eating" << std::endl;
}

void Pony::ponyRun() {
	if (type)
		std::cout << "Pony on the heap is running" << std::endl;
	else
		std::cout << "Pony on the stack is running" << std::endl;
}

void Pony::ponySleep() {
	if (type)
		std::cout << "Pony on the heap is sleeping" << std::endl;
	else
		std::cout << "Pony on the stack is sleeping" << std::endl;
}