#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, const char *argv[])
{
	ifstream ifs(argv[1]);
	if ( !ifs.is_open() ){
		std::cout << "errore: il file non viene aperto";
	}
	if (argc<2) {
		std::cout << "errore: nome del file non inserito";
	}
		
	if ( ifs.is_open() ) { 
			string city;
			double t1, t2, t3, t4;	
			while (ifs >> city >> t1 >> t2 >> t3 >> t4){
				double media= (t1+t2+t3+t4)/4;	
				std::cout << city << " la media è:" << media << "\n";
			}
		
	}	
	return 0;

}