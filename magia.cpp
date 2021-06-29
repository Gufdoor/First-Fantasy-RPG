//inclusão de bibliotecas =====================================================================================================================================//
#include "magia.h" 




//definição dos métodos de Arma =========================================================================================================================//

//método construtor -------------------------------------------------------------------------------------------------------------------------------------------//
Magia::Magia() {}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para setar stats da magia a ser usada ----------------------------------------------------------------------------------------------------------------//
void Magia::setarStatsMagia(int tipoMagia) {

    if (tipoMagia == 0) {
        this -> magia = "Poção da Vida";
        this -> cura = 200;
        this -> gastoMana = 12;
    }

    else if (tipoMagia == 1) {
        this -> magia = "Hálito de Fogo";
        this -> dano = 400;
        this -> gastoMana = 12;
    }

    else if (tipoMagia == 2) {
        this -> magia = "Bio";
        this -> dano = 360;
        this -> gastoMana = 14;
    }

    else if (tipoMagia == 3) {
        this -> magia = "Cura";
        this -> cura = 400;
        this -> gastoMana = 16;
    }

    else if (tipoMagia == 4) {
        this -> magia = "Flama gelada";
        this -> dano = 320;
        this -> gastoMana = 14;
    }

    else if (tipoMagia == 5) {
        this -> magia = "Intoxicação";
        this -> dano = 280;
        this -> gastoMana = 12;
    }

    else if (tipoMagia == 6) {
        this -> magia = "Tempestade";
        this -> dano = 200;
        this -> gastoMana = 12;
    }
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para gastar mana -------------------------------------------------------------------------------------------------------------------------------------//
int Magia::gastarMana() {
    return gastoMana;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para curar -------------------------------------------------------------------------------------------------------------------------------------------//
int Magia::curar(int codigoTipoCura) {
    setarStatsMagia(codigoTipoCura);
    return cura;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para calcular dano -----------------------------------------------------------------------------------------------------------------------------------//
int Magia::calcularDano(int codigoTipoAtaque) {
    setarStatsMagia(codigoTipoAtaque);
    return dano;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para retornar o gasto de mana de uma magia -----------------------------------------------------------------------------------------------------------//
int Magia::retornarGastoMana(int tipoMagia) {
    setarStatsMagia(tipoMagia);
    return gastoMana;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método destrutor --------------------------------------------------------------------------------------------------------------------------------------------//
Magia::~Magia() {}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//