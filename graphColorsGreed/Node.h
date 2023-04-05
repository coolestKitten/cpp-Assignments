#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Node{
    public:

        Node(int);

        int getColor();
        int getIndex();
        Node* getNext();
        vector<int> getEdges();

        void setColor(int);
        void setIndex(int);
        void setNext(Node*);

        void addAdj(int);
        bool findAdj(int);

        void shNode();

        
    private:
        int index, color;
        Node* next;
        vector <int> adj;

};



Node::Node(int _index){
    index = _index;
    color = -1;
    next = NULL;
}

int Node::getColor(){
    return color;

}
int Node::getIndex(){
    return index;
}
Node* Node::getNext(){
    return next;
}
vector<int> Node::getEdges(){
    return adj;
}


void Node::setColor(int _color){
    color = _color;
}
void Node::setIndex(int _index){
    index = _index;
}
void Node::setNext(Node* _next){
    next = _next;
}

void Node::addAdj(int newEdge){
    if(find(adj.begin(), adj.end(), newEdge) != adj.end()){
        cout << "Node already exists" << endl;
    } else {
        adj.push_back(newEdge);
    }
}
bool Node::findAdj(int target){
    if(find(adj.begin(), adj.end(), target) != adj.end()){
        return true;
    } else {
        return false;
    }
}

void Node::shNode(){
    cout << index << " -> ";
    
    for (int i = 0; i< adj.size();i++){
        cout << adj[i] << " ";
    }

    cout << "color: " << color << endl;
}