/*
* Javier Segovia
* Accepted in 0.016
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

//Global variables of the map and the related positions 
//we have to look to count the near bombs to that tile
char T[105][105];
int mi[8] = {-1,-1,-1,0,0,1,1,1};
int mj[8] = {-1,0,1,-1,1,-1,0,1};

int main(){
	int R,C,kase=1;
	bool first = true;

	//Main loop for the test cases, we must finish the program
	//when the number of rows and columns are 0
	while (cin>>R>>C && (R||C)) { 

		//Tricky endline
		if(first)first=false;
		else cout<<endl;

		//Output the kase number and increase that value
		cout<<"Field #"<<kase<<":"<<endl;
		kase++;

		//Read the input of minesweeper map
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				cin>>T[i][j];
			}
		}

		int ni,nj,r=0;

		// Check what we have to print for each position of the map
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				if(T[i][j] == '*') 
					//If there is a bomb, output the bomb
					cout<<"*"; 
				else{ 
					//If there is a point output the number of bombs adjacent to that tile
					r=0;
					for(int k=0;k<8;k++){ 
						//Check the 8 relative positions
						ni = i + mi[k];
						nj = j + mj[k];
						//check if the relative position is valid and if it is a bomb or not
						if(ni >= 0 && nj >= 0 && ni < R && nj < C && T[ni][nj] == '*'){
							r++;
						}
					}
					// output the value for that tile
					cout<<r; 
				}
			}cout<<endl;
		}
		
	}
}
