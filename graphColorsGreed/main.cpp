#include "Graph.h"

int main (){
    int V;

    cout << "Insert amount of verts: ";
    cin >> V;
    while(cin.fail() || V <= 0){
        cout << "Invalid input" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> V;
    }
    Graph newGraph(V);
    for (int i = 0; i< V; i++){
        newGraph.insertNode(i);
    }
    /*
    newGraph.insertNode(2);
    newGraph.insertNode(0);
    newGraph.insertNode(4);
    newGraph.insertNode(3);
    newGraph.insertNode(1);*/

    newGraph.shList();

    vector<int> insertions(V, 1);

    for (int i= 0; i < V; i++){
        for (int j=0; j<V; j++){
            cin >> insertions[j];
            while(cin.fail() || V <= 0){
                cout << "Invalid input at index: " << j << endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> insertions[j];
            }
        }
        newGraph.insertEdges(insertions, i);
    } 
    
    //newGraph.insertEdges({0,0,1,0,1}, 0);
    //newGraph.insertEdges({0,0,1,1,1}, 1);
    //newGraph.insertEdges({1,1,0,1,0}, 2);
    //newGraph.insertEdges({0,1,1,0,1}, 3);
    //newGraph.insertEdges({1,1,0,1,0}, 4);
    newGraph.colorNodes();
    newGraph.shList();
    return 0;
}
