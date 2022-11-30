#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void) {
    std::cout << "Constructor caled" << std::endl;
    Sample::_rbInst += 1;

    return;
}

Sample::~Sample(void) {
    std::cout << "Destructor called" << std::endl;
    Sample::_rbInst -= 1;
    return;
}

int Sample::getNbInst(void) {
    return Sample::_rbInst;
}

int Sample::_rbInst = 0;