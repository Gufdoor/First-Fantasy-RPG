//inclus�o de bibliotecas =====================================================================================================================================//
#include "magia.h" 




//defini��o dos m�todos de Arma =========================================================================================================================//

//m�todo construtor -------------------------------------------------------------------------------------------------------------------------------------------//
Magia::Magia() {}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//m�todo para setar stats da magia a ser usada ----------------------------------------------------------------------------------------------------------------//
void Magia::setarStatsMagia(int tipoMagia) {

    if (tipoMagia == 0) {
        this -> magia = "Po��o da Vida";
        this -> cura = 200;
        this -> gastoMana = 12;
    }

    else if (tipoMagia == 1) {
        this -> magia = "H�lito de Fogo";
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
        this -> magia = "Intoxica��o";
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



//m�todo para gastar mana -------------------------------------------------------------------------------------------------------------------------------------//
int Magia::gastarMana() {
    return gastoMana;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//m�todo para curar -------------------------------------------------------------------------------------------------------------------------------------------//
int Magia::curar(int codigoTipoCura) {
    setarStatsMagia(codigoTipoCura);
    return cura;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//m�todo para calcular dano -----------------------------------------------------------------------------------------------------------------------------------//
int Magia::calcularDano(int codigoTipoAtaque) {
    setarStatsMagia(codigoTipoAtaque);
    return dano;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//m�todo para retornar o gasto de mana de uma magia -----------------------------------------------------------------------------------------------------------//
int Magia::retornarGastoMana(int tipoMagia) {
    setarStatsMagia(tipoMagia);
    return gastoMana;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//m�todo destrutor --------------------------------------------------------------------------------------------------------------------------------------------//
Magia::~Magia() {}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//