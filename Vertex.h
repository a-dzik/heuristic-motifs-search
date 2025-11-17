#ifndef VERTEX_H
#define VERTEX_H

#include <list>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Vertex
{
public:
    string subsequence;
    int sequence_id;
    int position;
    list<Vertex> neighbours;

    Vertex();
    Vertex(string, int, int, list<Vertex>);
    void add_neighbour(Vertex s);
    void print_vertex();

    //friend ofstream & operator<<(ofstream &os, Vertex &v);
    friend bool operator==(const Vertex &v, const Vertex &u);
    Vertex operator=(const Vertex &v);
    bool operator<(const Vertex &v);

};

#endif

