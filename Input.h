#pragma once
#include "I_Input.h"
#include "Grid.h"
#include "Token_enum.h"
#include <memory>

class Input :
	public I_Input
{

public:
	Input();
	virtual std::string get_cell() const override;
	virtual std::string request_name(const std::string &name) const override;
	virtual std::string random_name(const std::string &name) const override;
	virtual bool play_again() const override;
	~Input() = default;
};

