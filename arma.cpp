//inclusão de bibliotecas =====================================================================================================================================//
#include "arma.h" 




//definição dos métodos de Arma =========================================================================================================================//

//método construtor -------------------------------------------------------------------------------------------------------------------------------------------//
Arma::Arma() {}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para criar armas -------------------------------------------------------------------------------------------------------------------------------------//
void Arma::criarArmas(int armaInicial, int armaFinal) {
    this -> armaInicial = armaInicial;
    this -> armaFinal = armaFinal;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para setar stats da arma em uso ----------------------------------------------------------------------------------------------------------------------//
void Arma::setarStatsArma(int tipoArma) {

    if (tipoArma == 0) {
        this -> arma = "Garra Letal";
        this -> danoMin = 100;
        this -> danoMax = 300;
    }

    else if (tipoArma == 1) {
        this -> arma = "Tridente Sagrado";
        this -> danoMin = 220;
        this -> danoMax = 420;
    }

    else if (tipoArma == 2) {
        this -> arma = "Espada Barroca";
        this -> danoMin = 300;
        this -> danoMax = 500;
    }

    else if (tipoArma == 3) {
        this -> arma = "Porrete";
        this -> danoMin = 180;
        this -> danoMax = 380;
    }

    else if (tipoArma == 4) {
        this -> arma = "Cajado";
        this -> danoMin = 50;
        this -> danoMax = 200;
    }

    else if (tipoArma == 5) {
        this -> arma = "Besta";
        this -> danoMin = 220;
        this -> danoMax = 420;
    }

    else if (tipoArma == 6) {
        this -> arma = "Esfera de Ataque";
        this -> danoMin = 200;
        this -> danoMax = 400;
    }

    else if (tipoArma == 7) {
        this -> arma = "Bul-Kathos";
        this -> danoMin = 500;
        this -> danoMax = 900;
    }
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para equipar arma ------------------------------------------------------------------------------------------------------------------------------------//
int Arma::equiparArma(int tipoArma) {  
    if (tipoArma == 7)  {
        setarStatsArma(7);
        return 7;
    }

    else if (tipoArma == 1) {
        setarStatsArma(armaFinal);
        return armaFinal;
    }

    else {
        setarStatsArma(armaInicial);
        return armaInicial;
    }
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para calcular dano da arma ---------------------------------------------------------------------------------------------------------------------------//
int Arma::calcularDano(int bulKhatos) {  //fazer calcula dano da bul khatos

    //declaração de variáveis
    srand(time(0));
    int danoCritico = 0;

    //processamento de dados
    if (bulKhatos == 7) {
        danoCritico = (rand() % 100) + 1;

        if (danoCritico <= 20)
            return (2 * (this -> danoMin + (rand() % (this -> danoMax - this -> danoMin + 1))));
        else
            return (this -> danoMin + (rand() % (this -> danoMax - this -> danoMin + 1)));
    }

    else
        return (this -> danoMin + (rand() % (this -> danoMax - this -> danoMin + 1)));
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método destrutor --------------------------------------------------------------------------------------------------------------------------------------------//
Arma::~Arma() {}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//