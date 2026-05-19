#pragma once
#include <set>
#include <map>
#include <queue>
#include "grafi.hpp"
#include <stack>
#include <string>
#include <fstream>
#include <iostream>
#include <optional>
#include <limits>

//adapter lifo e fifo
template <typename T>
class fifo {
	std::queue<T> dati;        //la mia classe contiene il contenitore STL queue
public:	
	fifo() 
		:dati() //costruttore default: crea un container vuoto
	{}  
	void put(const T& valore){
		dati.push(valore);
	}
	auto get(){
		auto elemento_selezionato=dati.front();
		dati.pop();
		return elemento_selezionato;
	}
	bool empty()const{
		return dati.empty();
	}
};

template <typename T>
class lifo {
	std::stack<T> dati;        //la mia classe contiene il contenitore STL stack
public:	
	lifo() 
		:dati() //costruttore default: crea un container vuoto
	{}  
	void put(const T& valore){
		dati.push(valore);
	}
	auto get(){
		auto elemento_selezionato=dati.top();
		dati.pop();
		return elemento_selezionato;
	}
	bool empty()const{
		return dati.empty();
	}
};
//implemento DFS e BFS insieme, sfruttando gli adapter
template <typename T, typename S, typename C>
T graph_visit(const T& grafo, const S& sorgente, C& contenitore){         //il contenitotre non è una costante perchè dovrò prenderci i nodi visitati poco alla volta
	T albero_visita;
	std::set<S> nodi_visitati;    //creo un set con i nodi visitati
	
	contenitore.put(sorgente);           //metto la sorgente nel mio contenitore(lifo o fifo)
	nodi_visitati.insert(sorgente);      //la aggiungo ai nodi visitati
	while (!contenitore.empty()){
		S nodo_considerato= contenitore.get();
		
		std::set<S> set_vicini=grafo.neighbours(nodo_considerato);
		for (auto iteratore = set_vicini.begin(); iteratore!=set_vicini.end(); iteratore++){
			S vicino = *iteratore;                      //faccio scorrere l'iteratore su tutto il set dei vicini e prendo l'elemento dove punta l'iteratore
			if (nodi_visitati.find(vicino)==nodi_visitati.end())  {                    //se cerco il mio vicino e arrivo alla fine senza averlo trovato 
				nodi_visitati.insert(vicino);                                          //lo aggiungo ai nodi visitati
				contenitore.put(vicino);
				
				albero_visita.add_edge(nodo_considerato, vicino);
			}
		}
	}
	return albero_visita;
}

template <typename T, typename S>
T recursive_dfs(const T& grafo, const S&sorgente){
	T albero_visita_ricorsiva;
	std::set<S> nodi_visitati;
	
	S nodo_considerato=sorgente;
	std::set<S> set_vicini=grafo.neighbours(nodo_considerato);
	if (nodi_visitati.find(nodo_considerato)==nodi_visitati.end()){
		chiamata_ricorsiva(grafo, nodo_considerato, nodi_visitati, albero_visita_ricorsiva);
	}
	return albero_visita_ricorsiva;
}
template <typename T, typename S>
void chiamata_ricorsiva(const T& grafo, const S& nodo_considerato, std::set<S>& nodi_visitati, T& albero_visita_ricorsiva ){
	nodi_visitati.insert(nodo_considerato);
	std::set<S> set_vicini=grafo.neighbours(nodo_considerato);          //ricreiamo un set dei nuovi vicini del nodo_considerato
	for (auto iteratore = set_vicini.begin(); iteratore!=set_vicini.end(); iteratore++){
			S vicino = *iteratore;
		if (nodi_visitati.find(vicino)==nodi_visitati.end()){
			albero_visita_ricorsiva.add_edge(nodo_considerato, vicino);
			chiamata_ricorsiva(grafo, vicino,nodi_visitati, albero_visita_ricorsiva);
		}
	//funzione che non restituisce nulla, semplicemente modifica ricorsivamente l'albero_visita_ricorsiva
	}
}


//funzione stampa per graph viz
template <typename T>
void salva_dot(T& grafo, const std::string& nome_file){
	std::ofstream ofs(nome_file);
	if(!ofs.is_open()){
		std::cerr<<"Impossibile aprire file\n";
		return;
	}
	ofs<< "graph G {" <<std::endl;
	auto nodi=grafo.all_nodes();
	for (auto& u: nodi){
		for (auto& v:grafo.neighbours(u)){			//per ogni nodo u prendiamo ogni vicino in grafo.neighbours
			if (u>v){                                //per stampare l'arco una sola volta
				ofs<<" " <<u<<"--"<<v<<";"<<std::endl;
			}
		}
	}
	ofs<<"}"<<std::endl;
	ofs.close();
}

template <typename T>
void dijkstra(const unidirected_graph<T>& grafo, 
			  const T& sorgente,
			  std::map<T, int>& distanze,                                 //uso una mappa che ad ogni nodi di tipo T associ un intero,ovvero la distanza con la sorgente
			  std:: map<T, std::optional<T>>& predecessori){                //stessa cosa, ma associa ad ogni nodo il suo predecessore
	         
	auto nodi= grafo.all_nodes();
	for (const auto& nodo: nodi){                                  //inizializzo distanze e predecessori
		distanze[nodo]=std::numeric_limits<int>::max();
		predecessori[nodo]= std:: nullopt;         //per gli interi non posso avere numeri negativi-> uso std::optional e nullopt per dire che non esiste un predecessore
	}
	predecessori[sorgente]=sorgente;
	distanze[sorgente]=0;
	
	std::set<T> coda_priorità;
	for (const auto& n:nodi){
		coda_priorità.insert(n);
	}
	while(!coda_priorità.empty()){
		auto it_minimo=coda_priorità.begin();
		for (auto it=coda_priorità.begin(); it!=coda_priorità.end(); it++){                 //troviamo il nodo con distanza minima; a questo punterà l'iteratore it_minimo 
			if (distanze[*it]<distanze[*it_minimo]){
				it_minimo=it;
			}
		}
		T u = *it_minimo;          //l'iteratore it_minimo punta al nodo u
		coda_priorità.erase(it_minimo);            //nel set cancello cosa sta nella posizione dell'iteratore minimo; corrisponde a dequeue
		
		
		if (distanze[u]== std::numeric_limits<int>::max()){
			break; //caso speciale: la distanza minima è infinito-> tutti i nodi distano infinito dalla sorgente 
		}
		for (const auto& v: grafo.neighbours(u)){
			if (coda_priorità.count(v)){
				int peso_arco =1;  				//metto il peso dell'arco =1
				if (distanze[v]>distanze[u] + peso_arco){
					distanze[v]=distanze[u] + peso_arco;
					predecessori[v]=u;
				}
			}                                                                                          
		}
	}
}
