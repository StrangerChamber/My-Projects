#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void Graph::addVertex(string name)
{
    vertex* v = new vertex;
    v->name = name;
    vertices.push_back(v);
}


void Graph::addEdge(string v1, string v2){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j]->name == v2 && i != j){
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = vertices[i];
                    vertices[j]->adj.push_back(av2);
                }
            }
        }
    }
}


void Graph::displayEdges(){
    for(int i = 0;i<vertices.size();i++){
        cout <<vertices[i]->name << " --> ";
        for(int j = 0; j<vertices[i]->adj.size();j++){
            cout << vertices[i]->adj[j].v->name << " ";
        }
        cout << endl;
    }
}

int distanceToStart(vertex* goal, vertex* start){

}

void Graph::breadthFirstTraverse(string sourceVertex){
    vertex* vStart;
    for(int i = 0; i<vertices.size();i++){
        if(vertices[i]->name == sourceVertex){
            vStart = vertices[i];
            break;
        }
    }
    vStart->visited = true;
    cout<< "Starting vertex (root): " << vStart->name << "-> ";
    queue<vertex*> q;
    q.push(vStart);
    vertex* n;
    int distance = 0;
    while(!q.empty()){
        n = q.front();
        q.pop();
        for(int x = 0; x<n->adj.size();x++){
            if(n->adj[x].v->visited == false){
                n->adj[x].v->visited = true;
                n->adj[x].v->distance = n->distance+1;
                q.push(n->adj[x].v);
                cout << n->adj[x].v->name << "(" << n->adj[x].v->distance << ")" << " ";
            }   
        }
    }
}

void DFTraversal(vertex *n)
{
    n->visited = true;
    for(int x = 0; x < n->adj.size(); x++ )
    {
        if(!n->adj[x].v->visited){
            DFTraversal(n->adj[x].v);
        }
    }

}

int Graph::getConnectedComponents(){

  int initial_components = 0;
  for(int i = 0;i<vertices.size();i++){
      if(!vertices[i]->visited){
          DFTraversal(vertices[i]);
          initial_components++;
      }
  }
  return initial_components;
}