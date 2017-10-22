#ifndef TELEFONATA_H
#define TELEFONATA_H
#include "orario.h"

class telefonata{
public:
  telefonata();
  telefonata(orario, orario, short int * =0);
  telefonata(const telefonata&);
  orario Inizio() const;
  orario Fine() const;
  short int* Numero() const;
  bool operator==(const telefonata&) const;
  bool sameNumber(const short int *, const short  int *) const;
private:
  orario inizio, fine;
  short int* numero;
};

std::ostream& operator<<(std::ostream&, const telefonata&);

#endif // TELEFONATA_H
