#include <iostream>
#include <vector>
#include <string>
#include "randfiller.h"
#include "is_sorted.hpp"
#include <cstdlib>

template<typename T>
void
print_vector(const std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

int main() {
	randfiller rf;
	for (int j=1; j<=100; j++){  //j come numero di vettori generati di elementi da 1 a 100
		double k_random= std::rand();
		int k = (int)(k_random / RAND_MAX *100 ) ;         //genero un numero rondom e lo normalizzo perchè sia tra 0 e 100
		
		std::vector<int> vi;
		vi.resize(k); 
		rf.fill(vi, -10, 10);
		//print_vector(vi);
		bubble_sort(vi);
		if (!is_sorted(vi)) return EXIT_FAILURE;           //s il rpogframma fallisce, devo bloccare il programma
		
		
		std::vector<float> vf;
		vf.resize(k);
		rf.fill(vf, -10.0f, 10.0f);
		//print_vector(vf);
		bubble_sort(vf);
		if (!is_sorted(vf)) return EXIT_FAILURE;
		
		std::vector<double> vd;
		vd.resize(k);
		rf.fill(vd, -10.0, 10.0);
		//print_vector(vd);
		bubble_sort(vd);
		if (!is_sorted(vd)) return EXIT_FAILURE;
		
		std::vector<std::string> vs = {"zero", "uno", "due", "tre", "quattro", "cinque", "sei", "sette", "otto", "nove"};
		//print_vector(vs);
		bubble_sort(vs);
		if (!is_sorted(vs)) return EXIT_FAILURE; 
		
	}
}