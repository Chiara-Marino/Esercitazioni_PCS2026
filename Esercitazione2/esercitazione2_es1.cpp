# include <iostream>

int main()
{
 double ad[4] = {0.0, 1.1, 2.2, 3.3};
 float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
 int ai[3] = {0, 1, 2};


 int x = 1;
 float y = 1.1;
 

 (&y)[1] = 0;   //prendo l'indirizzo di y (float) e aggiungo 1*4 (sizeoffloat); a ciò che trovo, sovrascrivo 0

 std::cout << x << "\n";     //stampa x
 
 std::cout << &ad[2] << "\n"; // stampa l'elemento in posizione 2 di ad, ovvero 2.2
                               // tra il suo indirizzo e quello di x c'è una differenza di 64 byte, ma ciò è  
								//dovuto al fatto che il computer non salva il memoria gli elementi nel modo
								// in cui vengono scritti-> in questo caso salva ad, af, ai e poi y e x
// dunque la riga 12 modifica ciò che trova nella posizione dopo y con la formula base+ i*sizeof(tipo), ovvero x 
// per questo motivo x viene sopvrascritto con 0 e il programma salva 0
 std::cout << &x << "\n";

 return 0;
}