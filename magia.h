//inclusão de bibliotecas =====================================================================================================================================//
#include <cstdlib>
#include <string.h>
#include <iostream> 
#include <ctime>
#ifndef MAGIA_H
#define MAGIA_H

using namespace std;




//classe personagem ===========================================================================================================================================//

class Magia {
    private:
        string magia;
        int dano;
        int cura;
        int gastoMana;

        void setarStatsMagia(int tipoMagia);

    public:
        Magia();  

        int gastarMana();
        int curar(int codigoTipoCura);
        int calcularDano(int codigoTipoAtaque);
        int retornarGastoMana(int tipoMagia);

        ~Magia();
};

#endif