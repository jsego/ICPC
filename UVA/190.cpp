/*
*  Javier Segovia
*  Accepted in 0.012
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define SQ(a) ((a)*(a))

typedef double T; // de j a r i n c l u s o cuando puntos son i n t
struct Point {
	public :
	T x,y; // punto d e f i n i d o por coordinado (x , y )
	Point() { x = -1.0; y = -1.0; }
	Point(T a , T b) { x = a ; y = b ; }
	double distance ( Point p) { // d i s t a n c i a ent r e dos puntos
		return sqrt( SQ(p.x-x)+ SQ(p.y-y) );
	}
};
struct Line {
	public :
	Point p , q ; // l i n e a d e f i n i d a por dos puntos DIFERENTES
	Line ( Point a , Point b) { p = a ; q = b ; }
	double distance ( Point r ) { // d i s t a n c i a de l i n e a a punto
		return r.distance (projection( r ) ) ;
	}
	// p r o j e c c i o n de punto sobr e l i n e a
	Point projection ( Point r ) {
		if(p.y == q.y )
		return isect( Line ( r , Point ( r.x , r.y + 1 ) ) ) ;
		T z = ( q.x-p.x )/( q.y-p.y ) ;
		return isect( Line ( r , Point (r.x+ 1 , r.y-z ) ) ) ;
	}
	Point isect ( Line l ) { // i n t e r s e c c i o n ent r e dos l i n e a s
		if(p.x == q.x ) {
			if(l.p.x == l.q.x ) // l i n e a s son p a r a l e l a s
			return Point() ;
			double a = (l.q.y-l.p.y)/( l.q.x-l.p.x ) ;
			return Point (p.x , l.p.y + a*(p.x-l.p.x) ) ;
		}
		else if( l.p.x == l.q.x )
		return l.isect (*this ) ;
		double a1 = ( q.y-p.y )/( q.x-p.x ) ;
		double a2 = ( l.q.y-l.p.y ) / ( l.q.x-l.p.x ) ;
		if( a1 == a2 ) // l i n e s a r e p a r a l l e l
			return Point();
		double x = ( l.p.y-p.y + p.x*a1-l.p.x*a2 ) / ( a1-a2 ) ;
		return Point (x , p.y + ( x-p.x )*a1 ) ;
	}
} ;

Point calc(Point a,Point b,Point c){
	double m1,m2,b2;
	Point res;
	if ((a.y-b.y)==0.0) {//m2 inf
		res.x = c.x;
		res.y = c.y+20.0;
	}
	else if((a.x - b.x)==0.0){//m2 == 0
		res.x = 30.0; 
		res.y = c.y;
	}
	else{
		m1 = (a.y - b.y)/(a.x - b.x);
		m2 = -1.0/m1;
		b2 = c.y - c.x * m2;
		res.x = 30.0; 
		res.y = m2 * 30.0 + b2;
	}
	return res;
}

int main(){
	Point p1,p2,p3;
	double pi = 3.141592653589793; pi*=2.0;
	cout.setf(ios::fixed);
	cout.precision(3);
	while (scanf("%lf %lf %lf %lf %lf %lf",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y) == 6) {
		Point mA,A,mB,B;
		mA.x = (p1.x + p2.x)/2.0;
		mA.y = (p1.y + p2.y)/2.0;
		mB.x = (p3.x + p2.x)/2.0;
		mB.y = (p3.y + p2.y)/2.0;
		A = calc(p1,p2,mA);
		B = calc(p3,p2,mB);
		Line lA(mA,A),lB(mB,B);
		Point it = lA.isect(lB);
		double r = sqrt( SQ(it.x - p1.x) + SQ(it.y - p1.y));
		cout<<"(x "<<(it.x<0 ? "+ ":"- ")<<(it.x<0 ? it.x*-1.0:it.x)<<")^2 + (y "<<(it.y<0 ? "+ ":"- ")<<(it.y<0 ? it.y*-1.0:it.y)<<")^2 = "<<r<<"^2\n";
		double ac = SQ(r)*-1.0 + SQ(it.x) + SQ(it.y);
		cout<<"x^2 + y^2 "<<(it.x<0 ? "+ ":"- ")<<(it.x<0 ? it.x*-2.0:it.x*2.0)<<"x "<<(it.y<0 ? "+ ":"- ");
		cout<<(it.y<0 ? it.y*-2.0:it.y*2.0)<<"y "<<(ac<0 ?"- ":"+ ")<<(ac<0 ? ac*-1:ac)<<" = 0"<<endl<<endl;
	}
}