#include "number.h"
#include <bits/stdc++.h>

// some random c++

void CompactMatrix::printMatrix(){
	printf("\n");
	for (int i = 0; i < this -> r; i ++){
		for (int j = 0; j < this -> c; j ++) {
			printf("%d ", (*this)[i][j]);
		}
		printf("\n");
	}
}

void swap(Number &n) {
	int t = n.x;
	n.x = n.y;
	n.y = t; 
}

int n, t[4*10];

void build(int a[], int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = a[tl];
	} else {
		int tm = (tl + tr) / 2;
		build(a, v*2, tl, tm);
		build(a, v*2 + 1, tm + 1, tr);
		t[v] = t[v*2] + t[v*2 + 1];
	}
}

int sum(int v, int tl, int tr, int l, int r) {
	if (l > r) {
		return 0;
	} 
	if (tl == l && tr == r) {
		return t[v];
	} else {
		int tm = (tl + tr) / 2;
		return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2 + 1, tm + 1, tr,  max(l, tm + 1), r);
	}
}

void update(int v, int tl, int tr, int p, int u) {
	if (tl == tr) {
		t[v] = u;
	} else {
		int tm = (tl + tr) / 2;
		if (p <= tm)
			update(v*2, tl, tm, p, u);
		else
			update(v*2+1, tm + 1, tr, p, u);
		t[v] = t[v*2] + t[v*2+1];
	}
}
void add(int ft[], int idx, int value, int length) {
	for(; idx < length; idx = idx | idx + 1) {
		ft[idx] += value;
	}
}
void buildFt(int ft[], int a[], int length) {
	for (int i = 0; i < length; i ++) {
		add(ft, i, a[i], length);
	}
}


int sumFt(int ft[], int r) {
	int ans = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1) {
		ans += ft[r];
	}
	return ans;
}

int main() {
	int a[] = {1,5,3,5,6,7,7,7,10};
	int length = sizeof(a) / sizeof(a[0]);
	int *ft = new int[length];
	buildFt(ft, a, length);
	for (int i = 0; i < length; i ++) {
		cout << ft[i] << " ";
	}
	cout << endl;

	//build(a, 1, 0, length - 1);
	cout << sum(1, 0, length - 1, 0, 1);
	cout << sumFt(ft, 1);
	

}
