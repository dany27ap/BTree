#include <iostream>
#include "BTree.h"

void creeazaBarbore(BTree*& t) {
	t = new BTree;
	t->tipNod = 'f';
	t->nrChei = 0;
}

void spargeNod(BTree*& u, int i, BTree*& v) {
	BTree *w = new BTree;
	w->tipNod = v->tipNod;
	w->nrChei = f - 1;
	
	for (int j = 0; j <= f - 2; ++j)
		w->cheie[j] = v->cheie[j + f];
	if (v->tipNod == 'i') {
		for (int j = 0; j <= f - 1; ++j) {
			w->fiu[j] = v->fiu[j + f];
		}
		v->nrChei = f - 1;
	}
	for (int j = u->nrChei; j >= i + 1; --j) {
		u->fiu[j + 1] = u->fiu[j];
	}
	u->fiu[i + 1] = w;
	for (int j = u->nrChei - 1; j >= i; --j) {
		u->cheie[j + 1] = u->cheie[j];
	}

	u->cheie[i] = v->cheie[f - 1];
	u->nrChei++;
}

void insereazainNodIncomplet(BTree * v, int k) {
	int i = v->nrChei - 1;
	if (v->tipNod == 'f') {
		while (i >= 0 && k < v->cheie[i]) {
			v->cheie[i + 1] = v->cheie[i];
			i--;
		}
		v->cheie[i + 1] = k;
		v->nrChei++;
	} else {
		while (i >= 0 && k < v->cheie[i])
			i--;
		i++;
		if (v->fiu[i]->nrChei == 2 * f - 1) {
			spargeNod(v, i, v->fiu[i]);
			if (k > v->cheie[i])
				i++;
		}
		insereazainNodIncomplet(v->fiu[i], k);
	}
}

void insereazaBarbore(BTree*& t, int k) {
	BTree *v = t;
	if (v->nrChei == 2 * f - 1) {
		BTree *u = new BTree;
		t = u;
		u->tipNod = 'i';
		u->nrChei = 0;
		u->fiu[0] = v;
		spargeNod(u, 0, v);
		insereazainNodIncomplet(u, k);
	} else {
		insereazainNodIncomplet(v, k);
	}
}

bool cautareBarbore(BTree* v, int k) {
	int i = 0;
	while (i < v->nrChei && k > v->cheie[i])
		i++;
	if (i < v->nrChei && k == v->cheie[i])
		return true;
	if (v->tipNod == 'f')
		return false;
	else
		return cautareBarbore(v->fiu[i], k);
}

void parcurgereBarbore(BTree * t) {
	if (t->tipNod == 'f') {
		for (int i = 0; i < t->nrChei; ++i)
			std::cout << t->cheie[i] << " ";
	} else {
		for (int i = 0; i < t->nrChei; ++i) {
			parcurgereBarbore(t->fiu[i]);
			std::cout << t->cheie[i] << " ";
		}
		parcurgereBarbore(t->fiu[t->nrChei]);
	}
}
