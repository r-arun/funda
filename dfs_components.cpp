#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define MAX_SIZE 1000

using namespace std;

bool visited[MAX_SIZE];
int component[MAX_SIZE];
vector <int> adj[MAX_SIZE];

int dfs(int val, int comp){
	component[val] = comp;
	visited[val] = true;
	for(int i = 0; i < adj[val].size(); ++i){
		int u = adj[val][i];
		if(!visited[u])
			dfs(u, comp);
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	int comp = 0;
	for(int i = 0; i < m; ++i){
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 0; i < m; ++i){
		if(!visited[i]){
			dfs(i, comp);
		}
		++comp;
	}
	for(int i = 0; i < m; ++i){
		cout<<i<<" "<<component[i];
	}
	cout<<endl;
	cout<<"Number of components "<<comp<<endl;
}
