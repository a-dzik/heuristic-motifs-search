#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Sequence
{
public:
    int sequence_id;
    vector<pair<char, int>>seq;
    vector<pair<int, int>>qual;

    Sequence();
    Sequence(int, vector<pair<char, int>>, vector<pair<int, int>>);
    void read_sequence_from_file();
    void print_seq();
};

#endif