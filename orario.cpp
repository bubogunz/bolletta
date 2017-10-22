#include "orario.h"

orario::orario(int o, int m, int s){
    if(o>23) o %= 24;
    if(m>59) m %= 60;
    if(s>59) s %= 60;
    sec =  o*3600 + m*60 + s;
}

int orario::ore() const{
    return sec/3600;
}
int orario::minuti() const{
    return (sec%3600)/60;
}
int orario::secondi() const{
    return orario::minuti()%60;
}
orario operator+(orario o, orario p){
    return orario(p.ore()+o.ore(), p.minuti()+o.minuti(), p.secondi()+o.secondi());
}
bool orario::operator==(const orario& o) const{
  return sec == o.sec;
}
std::ostream& operator<<(std::ostream& os, const orario& r){
    if(!r.ore()) os << "00:";
    else os << r.ore() << ':';
    if(!r.minuti()) os << "00:";
    else os << r.minuti() << ':';
    if(!r.secondi()) os << "00";
    else os << r.secondi();
    return os;
}
