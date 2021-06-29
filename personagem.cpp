//inclusão de bibliotecas =====================================================================================================================================//
#include "personagem.h" 



//definição dos métodos de Personagem =========================================================================================================================//

//método construtor -------------------------------------------------------------------------------------------------------------------------------------------//
Personagem::Personagem() {}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método criar personagem -------------------------------------------------------------------------------------------------------------------------------------//
void Personagem::criarPersonagem(string personagem, int codigoClasse, int vida, int mana, int forcaFisica, int forcaMagica, int resistenciaFisica, 
    int resistenciaMagica, int agilidade, int armaInicial, int armaFinal) {

    this -> personagem = personagem;
    this -> codigoClasse = codigoClasse; 
    this -> vida = vida; 
    this -> vidaMax = vida; 
    this -> mana = mana; 
    this -> manaMax = mana; 
    this -> forcaFisica = forcaFisica; 
    this -> forcaMagica = forcaMagica; 
    this -> resistenciaFisica = resistenciaFisica; 
    this -> resistenciaMagica = resistenciaMagica; 
    this -> agilidade = agilidade;  

    arma.criarArmas(armaInicial, armaFinal);
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para gastar mana -------------------------------------------------------------------------------------------------------------------------------------//
void Personagem::gastoMana() { //verificação de se tem mana suficiente vai ser feita no main

    mana -= magia.gastarMana();
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para atacar ------------------------------------------------------------------------------------------------------------------------------------------//
int Personagem::atacar(int codigoTipoAtaque, int tipoMagia) {

    //declaração de variáveis
    int dano = 0;

    //processamento de dados
    if (codigoTipoAtaque == 0) {        //ataque físico ou Bul Khatos

        if (armaEmUso == 7) 
            dano = ((forcaFisica / 100) + 1) * arma.calcularDano(7);

        else 
            dano = ((forcaFisica / 100) + 1) * arma.calcularDano(armaEmUso);
    }

    else if (codigoTipoAtaque == 1) {   //ataque mágico
        dano = ((forcaMagica / 100) + 1) * magia.calcularDano(tipoMagia);
        gastoMana();
    }

    return dano;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para curar -------------------------------------------------------------------------------------------------------------------------------------------//
int Personagem::curar(int codigoTipoCura) {

    if (codigoTipoCura == 0) {

        if (vida > (vidaMax - 200) && vida <= vidaMax || vida > vidaMax) {
            magia.curar(codigoTipoCura);
            vida = vidaMax;
        }

        else if (vida <= (vidaMax - 200)) 
            vida += magia.curar(codigoTipoCura);
    }

    else {

        if (vida > (vidaMax - 400) && vida <= vidaMax || vida > vidaMax) {
            magia.curar(codigoTipoCura);
            vida = vidaMax;
        }

        else if (vida <= (vidaMax - 400)) 
            vida += magia.curar(codigoTipoCura);
    }

    gastoMana();

    return vida;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para trocar de arma ----------------------------------------------------------------------------------------------------------------------------------//
int Personagem::trocarArma() {

    //declaração de variáveis
    srand(time(0));
    int bulKhatos;

    //processamento de dados
    bulKhatos = (rand() % 100) + 1;

    if (bulKhatos <= 20) { //20% de chance do player conseguir a Bul Khatos por turno
        this -> armaEmUso = arma.equiparArma(7);
        return 1;
    }

    else if (vida > (vidaMax * 0.3)) {
        this -> armaEmUso = arma.equiparArma(0);
        return 0;
    }

    else if (vida <= (vidaMax * 0.3)) {
        this -> armaEmUso = arma.equiparArma(1);
        return 0;
    }
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para calcular chance de esquiva ----------------------------------------------------------------------------------------------------------------------//
int Personagem::chanceEsquiva() {

    //declaração de variáveis
    srand(time(0));
    int agilidade;

    //processamento de dados
    agilidade = (rand() % 100) + 1;

    if (agilidade <= this -> agilidade)
        return 1;   //esquivou

    else
        return 0;   //não esquivou
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para receber dano ------------------------------------------------------------------------------------------------------------------------------------//
int Personagem::receberDano(int dano, int codigoTipoAtaque) {

    //declaração de variáveis
    int danoRecebido;

    //processamento de dados
    if (chanceEsquiva())
        return 0;

    if (codigoTipoAtaque == 0 || codigoTipoAtaque == 2) {   //ataques físicos
        danoRecebido = dano - (dano * (this -> resistenciaFisica / 100));

        if (danoRecebido > this -> vida)
            this -> vida = 0;
        else 
            this -> vida -= danoRecebido;
    }

    else if (codigoTipoAtaque == 1) {    //ataques mágicos
        danoRecebido = dano - (dano * (this -> resistenciaMagica / 100));

        if (danoRecebido > this -> vida)
            this -> vida = 0;
        else 
            this -> vida -= danoRecebido;
    }

    return danoRecebido;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para recarregar mana ---------------------------------------------------------------------------------------------------------------------------------//
void Personagem::recarregarMana() {
    if (mana <= (manaMax - 10))
        mana += 10;

    else if (mana > (manaMax - 10) && mana <= manaMax)
        mana = manaMax;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para verificar se tem mana suficiente ----------------------------------------------------------------------------------------------------------------//
int Personagem::verificarMana(int tipoMagia) {    
    if (magia.retornarGastoMana(tipoMagia) > mana)
        return 0;
    else 
        return 1;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para retornar nome da classe -------------------------------------------------------------------------------------------------------------------------//
string Personagem::retornarClasse() {    

    return this -> personagem;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para retornar vida -----------------------------------------------------------------------------------------------------------------------------------//
int Personagem::retornarVida() {    

    return this -> vida;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para retornar mana -----------------------------------------------------------------------------------------------------------------------------------//
int Personagem::retornarMana() {    

    return this -> mana;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para retornar força física ---------------------------------------------------------------------------------------------------------------------------//
int Personagem::retornarForcaFisica() {    

    return this -> forcaFisica;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para retornar força mágica ---------------------------------------------------------------------------------------------------------------------------//
int Personagem::retornarForcaMagica() {    

    return this -> forcaMagica;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para retornar resistência física ---------------------------------------------------------------------------------------------------------------------//
int Personagem::retornarResistenciaFisica() {    

    return this -> resistenciaFisica;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para retornar resistência mágica ---------------------------------------------------------------------------------------------------------------------//
int Personagem::retornarResistenciaMagica() {    

    return this -> resistenciaMagica;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para retornar agilidade ------------------------------------------------------------------------------------------------------------------------------//
int Personagem::retornarAgilidade() {    

    return this -> agilidade;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para retornar vida máxima ----------------------------------------------------------------------------------------------------------------------------//
int Personagem::retornarVidaMax() {    

    return this -> vidaMax;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para retornar mana máxima ----------------------------------------------------------------------------------------------------------------------------//
int Personagem::retornarManaMax() {    

    return this -> manaMax;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método para mostrar atributos -------------------------------------------------------------------------------------------------------------------------------//
void Personagem::printarAtributos() {
    cout << "\nClasse: " << personagem << "\n";
    cout << "Vida: " << vida << "\n";
    cout << "Mana: " << mana << "\n";
    cout << "Força física: " << forcaFisica << "\n";
    cout << "Força mágica: " << forcaMagica << "\n";
    cout << "Resistência física: " << resistenciaFisica << "\n";
    cout << "Resistência mágica: " << resistenciaMagica << "\n";
    cout << "Agilidade: " << agilidade << "\n\n";
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//método destrutor --------------------------------------------------------------------------------------------------------------------------------------------//
Personagem::~Personagem() {}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//