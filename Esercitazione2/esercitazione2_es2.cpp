# include <iostream>
# include<cmath>


int main()
{
	static const int N = 10;
 	double arr[N]={3.4, 5.6, 7.2, 4.9, 7.4, 8.8, 0.8, 7.3, 10.1, 8.3};
	
	double a= arr[0];
	for (int i=1; i<N; i=i+1) {
		a=std::min(	a, arr[i]);
	}
	std:: cout << "Il valore minimo è: " << a << "\n";
	
	double  b= arr[0];
	for (int i=1; i<N; i=i+1) {
		b=std::max(b, arr[i]);
	}
	std:: cout << "Il valore massimo è: " << b << "\n";
	
	double somma=0;
	for (int i=0; i<N; i=i+1) {
		somma=somma+arr[i];
		
	}
	double media=somma/N;
	std:: cout << "la media è: "<< media << "\n";
	
	double somma_quadrati=0;
	for (int i=0; i<N; i=i+1) {
		somma_quadrati=pow(arr[i]-media,2)+somma_quadrati;
	}
	double devstandard= std::sqrt(somma_quadrati/N);
	std:: cout << "la deviazione standard è: "<< devstandard<< "\n";
	
	
	return 0;
}