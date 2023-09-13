#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

#include "Graph.h"

int main(int argc, const char * argv[]) {
    cout << "Filename of graph to load: ";

    // TODO: next five code snippets
    // Snippet 1: read filename and open file
	string filename;
	cin >> filename;
	ifstream ifs("Tests/" + filename);
	/*
	if (!ifs) {
		cout << "error opening" << endl;
	}*/
	
    // Snippet 2: get number graph size
    int Vertices;
	int Edges;
	ifs >> Vertices >> Edges;
	
    // Snippet 3: create graph
	Graph graph;
	for(int i = 0; i < Vertices; i++) {
		graph.insertVertex(i);
	}
    // Snippet 4: read edges
	for(int j = 0; j < Edges; j++) {
		int a;
		int z;
		float weight;
		ifs >> a >> z >> weight;
		graph.insertEdge(a, z, weight);
	}
    // Snippet 5: read start and end of path
    int startVertex;
	int endVertex;
	ifs >> startVertex >> endVertex;
	ifs.close();
    cout << "Shortest path from " << startVertex << " to " << endVertex << ":" << endl;

    vector<Vertex*> path;

    // TODO: call shortest path on your graph for the sstart and end verices and save result to path
    path = graph.shortestPath(startVertex, endVertex);
    for (auto i : path) { // this is a for-each loop
        cout << i->label << " ";
    }
    // cout endline at very end
    cout << endl;
    return 0;
}
