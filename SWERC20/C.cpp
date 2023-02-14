
#include <cmath>
#include <iostream>

using namespace std;

int N;
char C[200];
long long A[200][200], B[200][200];

void update(int i, int j, long long x, long long y, char c) {
	long long res = 0;
	switch (c) {
	case '+': res = x + y; break;
	case '-': res = x - y; break;
	case '*': res = x * y; break;
	}
	if (res < A[i][(i + j) % N]) A[i][(i + j) % N] = res;
	if (B[i][(i + j) % N] < res) B[i][(i + j) % N] = res;
}

void update(int i, int j, int k, char c) {
	if (c == '?') {
		update(i, j, k, '+');
		update(i, j, k, '-');
		update(i, j, k, '*');
	}
	else {
		update(i, j, A[i][k % N], A[(k + 1) % N][(i + j) % N], c);
		update(i, j, A[i][k % N], B[(k + 1) % N][(i + j) % N], c);
		update(i, j, B[i][k % N], A[(k + 1) % N][(i + j) % N], c);
		update(i, j, B[i][k % N], B[(k + 1) % N][(i + j) % N], c);
	}
}

int main() {
	while (cin >> N) {
		for (int i = 0; i < N; ++i) {
			cin >> A[i][i] >> C[i];
			B[i][i] = A[i][i];
		}
		
		for (int j = 1; j < N; ++j)
			for (int i = 0; i < N; ++i) {
				A[i][(i + j) % N] =  1000000000000000000L;
				B[i][(i + j) % N] = -1000000000000000000L;
				for (int k = i; k < i + j; ++k)
					update(i, j, k, C[k % N]);
			}
			
		for (int i = 0; i < N; ++i)
			cout << abs(A[i][(i + N - 1) % N]) << abs(B[i][(i + N - 1) % N]);
		cout << "\n";
	}
}
