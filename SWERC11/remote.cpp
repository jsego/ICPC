
#include <iostream>

#define M 1000000007
#define ULL unsigned long long

using namespace std;

ULL expo( ULL b, int e ) {
	if ( e == 0 ) return 1;
	ULL m = expo( b, e / 2 );
	if ( e % 2 ) return m * m % M * b % M;
	else return m * m % M;
}

int main() {
	// guardar todos los primos entre 2 y 5000020 en v
	int k = 0, v[1000001];
	v[k++] = 2;
	for ( int i = 3; i <= 5000020; i += 2 ) {
		bool b = true;
		for ( int j = 0; b && v[j] * v[j] <= i; ++j )
			b = i % v[j] > 0;
		if (b) v[k++] = i;
	}

	int n;
	for ( cin >> n; n > 0; cin >> n ) {
		ULL res = 1;
		// para cada número primo que aparece al menos 2 veces entre 1 y n
		for ( int i = 0; 2 * v[i] <= n; ++i ) {
			int r = 0;
			// calcular el número de veces que aparece entre 1 y n
			for ( ULL e = v[i]; e <= n; e *= v[i] )
				r += n / e;
			// si el número es impar, restar uno
			if ( r % 2 ) --r;
			// multiplicar el exponente por el resultado
			res = res * expo( v[i], r ) % M;
		}
		cout << res << "\n";
	}
}
