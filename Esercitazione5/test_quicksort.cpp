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
        std::cout << v[i] << " "<<"\n";
    }
    std::cout << "\n";
}

int main() {
	randfiller rf;
	for (int j=1; j<=100; j++){  //k come numero di vettori generati
		double k_random= std::rand();
		int k = (int)(k_random / RAND_MAX *100 ) ;    
		
		std::vector<int> vi;
		vi.resize(k); 
		rf.fill(vi, -10, 10);
		//print_vector(vi);
		quick_sort(vi, 0, vi.size()-1);
		if (!is_sorted(vi)) return EXIT_FAILURE;
		
		std::vector<float> vf;
		vf.resize(k);
		rf.fill(vf, -10.0f, 10.0f);
		//print_vector(vf);
		quick_sort(vf, 0, vf.size()-1);
		if (!is_sorted(vf)) return EXIT_FAILURE;
		
		std::vector<double> vd;
		vd.resize(k);
		rf.fill(vd, -10.0, 10.0);
		//print_vector(vd);
		quick_sort(vd, 0, vd.size()-1);
		if (!is_sorted(vd)) return EXIT_FAILURE;
		
		std::vector<std::string> vs = {"zero", "uno", "due", "tre", "quattro", "cinque", "sei", "sette", "otto", "nove"};
		//print_vector(vs);
		quick_sort(vs, 0, vs.size()-1);
		if (!is_sorted(vs)) return EXIT_FAILURE;
		
	}
}