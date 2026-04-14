#include <vector>
#include <iostream>

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
