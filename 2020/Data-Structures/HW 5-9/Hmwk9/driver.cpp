#include <vector>
#include <iostream>
#include "Graph (2).hpp"
using namespace std;




int main(){
    Graph g1;
    g1.addVertex("Amsterdam");
    g1.addVertex("Broomfield");
    g1.addVertex("Calcutta");
    g1.addVertex("Dallas");
    g1.addVertex("Fabens");
    g1.addEdge("Amsterdam", "Broomfield", 10);
    g1.addEdge("Amsterdam", "Calcutta", 30);
    g1.addEdge("Broomfield", "Calcutta", 10);
    g1.addEdge("Broomfield", "Fabens", 50);
    g1.addEdge("Calcutta", "Dallas", 5);
    g1.addEdge("Fabens", "Dallas", 5);
    g1.shortestPath("Broomfield", "Fabens");

}