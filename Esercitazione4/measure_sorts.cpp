#include "randfiller.h"
#include "sorts.hpp"
#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>
#include "timecounter.h"


template<typename T>
void
print_vector(const std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

double secs= 1.0;
int main() {
	timecounter tc;                          /* istanzia il timecounter */
	randfiller rf;
	
	std::vector<double> tempo_bubblesort_interi(12);
	std::vector<double> tempo_insertionsort_interi(12);
	std::vector<double> tempo_selectionsort_interi(12);                  
	std::vector<double> tempo_sort_interi(12);
	
	std::vector<double> tempo_bubblesort_double(12);
	std::vector<double> tempo_insertionsort_double(12);
	std::vector<double> tempo_selectionsort_double(12);                  
	std::vector<double> tempo_sort_double(12);
	
	std::vector<double> tempo_bubblesort_float(12);
	std::vector<double> tempo_insertionsort_float(12);
	std::vector<double> tempo_selectionsort_float(12);                  
	std::vector<double> tempo_sort_float(12);
	int i=0;        //contatore vettori creati =posizione per salvare i tempi dei riordinamenti dei vettori
	
	for (int k=4; k<=8192; k=k*2){           //k come elementi dei vettori
	double somma_bubblesort_interi=0;
	double somma_selectionsort_interi=0;
	double somma_insertionsort_interi=0;
	double somma_sort_interi=0;
	double somma_bubblesort_float=0;
	double somma_selectionsort_float=0;
	double somma_insertionsort_float=0;
	double somma_sort_float=0;
	double somma_bubblesort_double=0;
	double somma_selectionsort_double=0;
	double somma_insertionsort_double=0;
	double somma_sort_double=0;
		for (int j=0	;j<100;	j=j+1)	{
			std::vector<int> vi;               //creo vettore vi (vettore interi)
			vi.resize(k); 
			rf.fill(vi, -10, 10);
			
			//ordino vi con le varie funzioni scritte nel file sort.hpp
			
			//uso una copia di vi e gli altri vettori generati random per metterli in ordine
			std::vector<int> vi_ordinato_bubble=vi;
			tc.tic(); 		/* avvialo */ 
			bubble_sort(vi_ordinato_bubble);
			secs = tc.toc(); 		/* ferma il contatore del tempo, ottieni il tempo e stampalo */
			somma_bubblesort_interi=somma_bubblesort_interi+secs;
	
			std::vector<int> vi_ordinato_selection=vi;
			tc.tic(); 
			selection_sort(vi_ordinato_selection);
			secs = tc.toc(); 
			
			somma_selectionsort_interi=somma_selectionsort_interi+secs;
			
			std::vector<int> vi_ordinato_insertion=vi;
			tc.tic(); 
			insertion_sort(vi_ordinato_insertion);
			secs = tc.toc(); 
			somma_insertionsort_interi=somma_insertionsort_interi+secs;
			
			std::vector<int> vi_ordinato_sort=vi;
			tc.tic();
			std::sort( vi_ordinato_sort.begin(), vi_ordinato_sort.end() );
			secs = tc.toc();
			somma_sort_interi+=secs;
			
			std::vector<float> vf;          //creo vettore vf (vettore float)
			vf.resize(k);
			rf.fill(vf, -10.0f, 10.0f);
			
			std::vector<float> vf_ordinato_bubble=vf;
			tc.tic(); 
			bubble_sort(vf_ordinato_bubble);
			secs = tc.toc(); 
			somma_bubblesort_float+=secs;
			
			std::vector<float> vf_ordinato_selection=vf;
			tc.tic(); 
			selection_sort(vf_ordinato_selection);
			secs = tc.toc(); 
			somma_selectionsort_float+=secs;
			
			std::vector<float> vf_ordinato_insertion=vf; 
			tc.tic();         
			insertion_sort(vf_ordinato_insertion);
			secs = tc.toc(); 
			somma_insertionsort_float+=secs;
			
			std::vector<float> vf_ordinato_sort=vf;
			tc.tic(); 
			std::sort( vf_ordinato_sort.begin(), vf_ordinato_sort.end() );
			secs = tc.toc();
			somma_sort_float+=secs;
			
			std::vector<double> vd;                //creo vettore vd (vettore double)
			vd.resize(k);
			rf.fill(vd, -10.0, 10.0);
			
			std::vector<double> vd_ordinato_bubble=vd;
			tc.tic();  
			bubble_sort(vd_ordinato_bubble);
			secs = tc.toc(); 
			somma_bubblesort_double+=secs;
			
			std::vector<double> vd_ordinato_selection=vd;
			tc.tic();  
			selection_sort(vd_ordinato_selection);
			secs = tc.toc(); 
			somma_selectionsort_double+=secs;
			
			
			std::vector<double> vd_ordinato_insertion=vd;
			tc.tic();  
			insertion_sort(vd_ordinato_insertion);
			secs = tc.toc(); 
			somma_insertionsort_double+=secs;
			
			std::vector<double> vd_ordinato_sort=vd;
			tc.tic(); 
			std::sort( vd_ordinato_sort.begin(), vd_ordinato_sort.end() );
			secs = tc.toc();
			somma_sort_double+=secs;
			
			}	
		double media_bubblesort_double=somma_bubblesort_double/100;          //rendo le somme delle medie aritmetiche
		double media_bubblesort_float=somma_bubblesort_float/100;
		double media_bubblesort_interi=somma_bubblesort_interi/100;
		double media_selectionsort_double=somma_selectionsort_double/100;
		double media_selectionsort_float=somma_selectionsort_float/100;
		double media_selectionsort_interi=somma_selectionsort_interi/100;
		double media_insertionsort_double=somma_insertionsort_double/100;
		double media_insertionsort_float=somma_insertionsort_float/100;
		double media_insertionsort_interi=somma_insertionsort_interi/100;
		double media_sort_double=somma_sort_double/100;
		double media_sort_float=somma_sort_float/100;
		double media_sort_interi=somma_sort_interi/100;
		
		tempo_bubblesort_interi[i]=media_bubblesort_interi;
		tempo_bubblesort_double[i]=media_bubblesort_double;
		tempo_bubblesort_float[i]=media_bubblesort_float;
		
		tempo_selectionsort_interi[i]=media_selectionsort_interi;
		tempo_selectionsort_double[i]=media_selectionsort_double;
		tempo_selectionsort_float[i]=media_selectionsort_float;
		
		tempo_insertionsort_interi[i]=media_insertionsort_interi;
		tempo_insertionsort_double[i]=media_insertionsort_double;
		tempo_insertionsort_float[i]=media_insertionsort_float;
		
		tempo_sort_interi[i]=media_sort_interi;
		tempo_sort_double[i]=media_sort_double;
		tempo_sort_float[i]=media_sort_float;
		
		i=i+1;       //incremento posizione vettore medie tempi
		}
	
	std::cout<<"Per grafici matlab:";
	std::cout<<"vettori tempi bubblesort\n";
	print_vector(tempo_bubblesort_double);
	print_vector(tempo_bubblesort_float);
	print_vector(tempo_bubblesort_interi);
	std::cout<<"vettori tempi selection sort\n";
	print_vector(tempo_selectionsort_double);
	print_vector(tempo_selectionsort_float);
	print_vector(tempo_selectionsort_interi);
	std::cout<<"vettori tempi insertion sort\n";
	print_vector(tempo_insertionsort_double);
	print_vector(tempo_insertionsort_float);
	print_vector(tempo_insertionsort_interi);
	std::cout<<"vettori tempi sort preimpostata\n";
	print_vector(tempo_sort_double);
	print_vector(tempo_sort_float);
	print_vector(tempo_sort_interi);
	
	return 0;
}	
	
	
	
	
	
	
	
	