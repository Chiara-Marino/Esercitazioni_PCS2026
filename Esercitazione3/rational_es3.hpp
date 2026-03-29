#include <concepts>
#include <iostream>
#include <numeric>       // per la funzione del massimo comune divisore gcd
#include <cmath>        //per il valore assoluto abs

template<typename I> requires std::integral<I>
class rational
{
	I num_;
	I den_;

void semplifica() {
	if (den_==0) {
	return;}
	else {
	I comune=std::gcd(std::abs(num_),std::abs(den_));
	num_/= comune;
	den_/= comune;
	}
};

public:
/* Costruttore di default */
	rational()
		: num_(I{0}), den_(I{1})            // scrivo solo 0 e non 0.0 come nell'esempio perchè tratto interi
		                                     // metto 1 per inizializzare il denominatore senza dìfinire nel NaN
{}

 /* Costruttore user-defined */
	rational(const I& pnum, const I& pden)
		: num_(pnum), den_(pden) 
		{semplifica();}                        //aggiungo la funzione semplifica nel costruttore per semplificare subito i numeri
	
/* Restituiscono i valori di num e den */
	I num() const { return num_; }
	I den() const { return den_; }
	
	
/* Implementazione canonica della somma +=*/
	rational& operator+=(const rational& other) {
	num_ = (other.den_*num_)+(other.num_*den_) ;
	den_ = other.den_*den_;
	semplifica();                //alla fine di ogni operazione, semplifico il risultato
	return *this;
    }
/* Implementazione canonica della somma + */
	rational operator+(const rational& other) const {
	rational ret = *this;
	ret += other;
	return ret;
}

/* Implementazione canonica della sottrazione */
	rational& operator-=(const rational& other) {
	num_ = (other.den_*num_) - (other.num_*den_);
	den_ = other.den_*den_;
	semplifica();
	return *this;
    }
/* Implementazione canonica della sottrazione - */
	rational operator-(const rational& other) const {
	rational ret = *this;
	ret -= other;                                              // qui non ho bisogno di usare semplifica perchè  
	return ret;                                               //sto solo copiando cosa succede nell'altra operazione
}															//la funzione semplifica darebbe anche problemi perchè 
															//non posso sovrascrivere i numeri per const
/* Implementazione canonica di moltiplicazione *= */
	rational& operator*=(const rational& other) {
	num_ *= other.num_;
	den_ *= other.den_;
	semplifica();
	return *this;
}
/* Implementazione canonica di moltiplicazione *  */
	rational operator*(const rational& other) const {
	rational ret = *this;
	ret*= other;
	return ret;
}
/* Implementazione canonica di divisione /= */
	rational& operator/=(const rational& other) {
	num_ *= other.den_;
	den_ *= other.num_;
	semplifica();
	return *this;
}
/* Implementazione canonica di divisione /  */
	rational operator/(const rational& other) const {
	rational ret = *this;
	ret /= other;
	return ret;
 }
};


template<typename I>
std::ostream&
operator<<(std::ostream& os, const rational<I>& v)
{
	if (v.den() ==0 && v.num() ==0) {
		os << "NaN" ;
	}
	else if ( v.den() ==0  && v.num() !=0) {
		os << "Inf" ;
	}
	else  { 
	os << "(" << v.num() << "," << v.den() << ")";
	}
	return os;
}	
