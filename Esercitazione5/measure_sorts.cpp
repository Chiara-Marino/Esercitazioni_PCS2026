#include "randfiller.h"
#include "is_sorted.hpp"
#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>
#include "timecounter.h"

using namespace std;
int main(){
	randfiller rf;
	timecounter tc;
	vector<vector<int>> prove;
	int numero_vettori=100; 
		
	for (int k=1; k<=100; k=k+4){
		int dimensione_vettore=k;  //si testano un centinaio di vettori, tutti di dimensione =k
		
		prove.resize(numero_vettori);       //riempio la matrice prove: contiene i 100 vettoori per ogni dimensione k 
		for (int i=0; i<numero_vettori; i++){
			prove[i].resize(dimensione_vettore);
			rf.fill(prove[i], -1000, 1000);
		}
		
		vector<vector<int>> prove_bubble=prove;
		vector<vector<int>> prove_selection=prove;
		vector<vector<int>> prove_insertion=prove;
		vector<vector<int>> prove_merge=prove;
		vector<vector<int>> prove_quick=prove;
		vector<vector<int>> prove_sort=prove;

		tc.tic();
		for (int j=0; j<numero_vettori; j++){
			bubble_sort(prove_bubble[j]);
		}
		double tempo_totale_bubble= tc.toc();
		double tempo_medio_bubble=tempo_totale_bubble/numero_vettori;

		tc.tic();
		for (int j=0; j<numero_vettori; j++){
			selection_sort(prove_selection[j]);
		}
		double tempo_totale_selection= tc.toc();
		double tempo_medio_selection=tempo_totale_selection/numero_vettori;

		tc.tic();
		for (int j=0; j<numero_vettori; j++){
			insertion_sort(prove_insertion[j]);
		}
		double tempo_totale_insertion= tc.toc();
		double tempo_medio_insertion=tempo_totale_insertion/numero_vettori;

		tc.tic();
		for (int j=0; j<numero_vettori; j++){
			merge_sort(prove_merge[j], 0, dimensione_vettore-1);
		}
		double tempo_totale_merge= tc.toc();
		double tempo_medio_merge=tempo_totale_merge/numero_vettori;

		tc.tic();
		for (int j=0; j<numero_vettori; j++){
			quick_sort(prove_quick[j],0, dimensione_vettore-1);
		}
		double tempo_totale_quick= tc.toc();
		double tempo_medio_quick=tempo_totale_quick/numero_vettori;

		tc.tic();
		for (int j=0; j<numero_vettori; j++){
			sort(prove_sort[j].begin(), prove_sort[j].end() );
		}
		double tempo_totale_sort= tc.toc();
		double tempo_medio_sort=tempo_totale_sort/numero_vettori;
		
	//ora stampiamo i risultati
	cout << k <<"\t"
				<< tempo_medio_bubble << "\t"
				<< tempo_medio_selection << "\t"
				<< tempo_medio_insertion << "\t"
				<< tempo_medio_merge << "\t"
				<< tempo_medio_quick << "\t"
				<< tempo_medio_sort << "\n";
	}
	
}

