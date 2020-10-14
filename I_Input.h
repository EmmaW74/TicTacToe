#pragma once
#include "Grid.h"
#include "Token_enum.h"

class I_Input
{

public:
	I_Input();
	virtual std::string get_cell() const = 0;
	virtual std::string request_name(const std::string &name) const = 0;
	virtual std::string random_name(const std::string &name) const = 0;
	virtual bool play_again() const = 0;
	virtual ~I_Input() = 0;
};

