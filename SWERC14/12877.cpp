#include<iostream>

using namespace std;

int T[300];
string A[11];
int P[11][11];
int L[11];
bool non_zero[11];
bool used_digits[11];
int V[11];
int N;


int recur(int c, int r,int ca){
	//last row used to check the result
	if(r+1 == N) {
		//smaller length than necessary
		if(P[r][c] == -1) return 0; 
		//last digit check
		if(c+1 == L[N-1]){ 
			//no correct value for last digit
			if(ca == 0) return 0; 
			//if the last digit has no value
			//check if ca applies
			if(V[P[r][c]] == -1){ 
				if(ca > 9 || used_digits[ca]) return 0;
				return 1;
			}
			//if the last digit has an assigned
			//value check if it is ca
			if(V[P[r][c]] == ca) return 1;
			return 0;
		}
		int res = 0;
		//current letter has no value
		if(V[P[r][c]] == -1){ 
			//check if ca is applicable
			if(used_digits[ca%10] || (non_zero[P[r][c]] && ca%10 == 0) ) res = 0;
			else{ 
				used_digits[ca%10] = true;
				V[P[r][c]] = ca%10;
				res = recur(c+1,0,ca/10);
				V[P[r][c]] = -1;
				used_digits[ca%10] = false;
			}
		}
		//check if the current letter has the same value as ca
		else if( V[P[r][c]] != (ca%10) ) res = 0;
		else res = recur(c+1, 0, ca/10); 
		return res;
	}
	//LETTERS TO ADD
	int res = 0;
	// no letter, look next row
	if(P[r][c] == -1) res = recur(c, r+1, ca); 
	// already assigned value
	else if(V[P[r][c]] != -1) res = recur(c, r+1, ca+V[P[r][c]]); 
	// current letter has no value
	else{
		//starting in 1 if 0 is not allowed
		for(int i=non_zero[P[r][c]];i<10;i++){ 
			if(!used_digits[i]){
				used_digits[i] = true;
				V[P[r][c]] = i;
				res += recur(c, r+1, ca+V[P[r][c]]);
				V[P[r][c]] = -1;
				used_digits[i] = false;
			}
		}	
	}
	return res;
}

int main(){
	while(cin>>N){
		//Reset
		for(int i=int('A');i<=int('Z');i++)  T[i] = -1;
		for(int i=0;i<10;i++) used_digits[i] = non_zero[i] = false;
		for(int i=0;i<10;i++) for(int j=0;j<10;j++) P[i][j] = -1;
		for(int i=0;i<10;i++) V[i] = -1;
		//New instance
		int pos = 0;
		for(int i=0;i<N;i++){
			cin>>A[i];
			L[i] = int(A[i].length());
			for(int j = L[i]-1,k=0;j>=0;j--,k++){
				if(T[int(A[i][j])] == -1){
					T[int(A[i][j])] = pos++;
				}
				P[i][k] = T[int(A[i][j])];
			}
			non_zero[P[i][L[i]-1]] = true;
		}
		//Get the result from the recursivity
		int res = recur(0, 0, 0);//col - row - carry
		cout<<res<<endl;
	}
}
