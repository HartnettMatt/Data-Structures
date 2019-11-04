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
  vertex *vStart = NULL;
  vertex *vEnd = NULL;
  for(unsigned int i = 0; i < vertices.size(); i++){
    if(vertices[i]->name.compare(start) == 0){
      vStart = vertices[i];
    } else if(vertices[i]->name.compare(end) == 0){
      vEnd = vertices[i];
    }
  }
  if(vStart == NULL || vEnd == NULL){
    cout << "Error: start or end not found" << endl;
    return NULL;
  }
  // If visited, means its been solved
  vStart->visited = true;
  vStart->distance = 0;
  vector<vertex*> solvedList;
  solvedList.push_back(vStart);
  while(!vEnd->visited){
    int minDist = 1000000;
    vertex *solvedV = NULL;
    for(unsigned int x = 0; x < solvedList.size(); x++){
      vertex *s = solvedList[x];
      // now iterate across s's adj solvedList
      for(unsigned int y = 0; y < s->adj.size(); y++){
        if(s->adj[y].v->visited == false){
          int dist = s->distance + s->adj[y].weight;
          if(dist < minDist){
            solvedV = s->adj[y].v;
            minDist = dist;
            s->adj[y].v->pred = s;
          }
        }
      }
    }
    solvedV->distance = minDist;
    solvedV->visited = true;
    solvedList.push_back(solvedV);
  }
  return vEnd;
}

void Graph::shortestpath(string start, string end){
  vertex *vStart = NULL;
  vertex *vEnd = NULL;
  for(unsigned int i = 0; i < vertices.size(); i++){
    if(vertices[i]->name.compare(start) == 0){
      vStart = vertices[i];
    } else if(vertices[i]->name.compare(end) == 0){
      vEnd = vertices[i];
    }
  }
  if(vStart == NULL || vEnd == NULL){
    cout << "Error: start or end not found" << endl;
    return;
  }
  vertex *crawler = vEnd;
  vector<vertex*> path;
  while(crawler != NULL){
    path.push_back(crawler);
    crawler = crawler->pred;
  }
  for(int i = path.size()-1; i >= 0; i--){
    cout << path[i]->name << " ";
  }
  cout << endl;
}

void Graph::setAllVerticesUnvisited(){
  for(unsigned int i = 0; i < vertices.size(); i++){
    vertices[i]->visited = false;
  }
}


// #endif // GRAPH_H
