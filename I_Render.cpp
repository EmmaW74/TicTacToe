#include "I_Render.h"
#include <iostream>

I_Render::I_Render() {
}

void I_Render::playing(std::string name) const {
	std::cout << name << " is taking their turn..." << std::endl;
}
I_Render::~I_Render() {};

