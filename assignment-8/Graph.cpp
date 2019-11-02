// #ifndef GRAPH_H
// #define GRAPH_H
#include "Graph.hpp"
#include<vector>
#include<iostream>
using namespace std;

void Graph::addEdge(string v1, string v2){
  for(int i = 0; i < vertices.size(); i++){
      if(vertices[i]->name == v1){
          for(int j = 0; j < vertices.size(); j++){
              if(vertices[j]->name == v2 && i != j){
                  adjVertex av;
                  av.v = vertices[j];
                  vertices[i]->adj.push_back(av);
                  adjVertex av2;
                  av2.v = vertices[i];
                  vertices[j]->adj.push_back(av2);
              }
          }
      }
  }
}

void Graph::addVertex(string name){
  bool found = false;
  for(int i = 0; i < vertices.size(); i++){
      if(vertices[i]->name == name){
          found = true;
      }
  }
  if(found == false){
      vertex * v = new vertex;
      v->name = name;
      vertices.push_back(v);
  }
}

void Graph::displayEdges(){
  for(unsigned int i = 0; i < vertices.size(); i++){
    cout << vertices[i]->name << " -->";
    for(unsigned int j = 0; j < vertices[i]->adj.size(); j++){
      cout << " " << vertices[i]->adj[j].v->name;
    }
    cout << endl;
  }
}

void Graph::breadthFirstTraverse(string sourceVertex){

}

int Graph::getConnectedComponents(){

}

bool Graph::checkBipartite(){

}


// #endif // GRAPH_H
