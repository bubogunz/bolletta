#ifndef ORARIO_H
#define ORARIO_H

#include<iostream>

class orario{
private:
	int sec;
public:
	orario(int =0, int =0, int =0);
	int ore() const;
	int minuti() const;
	int secondi() const;
	bool operator==(const orario&) const;
};
orario operator+(orario, orario);
std::ostream& operator<<(std::ostream&, const orario&);

#endif
