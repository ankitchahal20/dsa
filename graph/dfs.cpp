
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector<int> vec;

void dfs(int **graph, int vertex, int sv, int *visited){
    visited[sv]=true;
    vec.push_back(sv);
    for(int i=0;i<vertex;i++){
        if(i == sv)
            continue;
        if(graph[sv][i]==1 && visited[i]==false){
            dfs(graph, vertex ,i, visited);
        }
    }
}

int main()
{
    int vertex, edges;
    cin>>vertex>>edges;
    int **graph=new int*[vertex];
    for(int i=0;i<vertex;i++){
        graph[i]= new int[vertex];
        for(int j=0;j<vertex;j++){
            graph[i][j]=0;
        }
    }

    for(int i=0;i<edges;i++){
        int start,end;
        cin>>start>>end;
        graph[start][end]=1;
        graph[end][start]=1;
    }

    int *visited=new int[vertex];
    memset(visited,0, sizeof(visited));
    int startingVertex=0;
    dfs(graph, vertex ,startingVertex, visited );
    for(int i=0;i<vec.size();i++){
        cout<<" "<<vec[i]; 
    }
    return 0;
}