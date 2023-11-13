#include <iostream>
#include <vector>
#include <math.h>
#include <chrono>
#include <iomanip>
using namespace std;

void print_matrix(vector < vector <int> > matrix, int M, int N) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

void first_matrix_generation(vector <vector <int> > &matrix, int M, int N) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			matrix[i][j] = (N / M * i + j) * 2;
		}
	}
}

void second_matrix_generation(vector <vector <int> >& matrix, int M, int N) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			matrix[i][j] = (N / M * i * j) * 2;
		}
	}
}

bool ladder_search(vector <vector <int> >& matrix, int M, int N, int m, int n, int target) {
	while (1) {
		if ((matrix[m][n] < target))
			m++;
		else if (matrix[m][n] > target)
			n--;
		else if (matrix[m][n] == target) {
			return 1;
		}
		else {
			return 0;
		}
		if (m == M || n == -1)
			return 0;
	}
}

bool binary_search(vector <vector <int> >& matrix, int M, int N, int target) {
	for (int j = 0; j < M; j++) {
		int l = 0;
		int r = N - 1;
		while (l <= r) {
			int middle = (l + r) / 2;
			if (matrix[j][middle] < target)
				l = middle + 1;
			else if (matrix[j][middle] > target)
				r = middle - 1;
			else
				return 1;
		}
	}
	return 0;
}

bool exp_lad_search(vector <vector <int> > matrix, int M, int N, int target)
{
	int i = 0;
	int j = N - 1;
	while (i != M && j != -1)
	{
		if (matrix[i][j] == target)
			return 1;
		int border = 1;
		int l = 0;
		int r = 0;
		while ((j - border >= 0) && (matrix[i][j - border] > target)) {
			border *= 2;
		}
		l = j - border;
		r = j - border / 2;
		while (r <= l) {
			long long mid = (r - l) / 2 + l;
			if (matrix[i][mid] == target)
				return 1;
			else if (target < matrix[i][mid])
				r = mid - 1;
			else
				l = mid + 1;
		}
		if (l >= 0 && r >= 0)
			j = min(l, r);
		else if (l >= 0)
			j = l;
		else
			j = r;
		i++;
	}
	return 0;
}

int ladder_search_test(int data_gen) {
	for (int i = 0; i < 14; i++) {
		int M = pow(2, i);
		int N = pow(2, 13);
		int target = 0;
		vector <vector <int> > matrix(M, vector<int>(N, 0));      //�������� �������
		if (data_gen == 1) {
			first_matrix_generation(matrix, M, N);                //���������� ������� �� 1 ��������� ������
			target = 2 * N + 1;
		}
		else {
			second_matrix_generation(matrix, M, N);
			target = 16 * N + 1;
		}
		auto start = chrono::high_resolution_clock::now();
		ladder_search(matrix, M, N, 0, N - 1, target);            //����� �������� ������ ���������
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<float> duration = end - start;           //����� �����������
		cout << "M = ";
		cout << setw(4) << M;
		cout << ' ' << duration.count() * 1000000 << " mcs" << endl;
	}
	cout << endl;
	return 0;
}

int binary_search_test(int data_gen) {
	for (int i = 0; i < 14; i++) {
		int M = pow(2, i);
		int N = pow(2, 13);
		int target = 0;
		vector <vector <int> > matrix(M, vector<int>(N, 0));      //�������� �������
		if (data_gen == 1) {
			first_matrix_generation(matrix, M, N);                //���������� ������� �� 1 ��������� ������
			target = 2 * N + 1;
		}
		else {
			second_matrix_generation(matrix, M, N);               //���������� ������� �� 2 ��������� ������
			target = 16 * N + 1;
		}
		auto start = chrono::high_resolution_clock::now();        //����� �������� ������ ���������
		binary_search(matrix, M, N, target);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<float> duration = end - start;           //����� �����������
		cout << "M = ";
		cout << setw(4) << M;
		cout << ' ' << duration.count() * 1000000 << " mcs" << endl;
	}
	cout << endl;
	return 0;
}

int exp_lad_search_test(int data_gen) {
	for (int i = 0; i < 14; i++) {
		int M = pow(2, i);
		int N = pow(2, 13);
		int target = 0;
		vector <vector <int> > matrix(M, vector<int>(N, 0));      //�������� �������
		if (data_gen == 1) {
			first_matrix_generation(matrix, M, N);                //���������� ������� �� 1 ��������� ������
			target = 2 * N + 1;
		}
		else {
			second_matrix_generation(matrix, M, N);               //���������� ������� �� 2 ��������� ������
			target = 16 * N + 1;
		}
		auto start = chrono::high_resolution_clock::now();
		exp_lad_search(matrix, 0, N, target);                     //����� �������� ������ ���������
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<float> duration = end - start;           //����� �����������
		cout << "M = ";
		cout << setw(4) << M;
		cout << ' ' << duration.count() * 1000000 << " mcs" << endl;
	}
	cout << endl;
	return 0;
}


int main() {
	cout << "Choose data generation" << endl;
	int data_gen = 0;
	cin >> data_gen;
	cout << "Ladder search:" << endl;
	ladder_search_test(data_gen);
	cout << "Binary search:" << endl;
	binary_search_test(data_gen);
	cout << "Exp+Lad search:" << endl;
	exp_lad_search_test(data_gen);
	return 0;
}