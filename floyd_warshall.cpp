#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define MAX_SIZE 10
#define INFINITY INT_MAX
using namespace std;

template <int C, int R>
inline
void print_array( int (&arr)[ R ][ C ] )
{
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
template <int C, int R>
inline
vector<vector<int> > floyd_warshall(int (&adj) [R] [C]){
	vector <vector <int> > dist;
	for(int i = 0; i < R; ++i){
		vector<int> v;
		for(int j = 0; j < R; ++j)
			v.push_back(adj[i][j]);
		dist.push_back(v);
	}
	cout<<"Value "<<R<<endl;
	for(int k = 0; k < R; ++k){
		for(int i = 0; i < R; ++i){
			for(int j = 0; j < R; ++j){
				int cost = INFINITY;
				if((dist[i][k] != INFINITY) && (dist[k][j] != INFINITY))
					cost = dist[i][k] + dist[k][j];
				if( cost < dist[i][j])
					dist[i][j] = cost;
			}
		}
	}
	return dist;	
}

int main(){
	int n, m;
	cin>>n>>m;
	int arr[MAX_SIZE][MAX_SIZE];
	/*input format 
	number of vertices, n <= MAX_SIZE
	number of edges, e <= n*n
	in next e lines,
	source vertex id u, destination vertex id v, weight of edge w
	where the above represents a directed edge u, v with weight w
	*/

	for(int i = 0; i < MAX_SIZE; ++i){
		for(int j = 0; j < MAX_SIZE; ++j){
			if(i == j)
				arr[i][j] = 0;
			else
				arr[i][j] = INFINITY;
		}
	}
	for(int i = 0; i < m; ++i){
		int u, v , w;
		cin>>u>>v>>w;
		arr[u][v] = w;
	}
	vector<vector <int> > result = floyd_warshall(arr);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
}
