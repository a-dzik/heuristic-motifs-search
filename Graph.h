#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h"

#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Graph
{
public:
    vector<Vertex>vertices;

    Graph();
    Graph(vector<Vertex> v);
    void add_vertex(Vertex v);
    void print_graph();
};

#endif
