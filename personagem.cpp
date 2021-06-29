//inclus�o de bibliotecas =====================================================================================================================================//
#include "personagem.h" 



//defini��o dos m�todos de Personagem =========================================================================================================================//

//m�todo construtor -------------------------------------------------------------------------------------------------------------------------------------------//
Personagem::Personagem() {}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//m�todo criar personagem -------------------------------------------------------------------------------------------------------------------------------------//
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



//m�todo para gastar mana -------------------------------------------------------------------------------------------------------------------------------------//
void Personagem::gastoMana() { //verifica��o de se tem mana suficiente vai ser feita no main

    mana -= magia.gastarMana();
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//m�todo para atacar ------------------------------------------------------------------------------------------------------------------------------------------//
int Personagem::atacar(int codigoTipoAtaque, int tipoMagia) {

    //declara��o de vari�veis
    int dano = 0;

    //processamento de dados
    if (codigoTipoAtaque == 0) {        //ataque f�sico ou Bul Khatos

        if (armaEmUso == 7) 
            dano = ((forcaFisica / 100) + 1) * arma.calcularDano(7);

        else 
            dano = ((forcaFisica / 100) + 1) * arma.calcularDano(armaEmUso);
    }

    else if (codigoTipoAtaque == 1) {   //ataque m�gico
        dano = ((forcaMagica / 100) + 1) * magia.calcularDano(tipoMagia);
        gastoMana();
    }

    return dano;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//m�todo para curar -------------------------------------------------------------------------------------------------------------------------------------------//
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



//m�todo para trocar de arma ----------------------------------------------------------------------------------------------------------------------------------//
int Personagem::trocarArma() {

    //declara��o de vari�veis
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



//m�todo para calcular chance de esquiva ----------------------------------------------------------------------------------------------------------------------//
int Personagem::chanceEsquiva() {

    //declara��o de vari�veis
    srand(time(0));
    int agilidade;

    //processamento de dados
    agilidade = (rand() % 100) + 1;

    if (agilidade <= this -> agilidade)
        return 1;   //esquivou

    else
        return 0;   //n�o esquivou
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//m�todo para receber dano ------------------------------------------------------------------------------------------------------------------------------------//
int Personagem::receberDano(int dano, int codigoTipoAtaque) {

    //declara��o de vari�veis
    int danoRecebido;

    //processamento de dados
    if (chanceEsquiva())
        return 0;

    if (codigoTipoAtaque == 0 || codigoTipoAtaque == 2) {   //ataques f�sicos
        danoRecebido = dano - (dano * (this -> resistenciaFisica / 100));

        if (danoRecebido > this -> vida)
            this -> vida = 0;
        else 
            this -> vida -= danoRecebido;
    }

    else if (codigoTipoAtaque == 1) {    //ataques m�gicos
        danoRecebido = dano - (dano * (this -> resistenciaMagica / 100));

        if (danoRecebido > this -> vida)
            this -> vida = 0;
        else 
            this -> vida -= danoRecebido;
    }

    return danoRecebido;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//m�todo para recarregar mana ---------------------------------------------------------------------------------------------------------------------------------//
void Personagem::recarregarMana() {
    if (mana <= (manaMax - 10))
        mana += 10;

    else if (mana > (manaMax - 10) && mana <= manaMax)
        mana = manaMax;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//m�todo para verificar se tem mana suficiente ----------------------------------------------------------------------------------------------------------------//
int Personagem::verificarMana(int tipoMagia) {    
    if (magia.retornarGastoMana(tipoMagia) > mana)
        return 0;
    else 
        return 1;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//m�todo para retornar nome da classe -------------------------------------------------------------------------------------------------------------------------//
string Personagem::retornarClasse() {    

    return this -> personagem;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//m�todo para retornar vida -----------------------------------------------------------------------------------------------------------------------------------//
int Personagem::retornarVida() {    

    return this -> vida;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//m�todo para retornar mana -----------------------------------------------------------------------------------------------------------------------------------//
int Personagem::retornarMana() {    

    return this -> mana;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//m�todo para retornar for�a f�sica ---------------------------------------------------------------------------------------------------------------------------//
int Personagem::retornarForcaFisica() {    

    return this -> forcaFisica;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//m�todo para retornar for�a m�gica ---------------------------------------------------------------------------------------------------------------------------//
int Personagem::retornarForcaMagica() {    

    return this -> forcaMagica;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//m�todo para retornar resist�ncia f�sica ---------------------------------------------------------------------------------------------------------------------//
int Personagem::retornarResistenciaFisica() {    

    return this -> resistenciaFisica;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//m�todo para retornar resist�ncia m�gica ---------------------------------------------------------------------------------------------------------------------//
int Personagem::retornarResistenciaMagica() {    

    return this -> resistenciaMagica;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//m�todo para retornar agilidade ------------------------------------------------------------------------------------------------------------------------------//
int Personagem::retornarAgilidade() {    

    return this -> agilidade;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//m�todo para retornar vida m�xima ----------------------------------------------------------------------------------------------------------------------------//
int Personagem::retornarVidaMax() {    

    return this -> vidaMax;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//m�todo para retornar mana m�xima ----------------------------------------------------------------------------------------------------------------------------//
int Personagem::retornarManaMax() {    

    return this -> manaMax;
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//m�todo para mostrar atributos -------------------------------------------------------------------------------------------------------------------------------//
void Personagem::printarAtributos() {
    cout << "\nClasse: " << personagem << "\n";
    cout << "Vida: " << vida << "\n";
    cout << "Mana: " << mana << "\n";
    cout << "For�a f�sica: " << forcaFisica << "\n";
    cout << "For�a m�gica: " << forcaMagica << "\n";
    cout << "Resist�ncia f�sica: " << resistenciaFisica << "\n";
    cout << "Resist�ncia m�gica: " << resistenciaMagica << "\n";
    cout << "Agilidade: " << agilidade << "\n\n";
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//



//m�todo destrutor --------------------------------------------------------------------------------------------------------------------------------------------//
Personagem::~Personagem() {}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//