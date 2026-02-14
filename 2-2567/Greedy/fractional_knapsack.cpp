#include<bits/stdc++.h>

using namespace std ; 


int main(){
	int n  = 0 ;
	int w = 0 ; 
	cin >> n >> w ;
	
	vector<double> V ; 
	vector<double> W ; 
    vector<double> R ; 
    vector<double> index ; 
    double select[n] = {};
	
	for(int i =0 ; i < n ; i++){
		double v ;
		cin >> v ; 
		W.push_back(v) ; 
		index.push_back(i) ;
	}
	
	for(int i =0 ; i < n ; i++){
		double v ;
		cin >> v ; 
		V.push_back(v) ; 
	}
	
	for(int i =0 ; i < n ; i++){
		 double raio = V[i] / W[i] ;
		 R.push_back(raio) ; 
	}
	
	
	for(int i= 0 ; i < n ; i++){
		for(int j =0 ; j < n ; j++){
			if(R[j] < R[i]){
				swap(R[i], R[j] ); 
				swap(V[i], V[j]) ; 
				swap(W[i], W[j]) ;
				swap(index[i], index[j]) ;
			}
		}
	}

	//-----------------------------
	
	double sum_w = 0 ;
	double sum_v = 0 ;
	double t = 0 ; 
	double persen  = 0 ;
	for(int i = 0 ; i < n ; i++){
		t  = sum_w +  W[i] ; 
		
		if(t <= w){
			sum_v = sum_v + V[i] ; 
			sum_w = sum_w + W[i] ;
			select[i] = 1;
		}
		else{
			int sed = w - sum_w;
			persen = sed / W[i] ; 
			sum_v = sum_v + (V[i] * persen) ; 
				select[i] = persen;
			break ;   
		}
		
	}
	
	for(int i= 0 ; i < n ; i++){
		for(int j =0 ; j < n ; j++){
			if(index[j] > index[i]){
				swap(select[i], select[j]) ;
				swap(index[i], index[j]) ;
			}
		}
	}
	for(int i =0 ; i < n ; i++){
			cout << select[i] << " " ; 

	}
	cout << endl<< sum_v ; 
	
	
	
	
//	//_____________ print 	
//	for(int i =0 ; i < n ; i++){
//		cout << V[i] <<" " ; 
//	}
//	cout << endl;
//	for(int i =0 ; i < n ; i++){
//		cout << W[i] <<" " ; 
//	}
//	cout << endl;
//	for(int i =0 ; i < n ; i++){
//		cout << R[i] <<" " ; 
//	}
//	cout << endl;
//	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0 ;
}
