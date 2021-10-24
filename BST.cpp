#include "BST.h"

BST::BST()
{
	this->mpRoot = nullptr;
	this->morseFile.open("MorseTable.txt", std::ios::in);
	char tempChar;
	std::string tempString;
	while (!morseFile.eof())
	{
		getline(morseFile, tempString);   //grabbing the line with char in it
		tempChar = tempString.c_str()[0]; //taking the char out of it and putting into new variable
		getline(morseFile, tempString);   //grabbing the morse string that goes with it
		insert(this->mpRoot, tempChar, tempString);  //inserting the new node into the tree
	}

}

BST::~BST()
{
	chopTree(this->mpRoot);
}

void BST::print() const
{
	printTree(this->mpRoot);
}

void BST::printTree(BSTNode* pTree) const
{
	if (pTree != nullptr) //inorder traversal with print. format: [A] = [.-]
	{
		printTree(pTree->getLeftPtr());
		std::cout << "[" << pTree->getChar() << "] = [" << pTree->getMorse() << "]" << std::endl;
		printTree(pTree->getRightPtr());
	}
}

std::string BST::search(char searchChar) const
{
	std::string result = "error";
	searchTree(this->mpRoot, searchChar, &result);
	return result;
}

void BST::searchTree(BSTNode* pTree, char searchChar, std::string* result) const
{
	if (pTree != nullptr)
	{
		searchTree(pTree->getLeftPtr(), searchChar, result);
		if (pTree->getChar() == searchChar) *result = pTree->getMorse();
		searchTree(pTree->getRightPtr(), searchChar, result);
	}
}

void BST::insert(BSTNode* pTree, char newChar, std::string newMorse)
{
	if (pTree == nullptr)
	{
		this->mpRoot = new BSTNode(newChar, newMorse);
	}
	else if (pTree->getChar() > newChar)
	{
		if (pTree->getLeftPtr() != nullptr)
		{
			insert(pTree->getLeftPtr(), newChar, newMorse);
		}
		else
		{
			pTree->setLeftPtr(new BSTNode(newChar, newMorse));
		}
	}
	else if (pTree->getChar() < newChar)
	{
		if (pTree->getRightPtr() != nullptr)
		{
			insert(pTree->getRightPtr(), newChar, newMorse);
		}
		else
		{
			pTree->setRightPtr(new BSTNode(newChar, newMorse));
		}
	}
	else
	{
		std::cout << "ERROR: duplicate entered into the tree" << std::endl;
	} 
}

void BST::chopTree(BSTNode* pTree)
{
	if (pTree != nullptr)
	{
		chopTree(pTree->getLeftPtr());
		chopTree(pTree->getRightPtr());
		delete pTree;
	}
}