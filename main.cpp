#include <iostream>

using namespace std;

const int dimensioneMax=8;

//prototipi
void Ordinamento(string v[]);
void Ricerca(string v[]);
int Menu();

int main() {

  int scelta;
  string province[dimensioneMax] = {"TO","MI","GE","FI","PA","AO","BO","FG"};
  
  do {
    scelta=Menu();
    switch(scelta) {
      case 1:
        Ordinamento(province);
      break;
      case 2:
        Ricerca(province);
      break;
      case 0:
        cout<<"Esci"<<endl;
      break;
      default:
        cout<<"Attenzione, scelta sbagliata!"<<endl;
      break;
    }
  }while(scelta!=0);
  
  
}

int Menu() {
  int scegli;
  cout<<"-------MENU'-------"<<endl;
  cout<<"1-Ordina elementi"<<endl;
  cout<<"2-Esegui ricerca"<<endl;
  cout<<"0-Fine"<<endl;

  cout<<"Scegli un operazione: "<<endl;
  cin>>scegli;

  return scegli;
}


void Ordinamento(string v[]) {

  string temp;
  
  for(int i=0; i<dimensioneMax-1; i++) {
    for(int j=i+1; j<dimensioneMax; j++) {
      if(v[i]>v[j]) {
        temp=v[i];
        v[i]=v[j];
        v[j]=temp;
      }
    }
  }

  for(int i=0; i<dimensioneMax; i++) {
    cout<<v[i]<<endl;
  }
  
}


void Ricerca(string v[]) {

  int i=0;
  int inizio=0;
  bool trovato=false;
  int fine=dimensioneMax-1;
  string chiave;

  cout<<"Inserisci la sigla della provincia da carcare: ";
  cin>>chiave;

  while(trovato==false&&inizio<=fine) {
    i=(inizio+fine)/2;
    if(v[i]==chiave) {
      trovato=true;
    } else {
      if(v[i]>chiave) {
        fine=i-1;
      } else {
        inizio=i+1;
      }
    }
  }

  if(trovato==false) {
    cout<<"Provincia non trovata"<<endl;
  } else {
    cout<<"Provincia trovata"<<endl;
  }

  
}
