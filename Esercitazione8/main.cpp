#include "grafi.hpp"
#include <iostream>
#include <string>
#include <set>

void test_name(const std::string test_name, bool condizione){           //funzione per stampare il risultato dei test
	if (condizione){
		std::cout << "  Successo  "<< test_name<< "\n";
	}
	else {
		std::cout << "  Fallimento  "<< test_name<< "\n";
	}
}

int main(){
	unidirected_edge<int> e1(20,6);                                         //test su unidirected_edge
	test_name("Ordinamento arco", e1.from()==6 && e1.to()==20);
	
	unidirected_edge<int> e2(6,20);
	test_name("Uguaglianza archi invertiti", e1==e2);
	
	unidirected_graph<std::string> g;                           //test su unidirected graph
	g.add_edge("A", "B");
	g.add_edge("A", "C");
	auto nodi_adiacenti=g.neighbours("A");                         //test aggiunta archi + vicini
	std::set<std::string> nodi_attesi={"B","C"};
	test_name("aggiunta e conteggio dei nodi vicini", nodi_adiacenti==nodi_attesi);
	
	unidirected_graph<int> g1, g2;
	g1.add_edge(2, 3);
	g1.add_edge(1, 3);
	g2.add_edge(2, 3);
	

	std::set<int> g1_nodi=g1.all_nodes();           //test su all nodes
	std::set<int> nodi_attesi_g1={1,2,3};
	test_name("Elenco nodi", nodi_attesi_g1==g1_nodi);
	
	std::set<unidirected_edge<int>> g1_archi=g1.all_edges();           //test su all edges
	test_name("Elenco archi", (g1_archi.size()==2)&& (g1_archi.count(unidirected_edge<int> (1,3))==1));      //verifico che compaiono 2 archi e che uno è proprio (1,3)
	                                                                                                         //l'altro sarà (2,3)
	
	unidirected_graph<int> g_copia(g1);              //test sul costruttore di copia
	test_name("Grafo copiato", g_copia.all_edges()==g1.all_edges());
	
	g_copia.add_edge(4, 3);                           //test sul costruttore di copia-> modifico la copia ma non g1
	test_name("Grafo modificato copiato", g_copia.all_edges()!=g1.all_edges());
	
	unidirected_graph<int> diff= g1-g2;                        //test differenza grafi
	auto archi_risultanti= diff.all_edges();
	unidirected_edge<int> arco_rimasto(1,3);
	test_name("differenza tra due grafi", archi_risultanti.count(arco_rimasto)==1);
	
	unidirected_edge<int> arco=g1.edge_at(1);               //test su edge.at
	unidirected_edge<int> arco_cercato(2,3);
	test_name("arco trovato nella posizione inserita", arco==arco_cercato);
	
	auto pos= g1.edge_number(arco_cercato);                    //test su edge_number
	test_name("numero dell'arco cercato", pos == 1);
	
	return 0;
}
