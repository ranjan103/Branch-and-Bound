#include<bits/stdc++.h>
using namespace std;

class Item{
	public:
	float weight;
	int value;
};

class Node{
	public:
	int level,profit,bound;
	float weight;
};

int bound(Node u,int n,int W,Item arr[]){
	if (u.weight >= W) 
        return 0;  
    int profit_bound = u.profit; 
  
    int j = u.level + 1; 
    int totweight = u.weight; 
    while ((j < n) && (totweight + arr[j].weight <= W)) 
    { 
        totweight    += arr[j].weight; 
        profit_bound += arr[j].value; 
        j++; 
    } 
  
    if (j < n) 
        profit_bound += (W - totweight) * arr[j].value / 
                                         arr[j].weight; 
  
    return profit_bound; 
}

int knapsack(int W,Item a[],int n){
	sort(a,a+n,[&](Item &a,Item &b){
		return  ((double)a.value)/a.weight>((double)b.value)/b.weight;
	});
	
	Node u,v;
	u.level=-1;
	queue<Node> Q;
	u.profit=u.weight=0;
	Q.push(u);
	int maxProfit=0;
	while(!Q.empty()){
		u=Q.front();
		Q.pop();
		if(u.level==-1){
			v.level=0;
		}
		if(u.level==n-1){
			continue;
		}
		
		v.level=u.level+1;
		v.weight=u.weight+a[v.level].weight;
		v.profit=u.profit+a[v.level].value;
		if(v.weight<=W and v.profit>maxProfit){
			maxProfit=v.profit;
		}
		v.bound=bound(v,n,W,a);
		if(v.bound>maxProfit){
			Q.push(v);
		}
		v.weight=u.weight;
		v.profit=u.profit;
		v.bound=bound(v,n,W,a);
		if(v.bound>maxProfit){
			maxProfit=v.profit;
		}
	}
	return maxProfit;
}

int main(){
	
	int W;
	cin>>W;
	int n;
	cin>>n;
	Item a[n];
	for(int i=0;i<n;i++){
		cin>>a[i].weight>>a[i].value;
	} 
	cout<<knapsack(W,a,n)<<endl;
	
	return 0;
}
