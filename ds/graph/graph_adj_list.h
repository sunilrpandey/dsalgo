#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <queue>

namespace ds
{	
struct AdjListGraph
{
    AdjListGraph(int n = 0):num_vertices_(n){
        adj_list_.reserve(num_vertices_);
        for (int i = 0; i < num_vertices_; i++) {
            adj_list_.push_back(std::list<int>());
            visited_.push_back(false);
        }

    }
    ~AdjListGraph() {
    }
    void AddDirectedEdge(int u, int v) {
        adj_list_[u].push_back(v);
    }
    void AddUnDirectedEdge(int u, int v) {
        adj_list_[u].push_back(v);
        adj_list_[v].push_back(u);
    }
    void BFSTraversal(int start) {
        
        std::cout << "BFS Traversal : ";
        for (int i = 0; i < num_vertices_; i++) {
            visited_[i] = false;
        }

        std::queue<int> q;
        q.push(start);
        visited_[start] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            std::cout << u << "  ";

            for (auto v : adj_list_[u]) {
                if (visited_[v] == false) {
                    visited_[v] = true;
                    q.push(v);
                }
            }
        }
    }
    void DFSTraversal(int start) {
        std::cout << "DFS Traversal : ";
        for (int i = 0; i < num_vertices_; i++) {
            visited_[i] = false;
        }
        DFSTraversalUtil(start);
        std::cout << std::endl;
    }
private:
    void DFSTraversalUtil(int u) {
        std::cout << u << "  ";
        visited_[u] = true;

        for (auto v : adj_list_[u]) {
            if (visited_[v] == false) {
                DFSTraversalUtil(v);
            }
        }
    }
    int num_vertices_;
    std::vector<std::list<int>> adj_list_;
    std::vector<bool>  visited_;
};
}