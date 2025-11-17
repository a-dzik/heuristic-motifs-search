#include "Graph.h"

Graph::Graph()
{
    vector<Vertex> v;
    this->vertices = v;
}

Graph::Graph(vector<Vertex> v)
{
    vertices = v;
}

void Graph::add_vertex(Vertex v)
{
    vertices.push_back(v);
}

void Graph::print_graph()
{
    for(auto i: this->vertices)
        i.print_vertex();
}

