//inclusão de bibliotecas =====================================================================================================================================//
#include <cstdlib>
#include <string.h>
#include <iostream> 
#include <ctime>
#ifndef ARMA_H
#define ARMA_H

using namespace std;




//classe personagem ===========================================================================================================================================//

class Arma {
    private:
        string arma;
        int danoMin;
        int danoMax;
        int armaInicial;
        int armaFinal;

        void setarStatsArma(int tipoArma);

    public:
        Arma();  

        void criarArmas(int armaInicial, int armaFinal);
        int equiparArma(int tipoArma);
        int calcularDano(int bulKhatos);
        
        ~Arma();
};

#endif