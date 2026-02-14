#include <bits/stdc++.h>
#include <vector>

using namespace std ; 


int printGrap(vector<int> adjList[] , int n ){
	for(int i = 0 ; i< n ; i++){
		cout << i+1 << " : " ; 
		for(int j =0 ; j <adjList[i].size() ; j++){
			cout << adjList[i][j] << " " ;
		}
		cout << endl ;
	}
	
	
}



int main() {
	int n ,m , x, y ; 
	
	cin >> n >> m ; 
	vector<int> adjList[n]  ; 
	
	for(int i = 0 ; i < m ; i++){
		cin >> x >> y ;
		adjList[x-1].push_back(y) ;
	}
	
	
	
//	adjList[0].push_back(0) ; adjList[0].push_back(1) ;
//	adjList[0].push_back(2) ; adjList[1].push_back(3) ;
//	adjList[2].push_back(0) ; adjList[2].push_back(1) ;
//	adjList[2].push_back(4) ; adjList[3].push_back(2) ;
//	adjList[3].push_back(4) ; adjList[4].push_back(1) ;
	
	printGrap(adjList , n )  ; 
	return 0 ;
}
