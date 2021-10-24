/*****************************************************************************************
* Programmer: Josh Maloy                                                                 *
* Class: CptS 122, Fall 2021; Lab Section 1                                              *
* Programming Assignment: PA6                                                            *
* Date: October 24, 2021                                                                 *
* Description: this program defines a template for an incredibly useless class that holds*
* two data types                                                                         *
******************************************************************************************/

#pragma once
#include <string>
#include <iostream>
#include <fstream>

template<class from, class to>
class MorseData
{
public:
	MorseData(from newChar, to newMorse);
	from getChar();
	to getMorse();
private:
	from mCharacter;
	to mMorse;
};

template<class from, class to>
MorseData<from, to>::MorseData(from newChar, to newMorse)
{
	this->mCharacter = newChar;
	this->mMorse = newMorse;
}

template<class from, class to>
from MorseData<from, to>::getChar()
{
	return this->mCharacter;
}

template<class from, class to>
to MorseData<from, to>::getMorse()
{
	return this->mMorse;
}


