#include "telefonata.h"

int main(){
    /*orario le_tre(15);
    orario le_quattro(16);
    orario mezz;
    std::cout <<"le " << le_tre << " vengono prima delle " << le_quattro
                << ", ma prima di tutte c'e' la " << mezz << std::endl;
    orario sbagliato(23,59,59);
    std::cout << "orario sbagliato(23,59,59) costruisce " << sbagliato << std::endl;
    std::cout << "costruttori come convertitori di tipo:\norario s = 8 costruisce ";
    orario s = 8; std::cout << s << "\n";
    std::cout << "overloading dell'operatore +:\n";
    orario nuovo = sbagliato + s;
    std::cout << sbagliato << " + " << s << " = " << nuovo << "\n";
    nuovo = 1 + nuovo;
    std::cout << "orario+1 = 1+orario = " << nuovo <<"\n";*/
    short int* n = new short int[14];
    for(int i=0; i<14; i++) n[i] = i;
    telefonata brutta(orario(10,50,0), orario(10,55,0), n);
    telefonata bella(brutta);
    if(bella==brutta)std::cout<<"evviv\n";
    short int* b = bella.Numero();
    b[13] = 0;
    std::cout<< brutta << '\n' << bella << "\n";
}
