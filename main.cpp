/*****************************************************************************************
* Programmer: Josh Maloy                                                                 *
* Class: CptS 122, Fall 2021; Lab Section 1                                              *
* Programming Assignment: PA6                                                            *
* Date: October 24, 2021                                                                 *
* Description: this program creates a BST and translates normal english to morse code    *
******************************************************************************************/
#include "BST.h"

//
// Connor, in the assignment instructions, next to FULLSTOP, there is no charcater. I took the liberty of making that character that means that '~'.
// I then realized that in the sample text, '.' is the character for FULLSTOP. this messes up the balance of my tree, so I am just going to continue to use '~'
// thank you for understanding. I made the tree by hand (hardest part of this assignment tbh) and I don't want to redo the order in the file.
//
// I made a git repo and had a version history and then git said my version was out of date. I synced it and it put a bunch of random characters all over my assignment
// So, i redid the repo and it doesn't have any version history anymore. if you could still give me that extra point bc VS is trash, I would appreciate it but idc its only 1 point
//

int main()
{
	BST<char, std::string> myBST;
	myBST.print();
	myBST.convert();
	
	return 0;
}


//BASIC/ASCII ORDER
//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39
//, 1 2 3 4 5 6 7 8 9  0  ?  A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z  ~


//ORDER I WANT
//
//16 8 4 12 2 6 10 14 1 3 5 7 9 11 13 15 24 20 28 18 22 26 30 17 19 21 23 25 27 29 35 33 38 31 34 36 39 32 37
//16, 8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15, 24, 20, 28, 18, 22, 26, 30, 17, 19, 21, 23, 25, 27, 29, 35, 33, 38, 31, 34, 36, 39, 32, 37