#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

template<typename T>
class Graph{

	unordered_map<T,list<T> > m;

public:
	Graph(){

	}
	void addEdge(T u,T v,bool bidir=true){
		m[u].push_back(v);
		if(bidir){
			m[v].push_back(u);
		}
	}
	void print(){
		for(auto p:m){
			T src = p.first;
			list<T> l = p.second;

			cout<<src<<"->";
			for(auto dest:l){
				cout<<dest<<",";
			}
			cout<<endl;
		}
	}
	//Depth First Search/Traversal
	// void dfsVisit(T node,unordered_map<T,bool> &visited){
	// 	//.....Define the DFS Logic........
	// 	visited[node] = true;
	// 	cout<<node<<" ";

	// 	for(auto nbr:m[node]){
	// 		if(!visited[nbr]){
	// 			dfsVisit(nbr,visited);
	// 		}
	// 	}
	// }

	// void dfs(){
	// 	unordered_map<T,bool> visited;
		

	// 	for(auto city_pair:m){
	// 		T city = city_pair.first;
	// 		if(!visited[city]){
	// 			cout<<"Cluster : " ; 
	// 			dfsVisit(city,visited);
	// 			cout<<endl;
	// 		}
	// 	}
	// }
	bool  bfs(T start){
		queue<T> q;
		q.push(start);
		unordered_map<T,bool> visited;
		unordered_map<T,int > parent;
		//setting the parent and visited of every node as false  
        for(auto x : m )
        {
        	T temp = x.first; 
        	visited[temp] = false ; 
        	parent[temp] = x.first ; 
        }

		visited[start] = true;


		while(!q.empty()){
			T node = q.front();
			//cout<< node <<" ,";
			q.pop();

			for(auto nbr:m[node]){
				// this is the condition where it is being visited by another other node except the parent which visited it first 
				if(visited[nbr] &&  parent[node] != nbr){
					return false; 
				}
				else if(!visited[nbr])
				{
					visited[nbr] = true ; 
					parent[nbr] = node ; 
					q.push(nbr); 
				}
			}
		}

		//if doesnot return false return true

		return true ; 
	}
};


int main(){

	Graph<int > g;
	g.addEdge(0,1);
	g.addEdge(3,2);
	g.addEdge(1,2);
	//g.addEdge(0,3);
	


	bool ans = g.bfs(0);

	if(ans) cout << "no cycle, graph is a tree" ; 
	else cout << "cycle found graph is not a tree" ;
	

	//g.dfs();
    //g.print();


	return 0;
}