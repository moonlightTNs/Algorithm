#include<bits/stdc++.h>
#include<vector>
#include<queue>

using namespace std;



void BFS(vector<vector<int> > graph , int startV , int V , int L){
	vector<bool> visited(V , false) ; 
	vector<int> parent(V , -1) ; 
	
	queue<int> queue  ; 
	queue.push(startV) ; 
	visited[startV]  = true ;
	
	while(!queue.empty()){
		int current = queue.front() ; 
		queue.pop() ; 
		
		for(int i = 0 ; i< graph.size() ; i++){
			if(graph[current][i] && !visited[i]){
				queue.push(i) ;
				visited[i] = true ; 
				parent[i] = current ; 
			}
		}
		
	} 
	int count_l = 0 ; 
	int count = 0;
	
	for(int i = 0 ; i < parent.size(); i++){
	if(i == startV) continue;
	int goal = i;
	bool jear = false;
	for(int j = 0 ; j < parent.size() ; j++){
		goal = parent[goal] ;
		if(goal == -1){
			jear = true;
			break ;
		} 
		if(j > 1){
			count++;
			break;
		}
	
	}
	
	}

	cout << count ; 
}

int main() {
 
 	int n , start , L; 
 	cin >> n ; 
    vector<vector<int> > graph(n, vector<int>(n, 0));  
	

		while(1){
			int s = 0 ;
			int j = 0 ;
			cin >> s;
			cin >> j ; 
			if(s==0 && j==0){
				break ; 
			}
			else{
				graph[s-1][j-1] = 1  ; 
			}
		}
    cin >> start >> L ;
    
 	BFS(graph,start-1 , n	,L) ;
	

    return 0;
}

