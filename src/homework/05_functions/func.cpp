//add include statements
#include "func.h"
//add function code here
using namespace std;

double get_gc_content(const string& dna) 
{
    if (dna.empty()) {
        return 0.0;
    }

    int gc_count = 0;
    for (char c : dna) {
        if (c == 'C' || c == 'G') {
            gc_count++;
        }
    }
    return static_cast<double>(gc_count) / dna.length();
}

string get_reverse_string(string dna) {
    string reversed_dna = "";
    for (int i = dna.length() - 1; i >= 0; --i) {
        reversed_dna += dna[i];
    }
    return reversed_dna;
}

string get_dna_complement(string dna) {
    string reversed_dna = get_reverse_string(dna);
    for (char& c : reversed_dna) {
        switch (c) {
            case 'A': c = 'T'; break;
            case 'T': c = 'A'; break;
            case 'C': c = 'G'; break;
            case 'G': c = 'C'; break;
        }
    }
    return reversed_dna;
}