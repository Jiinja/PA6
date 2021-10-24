/*****************************************************************************************
* Programmer: Josh Maloy                                                                 *
* Class: CptS 122, Fall 2021; Lab Section 1                                              *
* Programming Assignment: PA6                                                            *
* Date: October 24, 2021                                                                 *
* Description: this program defines a BSTNode for use in the BST for translation         *
******************************************************************************************/

#pragma once
#include "MorseData.h"

template<class from, class to>
class BSTNode
{
public:
	BSTNode(from newChar, to newMorse);
	~BSTNode();
	BSTNode<from, to>* getRightPtr();
	BSTNode<from, to>* getLeftPtr();
	void setRightPtr(BSTNode<from, to>* newNode);
	void setLeftPtr(BSTNode<from, to>* newNode);
	from getChar();
	to getMorse();
private:
	MorseData<from, to>* mpData;
	BSTNode<from, to>* mpLeft;
	BSTNode<from, to>* mpRight;
};

template<class from, class to>
BSTNode<from, to>::BSTNode(from newChar, to newMorse)
{
	this->mpRight = nullptr;
	this->mpLeft = nullptr;
	this->mpData = new MorseData<from, to>(newChar, newMorse);
}

template<class from, class to>
BSTNode<from, to>::~BSTNode()
{
	delete this->mpData;
	this->mpRight = nullptr;
	this->mpLeft = nullptr;
}

template<class from, class to>
BSTNode<from, to>* BSTNode<from, to>::getRightPtr()
{
	return this->mpRight;
}

template<class from, class to>
BSTNode<from, to>* BSTNode<from, to>::getLeftPtr()
{
	return this->mpLeft;
}

template<class from, class to>
void BSTNode<from, to>::setRightPtr(BSTNode<from, to>* newNode)
{
	this->mpRight = newNode;
}

template<class from, class to>
void BSTNode<from, to>::setLeftPtr(BSTNode<from, to>* newNode)
{
	this->mpLeft = newNode;
}

template<class from, class to>
from BSTNode<from, to>::getChar()
{
	return this->mpData->getChar();
}

template<class from, class to>
to BSTNode<from, to>::getMorse()
{
	return this->mpData->getMorse();
}


