#include <iostream>
using namespace std;

#include "Naturale.h"

int Menu();

int main()
{int scelta;
Naturale numero,a,b,c;
 
 do
 {scelta=Menu();
  switch (scelta)
       {
        case 0:cout<<"\n\n\nHai scelto di uscire...\n";break;
        case 1:cout<<"\n\n       ---- Inserimento Naturale (intero positivo) ---\n\n";
               cout<<"\nInserire Il Dato  _ ";
               cin>>numero;
               cout<<"Il numero iserito e'_ ";
               cout<<numero<<endl<<endl;break;
        case 2:numero++;
               cout<<"\n\nIl numero incrementato e'_ ";
               cout<<numero<<endl<<endl;break;
        case 3:numero--;
               cout<<"\n\nIl numero decrementato e'_ ";
               cout<<numero<<endl<<endl;break;
        case 4:cout<<"\n\nInserire Il  primo  addendo a_ ";
               cin>>a;
               cout<<"\nInserire Il secondo addendo b_ ";
               cin>>b;
               c=a+b;
               cout<<"\nLa somma e'_ ";
               cout<<c<<endl<<endl;break;
        case 5:cout<<"\n\nInserire Il  primo  fattore a_ ";
               cin>>a;
               cout<<"\nInserire Il secondo fattore b_ ";
               cin>>b;
               c=a*b;
               cout<<"\nIl prodotto e'_ ";
               cout<<c<<endl<<endl;break;
        case 6:cout<<"\n\nInserire la base     a_ ";
               cin>>a;
               cout<<"\nInserire l'esponente b_ ";
               cin>>b;
               c=a^b;
               cout<<"\nIl risultato della potenza e'_ ";
               cout<<c<<endl<<endl;break;               
        case 7:cout<<"\n\nInserire Il Dato_ ";
               int aux;
			   cin>>numero;
               aux=numero.Fatt();		   //torna intero
               //c=numero.Fatt(numero);		//torna naturale
               cout<<"\nIl fattoriale e'_ ";
			   //cout<<c<<endl<<endl;
			   cout<<aux<<endl<<endl;break;
               
       }
  system("pause");     
 }while(scelta != 0);
}

int Menu()
{int risp;
 system("CLS");
 cout<<"\n\n       ---- MENU'----\n\n";
 cout<<"\n1. Inserimento";
 cout<<"\n2. Incrementa";
 cout<<"\n3. Decrementa";
 cout<<"\n4. Somma";
 cout<<"\n5. Prodotto";
 cout<<"\n6. Elevamento a Potenza";
 cout<<"\n7. Fattoriale";
 cout<<"\n0. Esci";
 cout<<"\n\n         Scelta_ ";
 cin>>risp;
 return risp;
}
