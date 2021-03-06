#include "telefonata.h"

telefonata::telefonata(orario i, orario o, unsigned short int *n): inizio(i), fine(o) {
  int j = 0;
  numero = new unsigned short int[14];
  while(j<14) { numero[j] = n[j]; j++; }
}
telefonata::telefonata(const telefonata& t): inizio(t.inizio), fine(t.fine) {
  numero = new unsigned short int[14];
  for(int i=0; i<14; i++) numero[i] = t.numero[i];
}
orario telefonata::Inizio() const { return inizio; }
orario telefonata::Fine() const { return fine;  }
unsigned short int *telefonata::Numero() const {  return numero;  }
bool telefonata::sameNumber(const unsigned short int *b, const unsigned short int *c) const{
  int i = 0;
  bool eq = true;
  while(i<14 && eq){
      eq = b[i]==c[i];
      i++;
    }
  return eq;
}
bool telefonata::operator==(const telefonata& t) const{
  return  inizio == t.inizio &&
          fine == t.fine  &&
          sameNumber(numero, t.numero);
}
std::ostream& operator<<(std::ostream& os, const telefonata& t){
  os <<  "INIZIO:" << t.Inizio() << " FINE:" <<  t.Fine()
        << " NUMERO CHIAMATO:";
  unsigned short int* f = t.Numero();
  for(int i=0; i<14; i++) os<<f[i];
  return os;
}
