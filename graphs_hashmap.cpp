#include <iostream>
#include<cstring>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
template<typename T>
// yeh wala graph generic hain koi se bhi datatype par chl jayega 
class Graph{
	unordered_map<T,list<T> >h;
public:
	void add_edge(T u,T v,bool bidirectional=false){
		h[u].push_back(v);
		if (bidirectional){
			h[v].push_back(u);
		}

	}
	void print(){
		 for(auto node:h){
		 	cout<<node.first<<"-->";
		 	for(auto neighbour:node.second){
		 		cout<<neighbour<<" ";
		 	}
		 	cout<<endl;
		 }
		 cout<<endl;
	}
	void bfs(T start){
		queue<T>q;
		unordered_map<T,bool>visited;
		q.push(start);
		visited[start]=true;
		unordered_map<T,int> distance;
		//           <key,value>
		distance[start]=0;

		while(!q.empty()){
			T node=q.front();
			q.pop();
			cout<<node<<" ";
			for(auto child:h[node]){
				if(!visited[child]){
					q.push(child);
					visited[child]=true;
					distance[child]=distance[node]+1;
				}
			}
		}
		cout<<endl;
		for(auto temp:distance){
			cout<<"minimum distance from source : "<<temp.first<<"to destination :0 "<<temp.second<<endl;
		}
	}

	int single_source_shortest_path(T start,T destination){
		queue<T>q;
		unordered_map<T,bool>visited;
		unordered_map<T,T> parent;
		q.push(start);
		visited[start]=true;
		unordered_map<T,int> distance;
		//           <key,value>
		distance[start]=0; 
		parent[start]=start;
		while(!q.empty()){
			T node=q.front();
			q.pop();
			cout<<node<<" ";
			for(auto child:h[node]){
				if(!visited[child]){
					q.push(child);
					visited[child]=true;
					distance[child]=distance[node]+1;
				}
			}
		}
		// cout<<endl;
		// for(auto temp:distance){
		// 	cout<<"minimum distance from source : "<<temp.first<<"to destination :0 "<<temp.second<<endl;
		// }
		return distance[destination];//since humne yaha hashmap bnaya tha which means 
		// humne har node ki shortest distance measure kar li toh directly issko return kar do.
	}
};
int main(){
	// Graph<string> g;
	// g.add_edge("Putin","Trump");
	// g.add_edge("Putin","Modi");
	// g.add_edge("Putin","Pope");
	// g.add_edge("Modi","Trump",true);
	// g.add_edge("Modi","Yogi",true);
	// g.add_edge("Yogi","Prabhu");
	// g.add_edge("Prabhu","Modi");
	// g.print();
	Graph<int> g;
	int no_of_node,no_of_edge;
	cin>>no_of_node>>no_of_edge;
	for(int i=0;i<no_of_edge;i++){
		int u,v;
		cin>>u>>v;
		g.add_edge(u,v);
	}
	g.print();
	// cout<<"bfs"<<endl;
	// g.bfs(0);
	cout<<g.single_source_shortest_path(0,5)<<endl;

	return 0;
}