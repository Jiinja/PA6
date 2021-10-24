#include "MorseData.h"

MorseData::MorseData(char newChar, std::string newMorse)
{
	this->mCharacter = newChar;
	this->mMorse = newMorse;
}

char MorseData::getChar()
{
	return this->mCharacter;
}

std::string MorseData::getMorse()
{
	return this->mMorse;
}
