
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
using namespace std;



bool cycleDetectionBFSHelper(int **graph, int vertex, int sv,int *visited){
    
    queue<int> q;
    map<int,int> parent;
    q.push(sv);
    visited[sv]=1;
    parent[sv]=sv;
    

    while(!q.empty())
    {
        int node=q.front();
        q.pop();

        for(int neighbour=0;neighbour<vertex;neighbour++)
        {
            if(graph[node][neighbour]==1 && visited[neighbour]==false)
            {
                //do traditional operation
                q.push(neighbour);
                visited[neighbour]=true;
                // setting neighbour parent
                parent[neighbour]=node;
            }
            else if(graph[node][neighbour]==1 && visited[neighbour]==true)
            {
                if( neighbour != parent[node])
                    return true;
            }
        }
    }

    return false;
    
    /*
    visited[sv]=true;
    
    for(int neighbour=0;neighbour<vertex;neighbour++)
    {
        if(graph[sv][neighbour]==1 && visited[neighbour]==false)
        {
            bool isCycleDetected=cycleDetectionBFSHelper(graph, vertex ,neighbour,sv, visited);
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
    */
}

bool cycleDetectionBFS(int **graph, int vertex, int *visited){
    
    //In case the input graph is dis-connected
    for(int i=0;i<vertex;i++){
        if(visited[i]==false)
        {
            bool isCycleDetected=cycleDetectionBFSHelper(graph,vertex,i,visited);
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

    bool isCycleDetected=cycleDetectionBFS(graph, vertex , visited);
    
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