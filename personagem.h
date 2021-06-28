//inclusão de bibliotecas =====================================================================================================================================//
#include <cstdlib>
#include <string.h>
#include <iostream> 
#include <ctime>
#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#include "arma.h" 
#include "magia.h" 

using namespace std;




//classe personagem ===========================================================================================================================================//

class Personagem {
    private:
        string personagem;
        int codigoClasse;
        int vida;
        int mana;
        float forcaFisica;
        float forcaMagica;
        float resistenciaFisica;
        float resistenciaMagica;
        int agilidade;
        int vidaMax;
        int manaMax;
        int armaEmUso;

        int chanceEsquiva();
        void gastoMana();

        Arma arma;
        Magia magia;

    public:
        Personagem(); 

        //ações do usuário
        void criarPersonagem(string personagem, int codigoClasse, int vida, int mana, int forcaFisica, int forcaMagica, int resistenciaFisica, 
            int resistenciaMagica, int agilidade, int armaInicial, int armaFinal);
        int atacar(int codigoTipoAtaque, int tipoMagia);
        int curar(int codigoTipoCura);

        //segundo plano das ações do usuário
        int trocarArma();
        int verificarMana(int tipoMagia);
        void printarAtributos();
        int receberDano(int dano, int codigoTipoAtaque);  
        void recarregarMana();

        //retorno de atributos
        string retornarClasse();
        int retornarVida();
        int retornarMana();
        int retornarForcaFisica();
        int retornarForcaMagica();
        int retornarResistenciaFisica();
        int retornarResistenciaMagica();
        int retornarAgilidade();
        int retornarVidaMax();
        int retornarManaMax();

        ~Personagem();
};

#endif