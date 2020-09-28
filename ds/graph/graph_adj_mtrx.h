#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <queue>

namespace ds
{
struct AdjMtrxGraph
{
    static const int MAX_VERTEX_SIZE = 100;

    AdjMtrxGraph(int n = 0) :num_vertices_(n) {
        for (int i = 0; i < num_vertices_; i++) {
            for (int j = 0; j < num_vertices_; j++) {
                adj_mtrx_[i][j] = 0;
            }
            visited_[i] = false;
        }
    }
    ~AdjMtrxGraph() {
    }
    void AddDirectedEdge(int u, int v) {
        adj_mtrx_[u][v] = 1;
    }
    void AddUnDirectedEdge(int u, int v) {
        adj_mtrx_[u][v] = 1;
        adj_mtrx_[v][u] = 1;
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

            for (int v = 0; v < num_vertices_; v++) {
                if (adj_mtrx_[u][v] && (visited_[v] == false)) {
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
    void DFSTraversalUtil(int u) {
        std::cout << u << "  ";
        visited_[u] = true;

        for (int v = 0; v < num_vertices_; v++) {
            if (adj_mtrx_[u][v] && (visited_[v] == false)) {
                DFSTraversalUtil(v);
            }
        }
    }
private:
    int num_vertices_;
    int adj_mtrx_[MAX_VERTEX_SIZE][MAX_VERTEX_SIZE];
    bool visited_[MAX_VERTEX_SIZE];
};
};