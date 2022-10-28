#pragma once
#include <map>
#include <vector>
#include <string>


using namespace std;

typedef int Vertex;

class Graph{
public:
	explicit Graph(int n);
	int size();
	void addLabel(Vertex i, const string& s);
	void addEdge(Vertex i, Vertex j);
	vector<Vertex> getAdjacentVertices(Vertex N);
	string getLabel(Vertex N);
	Vertex getVertex(const string& label);


private:

	// member variables and functions to implement the public member functions
	vector< vector<Vertex>> adj;
	map<string, Vertex> labelsToInt;
	map<Vertex, string> intToLabels;
	
};


// return a list of names that contain friends of friends of person
// names should not be repeated
vector<string> recommendFriends(Graph &graph, const string& person);

// COMPLETED
// read from a text file, the labels (names) to be associate with each vertex (int)
void readNamesFromFile(Graph &graph, const string& filename);

// COMPLETED
// read from a text file, the list of friends for each vertex (int)
void readFriendsFromFile(Graph &graph, const string& filename);
