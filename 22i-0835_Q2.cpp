#include"22i-0835_Q2.h"

Matrix::Matrix() {
	matrix = nullptr;
	row = 0;
	col = 0;
}

Matrix::Matrix(int r, int c) {
	row = r;
	col = c;
	matrix = new int* [row];
	for (int i = 0; i < row; i++) {
		matrix[i] = new int[col];
	}
}

Matrix::Matrix(const Matrix& mat) {
	row = mat.row;
	col = mat.col;
	matrix = new int* [row];
	for (int i = 0; i < row; i++) {
		matrix[i] = new int[col];
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matrix[i][j] = mat.matrix[i][j];
		}
	}
}

void Matrix::set(int i, int j, float val) {
	matrix[i][j] = val;
}

float Matrix::get(int i, int j)const {
	return matrix[i][j];
}

Matrix Matrix::multiplyElement(const Matrix mat) {
	Matrix m1(mat.row,mat.col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			m1.matrix[i][j] = matrix[i][j] * mat.matrix[i][j];
		}
	}
	return m1;
}

void Matrix::makeZero() {
	int x = 0; int y = 0;
	bool flag = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (matrix[i][j] == 0) {
				flag = true;
				x = i;
				y = j;
			}
		}
	}
	if (flag) {
		for (int i = 0; i < row; i++) {
			matrix[i][y] = 0;
		}
		for (int j = 0; j < col; j++) {
			matrix[x][j] = 0;
		}
	}
}

bool Matrix::searchNumber(int number) {
	int temp = number;
	int len = 0;
	while (temp != 0) {
		len++;
		temp /= 10;
	}
	temp = number;
	int size = len;
	
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
	for (int i = len - 1; i >= 0; i--) {
		arr[i] = temp % 10;
		temp = temp / 10;
	}

	bool found = 0;
	int y = 0;


	int a = 0, b = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (matrix[i][j]==arr[y]) {
				a = i;
				b = j;
				found = 1;
			}
			else {
			}
			

		}
	}
	y++;
	while (y < len && found) {
		if (arr[y] == matrix[a + 1][b]) {
			a++;
		}
		else if (arr[y] == matrix[a][b+1]) {
			b++;
		}
		else if (arr[y] == matrix[a - 1][b]) {
			a--;
		}
		else if (arr[y] == matrix[a][b-1]) {
			b--;
		}
		else {
			found = 0;
		}

		y++;

	}
	delete arr;

	return found;

	//while (found && y<len) {
	//	for (int i = 1; i < row-1; i++) {
	//		for (int j = 1; j < col-1; j++) {
	//			if (matrix[i][j] == arr[y]) {
	//				if (matrix[i + 1][j] == arr[y + 1] || matrix[i][j + 1] == arr[y + 1] || matrix[i - 1][j] == arr[y + 1] || matrix[i][j - 1] == arr[y + 1]) {
	//					continue;
	//				}
	//				else {
	//					found = 0;
	//				}
	//			}

	//		}
	//	}
	//}





}


void Matrix::rotateBy90() {
	Matrix temp(row, col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			temp.matrix[i][j] = matrix[i][j];
		}
	}
	delete[]matrix;
	matrix = NULL;
	int t = row;
	row = col;
	col = t;
	matrix = new int* [row];
	for (int i = 0; i < row; i++) {
		matrix[i] = new int[col];
	}

	for (int i = temp.col - 1; i >= 0; i--) {
		for (int j = 0; j < temp.row; j++) {
			matrix[(temp.col-1)-i][j] = temp.matrix[j][i];
		}
	}

	//for (int i = 0; i < temp.row; i++) {
	//	for (int j = 0; j < temp.col; j++) {

	//	}
	//}

	//int column = temp.col - 1;
	//for (int i = 0; i < temp.col; i++) {
	//	int rows = 0;
	//	for (int j = 0; j < temp.row; j++) {
	//		matrix[i][j] = temp.matrix[rows][column];
	//		rows++;
	//	}
	//	column--;
	//}

}


int Matrix::LeftDiagonalTotal() {
	int sum = 0;
	for (int i = 0; i < row; i++) {
		sum += matrix[i][i];
	}
	return sum;
}

int Matrix::RightDiagonalTotal() {
	int sum = 0;
	//for (int i = 0; i < row; i++) {
	//	for (int j = col-1 ; j > 0; j--) {
	//		sum += matrix[i][j];
	//		break;
	//	}
	//}
	int i = 0;
	int j = col;
	j--;
	while (i < row) {
		sum += matrix[i][j];
		i++;
		j--;
	}

	return sum;
}

Matrix Matrix::Merge(Matrix m) {
	Matrix mat(row, col + m.col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			mat.matrix[i][j] = matrix[i][j];
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = col; j < mat.col; j++) {
			mat.matrix[i][j] = m.matrix[i][j - col];
		}
	}

	return mat;
}

void Matrix::input() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << "Pls enter value at index(" << i << "," << j << ")" << endl;
			cin >> matrix[i][j];
		}
	}
}

void Matrix::display() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
Matrix::~Matrix() {
	for (int i = 0; i < row; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = nullptr;
 }
