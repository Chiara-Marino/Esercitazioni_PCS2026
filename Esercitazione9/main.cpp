#include "adapter.hpp"
#include "grafi.hpp"
#include <set>
#include <map>

int main() {
	unidirected_graph<int> G;
	G.add_edge(1,3);
	G.add_edge(6,3);
	G.add_edge(6,8);
	G.add_edge(6,1);
	G.add_edge(1,4);
	G.add_edge(4,6);
	G.add_edge(6,7);
	G.add_edge(8,9);
	G.add_edge(7,6);
	G.add_edge(4,7);
	G.add_edge(4,2);
	G.add_edge(1,2);
	G.add_edge(7,2);
	G.add_edge(5,7);
	G.add_edge(5,2);
	G.add_edge(7,9);

	fifo<int> contenitore1;
	auto bfsG= graph_visit(G, 1, contenitore1);            //test bfs
	salva_dot(bfsG, "bfsG_risultati.dot");

	lifo<int> contenitore2;
	auto dfsG= graph_visit(G, 1, contenitore2);             //test dfs
	salva_dot(dfsG, "dfsG_risultati.dot");
	
	auto dfsG_ricorsiva=recursive_dfs(G, 1);
	salva_dot(dfsG_ricorsiva, "dfsG_ricorsiva_risultati.dot");

	
	std::map<int, int> distanze;
	std:: map<int, std::optional<int>> predecessori;

	dijkstra(G, 1, distanze, predecessori);
	unidirected_graph<int> albero_dijkstra;
	for (auto const& [nodo, predecessore]: predecessori){
		if (predecessore.has_value()){
			albero_dijkstra.add_edge(predecessore.value(),nodo);
		}
	}
	salva_dot(albero_dijkstra, "dijkstra_risultati.dot");
	return 0;
}

