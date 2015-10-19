#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

#define X first
#define Y second
#define PB push_back
#define SZ size()
#define SQ(a) ((a)*(a))
#define MP make_pair

typedef double T;     // posiblemente cambiar a double
typedef pair<T,T> P;
T xp(P p, P q, P r) {
  return (q.X-p.X)*(r.Y-p.Y) - (r.X-p.X)*(q.Y-p.Y);
}
struct Vect {
  P p, q;  T dist;
  Vect(P &a, P &b) {
    p = a;  q = b;
    dist = SQ(a.X - b.X) + SQ(a.Y - b.Y);
  }
  bool operator<(const Vect &v) const {
    T t = xp(p, q, v.p);
    return (t < 0) || (t == 0 && dist < v.dist);
  }
};

vector<P> convexhull(vector<P> v) { // v.SZ >= 2
  if( v.SZ < 2 )
	return v;
  sort(v.begin(), v.end());
  vector<Vect> u;
  for (int i = 1; i < (int)v.SZ; i++)
    u.PB(Vect(v[i], v[0]));
  sort(u.begin(), u.end());
  vector<P> w(v.SZ, v[0]);
  int j = 1;  w[1] = u[0].p;
  for (int i = 1; i < (int)u.SZ; i++) {
    T t = xp(w[j-1], w[j], u[i].p);
    for (j--; t < 0 && j > 0; j--)
      t = xp(w[j-1], w[j], u[i].p);
    j += t > 0 ? 2 : 1;
    w[j] = u[i].p;
  }
  w.resize(j+1);
  return w;
}

long double dist( P &a, P &b ){
	int dx = abs( a.X - b.X );
	int dy = abs( a.Y - b.Y );
	int diff = abs( dx - dy );
	int mini = min( dx , dy );
	return mini*(long double)sqrt(2) + diff;
}

int main() {
	cout.setf(ios::fixed);
	cout.precision( 6 );
	int N;
	while( cin >> N ){
		vector<P> v(N);
		for(int n = 0; n < N; n++){
			cin >> v[n].X >> v[n].Y;
		}
		vector<P> w = convexhull( v );
		long double res = 4*sqrt(2) + dist( w[0] , w[int(w.size())-1] );
		for(int i = 1; i < int(w.size()); i++)
			res += dist( w[i] , w[i-1] );
		cout << res << endl;
	}
} 
