#include "graph_adj_list.h"
#include "graph_adj_mtrx.h"

int main()
{
	{
		std::cout << "Adj List Graph Demo" << std::endl;
		int n = 4;
		int e = 6;
		ds::AdjListGraph adj_graph(4);
		adj_graph.AddDirectedEdge(0, 1);
		adj_graph.AddDirectedEdge(0, 2);
		adj_graph.AddDirectedEdge(1, 2);
		adj_graph.AddDirectedEdge(2, 0);
		adj_graph.AddDirectedEdge(2, 3);
		adj_graph.AddDirectedEdge(3, 3);

		adj_graph.DFSTraversal(1);

		//adj_graph.BFSTraversal(2);
	}
	{
		std::cout << std::endl << "Adj Mtrx Graph Demo" << std::endl;
		int n = 4;
		int e = 6;
		ds::AdjMtrxGraph matrx_graph(4);
		matrx_graph.AddDirectedEdge(0, 1);
		matrx_graph.AddDirectedEdge(0, 2);
		matrx_graph.AddDirectedEdge(1, 2);
		matrx_graph.AddDirectedEdge(2, 0);
		matrx_graph.AddDirectedEdge(2, 3);
		matrx_graph.AddDirectedEdge(3, 3);

		matrx_graph.DFSTraversal(1);

		//matrx_graph.BFSTraversal(2);
	}
	
	std::cin.get();
	return 0;
}