#include <iostream>
#include "BTree.h"

int main() {
	BTree *root;
	creeazaBarbore(root);
	for (int i = 0; i < 15; ++i) {
		int v1 = rand() % 100;
		insereazaBarbore(root, v1);
	}
	parcurgereBarbore(root);
	std::cout << std::endl;
}