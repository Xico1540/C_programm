/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * @file   main.c
 * @author Xico
 *
 * @date Created on 22 de dezembro de 2022, 22:00
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoes.h"
#include "structs.h"
#include "ficheiros.h"
#include "produtos.h"
#include "encomendas.h"
#include "gestaoproducao.h"
/**
 * 
 * @brief define que o LOGS e um nome de um ficheiro.
 */
#define LOGS "logs.txt"
/**
 * 
 * @brief define que CAPACIDADE e o numero 20.
 */
#define CAPACIDADE 20 

/**
 * @hidden
 * 
 */

int main() {




    Cliente cliente;
    Clientes loja;
    Componente componente;
    Componentes armazem;
    Produto produto;
    Produtos prodvenda;
    Encomenda encomenda;
    Encomendas encomendas;

    //Locação de memoria para as varias listas ;
    loja.tamtotal = 10;
    loja.inseridosc = 0;
    loja.listacliente = (Cliente *) malloc(sizeof (Cliente) * loja.tamtotal);

    armazem.tamcomp = 10;
    armazem.contador = 0;
    armazem.listacomponente = (Componente *) malloc(sizeof (Componente) * armazem.tamcomp);

    prodvenda.tamprod = 10;
    prodvenda.contadorp = 0;
    prodvenda.listaProdutos = (Produto *) malloc(sizeof (Produto) * prodvenda.tamprod);

    encomendas.tame = 10;
    encomendas.contadore = 0;
    encomendas.listaEncomendas = (Encomenda *) malloc(sizeof (Encomenda) * encomendas.tame);

    encomenda.prode = (prod *) malloc(sizeof (prod) * 1);
    encomenda.tamanhoprode = 0;
    encomenda.contadorprode = 0;


    produto.tamanhocomp = 0;
    produto.contadorcomp = 0;
    produto.composicao = (Materiais *) malloc(sizeof (Materiais) * 1);

    //Leitura de Ficheiros
    lerClientes(&loja);
    lerMateriais(&armazem);
    lerEncomendas(&encomendas);
    lerFicheiroMoveis(&prodvenda);

    //Declaracao de Variaveis
    int idprocura, opu, nifnovo, j, dianovo, mesnovo, anonovo, novaquantidade, comp, id, n;
    float novopreco;
    char nomenovo[CAPACIDADE ], moradanova[CAPACIDADE ], paisnovo[CAPACIDADE ], descricaonova[CAPACIDADE ], unidadenova[3], c, codmat[CAPACIDADE ], novasdimensoes[CAPACIDADE ], passeadmin[CAPACIDADE] = "admin123", passefunc[CAPACIDADE] = "func123";
    char pa[CAPACIDADE], pf[CAPACIDADE];


    //menu

    do {
        int user = obterInt(VALOR_MIN_USERS, VALOR_MAX_USERS, LER_UTILIZADOR);
        switch (user) {
            case 1:
                printf("\nInsira a palavra passe de admin\n-");
                scanf("%s", pa);
                limpaBuffer();
                if ((strcmp(pa, passeadmin)) != 0) {
                    printf("\nPalavra passe errada\n");
                    return 0;
                }
                int gestao = obterInt(VALOR_MIN_ADMIN, VALOR_MAX_ADMIN, ADMIN_MENU); //gestão do admin
                switch (gestao) {
                    case 0:
                        break;
                    case 1://ABRE MENU DE GESTAO DE CLIENTES 
                        int gestaoclientes = obterInt(VALOR_MIN_GERIRCLIENTEMENU, VALOR_MAX_GERIRCLIENTEMENU, GESTAO_CLIENTE); //gerir clientes sendo admin 
                        switch (gestaoclientes) {
                            case 0:
                                break;


                            case 1://registo clientes , verificação de registo
                                registarCliente(&cliente);
                                int inseriu = inserirCliente(&loja, &cliente);
                                if (inseriu == 0) {
                                    printf("O Cliente inserido já existe, nao adicionado\n");
                                } else {
                                    printf("Cliente adicionado com sucesso\n");
                                }
                                c = obterCaratere(CARATERE);
                                limpaBuffer();
                                break;



                            case 2://edicao de clientes
                                imprimirTudo(&loja);
                                printf("Qual o id do cliente a atualizar?\n-\n");
                                scanf("%d", &idprocura);
                                limpaBuffer();
                                printf("O que deseja atualizar no cliente:\n1-nif\n2-nome\n3-pais\n4-morada\n-");
                                scanf("%d", &opu);
                                limpaBuffer();
                                switch (opu) {
                                    case 1:
                                        printf("\nDigite o novo nif\n");
                                        scanf("%d", &nifnovo);
                                        limpaBuffer();
                                        atualizarClienteNif(&loja, &idprocura, nifnovo);
                                        c = obterCaratere(CARATERE);
                                        break;
                                    case 2:
                                        printf("\nDigite o novo nome\n");
                                        scanf("%s", &nomenovo);
                                        limpaBuffer();
                                        atualizarClienteNome(&loja, &idprocura, nomenovo);
                                        c = obterCaratere(CARATERE);
                                        break;
                                    case 3:
                                        printf("\nDigite o novo pais\n");
                                        scanf("%s", &paisnovo);
                                        limpaBuffer();
                                        atualizarClientePais(&loja, &idprocura, paisnovo);
                                        c = obterCaratere(CARATERE);
                                        break;
                                    case 4:
                                        printf("\nDigite a nova morada\n");
                                        scanf("%s", &moradanova);
                                        limpaBuffer();
                                        atualizarClienteMorada(&loja, &idprocura, moradanova);
                                        c = obterCaratere(CARATERE);
                                        break;
                                }
                                break;


                            case 3://remove os clientes
                                imprimirTudo(&loja);
                                printf("\n");
                                printf("Qual o id do cliente que deseja eliminar?");
                                scanf("%d", &idprocura);
                                limpaBuffer();
                                removerCliente(&loja, &idprocura);
                                c = obterCaratere(CARATERE);


                                break;
                            case 4://lista todos os clientes adicionados
                                imprimirTudo(&loja);
                                c = obterCaratere(CARATERE);

                                break;
                            case 5 :
                                OrdenaClientes(&loja);
                                c = obterCaratere(CARATERE);
                                break;
                        }
                        break;



                    case 2://gerir produtos enquanto admin
                        int opcao = obterInt(VALOR_MIN_GERIRPRODUTO, VALOR_MAX_GERIRPRODUTO, GESTAO_PRODUTOS);
                        switch (opcao) {
                            case 0:
                                break;

                            case 1://registar materiais
                                registarComponente(&componente);
                                int inseriuc = inserirComponente(&armazem, &componente);
                                if (inseriuc == 0) {
                                    printf("Componente com mesmo Id encontrado, Componente não registado.\n");
                                } else {
                                    printf("Componente adicionado com sucesso\n");
                                }
                                c = obterCaratere(CARATERE);
                                limpaBuffer();
                                break;
                            case 2://editar materiais
                                imprimirTodosComponentes(&armazem);
                                printf("Qual o codigo do componente da lista acima que deseja atualizar?\n-\n");
                                scanf("%s", codmat);
                                limpaBuffer();
                                printf("O que deseja atualizar no componente:\n1-descricao\n2-unidade\n-");
                                scanf("%d", &opu);
                                limpaBuffer();
                                switch (opu) {
                                    case 1:
                                        printf("\nDigite a nova descricao\n");
                                        scanf("%s", descricaonova);
                                        limpaBuffer();
                                        atualizarComponenteDescricao(&armazem, codmat, descricaonova);
                                    case 2:
                                        printf("\nDigite se Unidade -UN se par -PAR\n");
                                        scanf("%s", unidadenova);
                                        limpaBuffer();
                                        atualizarComponenteUnidade(&armazem, codmat, unidadenova);
                                }


                                break;


                            case 3://remover materiais 
                                imprimirTodosComponentes(&armazem);
                                printf("Qual o codigo do componente da lista acima que deseja remover!?\n-\n");
                                scanf("%s", codmat);
                                limpaBuffer();
                                removerComponente(&armazem, codmat);
                                c = obterCaratere(CARATERE);
                                limpaBuffer();
                                break;

                            case 4://listar materiais
                                imprimirTodosComponentes(&armazem);
                                c = obterCaratere(CARATERE);
                                limpaBuffer();
                                break;

                            case 5://registar produtos
                                registarProduto(&produto, &armazem, &componente);
                                int inseriucp = inserirProduto(&prodvenda, &produto);
                                if (inseriucp == 0) {
                                    printf("Foi encontrado um produto com um codigo igual, produto não registado.\n");
                                } else {
                                    printf("Produto adicionado com sucesso\n");
                                }
                                c = obterCaratere(CARATERE);
                                limpaBuffer();
                                break;

                            case 6://editar produtos
                                imprimirTodosProdutos(&prodvenda);
                                printf("Qual o codigo do componente da lista acima que deseja atualizar!?\n-\n");
                                scanf("%s", codmat);
                                limpaBuffer();
                                printf("O que deseja atualizar no produto:\n1-Nome\n2-Dimensoes\n3-Preco\n4-Editar quantidade de componente\n5-Remover Componente \n-");
                                scanf("%d", &opu);
                                limpaBuffer();
                                switch (opu) {
                                    case 1:
                                        printf("\nDigite o novo nome\n");
                                        scanf("%s", nomenovo);
                                        limpaBuffer();
                                        atualizarProdutonome(&prodvenda, codmat, nomenovo);
                                        c = obterCaratere(CARATERE);
                                        limpaBuffer();
                                        break;
                                    case 2:
                                        printf("\nDigite as novas Dimensoes\n");
                                        scanf("%s", &novasdimensoes);
                                        limpaBuffer();
                                        atualizarProdutodimensoes(&prodvenda, codmat, novasdimensoes);
                                        c = obterCaratere(CARATERE);
                                        limpaBuffer();
                                        break;
                                    case 3:
                                        printf("\nDigite o novo preco\n");
                                        scanf("%f", &novopreco);
                                        limpaBuffer();
                                        atualizarProdutoPreco(&prodvenda, codmat, novopreco);
                                        c = obterCaratere(CARATERE);
                                        limpaBuffer();
                                        break;
                                    case 4:
                                        printf("\nQual o numero do componente que deseja editar\n-");
                                        scanf("%d", &comp);
                                        limpaBuffer();
                                        printf("\nDigite a nova quantidade\n");
                                        scanf("%d", &novaquantidade);
                                        limpaBuffer();
                                        editarComposicaoQuantidade(&prodvenda, codmat, comp, novaquantidade);
                                        c = obterCaratere(CARATERE);
                                        limpaBuffer();
                                        break;
                                    case 5:
                                        printf("\nQual o numero do produto que deseja remover\n-");
                                        scanf("%d", &comp);
                                        limpaBuffer();
                                        removerComposicao(&prodvenda, codmat, comp);
                                        c = obterCaratere(CARATERE);
                                        limpaBuffer();
                                        break;
                                }

                                break;
                            case 7://remover produtos
                                imprimirTodosProdutos(&prodvenda);
                                printf("Qual o codigo do Produto da lista acima que deseja remover!?\n-\n");
                                scanf("%s", codmat);
                                limpaBuffer();
                                removerProduto(&prodvenda, codmat);
                                c = obterCaratere(CARATERE);
                                limpaBuffer();

                                break;
                            case 8://listar produtos
                                imprimirTodosProdutos(&prodvenda);
                                c = obterCaratere(CARATERE);
                                break;
                            case 9://ordenaçao dos produtos
                                OrdenaProdutos(&prodvenda);
                                c = obterCaratere(CARATERE);
                                break;

                        }
                        break;

                    case 3://gestao de produçao 
                        gestaoProducao(&encomendas, &prodvenda, &armazem);
                        break;
                }
                break;
            case 2:
                int menucliente = obterInt(VALOR_MIN_CLIENTE, VALOR_MAX_CLIENTE, MENU_CLIENTE);
                switch (menucliente) {
                    case 1://Abre menu que gere clientes enquanto cliente
                        int gerircliente = obterInt(VALOR_MIN_GERIRCLIENTE, VALOR_MAX_GERIRCLIENTE, GERIR_CLIENTE);
                        switch (gerircliente) {
                            case 0:
                                break;

                            case 1://cliente registrase 
                                registarCliente(&cliente);
                                int inseriu = inserirCliente(&loja, &cliente);
                                if (inseriu == 0) {
                                    printf("Cliente com este id ja existe, volte a tentar registar se com outro id\n");
                                } else {
                                    printf("Registado com sucesso\n");
                                }
                                c = obterCaratere(CARATERE);
                                limpaBuffer();
                                break;


                            case 2://edita os seus proprios dados
                                printf("Qual o seu id  !?\n-\n");
                                scanf("%d", &idprocura);
                                limpaBuffer();
                                printf("O que deseja atualizar nos seus dados de cliente:\n1-nif\n2-nome\n3-pais\n4-morada\n-");
                                scanf("%d", &opu);
                                limpaBuffer();
                                switch (opu) {
                                    case 1:
                                        printf("\nDigite o novo nif\n");
                                        scanf("%d", &nifnovo);
                                        limpaBuffer();
                                        atualizarClienteNif(&loja, &idprocura, nifnovo);
                                        c = obterCaratere(CARATERE);
                                        break;
                                    case 2:
                                        printf("\nDigite o novo nome\n");
                                        scanf("%s", &nomenovo);
                                        limpaBuffer();
                                        atualizarClienteNome(&loja, &idprocura, nomenovo);
                                        c = obterCaratere(CARATERE);
                                        break;
                                    case 3:
                                        printf("\nDigite o novo pais\n");
                                        scanf("%s", &paisnovo);
                                        limpaBuffer();
                                        atualizarClientePais(&loja, &idprocura, paisnovo);
                                        c = obterCaratere(CARATERE);
                                        break;
                                    case 4:
                                        printf("\nDigite a nova morada\n");
                                        scanf("%s", &moradanova);
                                        limpaBuffer();
                                        atualizarClienteMorada(&loja, &idprocura, moradanova);
                                        c = obterCaratere(CARATERE);
                                        break;
                                }
                                break;

                            case 3://autoremove se 
                                printf("Qual o seu id ?\n");
                                scanf("%d", &idprocura);
                                limpaBuffer();
                                printf("Deseja mesmo auto remover-se da lista de clientes 1- se sim ,2-se nao  !?\n- ");
                                scanf("%d", &j);
                                limpaBuffer();
                                if (j == 1) {
                                    removerCliente(&loja, &idprocura);
                                } else {
                                    printf("Cliente nao removido ");
                                }
                                c = obterCaratere(CARATERE);
                                break;
                        }
                        break;


                    case 2://MENU DE REGISTAR ENCOMENDAS
                        int encomendad = obterInt(VALOR_MIN_ENCOMENDAS, VALOR_MAX_ENCOMENDAS, ENCOMENDAS);
                        switch (encomendad) {
                            case 0:
                                break;
                            case 1://registar encomenda
                                registarEncomenda(&encomenda, &prodvenda, &loja);
                                int inseriue = inserirEncomenda(&encomendas, &encomenda);
                                if (inseriue == 0) {
                                    printf("Encomenda com este id ja existe, tente registar com outro id\n");
                                } else {
                                    printf("Encomenda Registada com sucesso.\n");
                                }
                                c = obterCaratere(CARATERE);
                                limpaBuffer();
                                break;
                            case 2://editar encomenda
                                printf("Qual o numero de encomenda que deseja alterar  ?\n-\n");
                                scanf("%d", &idprocura);
                                limpaBuffer();
                                printf("O que deseja atualizar na data da sua encomenda:\n1-Dia\n2-Mes\n3-Ano\n4-Editar a quantidade de um produto\n5-Remover Produto\n-");
                                scanf("%d", &opu);
                                limpaBuffer();
                                switch (opu) {
                                    case 1:
                                        printf("\nDigite o novo dia\n");
                                        scanf("%d", &dianovo);
                                        limpaBuffer();
                                        atualizarEncomendaDia(&encomendas, &idprocura, dianovo);
                                        c = obterCaratere(CARATERE);
                                        break;
                                    case 2:
                                        printf("\nDigite o mes dia\n");
                                        scanf("%d", &mesnovo);
                                        limpaBuffer();
                                        atualizarEncomendaMes(&encomendas, &idprocura, mesnovo);
                                        c = obterCaratere(CARATERE);
                                        break;
                                    case 3:
                                        printf("\nDigite o novo ano\n");
                                        scanf("%d", &anonovo);
                                        limpaBuffer();
                                        atualizarEncomendaAno(&encomendas, &idprocura, anonovo);
                                        c = obterCaratere(CARATERE);
                                        break;
                                    case 4:
                                        printf("\nQual o numero do produto que deseja editar\n-");
                                        scanf("%d", &comp);
                                        limpaBuffer();
                                        printf("\nDigite a nova quantidade\n");
                                        scanf("%d", &novaquantidade);
                                        limpaBuffer();
                                        editarProdutoQuantidade(&encomendas, &idprocura, comp, novaquantidade);
                                        c = obterCaratere(CARATERE);
                                        limpaBuffer();
                                        break;
                                    case 5:
                                        printf("\nQual o numero do produto que deseja remover\n-");
                                        scanf("%d", &comp);
                                        limpaBuffer();
                                        removerProd(&encomendas, &idprocura, comp);
                                        c = obterCaratere(CARATERE);
                                        limpaBuffer();
                                        break;

                                }
                                break;
                            case 3://remover encomenda
                                printf("Qual o numero da sua encomenda que quer remover !?\n");
                                scanf("%d", &idprocura);
                                limpaBuffer();
                                printf("Deseja remover a sua encomenda \n 1- Sim ,2- Nao  !?\n ");
                                scanf("%d", &j);
                                limpaBuffer();
                                if (j == 1) {
                                    removerEncomenda(&encomendas, &idprocura);
                                } else {
                                    printf("Encomenda nao removida ");
                                }
                                c = obterCaratere(CARATERE);
                                break;


                            case 4://listar encomendas
                                imprimirTodasEncomendas(&encomendas);
                                c = obterCaratere(CARATERE);
                                break;
                        }

                        break;
                }
                break;

            case 3:
                printf("\nDigite a palavra passe de funcionario\n-");
                scanf("%s", pf);
                if ((strcmp(pf, passefunc)) != 0) {
                    printf("\nPalavra passe incorreta\n");
                    return 0;
                }
                int funcionarios = obterInt(VALOR_MIN_FUN, VALOR_MAX_FUN, FUNCIONARIO);
                printf("Qual o id do seu cartao de funcionario \n-");
                scanf("%d", &id);
                limpaBuffer();
                switch (funcionarios) {
                    case 0:
                        break;
                    case 1:
                        printf("Declarar: \n > 1-Entrada \n > 2-Saida!?");
                        scanf("%d", &n);
                        limpaBuffer();
                        if (n == 1) {
                            logs(&id, "entrada", LOGS);
                            printf("\n Entrada efetuada com sucesso, bom trabalho\n");
                        } else {
                            logs(&id, "saida", LOGS);
                            printf("\n Saida efetuada com sucesso, bom descanso\n");
                        }
                        c = obterCaratere(CARATERE);
                        break;
                    case 2:
                        imprimirTodosProdutos(&prodvenda);
                        logs(&id, "lista produtos ", LOGS);
                        c = obterCaratere(CARATERE);
                        break;
                    case 3:
                        imprimirTodosComponentes(&armazem);
                        logs(&id, "lista componentes ", LOGS);
                        c = obterCaratere(CARATERE);
                        break;
                    case 4:
                        imprimirTodasEncomendas(&encomendas);
                        logs(&id, "lista encomendas ", LOGS);
                        c = obterCaratere(CARATERE);
                        break;
                }
                break;
        }

    } while (c != 'n' && c != 'N');

    //guardar memoria em ficheiros
    registarClientes(&loja);
    registarMateriais(&armazem);
    registarEncomendas(&encomendas);
    escreverFicheiroMovel(&prodvenda);

    //libertação de memoria
    free(loja.listacliente);
    free(armazem.listacomponente);
    free(prodvenda.listaProdutos);
    free(encomendas.listaEncomendas);
    free(encomenda.prode);
    free(produto.composicao);

    return (EXIT_SUCCESS);
}

