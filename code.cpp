#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    string word;
    int Lav_dist;
    vector<Node> children;
    Node(string word, int Lav_dist, vector<Node> children) {
        this->word = word;
        this->Lav_dist = Lav_dist;
        this->children = children;
    }
};