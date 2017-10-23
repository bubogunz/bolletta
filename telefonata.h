#ifndef TELEFONATA_H
#define TELEFONATA_H
#include "orario.h"

class telefonata{
public:
  telefonata();
  telefonata(orario, orario, unsigned short int * =0);
  telefonata(const telefonata&);
  orario Inizio() const;
  orario Fine() const;
  unsigned short int* Numero() const;
  bool operator==(const telefonata&) const;
  bool sameNumber(const unsigned short int *, const unsigned short  int *) const;
private:
  orario inizio, fine;
  unsigned short int* numero; //banana
};

std::ostream& operator<<(std::ostream&, const telefonata&);

#endif // TELEFONATA_H
