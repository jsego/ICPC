#include<iostream>
#include<algorithm>
using namespace std;

//DP: A if the player 1 plays first
//and B if the player 2 plays first
double A[502][502],B[502][502];
//Adjacent list used for the second player
int T[21][2] = {
	{0,0}, {20,18}, {15, 17}, {17, 19}, {18, 13}, {12, 20}, {13,10},
	{19,16}, {16,11}, {14,12}, {6,15}, {8,14}, {9,5}, {4,6}, {11,9},
	{10,2}, {7,8}, {2,3}, {1,4}, {3,7}, {5,1}
};

int main(){
	cout.setf(ios::fixed);
	cout.precision(12);
	//Precompute all the solutions for the problem
	A[0][0] = B[0][0] = 0.0;
	for(int i=1;i<501;i++){
		A[0][i] = B[i][0] = 1.0;
		A[i][0] = B[0][i] = 0.0;
	}
	//
	double outa, outb;
	for(int i=1;i<502;i++){ //P1 score
		for(int j=1;j<502;j++){//P2 score
			A[i][j] = B[i][j] = outa = outb = 0.0;
			//Add the probs for the first player that
			//are already known, and add in "outa"
			//the probs that are unknown
			for(int k = i-1;k+20>=i;k--) {
				if(k>=0) A[i][j] += (1.0 - B[k][j])/20.0;
				else outa += 1.0;
			}
			double a,b,c, coutb, pa, pb;
			//Maximize the probability of winning of the
			//second player given each section
			for(int k=1;k<21;k++){ 
				//The unknown probs are saved in "coutb"
				coutb = 0.0;
				if(j>=k)a = (1.0 - A[i][j-k]);
				else{ a = 0.0; coutb += 1.0;}
				if(j>=T[k][0]) b=(1.0-A[i][j-T[k][0]]);
				else{ b = 0.0; coutb += 1.0;}
				if(j>=T[k][1]) c=(1.0-A[i][j-T[k][1]]);
				else{ c = 0.0; coutb += 1.0;}
				//At each possible section calculate the 
				//probability of winning for the player 1
				pa = (A[i][j] + (outa/20.0)*(1.0 - ((a+b+c+coutb)/3.0)))/(1.0 - (outa*coutb)/60.0);
				//Given the player 1 probability calc
				//the player 2 probability
				pb = (a+b+c)/3.0 + coutb*(1.0-pa)/3.0;
				//Save the max prob for second player
				if(pb > B[i][j]){
					B[i][j] = pb; outb = coutb;
				}
			}
			//Add the remaining value of not scoring
			//this time but to end up winning
			A[i][j] += (outa/20.0)*(1-B[i][j]);
		}
	}
	//Print the output for each query
	int N;
	while(cin>>N,N){
		cout<<A[N][N]<<" "<<B[N][N]<<endl;
	}
}
