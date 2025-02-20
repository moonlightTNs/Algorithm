#include<bits/stdc++.h>
#include<vector>
#include<queue>

using namespace std;

//void print_graph(vector<vector<int> > &graph) {
//    for(int i = 0; i < graph.size(); i++) {  
//        cout << i+1 << " ";
//        for(int j = 0; j < graph[i].size(); j++) {
//            cout << " " << graph[i][j];
//        }
//        cout << endl;
//    }
//}

void BFS(vector<vector<int> > graph , int startV , int V , int goal){
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
	int count = 0 ; 
	for(int i = 0 ; i < parent.size() ; i++){
		goal = parent[goal] ;
		if(goal == -1){
			break ;
		} 
		count++ ;
	}
	cout << count ; 
}

int main() {
 
 	int n , start , end ; 
 	cin >> n ; 
    vector<vector<int> > graph(n, vector<int>(n, 0));  
	
	for(int i = 0 ; i < n ; i++){
		int s = 0;
		cin >> s;
		while(1){
			int j ;
			cin >> j ; 
			if(j==0){
				break ; 
			}
			else{
				graph[s-1][j-1] = 1  ; 
			}
		}
	}
	
    cin >> start >> end ;
    
 	BFS(graph,start-1 , n	,end-1) ;
	

    return 0;
}

