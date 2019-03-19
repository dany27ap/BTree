#pragma once
#define f 2


struct BTree {
	char tipNod;
	int nrChei;
	int cheie[2 * f - 1];
	int data[2 * f - 1];
	BTree *fiu[2 * f - 1];
};

void creeazaBarbore(BTree *&t);
void spargeNod(BTree*& u, int i, BTree*& v);
void insereazainNodIncomplet(BTree *v, int k);
void insereazaBarbore(BTree *&t, int k);
bool cautareBarbore(BTree *v, int k);
void parcurgereBarbore(BTree *t);
