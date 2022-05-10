
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;



bool cycleDetectionDFSHelper(int **graph, int vertex, int sv,int parentNode, int *visited){
    visited[sv]=true;
    
    for(int neighbour=0;neighbour<vertex;neighbour++)
    {
        if(graph[sv][neighbour]==1 && visited[neighbour]==false)
        {
            bool isCycleDetected=cycleDetectionDFSHelper(graph, vertex ,neighbour,sv, visited);
            if(isCycleDetected){
                return true;
            }
        }
        else if(graph[sv][neighbour]==1 && visited[neighbour]==true)
        {
            // Core logic is this only
            if(neighbour != parentNode){
                return true;
            }
        }
    }
    return false;
}

bool cycleDetectionDFS(int **graph, int vertex, int *visited){
    
    //In case the input graph is dis-connected
    for(int i=0;i<vertex;i++){
        if(visited[i]==false)
        {
            bool isCycleDetected=cycleDetectionDFSHelper(graph,vertex,i,i,visited);
            if(isCycleDetected)
            {
                return true;
            }
        }
    }
    return false;
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

    bool isCycleDetected=cycleDetectionDFS(graph, vertex , visited );
    
    if(isCycleDetected){
         cout<<"Yes there exsists a cycle in the graph :disappointed";
    }
    else cout<<"Yehhh no cycle in graph";
    
    //cleaning the memory
    for(int i=0;i<vertex;i++){
        delete [] graph[i];
    }

    delete []graph;
    delete []visited;


    return 0;
}