class Number {
public:
	int x;
	int y;

    Number(int x, int y) {
		this->x = x;
		this->y = y;
	}

	int add();
};

class Matrix {
protected:
	int r;
	int c;
public:
	int array[2] = {1,2};
	int **m;
	Matrix(int r, int c) {
		this->r = r;
		this->c = c;
		this -> m = new int*[r];
		for (int i = 0; i < c; i ++) {
			this -> m[i] = new int[c];
		}
	}
	void printMatrix();
};

class CompactMatrix : public Matrix {
	public:
	int *m;
	CompactMatrix(int r, int c): Matrix(r,c) {
		this -> r = r;
		this -> c = c;
		this -> m = new int[r*c];
	}
	class getIndex {
		friend class CompactMatrix;
	public:
		int baseIndex;
		CompactMatrix& co;
		int& operator[](int col) {
			return co.m[baseIndex + col];
		}
		getIndex(CompactMatrix &co, int row): co(co) {
			this -> baseIndex = row * (co.c);
		}
	};
	getIndex operator[](int row) {
		return getIndex(*this, row);
	}
	void printMatrix();
};


