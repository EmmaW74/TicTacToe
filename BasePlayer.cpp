#include "BasePlayer.h"


BasePlayer::BasePlayer() :
	name{ "Player" }, XorO{ Token::NONE }{
}

BasePlayer::BasePlayer(std::string name, Token XorO) :
	name{ name }, XorO{ XorO } {};
