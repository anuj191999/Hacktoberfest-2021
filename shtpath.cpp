#include<bits/stdc++.h>
using namespace std;
void BFS(vector<int> adj[], int N, int src) 
{ 
	vector<int>dist(N,INT_MAX);
	queue<int>  q;
	
	dist[src] = 0;
	q.push(src); 

	while(q.empty()==false) 
	{ 
		int node = q.front(); 
		q.pop();
		 
		for(auto it:adj[node]){
		    if(dist[node] + 1 < dist[it]){
		        dist[it]=dist[node]+1;
		        q.push(it);
		    }
		} 
	} 
	for(int i = 0;i<N;i++) cout << dist[i] << " "; 
	
} 
int main()
{
    int n,m;
	cin>>n>>m;
	//here n and m is number of vertices and edges respectively
	vector<int>adj[n+1];
	// this for undirected graph
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	BFS(adj,n,0);
}
