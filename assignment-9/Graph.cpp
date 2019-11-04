// #ifndef GRAPH_H
// #define GRAPH_H
#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

void Graph::addEdge(string v1, string v2, int num){
  for(unsigned int i = 0; i < vertices.size(); i++){
      if(vertices[i]->name == v1){
          for(unsigned int j = 0; j < vertices.size(); j++){
              if(vertices[j]->name == v2 && i != j){
                  adjVertex av;
                  av.v = vertices[j];
                  av.weight = num;
                  vertices[i]->adj.push_back(av);
                  adjVertex av2;
                  av2.v = vertices[i];
                  av2.weight = num;
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

// TODO: Account for weights
void Graph::displayEdges(){
  for(unsigned int i = 0; i < vertices.size(); i++){
    cout << vertices[i]->name << " -->";
    for(unsigned int j = 0; j < vertices[i]->adj.size(); j++){
      cout << " " << vertices[i]->adj[j].v->name;
    }
    cout << endl;
  }
}

void DFTraversal(string sourceVertex, vector<vertex*> vertices){
  vertex *n = NULL;
  for(unsigned int i = 0; i < vertices.size(); i++){
    if(vertices[i]->name.compare(sourceVertex) == 0 && !vertices[i]->visited){
      n = vertices[i];
    }
  }
  if(n == NULL){
    cout << "Done" << endl;
    return;
  }
  n->visited = true;
  cout << n->name << " --> ";
  for(unsigned int x = 0; x < n->adj.size(); x++ )
  {
    if(!n->adj[x].v->visited){
      DFTraversal(n->adj[x].v->name, vertices);
    }
  }
}
void Graph::depthFirstTraversal(string sourceVertex){
  DFTraversal(sourceVertex, vertices);
  cout << "Done" << endl;
}

// TODO: Finish these three methods:
vertex* Graph::DijkstraAlgorithm(string start, string end){
  queue<vertex*> q;
  vertex *vStart = NULL;
  vertex *vEnd = NULL;

  for(unsigned int i = 0; i < vertices.size(); i++){
    vertices[i]->distance = 100000;
    vertices[i]->pred = NULL;
    q.push(vertices[i]);
    if(vertices[i]->name.compare(start) == 0){
      vStart = vertices[i];
    } else if (vertices[i]->name.compare(end) == 0){
      vEnd = vertices[i];
    }
  }
  if(vStart == NULL || vEnd == NULL){
    cout << "Error: start or end not found" << endl;
    return NULL;
  }
  vStart->distance = 0;
  q.push(vStart);
  while(!q.empty()){
    vertex *u = q.front();
    q.pop();
    for(unsigned int j = 0; j < u->adj.size(); j++){
      int alt = u->distance + u->adj[j].weight;
      if(alt < u->adj[j].v->distance){
        u->adj[j].v->distance = alt;
        u->adj[j].v->pred = u;
      }
      // q.push(u->adj[j].v);
    }
  }
  return vEnd;
}

void Graph::shortestpath(string start, string end){

}

void Graph::setAllVerticesUnvisited(){

}


// #endif // GRAPH_H
