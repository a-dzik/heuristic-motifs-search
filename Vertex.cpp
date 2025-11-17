#include "Vertex.h"

Vertex::Vertex()
{
    string subsequence;
    int sequence_id;
    int position;
    list<Vertex> neighbours;
    this->subsequence = subsequence;
    this->sequence_id = sequence_id;
    this->position = position;
    this->neighbours = neighbours;

}

Vertex::Vertex(string subsequence, int sequence_id, int position, list<Vertex> neighbours)
{
    this->subsequence = subsequence;
    this->sequence_id = sequence_id;
    this->position = position;
    this->neighbours = neighbours;
}

void Vertex::add_neighbour(Vertex s)
{
    neighbours.push_back(s);
}

void Vertex::print_vertex()
{
    cout << this->subsequence << endl;
    cout << "sequence number: " << this->sequence_id << endl;
    cout << "position: " << this->position << endl;
    cout << "\n\n";
}

Vertex Vertex::operator=(const Vertex &v)
{
    this->subsequence = v.subsequence;
    this->sequence_id = v.sequence_id;
    this->position = v.position;
    this->neighbours = v.neighbours;
}

bool operator==(const Vertex &v, const Vertex &u)
{
    if(u.subsequence == v.subsequence && u.sequence_id == v.sequence_id && u.position == v.position)
        return true;
    else return false;
}

/*
bool operator<(const Vertex &v, const Vertex &u)
{
    if(v.sequence_id.compare(u.sequence_id)>0)
        return true;
    else return false;
} */

bool Vertex::operator<(const Vertex &v)
{
    return this->sequence_id < v.sequence_id;
}

