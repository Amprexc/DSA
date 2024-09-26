#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph {
private:
    unordered_map<string, unordered_set<string>> adjList;


public:
    bool addVertex(string vertex) {
        if (adjList.count(vertex) == 0) {
            adjList[vertex];
            return true;
        }
        return false;
    }

    bool addEdge(string vertex1, string vertex2) {
        if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
            adjList.at(vertex1).insert(vertex2);
            adjList.at(vertex2).insert(vertex1);
            return true;
        }
        return false;
    }
    bool removeEdge(string vertex1, string vertex2) {
        if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
            adjList.at(vertex1).erase(vertex2);
            adjList.at(vertex2).erase(vertex1);
            return true;
        }
        return false;
    }

    bool removeVertex(string vertex) {
        if (adjList.count(vertex) != 0) {
            for (auto otherVertex : adjList.at(vertex)) {
                adjList.at(otherVertex).erase(vertex);
            }
            adjList.erase(vertex);
            return true;
        }
        else {
            return false;
        }
    }

    void printGraph() {
        for (auto [vertex, edges] : adjList) {
            cout << vertex << ": [ ";
            for (auto edge : edges) {
                cout << edge << " ";
            }
            cout << "]" << endl;
        }
    }
};