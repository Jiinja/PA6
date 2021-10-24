/*****************************************************************************************
* Programmer: Josh Maloy                                                                 *
* Class: CptS 122, Fall 2021; Lab Section 1                                              *
* Programming Assignment: PA6                                                            *
* Date: October 24, 2021                                                                 *
* Description: this program defines a template for a BST that translates english to morse code*
******************************************************************************************/

#pragma once
#include "BSTNode.h"

template<class from, class to>
class BST
{
public:
	BST();
	~BST();
	void print() const;
	void convert();
private:
	to search(from searchChar) const;
	void printTree(BSTNode<from, to>* pTree, int counter) const;
	void searchTree(BSTNode<from, to>* pTree, from searchChar, to* result) const;
	void insert(BSTNode<from, to>* pTree, from newChar, to newMorse);
	void chopTree(BSTNode<from, to>* pTree);
	std::fstream morseFile;
	BSTNode<from, to>* mpRoot;
};

template<class from, class to>
BST<from, to>::BST()
{
	this->mpRoot = nullptr;
	this->morseFile.open("MorseTable.txt", std::ios::in);
	from tempChar;
	to tempString;
	while (!morseFile.eof())
	{
		getline(morseFile, tempString);   //grabbing the line with char in it
		tempChar = tempString.c_str()[0]; //taking the char out of it and putting into new variable
		getline(morseFile, tempString);   //grabbing the morse string that goes with it
		insert(this->mpRoot, tempChar, tempString);  //inserting the new node into the tree
	}
	this->morseFile.close();
}

template<class from, class to>
BST<from, to>::~BST()
{
	chopTree(this->mpRoot);
}

template<class from, class to>
void BST<from, to>::convert() 
{
	this->morseFile.open("Convert.txt", std::ios::in);
	to tempString;
	while (!this->morseFile.eof())
	{
		getline(this->morseFile, tempString);
		std::string::iterator decipherer = tempString.begin();
		while (decipherer != tempString.end())
		{
			if (*decipherer == ' ')
			{
				std::cout << "   ";
			}
			else
			{
				std::cout << search(std::toupper(*decipherer));
			}
			std::cout << " ";
			decipherer++;
		}
		std::cout << std::endl;
	}
	morseFile.close();
}

template<class from, class to>
void BST<from, to>::print() const
{
	printTree(this->mpRoot, 0);
}

template<class from, class to>
void BST<from, to>::printTree(BSTNode<from, to>* pTree, int counter) const
{
	if (pTree != nullptr) //inorder traversal with print. format: [A] = [.-]
	{
		printTree(pTree->getLeftPtr(), counter);
		std::cout << "[" << pTree->getChar() << "] = [" << pTree->getMorse() << "]" << std::endl;
		printTree(pTree->getRightPtr(), counter);
	}
}

template<class from, class to>
to BST<from, to>::search(from searchChar) const
{
	to result = "error";
	searchTree(this->mpRoot, searchChar, &result);
	return result;
}

template<class from, class to>
void BST<from, to>::searchTree(BSTNode<from, to>* pTree, from searchChar, to* result) const
{
	if (pTree != nullptr)
	{
		searchTree(pTree->getLeftPtr(), searchChar, result);
		if (pTree->getChar() == searchChar) *result = pTree->getMorse();
		searchTree(pTree->getRightPtr(), searchChar, result);
	}
}

template<class from, class to>
void BST<from, to>::insert(BSTNode<from, to>* pTree, from newChar, to newMorse)
{
	if (pTree == nullptr)
	{
		this->mpRoot = new BSTNode<from, to>(newChar, newMorse);
	}
	else if (pTree->getChar() > newChar)
	{
		if (pTree->getLeftPtr() != nullptr)
		{
			insert(pTree->getLeftPtr(), newChar, newMorse);
		}
		else
		{
			pTree->setLeftPtr(new BSTNode<from, to>(newChar, newMorse));
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
			pTree->setRightPtr(new BSTNode<from, to>(newChar, newMorse));
		}
	}
	else
	{
		std::cout << "ERROR: duplicate entered into the tree" << std::endl;
	}
}

template<class from, class to>
void BST<from, to>::chopTree(BSTNode<from, to>* pTree)
{
	if (pTree != nullptr)
	{
		chopTree(pTree->getLeftPtr());
		chopTree(pTree->getRightPtr());
		delete pTree;
	}
}

