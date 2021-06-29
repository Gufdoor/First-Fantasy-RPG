//inclus�o de bibliotecas =====================================================================================================================================//
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <ctime>
#include <ctype.h>
#include <locale.h>
#include "personagem.h" 
#include "arma.h" 
#include "magia.h" 

using namespace std;




//programa principal ==========================================================================================================================================//

int main () {

    setlocale(LC_ALL,"");   //habilita a acentua��o para o portugu�s



    //declara��o de vari�veis ---------------------------------------------------------------------------------------------------------------------------------//
    int opcaoMenu1, opcaoMenuBatalha;
    int escolherClasse, quantidadeEscolhaClasse;                            //vari�veis para o campo de sele��o de personagens
    int codigoTipoAtaque, tipoMagia, codigoTipoCura;                        //vari�veis a serem usadas correla��o a classe Personagem
    int quantidadeTurnos;                                                   //vari�vel para controle dos turnos
    int acao, danoAtaque, danoRecebido, bulKhatos1, bulKhatos2, verifica;   //vari�vel para intermediar a��o escolhida pelo jogador



    //processamento de dados - MENU ---------------------------------------------------------------------------------------------------------------------------//
    do {
        system("cls");          //limpar dados no console
        cout << "\nV1.0 ----------------------| First Fantasy RPG |----------------------- Gufdoor\n\n";
        cout << "1.Jogar\n2.Sobre\n3.Regras\n4.Sair\n\nInsira uma das op��es acima: ";
        cin >> opcaoMenu1;
        cout << "\n";

            //valida��o da entrada
            while (opcaoMenu1 != 1 && opcaoMenu1 != 2 && opcaoMenu1 != 3 && opcaoMenu1 != 4) {
                system("cls");
                cout << "\nV1.0 ----------------------| First Fantasy RPG |----------------------- Gufdoor\n\n";
                cout << "1.Jogar\n2.Sobre\n3.Regras\n4.Sair\n\nInsira uma das op��es acima: ";
                cin >> opcaoMenu1;
                cout << "\n";
            }



        if (opcaoMenu1 == 1) {
            Personagem *player1 = new Personagem();
            Personagem *player2 = new Personagem();
            quantidadeEscolhaClasse = 0;
            quantidadeTurnos = 1;

            while (quantidadeEscolhaClasse < 2) {
                system("cls");
                printf("Player %d - Sele��o de classe\n\n", quantidadeEscolhaClasse + 1);
                cout << "Humanos\n   0.Guerreiro\n   1.Ladr�o\n   2.Mago\n   3.Paladino\n\n";
                cout << "Inumanos\n   4.Animal\n   5.Troll\n   6.Drag�o\n   7.Zumbi\n\n";
                cout << "Insira o n�mero de uma das classes acima: ";
                cin >> escolherClasse;

                    //valida��o da entrada
                    while (escolherClasse != 0 && escolherClasse != 1 && escolherClasse != 2 && escolherClasse != 3 && escolherClasse != 4 && escolherClasse != 5 && escolherClasse != 6 && escolherClasse != 7) {
                        system("cls");
                        printf("Player %d - Sele��o de classe\n\n", quantidadeEscolhaClasse + 1);
                        cout << "Humanos\n   0.Guerreiro\n   1.Ladr�o\n   2.Mago\n   3.Paladino\n\n";
                        cout << "Inumanos\n   4.Animal\n   5.Troll\n   6.Drag�o\n   7.Zumbi\n\n";
                        cout << "Insira o n�mero de uma das classes acima: ";
                        cin >> escolherClasse;
                    }

                if (escolherClasse == 0) {
                    system("cls");

                    if (quantidadeEscolhaClasse == 0)
                        player1 -> criarPersonagem("Guerreiro", 0, 4000, 30, 100, 20, 80, 20, 16, 0, 1);
                    else
                        player2 -> criarPersonagem("Guerreiro", 0, 4000, 30, 100, 20, 80, 20, 16, 0, 1);

                    cout << "Voc� escolheu o seguinte personagem:\n";

                    if (quantidadeEscolhaClasse == 0)
                        player1 -> printarAtributos();
                    else
                        player2 -> printarAtributos();;

                    cout << "\n\n";
                    system("pause");
                }

                else if (escolherClasse == 1) {
                    system("cls");

                    if (quantidadeEscolhaClasse == 0)
                        player1 -> criarPersonagem("Ladr�o", 1, 2800, 50, 50, 30, 40, 50, 30, 3, 5);
                    else
                        player2 -> criarPersonagem("Ladr�o", 1, 2800, 50, 50, 30, 40, 50, 30, 3, 5);

                    cout << "Voc� escolheu o seguinte personagem:\n";

                    if (quantidadeEscolhaClasse == 0)
                        player1 -> printarAtributos();
                    else
                        player2 -> printarAtributos();

                    cout << "\n\n";
                    system("pause");
                }

                else if (escolherClasse == 2) {
                    system("cls");

                    if (quantidadeEscolhaClasse == 0)
                        player1 -> criarPersonagem("Mago", 2, 2500, 100, 40, 100, 30, 80, 25, 4, 6);
                    else
                        player2 -> criarPersonagem("Mago", 2, 2500, 100, 40, 100, 30, 80, 25, 4, 6);

                    cout << "Voc� escolheu o seguinte personagem:\n";

                    if (quantidadeEscolhaClasse == 0)
                        player1 -> printarAtributos();
                    else
                        player2 -> printarAtributos();

                    cout << "\n\n";
                    system("pause");
                }

                else if (escolherClasse == 3) {
                    system("cls");

                    if (quantidadeEscolhaClasse == 0)
                        player1 -> criarPersonagem("Paladino", 3, 3200, 80, 60, 50, 60, 60, 18, 5, 2);
                    else
                        player2 -> criarPersonagem("Paladino", 3, 3200, 80, 60, 50, 60, 60, 18, 5, 2);

                    cout << "Voc� escolheu o seguinte personagem:\n";

                    if (quantidadeEscolhaClasse == 0)
                        player1 -> printarAtributos();
                    else
                        player2 -> printarAtributos();

                    cout << "\n\n";
                    system("pause");
                }
                
                else if (escolherClasse == 4) {
                    system("cls");

                    if (quantidadeEscolhaClasse == 0)
                        player1 -> criarPersonagem("Animal", 4, 3200, 30, 80, 20, 80, 20, 25, 0, 3);
                    else
                        player2 -> criarPersonagem("Animal", 4, 3200, 30, 80, 20, 80, 20, 25, 0, 3);

                    cout << "Voc� escolheu o seguinte personagem:\n";

                    if (quantidadeEscolhaClasse == 0)
                        player1 -> printarAtributos();
                    else
                        player2 -> printarAtributos();

                    cout << "\n\n";
                    system("pause");
                }

                else if (escolherClasse == 5) {
                    system("cls");

                    if (quantidadeEscolhaClasse == 0)
                        player1 -> criarPersonagem("Troll", 5, 2800, 20, 100, 20, 80, 20, 20, 4, 3);
                    else
                        player2 -> criarPersonagem("Troll", 5, 2800, 20, 100, 20, 80, 20, 20, 4, 3);

                    cout << "Voc� escolheu o seguinte personagem:\n";

                    if (quantidadeEscolhaClasse == 0)
                        player1 -> printarAtributos();
                    else
                        player2 -> printarAtributos();

                    cout << "\n\n";
                    system("pause");
                }

                else if (escolherClasse == 6) {
                    system("cls");

                    if (quantidadeEscolhaClasse == 0)
                        player1 -> criarPersonagem("Drag�o", 6, 3000, 40, 100, 20, 50, 50, 30, 0, 6);
                    else
                        player2 -> criarPersonagem("Drag�o", 6, 3000, 40, 100, 20, 50, 50, 30, 0, 6);

                    cout << "Voc� escolheu o seguinte personagem:\n";

                    if (quantidadeEscolhaClasse == 0)
                        player1 -> printarAtributos();
                    else
                        player2 -> printarAtributos();

                    cout << "\n\n";
                    system("pause");
                }
                
                else {
                    system("cls");

                    if (quantidadeEscolhaClasse == 0)
                        player1 -> criarPersonagem("Zumbi", 7, 2500, 20, 40, 20, 40, 80, 18, 0, 3);
                    else
                        player2 -> criarPersonagem("Zumbi", 7, 2500, 20, 40, 20, 40, 80, 18, 0, 3);

                    cout << "Voc� escolheu o seguinte personagem:\n";

                    if (quantidadeEscolhaClasse == 0)
                        player1 -> printarAtributos();
                    else
                        player2 -> printarAtributos();

                    cout << "\n\n";
                    system("pause");
                }

                quantidadeEscolhaClasse++;

            } //fim do while


            system("cls");
            cout << "Personagens criados!\nPreparem-se para a batalha!\n\n\n";
            system("pause");



            //sitema de batalha -------------------------------------------------------------------------------------------------------------------------------//
            do {
                bulKhatos1 = player1 -> trocarArma();
                bulKhatos2 = player2 -> trocarArma();

                player1 -> recarregarMana();
                player2 -> recarregarMana();

                if (bulKhatos1 || bulKhatos2) {
                    system("cls");
                    cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                    cout << "\n\nTurno Lend�rio!\n\nJogadores ir�o utilizar a Bul Khatos nesse turno.\n\n";
                    system("pause");
                }

                do {
                    system("cls");
                    cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                    cout << "\n\nVez do player 1!\n\n\n";
                    player1 -> printarAtributos();

                    if (player1->retornarVida() <= player1->retornarVidaMax() * 0.3) 
                        cout << "\n\nVida abaixo dos 30%%! Arma foi trocada.\n\n";

                    cout << "\n\n\nEscolha uma a��o:\n\n";
                    cout << "1.Atacar\n2.Curar\n3.Sair da batalha\n\n";
                    cout << "-> ";
                    cin >> acao;

                        //validar entrada
                        while (acao != 1 && acao != 2 && acao != 3) {
                            system("cls");
                            cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                            cout << "\n\nVez do player 1!\n\n\n";
                            player1 -> printarAtributos();
                            cout << "\n\n\nEscolha uma a��o:\n\n";
                            cout << "1.Atacar\n2.Curar\n3.Sair da batalha\n\n";
                            cout << "-> ";
                            cin >> acao;
                        }



                    if (acao == 1) {
                        system("cls");
                        cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                        cout << "\n\nVez do player 1!\n\n\n";
                        cout << "Escolha um tipo de ataque:\n\n1.Ataque f�sico\n2.Ataque m�gico\n\n";
                        cout << "-> ";
                        cin >> codigoTipoAtaque;

                            //validar entrada
                            while (codigoTipoAtaque != 1 && codigoTipoAtaque != 2) {
                                system("cls");
                                cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                cout << "\n\nVez do player 1!\n\n\n";
                                cout << "Escolha um tipo de ataque:\n\n1.Ataque f�sico\n2.Ataque m�gico\n\n";
                                cout << "-> ";
                                cin >> codigoTipoAtaque;
                            }

                        if (codigoTipoAtaque == 1) {
                            codigoTipoAtaque = 0;

                            danoAtaque = player1 -> atacar(codigoTipoAtaque, 0);
                            danoRecebido = player2 -> receberDano(danoAtaque, codigoTipoAtaque);

                            system("cls");
                            cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                            cout << "\n\n\nPlayer 1 atacou!";
                            cout << "\n\nDano do ataque: " << danoAtaque;

                            if (danoRecebido == 0)
                                cout << "\n\nPlayer 2 esquivou!";
                            else    
                                cout << "\nDano recebido pelo player 2: " << danoRecebido;

                            cout << "\nVida atual do player 2: " << player2->retornarVida() << "/" << player2->retornarVidaMax() << "\n\n\n";
                            acao = 5;
                            system("pause");
                        }

                        else {
                            codigoTipoAtaque = 1;

                            if (player1->retornarClasse() == "Guerreiro") {
                                system("cls");
                                cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                cout << "\n\nVez do player 1!\n\n\n";
                                cout << "Escolha um tipo de ataque m�gico:\n\n6.Tempestade\n\n";
                                cout << "-> ";
                                cin >> tipoMagia;

                                    //validar entrada
                                    while (tipoMagia != 6) {
                                        system("cls");
                                        cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                        cout << "\n\nVez do player 1!\n\n\n";
                                        cout << "Escolha um tipo de ataque m�gico:\n\n6.Tempestade\n\n";
                                        cout << "-> ";
                                        cin >> tipoMagia;
                                    }

                                verifica = player1 -> verificarMana(tipoMagia);

                            } //fim if

                            else if (player1->retornarClasse() == "Ladr�o") {
                                system("cls");
                                cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                cout << "\n\nVez do player 1!\n\n\n";
                                cout << "Escolha um tipo de ataque m�gico:\n\n5.Intoxica��o\n6.Tempestade\n\n";
                                cout << "-> ";
                                cin >> tipoMagia;

                                    //validar entrada
                                    while (tipoMagia != 5 && tipoMagia != 6) {
                                        system("cls");
                                        cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                        cout << "\n\nVez do player 1!\n\n\n";
                                        cout << "Escolha um tipo de ataque m�gico:\n\n5.Intoxica��o\n6.Tempestade\n\n";
                                        cout << "-> ";
                                        cin >> tipoMagia;
                                    }

                                verifica = player1 -> verificarMana(tipoMagia);

                            } //fim else if

                            else if (player1->retornarClasse() == "Mago") {
                                system("cls");
                                cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                cout << "\n\nVez do player 1!\n\n\n";
                                cout << "Escolha um tipo de ataque m�gico:\n\n2.Bio\n4.Flama Gelada\n5.intoxica��o\n6.Tempestade\n\n";
                                cout << "-> ";
                                cin >> tipoMagia;

                                    //validar entrada
                                    while (tipoMagia != 2 && tipoMagia != 4 && tipoMagia != 5 && tipoMagia != 6) {
                                        system("cls");
                                        cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                        cout << "\n\nVez do player 1!\n\n\n";
                                        cout << "Escolha um tipo de ataque m�gico:\n\n2.Bio\n4.Flama Gelada\n5.intoxica��o\n6.Tempestade\n\n";
                                        cout << "-> ";
                                        cin >> tipoMagia;
                                    }

                                verifica = player1 -> verificarMana(tipoMagia);

                            } //fim else if

                            else if (player1->retornarClasse() == "Paladino") {
                                system("cls");
                                cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                cout << "\n\nVez do player 1!\n\n\n";
                                cout << "Escolha um tipo de ataque m�gico:\n\n4.Flama Gelada\n6.Tempestade\n\n";
                                cout << "-> ";
                                cin >> tipoMagia;

                                    //validar entrada
                                    while (tipoMagia != 4 && tipoMagia != 6) {
                                        system("cls");
                                        cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                        cout << "\n\nVez do player 1!\n\n\n";
                                        cout << "Escolha um tipo de ataque m�gico:\n\n4.Flama Gelada\n6.Tempestade\n\n";
                                        cout << "-> ";
                                        cin >> tipoMagia;
                                    }

                                verifica = player1 -> verificarMana(tipoMagia);

                            } //fim else if

                            else if (player1->retornarClasse() == "Animal") {
                                system("cls");
                                cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                cout << "\n\nVez do player 1!\n\n\n";
                                cout << "Escolha um tipo de ataque m�gico:\n\n2.Bio\n\n";
                                cout << "-> ";
                                cin >> tipoMagia;

                                    //validar entrada
                                    while (tipoMagia != 2) {
                                        system("cls");
                                        cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                        cout << "\n\nVez do player 1!\n\n\n";
                                        cout << "Escolha um tipo de ataque m�gico:\n\n2.Bio\n\n";
                                        cout << "-> ";
                                        cin >> tipoMagia;
                                    }

                                verifica = player1 -> verificarMana(tipoMagia);

                            } //fim else if

                            else if (player1->retornarClasse() == "Troll") {
                                system("cls");
                                cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                cout << "\n\nVez do player 1!\n\n\n";
                                cout << "Escolha um tipo de ataque m�gico:\n\n5.Intoxica��o\n\n";
                                cout << "-> ";
                                cin >> tipoMagia;

                                    //validar entrada
                                    while (tipoMagia != 5) {
                                        system("cls");
                                        cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                        cout << "\n\nVez do player 1!\n\n\n";
                                        cout << "Escolha um tipo de ataque m�gico:\n\n5.Intoxica��o\n\n";
                                        cout << "-> ";
                                        cin >> tipoMagia;
                                    }

                                verifica = player1 -> verificarMana(tipoMagia);

                            } //fim else if

                            else if (player1->retornarClasse() == "Drag�o") {
                                system("cls");
                                cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                cout << "\n\nVez do player 1!\n\n\n";
                                cout << "Escolha um tipo de ataque m�gico:\n\n1.H�lito de Fogo\n\n";
                                cout << "-> ";
                                cin >> tipoMagia;

                                    //validar entrada
                                    while (tipoMagia != 1) {
                                        system("cls");
                                        cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                        cout << "\n\nVez do player 1!\n\n\n";
                                        cout << "Escolha um tipo de ataque m�gico:\n\n1.H�lito de Fogo\n\n";
                                        cout << "-> ";
                                        cin >> tipoMagia;
                                    }

                                verifica = player1 -> verificarMana(tipoMagia);

                            } //fim else if

                            else if (player1->retornarClasse() == "Zumbi") {
                                system("cls");
                                cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                cout << "\n\nVez do player 1!\n\n\n";
                                cout << "Escolha um tipo de ataque m�gico:\n\n5.Intoxica��o\n\n";
                                cout << "-> ";
                                cin >> tipoMagia;

                                    //validar entrada
                                    while (tipoMagia != 5) {
                                        system("cls");
                                        cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                        cout << "\n\nVez do player 1!\n\n\n";
                                        cout << "Escolha um tipo de ataque m�gico:\n\n5.Intoxica��o\n\n";
                                        cout << "-> ";
                                        cin >> tipoMagia;
                                    }

                                verifica = player1 -> verificarMana(tipoMagia);

                            } //fim else if

                            if (verifica) {
                                danoAtaque = player1 -> atacar(codigoTipoAtaque, tipoMagia);
                                danoRecebido = player2 -> receberDano(danoAtaque, codigoTipoAtaque);

                                system("cls");
                                cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                cout << "\n\n\nPlayer 1 atacou!";
                                cout << "\n\nDano do ataque: " << danoAtaque;

                                if (danoRecebido == 0)
                                    cout << "\n\nPlayer 2 esquivou!";
                                else    
                                    cout << "\nDano recebido pelo player 2: " << danoRecebido;

                                cout << "\nVida atual do player 2: " << player2->retornarVida() << "/" << player2->retornarVidaMax() << "\n\n\n";
                                acao = 5;
                                system("pause");
                            }

                            else {
                                system("cls");
                                cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                cout << "\n\nPlayer 1 n�o possui mana suficiente.\n\n";
                                acao = 10;
                                system("pause");
                            }

                        } //fim else

                    } //fim if



                    else if (acao == 2) {
                        system("cls");
                        cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                        cout << "\n\nVez do player 1!\n\n\n";
                        cout << "Escolha um tipo de cura:\n\n1.Po��o da Vida\n\n";

                        if (player1 -> retornarClasse() == "Mago")
                            cout << "2.Cura\n\n";

                        cout << "-> ";
                        cin >> codigoTipoCura;

                            //validar entrada
                            while (codigoTipoCura != 1 && codigoTipoCura != 2) {
                                system("cls");
                                cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                cout << "\n\nVez do player 1!\n\n\n";
                                cout << "Escolha um tipo de cura:\n\n1.Po��o da Vida\n\n";

                                if (player1 -> retornarClasse() == "Mago")
                                    cout << "2.Cura\n\n";

                                cout << "-> ";
                                cin >> codigoTipoCura;
                            }
                        
                        verifica = player1 -> verificarMana(codigoTipoCura);

                        if (verifica) {

                            if (codigoTipoCura == 1) {
                                codigoTipoCura = 0;
                                player1 -> curar(codigoTipoCura);
                            }

                            else {
                                codigoTipoCura = 3;
                                player1 -> curar(codigoTipoCura);
                            }

                            system("cls");
                            cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                            cout << "\n\n\nPlayer 1 se curou!";
                            cout << "\n\nVida atual: " << player1->retornarVida() << "/" << player1->retornarVidaMax() << "\n\n\n";
                            acao = 5;
                            system("pause");
                        }

                        else {
                            system("cls");
                            cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                            cout << "\n\nPlayer 1 n�o possui mana suficiente.\n\n";
                            acao = 10;
                            system("pause");
                        }

                    } //fim else if 




                
                    else {
                        system("cls");
                        cout << "Voc� tem certeza que deseja sair da batalha?\n\n0.Sim\n1.N�o\n\n";
                        cout << "-> ";
                        cin >> acao;

                            //validar entrada
                            while (acao != 0 && acao != 1) {
                                system("cls");
                                cout << "Voc� tem certeza que deseja sair da batalha?\n\n0.Sim\n1.N�o\n\n";
                                cout << "-> ";
                                cin >> acao;
                            }
                    } //fim else

                } while (acao != 0 && acao != 5); //fim do-while




                if (acao != 0 && player2->retornarVida() > 0) {
                    do {
                    system("cls");
                    cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                    cout << "\n\nVez do player 2!\n\n\n";
                    player2 -> printarAtributos();
                    cout << "\n\n\nEscolha uma a��o:\n\n";
                    cout << "1.Atacar\n2.Curar\n3.Sair da batalha\n\n";
                    cout << "-> ";
                    cin >> acao;

                        //validar entrada
                        while (acao != 1 && acao != 2 && acao != 3) {
                            system("cls");
                            cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                            cout << "\n\nVez do player 2!\n\n\n";
                            player2 -> printarAtributos();

                            if (player2->retornarVida() <= player2->retornarVidaMax() * 0.3) 
                                cout << "\n\nVida abaixo dos 30%%! Arma foi trocada.\n\n";

                            cout << "\n\n\nEscolha uma a��o:\n\n";
                            cout << "1.Atacar\n2.Curar\n3.Sair da batalha\n\n";
                            cout << "-> ";
                            cin >> acao;
                        }



                    if (acao == 1) {
                        system("cls");
                        cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                        cout << "\n\nVez do player 2!\n\n\n";
                        cout << "Escolha um tipo de ataque:\n\n1.Ataque f�sico\n2.Ataque m�gico\n\n";
                        cout << "-> ";
                        cin >> codigoTipoAtaque;

                            //validar entrada
                            while (codigoTipoAtaque != 1 && codigoTipoAtaque != 2) {
                                system("cls");
                                cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                cout << "\n\nVez do player 2!\n\n\n";
                                cout << "Escolha um tipo de ataque:\n\n1.Ataque f�sico\n2.Ataque m�gico\n\n";
                                cout << "-> ";
                                cin >> codigoTipoAtaque;
                            }

                        if (codigoTipoAtaque == 1) {
                            codigoTipoAtaque = 0;

                            danoAtaque = player2 -> atacar(codigoTipoAtaque, 0);
                            danoRecebido = player1 -> receberDano(danoAtaque, codigoTipoAtaque);

                            system("cls");
                            cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                            cout << "\n\n\nPlayer 2 atacou!";
                            cout << "\n\nDano do ataque: " << danoAtaque;

                            if (danoRecebido == 0)
                                cout << "\n\nPlayer 1 esquivou!";
                            else    
                                cout << "\nDano recebido pelo player 1: " << danoRecebido;

                            cout << "\nVida atual do player 1: " << player1->retornarVida() << "/" << player1->retornarVidaMax() << "\n\n\n";
                            acao = 5;
                            system("pause");
                        }

                        else {
                            codigoTipoAtaque = 1;

                            if (player2->retornarClasse() == "Guerreiro") {
                                system("cls");
                                cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                cout << "\n\nVez do player 2!\n\n\n";
                                cout << "Escolha um tipo de ataque m�gico:\n\n6.Tempestade\n\n";
                                cout << "-> ";
                                cin >> tipoMagia;

                                    //validar entrada
                                    while (tipoMagia != 6) {
                                        system("cls");
                                        cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                        cout << "\n\nVez do player 2!\n\n\n";
                                        cout << "Escolha um tipo de ataque m�gico:\n\n6.Tempestade\n\n";
                                        cout << "-> ";
                                        cin >> tipoMagia;
                                    }

                                verifica = player2 -> verificarMana(tipoMagia);

                            } //fim if

                            else if (player2->retornarClasse() == "Ladr�o") {
                                system("cls");
                                cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                cout << "\n\nVez do player 2!\n\n\n";
                                cout << "Escolha um tipo de ataque m�gico:\n\n5.Intoxica��o\n6.Tempestade\n\n";
                                cout << "-> ";
                                cin >> tipoMagia;

                                    //validar entrada
                                    while (tipoMagia != 5 && tipoMagia != 6) {
                                        system("cls");
                                        cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                        cout << "\n\nVez do player 2!\n\n\n";
                                        cout << "Escolha um tipo de ataque m�gico:\n\n5.Intoxica��o\n6.Tempestade\n\n";
                                        cout << "-> ";
                                        cin >> tipoMagia;
                                    }

                                verifica = player2 -> verificarMana(tipoMagia);

                            } //fim else if

                            else if (player2->retornarClasse() == "Mago") {
                                system("cls");
                                cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                cout << "\n\nVez do player 2!\n\n\n";
                                cout << "Escolha um tipo de ataque m�gico:\n\n2.Bio\n4.Flama Gelada\n5.intoxica��o\n6.Tempestade\n\n";
                                cout << "-> ";
                                cin >> tipoMagia;

                                    //validar entrada
                                    while (tipoMagia != 2 && tipoMagia != 4 && tipoMagia != 5 && tipoMagia != 6) {
                                        system("cls");
                                        cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                        cout << "\n\nVez do player 2!\n\n\n";
                                        cout << "Escolha um tipo de ataque m�gico:\n\n2.Bio\n4.Flama Gelada\n5.intoxica��o\n6.Tempestade\n\n";
                                        cout << "-> ";
                                        cin >> tipoMagia;
                                    }

                                verifica = player2 -> verificarMana(tipoMagia);

                            } //fim else if

                            else if (player2->retornarClasse() == "Paladino") {
                                system("cls");
                                cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                cout << "\n\nVez do player 2\n\n\n";
                                cout << "Escolha um tipo de ataque m�gico:\n\n4.Flama Gelada\n6.Tempestade\n\n";
                                cout << "-> ";
                                cin >> tipoMagia;

                                    //validar entrada
                                    while (tipoMagia != 4 && tipoMagia != 6) {
                                        system("cls");
                                        cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                        cout << "\n\nVez do player 2!\n\n\n";
                                        cout << "Escolha um tipo de ataque m�gico:\n\n4.Flama Gelada\n6.Tempestade\n\n";
                                        cout << "-> ";
                                        cin >> tipoMagia;
                                    }

                                verifica = player2 -> verificarMana(tipoMagia);

                            } //fim else if

                            else if (player2->retornarClasse() == "Animal") {
                                system("cls");
                                cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                cout << "\n\nVez do player 2!\n\n\n";
                                cout << "Escolha um tipo de ataque m�gico:\n\n2.Bio\n\n";
                                cout << "-> ";
                                cin >> tipoMagia;

                                    //validar entrada
                                    while (tipoMagia != 2) {
                                        system("cls");
                                        cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                        cout << "\n\nVez do player 2!\n\n\n";
                                        cout << "Escolha um tipo de ataque m�gico:\n\n2.Bio\n\n";
                                        cout << "-> ";
                                        cin >> tipoMagia;
                                    }

                                verifica = player2 -> verificarMana(tipoMagia);

                            } //fim else if

                            else if (player2->retornarClasse() == "Troll") {
                                system("cls");
                                cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                cout << "\n\nVez do player 2!\n\n\n";
                                cout << "Escolha um tipo de ataque m�gico:\n\n5.Intoxica��o\n\n";
                                cout << "-> ";
                                cin >> tipoMagia;

                                    //validar entrada
                                    while (tipoMagia != 5) {
                                        system("cls");
                                        cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                        cout << "\n\nVez do player 2!\n\n\n";
                                        cout << "Escolha um tipo de ataque m�gico:\n\n5.Intoxica��o\n\n";
                                        cout << "-> ";
                                        cin >> tipoMagia;
                                    }

                                verifica = player2 -> verificarMana(tipoMagia);

                            } //fim else if

                            else if (player2->retornarClasse() == "Drag�o") {
                                system("cls");
                                cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                cout << "\n\nVez do player 2!\n\n\n";
                                cout << "Escolha um tipo de ataque m�gico:\n\n1.H�lito de Fogo\n\n";
                                cout << "-> ";
                                cin >> tipoMagia;

                                    //validar entrada
                                    while (tipoMagia != 1) {
                                        system("cls");
                                        cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                        cout << "\n\nVez do player 2!\n\n\n";
                                        cout << "Escolha um tipo de ataque m�gico:\n\n1.H�lito de Fogo\n\n";
                                        cout << "-> ";
                                        cin >> tipoMagia;
                                    }

                                verifica = player2 -> verificarMana(tipoMagia);

                            } //fim else if

                            else if (player2->retornarClasse() == "Zumbi") {
                                system("cls");
                                cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                cout << "\n\nVez do player 2!\n\n\n";
                                cout << "Escolha um tipo de ataque m�gico:\n\n5.Intoxica��o\n\n";
                                cout << "-> ";
                                cin >> tipoMagia;

                                    //validar entrada
                                    while (tipoMagia != 5) {
                                        system("cls");
                                        cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                        cout << "\n\nVez do player 2!\n\n\n";
                                        cout << "Escolha um tipo de ataque m�gico:\n\n5.Intoxica��o\n\n";
                                        cout << "-> ";
                                        cin >> tipoMagia;
                                    }

                                verifica = player2 -> verificarMana(tipoMagia);

                            } //fim else if

                            if (verifica) {
                                danoAtaque = player2 -> atacar(codigoTipoAtaque, tipoMagia);
                                danoRecebido = player1 -> receberDano(danoAtaque, codigoTipoAtaque);

                                system("cls");
                                cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                cout << "\n\n\nPlayer 2 atacou!";
                                cout << "\n\nDano do ataque: " << danoAtaque;

                                if (danoRecebido == 0)
                                    cout << "\n\nPlayer 1 esquivou!";
                                else    
                                    cout << "\nDano recebido pelo player 1: " << danoRecebido;

                                cout << "\nVida atual do player 1: " << player2->retornarVida() << "/" << player2->retornarVidaMax() << "\n\n\n";
                                acao = 5;
                                system("pause");
                            }

                            else {
                                system("cls");
                                cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                cout << "\n\nPlayer 2 n�o possui mana suficiente.\n\n";
                                acao = 10;
                                system("pause");
                            }

                        } //fim else

                    } //fim if



                    else if (acao == 2) {
                        system("cls");
                        cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                        cout << "\n\nVez do player 2!\n\n\n";
                        cout << "Escolha um tipo de cura:\n\n1.Po��o da Vida\n\n";

                        if (player2 -> retornarClasse() == "Mago")
                            cout << "2.Cura\n\n";

                        cout << "-> ";
                        cin >> codigoTipoCura;

                            //validar entrada
                            while (codigoTipoCura != 1 && codigoTipoCura != 2) {
                                system("cls");
                                cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                                cout << "\n\nVez do player 2!\n\n\n";
                                cout << "Escolha um tipo de cura:\n\n1.Po��o da Vida\n\n";

                                if (player2 -> retornarClasse() == "Mago")
                                    cout << "2.Cura\n\n";

                                cout << "-> ";
                                cin >> codigoTipoCura;
                            }
                        
                        verifica = player2 -> verificarMana(codigoTipoCura);

                        if (verifica) {

                            if (codigoTipoCura == 1) {
                                codigoTipoCura = 0;
                                player2 -> curar(codigoTipoCura);
                            }

                            else {
                                codigoTipoCura = 3;
                                player2 -> curar(codigoTipoCura);
                            }

                            system("cls");
                            cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                            cout << "\n\n\nPlayer 2 se curou!";
                            cout << "\n\nVida atual: " << player2->retornarVida() << "/" << player2->retornarVidaMax() << "\n\n\n";
                            acao = 5;
                            system("pause");
                        }

                        else {
                            system("cls");
                            cout << "|==================== Turno " << quantidadeTurnos << " ====================|";
                            cout << "\n\nPlayer 2 n�o possui mana suficiente.\n\n";
                            acao = 10;
                            system("pause");
                        }

                    } //fim else if 




                
                    else {
                        system("cls");
                        cout << "Voc� tem certeza que deseja sair da batalha?\n\n0.Sim\n1.N�o\n\n";
                        cout << "-> ";
                        cin >> acao;

                            //validar entrada
                            while (acao != 0 && acao != 1) {
                                system("cls");
                                cout << "Voc� tem certeza que deseja sair da batalha?\n\n0.Sim\n1.N�o\n\n";
                                cout << "-> ";
                                cin >> acao;
                            }
                    } //fim else

                } while (acao != 0 && acao != 5); //fim do-while
                }




                if (player1->retornarVida() == 0) {
                    system("cls");
                    cout << "Player 1 morreu!\n\nPlayer 2 � o vencedor!\n\n\n\nObrigado por jogar :)\n\n";
                    system("pause");
                }
                else if (player2->retornarVida() == 0) {
                    system("cls");
                    cout << "Player 2 morreu!\n\nPlayer 1 � o vencedor!\n\n\n\nObrigado por jogar :)\n\n";
                    system("pause");
                }

                quantidadeTurnos++;

            } while (player1->retornarVida() > 0 && player2->retornarVida() > 0 && acao != 0);



            player1 -> ~Personagem();
            player2 -> ~Personagem();

            delete player1;
            delete player2;

        } //fim do if



        else if (opcaoMenu1 == 2) {
            system("cls");

            cout << "\nV1.0 ----------------------| First Fantasy RPG |----------------------- Gufdoor\n\n";
            cout << "First Fantasy RPG � um jogo estrat�gico de batalha de turnos com tem�tica inspirada em jogos de RPG. \nNeste jogo voc� poder� utilizar classes ";  
            cout << "como Paladino e Mago, utilizando magias e armas lend�rias para travar batalhas �picas com um amigo.\n\n";
            cout << "O jogo foi desenvolvido como um trabalho na disciplina de Algoritimos e Estruturas de Dados na PUC Minas.\n\n\n";
            cout << "Criador, diretor, desenvolvedor, quase morto: Gufdoor\n\n\n";

            system("pause");
        } //fim do if



        else if (opcaoMenu1 == 3) {
            system("cls");

            cout << "\nV1.0 ----------------------| First Fantasy RPG |----------------------- Gufdoor\n\n";
            cout << "01.O jogo � um multiplayer para duas pessoas. Cada uma assumir� um personagem de sua escolha.\n";
            cout << "   Para obter mais informa��es sobre as classes, acesse os anexos presentes nos arquivos do jogo.\n\n";
            cout << "02.A base da gameplay � definida por turnos, em que em cada turno cada jogador ter� direito a um movimento.\n";
            cout << "   Tais movimentos podem ser atacar (dano f�sico ou m�gico) ou curar e o jogo termina quando a vida de um jogador zerar.\n";
            cout << "   No decorrer dos turno, h� uma chance dos jogadores entrarem em um turno lend�rio.\n";
            cout << "   Neste turno, ambos os jogadores receber�o uma arma lend�ria com dano elevado e chance de efetuar um dano cr�tico.\n\n";
            cout << "03.Cada classe possui duas armas pr�-definidas: uma arma inicial e uma arma final.\n";
            cout << "   A arma inicial possui um potencial de dano menor que a arma final.\n";
            cout << "   Entretanto a arma final s� poder� ser utilizada quando a vida do jogador for menor ou igual � 30%%\n";
            cout << "   Esta troca de armas ser� realizada de forma autom�tica.\n";
            cout << "   Para obter mais informa��es sobre as armas, acesse os anexos presentes nos arquivos do jogo.\n\n";
            cout << "04.Cada classe possui atributos referente a for�a f�sica, for�a m�gica, resist�ncia f�sica e resist�ncia m�gica.\n";
            cout << "   Os atributos de for�a ir�o aumentar o potencial de dado da arma ou magia usada.\n";
            cout << "   J� os atributos de resist�ncia ir�o diminuir o potencial de dado recebido por uma arma ou magia.\n\n";
            cout << "05.Toda classe possui pontos de agilidade fixos. Tais pontos trazem a possibilidade de desviar de um ataque.\n\n";
            cout << "06.Para cada magia utilizada, uma determinada quantidade de mana ser� gasta e, a cada turno, 10 pontos de mana ser�o regenerados.\n";
            cout << "   Para obter mais informa��es sobre as magias, acesse os anexos presentes nos arquivos do jogo.\n\n";
            cout << "07.Toda arma possui um dano m�ximo e um dano m�nimo. O dano resultante ser� calculado de forma aleat�ria pelo sistema.\n\n\n";
            cout << "Lembre-se: 'Um mago nunca chega atrasado, ele chega exatamente na hora em que ele bem entender.' -Gandalf\n\n";
            cout << "Divirta-se!\n\n\n";

            system("pause");

        } //fim do if
        
        else {}

    } while (opcaoMenu1 != 4);

    system("cls");
    system("pause");
}