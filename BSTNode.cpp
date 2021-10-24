#include "BSTNode.h"

BSTNode::BSTNode(char newChar, std::string newMorse)
{
	this->mpRight = nullptr;
	this->mpLeft = nullptr;
	this->mpData = new MorseData(newChar, newMorse);
}

BSTNode::~BSTNode()
{
	delete this->mpData;
	this->mpRight = nullptr;
	this->mpLeft = nullptr;
}

BSTNode* BSTNode::getRightPtr()
{
	return this->mpRight;
}

BSTNode* BSTNode::getLeftPtr()
{
	return this->mpLeft;
}

void BSTNode::setRightPtr(BSTNode* newNode)
{
	this->mpRight = newNode;
}

void BSTNode::setLeftPtr(BSTNode* newNode)
{
	this->mpLeft = newNode;
}

char BSTNode::getChar()
{
	return this->mpData->getChar();
}

std::string BSTNode::getMorse()
{
	return this->mpData->getMorse();
}
