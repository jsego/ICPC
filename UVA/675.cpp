/*
*  Javier Segovia
*  Accepted in 0.244
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include<stdio.h>
#define MP make_pair
#define PB push_back
#define SQ(a) (a)*(a)
#define SZ(a) (int)a.size()
#define X first
#define Y second
#define SL size()
#define LE length()
using namespace std;
//const double piF = 2*acos(0);

struct point{
	int x,y;
	point(){}
	point(int X, int Y){x = X; y = Y;}
	bool operator<(const point &p)const{
		return (x < p.x || (x == p.x &&y < p.y));
	}
};

int total=0,resul=0;
point AR[1500000];
point CR[1500000];
point BR[1500000];
inline double dist(const point &a, const point &b){
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

// 2D cross product.
// Return a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
long long crossproduct(const point &O, const point &A, const point &B){
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is NOT the same as the first one.
void convexHull(){
	long long n = total, k = 0;
	//vector<point> H(2*n);
	// Sort Points lexicographically
	sort(AR,AR+total);
	// Build lower hull
	for (long long i = 0; i < n; i++) {
		while (k >= 2 && crossproduct(BR[k-2], BR[k-1], AR[i]) <= 0) k--;
		BR[k++] = AR[i];
	}
	// Build upper hull
	for (long long i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && crossproduct(BR[k-2], BR[k-1], AR[i]) <= 0) k--;
		BR[k++] = AR[i];
	}
	//H.resize(k-1); 
	resul = k-1;
	//return H;
}

int find_first(){
	for (int i=0; i<total; i++) {
		for (int j=0; j<resul; j++) {
			//cout<<"("<<AR[i].x<<","<<AR[i].y<<") <-> ("<<BR[j].x<<","<<BR[j].y<<")"<<endl;
			if(CR[i].x == BR[j].x && CR[i].y == BR[j].y)
				return j;
		}
	}
	return 0;
}

int main(){
	
	string s="1";
	
	int xx,yy; char cc;
	bool first=false;
	
	while (getline(cin,s) && int(s.LE)>0) {
		if(first) cout<<endl;
		else first=true;
		total = 0;
		while (int(s.LE)>0) { 
			istringstream iss(s);
			iss>>xx>>cc>>yy;
			CR[total]	= point(xx,yy);
			AR[total++] = point(xx,yy);
			getline(cin,s);
		}total--;
		
		convexHull();
		int beg=0;
		beg = find_first();
		//cout<<"BEG: "<<beg<<endl;
		for (int i=0; i<resul; i++) {
			cout<<BR[(i+beg)%resul].x<<", "<<BR[(i+beg)%resul].y<<endl;
		}cout<<BR[beg].x<<", "<<BR[beg].y<<endl;
	}
	exit(0);
}