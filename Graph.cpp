
#include <fstream>
#include <iostream>
#include <sstream>
#include "Graph.h"

// initialize an undirected graph that can store at most n vertices
Graph::Graph(int n) {

    adj.resize(n);
}


// return the maximum number of vertices
int Graph::size() {
    return adj.size();
}


// give a string label to vertex
void Graph::addLabel(Vertex i, const string& s) {
    intToLabels[i] = s;
    labelsToInt[s] = i;
}

// TO DO
// add an edge between vertices i and j
void Graph::addEdge(Vertex i, Vertex j) {
    adj[i].push_back(j);
}

// return a vector of vertices adjacent to vertex n
vector<Vertex> Graph::getAdjacentVertices(Vertex n) {
    vector<Vertex> vertex_adj;
    //getting friends
    for (int & i : adj[n]) {
        vertex_adj.push_back(i);
    }

    return vertex_adj;
}

// return a list of names that contain friends of friends of person
// names should not be repeated
vector<string> recommendFriends(Graph &graph, const string &person) {
    //getting index of the person
    Vertex index = graph.getVertex(person);
    //getting friends of that person
    vector<Vertex> vertex_adj = graph.getAdjacentVertices(index);

    vector<string> recommended_friends;

    vector<Vertex> vertex_recommend;
    map<string, bool> unique_list;
    string friend_name;

    //adding himself to the unique list
    friend_name = graph.getLabel(index);
    unique_list[friend_name] = true;

    //adding friends to unique list
    for (int i : vertex_adj) {
        friend_name = graph.getLabel(i);
        unique_list[friend_name] = true;

    }

    for (int i : vertex_adj) {
        //getting friends of friends
        vertex_recommend = graph.getAdjacentVertices(i);

        for (int j : vertex_recommend) {

            friend_name = graph.getLabel(j);
            //checking if not already added
            if (!unique_list[friend_name]) {
                recommended_friends.push_back(friend_name);
                unique_list[friend_name] = true;
            }
        }
    }
    return recommended_friends;
}


// read from a text file, the labels (names) to be associate with each vertex (int)
void readNamesFromFile(Graph &graph, const string &filename) {

    ifstream inputFile;
    inputFile.open(filename);
    if (!inputFile.is_open())
        throw invalid_argument("Unable to open file " + filename);
    string s;
    int i;
    while (!inputFile.eof()) {
        inputFile >> i >> s;
        // cout << "adding label " << i << ": " << s << endl;
        graph.addLabel(i, s);
    }
}

// read from a text file, the list of friends for each vertex (int)
void readFriendsFromFile(Graph &graph, const string &filename) {

    ifstream inputFile;
    inputFile.open(filename);
    if (!inputFile.is_open())
        throw invalid_argument("Unable to open file " + filename);

    for (string line; getline(inputFile, line);) {
        istringstream iss(line);
        int i;
        iss >> i;
        int j;
        while (!iss.eof()) {
            iss >> j;
            // cout << "adding edge " << i << " to " << j << endl;
            graph.addEdge(i, j);
        }
    }
}

string Graph::getLabel(Vertex n) {
    return intToLabels[n];
}

Vertex Graph::getVertex(const string &label) {
    return labelsToInt[label];
}
