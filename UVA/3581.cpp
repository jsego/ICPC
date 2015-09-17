/*
 *  3581.cpp
 *  
 *
 *  Created by Javier Segovia on 10/10/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
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
vector<point> convexHull(vector<point> &P){
	long long n = P.size(), k = 0;
	vector<point> H(2*n);
	// Sort Points lexicographically
	sort(P.begin(), P.end());
	// Build lower hull
	for (long long i = 0; i < n; i++) {
		while (k >= 2 && crossproduct(H[k-2], H[k-1], P[i]) < 0) k--;
		H[k++] = P[i];
	}
	// Build upper hull
	for (long long i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && crossproduct(H[k-2], H[k-1], P[i]) < 0) k--;
		H[k++] = P[i];
	}
	H.resize(k-1);
	return H;
}

bool intSect(point a,point b, point c, point d){
	double ay=(double)(a.y+0.000000001),ax=(double)(a.x+0.000000001);
	double by = (double)(b.y+0.000000001),bx=(double)(b.x+0.000000001);
	double cy=(double)(c.y+0.000000001),cx=(double)(c.x+0.000000001);
	double dy = (double)(d.y+0.000000001), dx = (double)(d.x+0.000000001);
	if (a.x == b.x) {
		if (c.x == d.x) {
			return false;
		}
		double aa = cy +(dy-cy)*(ax-cx)/(dx-cx);
		if( ((aa>=ay && aa<=by)|| (aa>=by&&aa<=ay)) &&
		   ((aa>=cy && aa<=dy)|| (aa>=dy&&aa<=cy)) &&
		   ((a.x >= c.x && a.x <= d.x) || (a.x>=d.x && a.x<=c.x))
		   )return true;		
		return false;
	}
	else if(c.x == d.x){
		return intSect(c,d,a,b);
	}
	if( (b.y-a.y)*(d.x-c.x) == (d.y-c.y)*(b.x-a.x) ){
		return false;
	}
	double a1 = (by-ay)/(bx-ax);
	double a2 = (dy-cy)/(dx-cx);
	double x = (cy - ay + ax*a1 - cx*a2)/(a1-a2);
	double y = ay + (x-ax)*a1;
	if( ((x >= ax && x <=bx)||(x>=bx && x<=ax))
	   &&((x >= cx && x <=dx)||(x>=dx && x<=cx))
	   && ((y >= ay && y <=by)||(y>=by && y<=ay))
	   && ((y >= cy && y <=dy)||(y>=dy && y<=cy))
	   )return true;
	return false;
}

int main(){
	int N,M,a,b,c,d,kase=1;
	while (cin>>N>>M && (N||M) ){
		if(kase>1)cout<<endl;
		vector<point> v1,v2,r1,r2;
		
		for (int i=0; i<N; i++) {
			cin>>a>>b>>c>>d;
			v1.PB(point(a,b));
			v1.PB(point(a,d));
			v1.PB(point(c,b));
			v1.PB(point(c,d));
		}
		for (int j=0; j<M; j++) {
			cin>>a>>b>>c>>d;
			v2.PB(point(a,b));
			v2.PB(point(a,d));
			v2.PB(point(c,b));
			v2.PB(point(c,d));
		}
		r1 = convexHull(v1);
		r2 = convexHull(v2);
		bool intersect = false;
		vector<point> global,solG;
		for(int i=0;i<(int)r1.SL;i++) global.PB(r1[i]);
		for(int i=0;i<(int)r2.SL;i++) global.PB(r2[i]);
		solG = convexHull(global);
		//cout<<"TAMS: "<<solG.SL<<" "<<r1.SL<<" "<<r2.SL<<endl;
		if(solG.SL == r1.SL){
			intersect = true;
			for(int i=0;i<(int)r1.SL;i++){ 
				//cout<<"SOL: "<<solG[i].x<<" "<<solG[i].y<<" R1: "<<r1[i].x<<" "<<r1[i].y<<endl;
				if(solG[i].x!=r1[i].x || solG[i].y!=r1[i].y){
					intersect = false; 
					break;
				}
			}
		}
		if(solG.SL == r2.SL && !intersect){
			intersect = true;
			for(int i=0;i<(int)r2.SL;i++){
				//cout<<"SOL: "<<solG[i].x<<" "<<solG[i].y<<" R1: "<<r1[i].x<<" "<<r1[i].y<<endl;
				if(solG[i].x!=r2[i].x || solG[i].y!=r2[i].y){
					intersect = false; 
					break;
				}
			}
		}
		//bool last; 
		int next1,next2;
		for(int i=0;i<(int)r1.SL && !intersect; i++){
			next1 = i+1; if(next1 == (int)r1.SL) next1=0;
			for(int j=0;j<(int)r2.SL&&!intersect;j++){
				next2 = j+1; if(next2 == (int)r2.SL) next2 = 0;
				intersect = intSect(r1[i],r1[next1],r2[j],r2[next2]);
				//cout<<"I: "<<i<<" J: "<<j<<endl;
			}
		}
		cout<<"Case "<<kase++<<": It is ";		
		if(intersect) {
			cout<<"not possible to separate the two groups of vendors."<<endl;
		}
		else{
			cout<<"possible to separate the two groups of vendors."<<endl;
		}
	}
}