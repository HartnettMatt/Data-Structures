// #include "Graph.hpp"
//
// void DFTraversal(vertex *n){
//     n->visited = true;
//     for(unsigned int x = 0; x < n->adj.size(); x++ )
//     {
//       if(!n->adj[x].v->visited){
//         DFTraversal(n->adj[x].v);
//       }
//     }
// }
//
int gCC(vertex *v){
  int c = 0;
  for(unsigned int i = 0; i < vertices.size(); i++){
    if(!vertices[i]->visited){
      DFTraversal(vertices[i]);
      c++;
    }
  }
  return c;
}
//
// int findNext(vector<vertex*> vertices){
//   for(unsigned int i = 0; i < vertices.size(); i++){
//     if(vertices[i]->visited == false){
//       return i;
//     }
//   }
//   return -1;
// }
//
// void reset(vector<vertex*> vertices){
//   for(unsigned int i = 0; i < vertices.size(); i++){
//     vertices[i]->visited = false;
//   }
// }
//
bool checkHelper(Vertex *v){
  queue<vertex*> q;
  vector<vertex*> red;
  vector<vertex*> blue;
  vertex *n;
  q.push(v);
  v->color = "red";
  unsigned int cc = gCC(v);
  reset(vertices);
  for(unsigned int h = 0; h < cc; h++){
    if(h != 0){
      int next = findNext(vertices);
      if(next != -1){
        q.push(vertices[next]);
        vertices[next]->color = "red";
      }
    }
    while(!q.empty()){
      n = q.front();
      q.pop();
      for(unsigned int i = 0; i < n->adj.size(); i++){
        if(!n->adj[i].v->visited){
          n->adj[i].v->visited = true;
          if(n->color.compare("red") == 0){
            n->adj[i].v->color = "blue";
            blue.push_back(n->adj[i].v);
          } else if (n->color.compare("blue") == 0){
            n->adj[i].v->color = "red";
            red.push_back(n->adj[i].v);
          }
        }
      }
    }

    for(unsigned int k = 0; k < red.size(); k++){
      for(unsigned int m = 0; m < blue.size(); m++){
        if(red[k] == blue[m]){
          return false;
        }
      }
    }

  }

  return true;
}


bool checkHelper(Vertex *v){

}
