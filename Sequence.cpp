#include "Sequence.h"

Sequence::Sequence()
{
    vector<pair<char, int>>seq;
    vector<pair<int, int>>qual;
    this->sequence_id = sequence_id;
    this->seq = seq;
    this->qual = qual;
}

Sequence::Sequence(int sequence_id, vector<pair<char, int>>seq, vector<pair<int, int>>qual)
{
    this->sequence_id = sequence_id;
    this->seq = seq;
    this->qual = qual;
}

void Sequence::read_sequence_from_file()
{
 
}

void Sequence::print_seq()
{
    for(auto i: this->seq)
        cout << i.first;
    cout << endl;
    for(auto i: this->seq)
        cout << i.second << ' ';
    cout << "\n\n";
    for(auto i: this->qual)
        cout << i.first << ' ';
    cout << "\n\n";
    for(auto i: this->qual)
        cout << i.second << ' ';
    cout << "\n\n";
}