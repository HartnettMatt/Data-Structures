#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

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
