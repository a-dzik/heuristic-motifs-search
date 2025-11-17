#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <list>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

#include "Vertex.h"

#include "Graph.h"
#include "Sequence.h"

int main()
{
    //wczytanie instancji z pliku
    ifstream file_fasta, file_qual;
    string filename_fasta, filename_qual;
    cout << "Podaj nazwe pliku .fasta: ";
    cin >> filename_fasta;
    file_fasta.open(filename_fasta);
    cout << "Podaj nazwe pliku .qual: ";
    cin >> filename_qual;
    file_qual.open(filename_qual);
    string line_fasta, line_qual;
    char nc;
    int q;
    int count1, count2;
    vector<Sequence>temp_sequences;

    while(!file_fasta.eof())
    {
        Sequence s;
        count1 = 0;
        count2 = 0;

        getline(file_fasta, line_fasta);
        istringstream ss(line_fasta);
        ss >> nc;
        ss >> s.sequence_id;

        getline(file_fasta, line_fasta);
        istringstream sr(line_fasta);
        while(sr >> nc)
            s.seq.push_back(make_pair(nc, ++count1));

        getline(file_qual, line_qual);
    
        getline(file_qual, line_qual);
        istringstream so(line_qual);
        while(so >> q)
            s.qual.push_back(make_pair(q, ++count2));

        temp_sequences.push_back(s);
    }

    int treshold;
    while(1)
    {
        cout << "Podaj prog wiarygodnosci: ";
        cin >> treshold;
        if(treshold >= 0 && treshold <= 40)
            break;
        else cout << "Wartosc musi znajdowac sie w przedziale 0-40!" << endl;
    }
   
    //filtrowanie sekwencji pod względem progu wiarygodności
    vector<Sequence>sequences;
    for(auto i: temp_sequences)
    {
        Sequence x;
        x.sequence_id = i.sequence_id;
        
        for(auto j: i.qual)
        {
            if(j.first >= treshold)
            {
                for(auto k: i.seq)
                {
                    if(k.second == j.second)
                        x.seq.push_back(k); 
                }
                x.qual.push_back(j);
            }
        }
        sequences.push_back(x);
    }

    int k;
    while(1)
    {
        cout << "Podaj wartosc k (dlugosc podciagu): ";
        cin >> k;
        if(k >= 4 && k <= 9)
            break;
        else cout << "Wartosc musi znajdowac sie w przedziale 4-9!" << endl;
    }

    Graph G;
    //utworzenie wierzchołków z etykietami bedącymi wszytskimi możliwymi podciągami o dł. k i dodanie ich do grafu
    for(auto i: sequences)
    {
        string seq_in_string = "";
        for(auto j: i.seq)
            seq_in_string += j.first;

        for(int j=0; j < (i.seq.size() - k + 1); j++)
        {
            Vertex v;
            v.sequence_id = i.sequence_id;
            v.position = (i.seq[j]).second;
            v.subsequence = seq_in_string.substr(j, k);
            G.add_vertex(v);
        }
    }

    //dodanie krawędzi do grafu
    for(vector<Vertex>::iterator it = G.vertices.begin() ; it != G.vertices.end(); ++it)
    {
        for(vector<Vertex>::iterator it2 = G.vertices.begin() ; it2 != G.vertices.end(); ++it2)
        {
            if(it->subsequence == it2->subsequence && it->sequence_id != it2->sequence_id && abs(it->position - it2->position) <= 10*k)
                it->add_neighbour(*it2);
        }
    }

    //wyszukiwanie struktury gwiazdy w grafie
    Graph star;
    bool in_star = false;
    for(auto a: G.vertices)
    {
        if(a.neighbours.size() >= 4)
        {                              
            star.add_vertex(a);
            for(auto b: a.neighbours)
            {
                for(auto c: star.vertices)
                {
                    if(c.sequence_id == b.sequence_id)
                        in_star = true;
                }
                if(!in_star)
                    star.add_vertex(b);
                in_star = false;
            }
            if(star.vertices.size() == 5)
            {                                   //mając zagwarantowane, że w uzbieranej klice nie ma żadnego wierzchołka z tej samej sekwencji, 
                star.print_graph();             //musimy sprawdzić, czy ta klika ma 5 wierzchołków (reprezentuje wszystkie 5 sekwencji)
                break;
            }                               
            else star = Graph();
        }
    }

    system("pause");
    return 0;
}