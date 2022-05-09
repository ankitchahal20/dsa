#include<iostream>
#include<cstring>
#include<queue>
#include<vector>

using namespace std;

vector<int> vec;

void bfs(int **graph, int vertex, int sv, int *visited){

    queue<int> q;
    q.push(sv);
    visited[sv]=1;

    while(!q.empty()){
        int v=q.front();
        vec.push_back(v);
        q.pop();
        
        
        for(int i=0;i<vertex;i++){
            if(i==sv) continue;
            if(graph[v][i]==1 && visited[i]==false){
                visited[i]=1;
                q.push(i);
            }
        }
    }

}


int main(){

    int vertex, edges;
    cin>>vertex>>edges;
    int **graph=new int*[vertex];
    for(int i=0;i<vertex;i++){
        graph[i]=new int[vertex];
        for(int j=0;j<vertex;j++){
            graph[i][j]=0;
        }
    }

    for(int j=0;j<edges;j++){
        int start,end;
        cin>>start>>end;
        graph[start][end]=1;
        graph[end][start]=1;
    }

    int *visited=new int[vertex];
    memset(visited,0,sizeof(visited));

    int startingVertex=0;
    bfs(graph,vertex,startingVertex,visited);

    for(int i=0;i<vec.size();i++){
        cout<<" "<<vec[i];
    }

    for(int i =0;i<vertex;i++){
        delete [] graph[i];
    }

    delete [] graph;
    delete [] visited;

    return 0;
}