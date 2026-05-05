#include <vector>
#include <iostream>
#include <limits>

using namespace std;

template<typename T>
void bubble_sort(vector <T>& A){                             //algoritmo bubble sort
	int n=A.size();    
	for (int i=0; i<(n-1); i++ ){                           //rispetto allo psedudo codice, ricorda che i vettori pertono dalla posizione 0
		for (int j=(n-1); j>=i+1; j--){
			if (A[j]<A[j-1]){
				swap(A[j],A[j-1]);
			}
		}
	}
}

template<typename T>
void selection_sort(vector <T>& A){                             //algoritmo selection sort
	int n=A.size();    
	for (int i=0; i<(n-1); i++ ){ 	
		int min_index=i;
		for (int j=(i+1); j<n; j++){
			if (A[j]<A[min_index]){
				min_index=j;
			}
		}
		if (min_index!=i){
			swap(A[i],A[min_index]);
		}
	}
}
template<typename T>
void insertion_sort(vector <T>& A){                             //algoritmo insertion sort
	int n=A.size();    
	for (int j=0; j<n; j++ ){  
		T key	= A[j];	
		int i= j-1;
		while (i>=0 && A[i]>key){
			A[i+1]=A[i];
			i--;
		}
	A[i+1]=key;
	}
}

template<typename T>                              //implementiamo fusion da usare nel merge sort
void fusion(vector <T> & A, int p,int q, int r){ 
	int n1=q-p+1;
	int n2=r-q;
	vector<T> L(n1), R(n2);
	for (int i=0; i<n1; i++){
		L[i]=A[p+i];
		}
	for (int j=0; j<n2; j++){
		R[j]=A[q+j+1];
		}
	
	int i=0;                            
	int j=0;
	int k=p;	
	while (i<n1 && j<n2){
		if (L[i]<=R[j]){
			A[k]=L[i];
			i=i+1;
		}
		else {
			A[k]=R[j];
			j=j+1;
		}
		k++;
	}
	
	while (i<n1){
		A[k]=L[i];
		i++;
		k++;
	}
	while (j<n2){
		A[k]=R[j];
		j++;
		k++;
	}
	
}

template<typename T>                                             //algoritmo merge sort
void merge_sort(vector <T> & A, int p, int r){              //q è il centro, p e r sono i puntatori di sinistra e destra rispettivamente
	int q=0;
	if (p<r){
		q=(p+r)/2;
		merge_sort(A,p,q);
		merge_sort(A,q+1,r);
		fusion(A,p,q,r);                    //fusion=merge implementata da noi
	}
}

template<typename T> 
int partition(vector <T> & A, int p, int r){
	T x =A[r];
	int i=p-1;
	for (int j=p; j<=r-1; j++){
		if (A[j]<=x) {
			i=i+1;
			swap(A[i], A[j]);
		}
	}
swap(A[i+1], A[r]);
	return i+1;
}

template<typename T>                                             //algoritmo quick sort
void quick_sort(vector <T> & A, int p, int r){              //q è il centro, p e r sono i puntatori di sinistra e destra rispettivamente
	if (p<r){
		int q=partition(A,p,r);
		quick_sort(A,p,q-1);
		quick_sort(A,q+1,r);
	}
}


#include <iostream>
					
template<typename T>
bool is_sorted(const std::vector<T>& vec)
{
if (vec.size() <= 0) {
return true;                               //se lascio {} come nell'esempio, rischio di non capire quando la mia funzione 
}                                           //mi stampa falso-> o il vettore ha lunghezza 0 oppure non è ordinato
bool flag=true;

for (size_t i = 0; i < (vec.size()-1); i++) {
	if (vec[i]<=vec[i+1]){
		flag= true; 
	}
	else {
		flag= false;
		break;
	}
}
return flag;
}


//quicksort MODIFICATA-> dopo aver trovato N-soglia
template<typename T>
void insertion_sort_adattato(vector <T>& A,int p, int r){                             //algoritmo insertion sort adattato ad un vettore di indici da p a r
	int n=A.size();                                                                    //da usare nel quicksort modificato
	for (int j=p+1; j<=r; j++ ){  
		T key	= A[j];	
		int i= j-1;
		while (i>=p && A[i]>key){
			A[i+1]=A[i];
			i--;
		}
	A[i+1]=key;
	}
}

template<typename T>                                             //algoritmo quick sort
void quick_sort_ibrido(vector <T> & A, int p, int r){              //q è il centro, p e r sono i puntatori di sinistra e destra rispettivamente
	int n_soglia=256;                         //valore del'N-soglia trovato con il grafico
	if (p<r){
		if((r-p+1)<=n_soglia){                     //se sono sotto il valore dell'n-soglia, sfrutto l'insertion sort
			insertion_sort_adattato(A,p,r);
		}
		else{
			int q=partition(A,p,r);
			quick_sort_ibrido(A,p,q-1);
			quick_sort_ibrido(A,q+1,r);
		}
	}
}