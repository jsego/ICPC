/*
*  Javier Segovia
*  Accepted in 0.012
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
int main(){
	int i[4],f[4],kases,sum1,sum2,inter,max[2],min[2]; 
	cin>>kases;
	for (int k=1; k<=kases; k++) {
		cin>>i[0]>>i[1]>>f[0]>>f[1];
		cin>>i[2]>>i[3]>>f[2]>>f[3];
		max[0] = MAX(i[0],i[2]);
		max[1] = MAX(i[1],i[3]);
		min[0] = MIN(f[0],f[2]);
		min[1] = MIN(f[1],f[3]);
		//cout<<"("<<min[0]<<","<<min[1]<<") - ("<<max[0]<<","<<max[1]<<")"<<endl;
		if(min[0]>max[0] && min[1]>max[1])
			inter=(min[0]-max[0])*(min[1]-max[1]);
		else inter = 0;
		sum1 = (f[0]-i[0])*(f[1]-i[1]);
		sum2 = (f[2]-i[2])*(f[3]-i[3]);
		sum2 = sum2+sum1-inter*2;
		cout<<"Night "<<k<<": "<<inter<<" "<<sum2<<" "<<10000-sum2-inter<<endl;
	}
}