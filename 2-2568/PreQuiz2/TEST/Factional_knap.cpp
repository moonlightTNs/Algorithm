#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Item{
    public :
    double weight ;
    double value ;
    double ratio ; 
};


int main(){

    int num , capa ; 
    cin >> num >> capa ; 
    vector<Item> item(num+1) ;

    for (int i = 0 ; i < num ; i++){
        cin >>  item[i].weight ;
        cin >>  item[i].value ;
        item[i].ratio = item[i].value / item[i].weight ;

    }

    sort(item.begin(),item.end() , [](Item a , Item b){
        return a.ratio > b.ratio ;
    }) ;

    // for(int i = 0; i<num ; i++ ){
    //     cout << item[i].weight << " " ; 
    //     cout << item[i].value << " ";
    //     cout << item[i].ratio << " " ;
    //     cout << endl ;
    // }

    double remaining = capa ;
    double totalValue = 0.0;
    
    for(int i =0 ; i < num ; i++){
        if(item[i].weight <= remaining ){
            totalValue += item[i].value  ;
            remaining -= item[i].weight  ;
        }
        else{
            double per = (remaining / item[i].weight) * 100;
            double newVal = item[i].value * per / 100 ;
            totalValue += newVal ;
            break;
        }
    }

    cout << endl ;

    cout << totalValue ;
}