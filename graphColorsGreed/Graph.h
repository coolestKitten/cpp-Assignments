#pragma once
#include "Node.h"

class Graph{
    private:
        int numVert;
        Node* head;
    public:
        Graph(int);

        Node* getHead();
        int getAmtVert();

        void setHead(Node*);

        void insertNode(int);
        void insertEdges(vector<int>, int);
        void shList();
        Node* returnByIndex(int);
        
        void colorNodes();
};

Graph::Graph(int V){
    numVert = V;
    head = NULL;
}

Node* Graph::getHead(){
    return head;
}
int Graph::getAmtVert(){
    return numVert;
}

void Graph::setHead(Node* _head){
    head = _head;
}

Node* Graph::returnByIndex(int Index){
  if (head == NULL){
    return NULL;
  } else {
    Node* aux = head;
    while (aux != NULL && aux->getIndex() != Index){
      aux = aux->getNext();

    }
    if (aux == NULL){
      return NULL;
    } else {
      return aux;
    }
  }

} 

void Graph::insertNode(int _newNode){
    Node* newDat = new Node(_newNode);
    //cout << "kiti" << endl;
    if(head == NULL){
        head = newDat;

    } else {
        Node *aux = head, *prev = head;
        
        while (aux != NULL && aux->getIndex() < _newNode){
            prev = aux;
            aux = aux->getNext();
        }
        //cout << "kiti" << endl;
        if (prev == aux){
            newDat->setNext(head);
            head = newDat;
        } else if (aux == NULL){
            prev->setNext(newDat);
        } else {
            prev->setNext(newDat);
            newDat->setNext(aux);
        }
    }


}

// receives an adjacency vector, like so {0 0 1 0 1}, and an integer, indicating the node it belongs to
void Graph::insertEdges(vector<int> edges, int nodeIndex){ 
    Node* aux = head;
    //cout << "BeginInsertion" << endl;

    while (aux != NULL){ // finds the node requested by method
        //cout << "SwitchingNode" << endl;

        if (aux->getIndex() == nodeIndex){
            //cout << "FoundNode" << endl;
            for (int i = 0; i<edges.size(); i++){
                if(edges[i] == 1 && aux->findAdj(i) == false){
                    //cout << "AdjFound, inserting" << endl;

                    aux->addAdj(i);
                }
            }
            //aux = aux->getNext();
           
        }
        aux = aux->getNext();
    }
    
}

void Graph::shList(){
    Node *aux = head;
    while (aux != NULL){
        aux -> shNode();
        aux = aux->getNext();
    }
}
        
void Graph::colorNodes(){
    vector<bool> available(numVert, false);
    head->setColor(0);
    Node* aux = head->getNext();

    while (aux != NULL){
        vector<int> adj = aux->getEdges();
        //cout << "Current node is: " << aux->getIndex() << endl;
        for (int i = 0; i< adj.size(); ++i){
            //cout << "Adjacent nodes: " << adj.size() << endl;
            if(returnByIndex(adj[i])->getColor() != -1){ // get the node based on the index, then get the assigned color
                //cout << "Node color is: " << returnByIndex(adj[i])->getColor() << " setting as occupied" << endl;
                available[returnByIndex(adj[i])->getColor()] = true;
            }// if the color is unassigned, set the corresponding color to occupied
        }
        //cout << "Available colors: " << endl;
        for (int i = 0; i < available.size(); i++){

            cout << available[i] << " ";
        
        }
        cout << endl;
        //find the next available color
        int cID;
        for (cID = 0; cID< available.size(); cID++){
            if(available[cID] == false){
                //out << "next available color: " << cID << endl;
                break;
            }
        }

        // assign the found color
        aux->setColor(cID);

        //reset all color values back to false
        for (int i = 0; i < available.size(); i++){
            if(returnByIndex(adj[i])->getColor() != -1){ 
                available[returnByIndex(adj[i])->getColor()] = false;
            }
        }

        //move to the next node
        aux = aux->getNext();
    }

}