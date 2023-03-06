#include <iostream>
#include <vector>
#include <queue>
#include "Graph (2).hpp"
using namespace std;

void Graph::addEdge(string v1, string v2, int num){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j]->name == v2 && i != j){
                    adjVertex av;
                    av.v = vertices[j];
                    av.weight = num;
                    vertices[i]->adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = vertices[i];
                    av2.weight = num;
                    vertices[j]->adj.push_back(av2);
                }
            }
        }
    }
}

void Graph::addVertex(string name)
{
    vertex* v = new vertex;
    v->name = name;
    vertices.push_back(v);
}


void Graph:: depthFirstTraversal(string sourceVertex){
    vertex* n;
    for(int i = 0; i<vertices.size();i++){
        if(sourceVertex == vertices[i]->name){
            n = vertices[i];
            break;
        }
    }
    cout << n->name << " -> ";
    n->visited = true;
    for(int x = 0; x < n->adj.size(); x++ )
    {
        if(!n->adj[x].v->visited){
            n->adj[x].v->distance = n->distance+1;
            depthFirstTraversal(n->adj[x].v->name);
        }
    }
    if(n->distance == 0){
        cout << "DONE";
    }
}

void Graph:: dijkstraTraverse(string start){
    vertex* n;
    for(int i = 0; i<vertices.size();i++){
        if(vertices[i]->name == start){
            n = vertices[i];
            break;
        }
    }
    n->visited = true;
    n->distance = 0;
    vector<vertex*> solvedList;
    solvedList.push_back(n);
    bool allSolved = false;
    while(!allSolved){
        int minDist = 10000000;
        vertex* solvedV =  NULL;
        allSolved = true;
        for(int j = 0; j<solvedList.size();j++){
            vertex* s = solvedList[j];
            for(int k = 0; k<s->adj.size();k++){
                if(!s->adj[k].v->visited){
                    int dist = s->distance + s->adj[k].weight;
                    s->adj[k].v->pred = s;
                    if(dist<minDist){
                        solvedV = s->adj[k].v;
                        minDist = dist;
                    }
                    allSolved = false;
                }
            }
        }
        if(!allSolved){
            solvedV->distance = minDist;
            solvedV->visited = true;
            solvedList.push_back(solvedV);
        }

    }
}








void Graph:: shortestPath(string start, string end){
    vertex* n;
    for(int i = 0; i<vertices.size();i++){
        if(vertices[i]->name == start){
            n = vertices[i];
            break;
        }
    }
    n->visited = true;
    n->distance = 0;
    vector<vertex*> solved;
    solved.push_back(n);
    vertex* s;
    bool allsolved = false;
    vertex* solveMe;
    while(!allsolved){
        int minDist = 10000000;    
        solveMe =NULL;
        allsolved = true;
        for(int i = 0;i<solved.size();i++){
            s = solved[i];
            for(int j = 0;j<s->adj.size();j++){
                if(s->adj[j].v->visited == false){
                    if(s->distance + s->adj[j].weight<=minDist){
                        s->adj[j].v->distance = s->distance + s->adj[j].weight;                    
                        s->adj[j].v->pred = s;                    
                        minDist = s->adj[j].v->distance;
                        solveMe = s->adj[j].v;
                    }
                    allsolved = false;
                }
            } 
        }
        if(allsolved == false){
            solveMe->distance = minDist; 
            solved.push_back(solveMe);
            solveMe->visited = true;
        }
    }
   vertex* ending;
   for(int i = 0;i<vertices.size();i++){
       if(vertices[i]->name == end){
           ending = vertices[i];
           break;
       }
   }
   vector<vertex*> path;
   while(ending != NULL){
       path.insert(path.begin(), ending);
       ending = ending->pred;
   }
   for(int k = 0;k<path.size();k++){
       cout << path[k]->name << " -> ";
       if(k == path.size()-1){
           cout<<"DONE [" << path[k]->distance << ']' << endl;
       }
   }
}