/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.c to edit this template
 */

/* 
 * File:   encomendas.c
 * Author: Xico
 * 
 * Created on 15 de janeiro de 2023, 00:42
 */

#include "encomendas.h"
#include "produtos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "funcoes.h"

//CRUD DA LISTA DE PRODUTOS DENTRO DAS ENCOMENDAS.
/**
 * 
 * @inheritDoc
 */
void procuraProd(Encomenda *encomenda ,char *cod, int *pos){
    (*pos) = -1;
    int i = 0;
    while ((*pos) == -1 && i < encomenda->contadorprode) {
        if (strcmp(cod, (encomenda+i)->prode->cod) == 0) {
            (*pos) = i;
        }
        i++;
    }
}

/**
 * 
 * @inheritDoc
 */
int inserirProdutoEncomenda(Encomenda * encomenda, prod * m) {

    //verificar se nao ah repetidos 
    int pos;
    procuraProd(encomenda, m->cod, &pos);

    if (pos != -1) {
        return 0;
    }
    if(encomenda->contadorprode == encomenda->tamanhoprode){
    encomenda->prode = (prod*) realloc(encomenda->prode, sizeof (prod)*(encomenda->contadorprode + 1));
    encomenda->tamanhoprode ++;
    
    }
    //posso inserir 
    encomenda->prode[encomenda->contadorprode++] = *m;
    
    return 1;
}

/**
 * 
 * @inheritDoc
 */
void editarProdutoQuantidade(Encomendas *encomendas,int *idprocura,int numprocura,int quantidadenova){
    int pos;
    procuraEncomenda(encomendas,idprocura,&pos);
    
    encomendas->listaEncomendas[pos].prode[numprocura-1].quantidadeprod = quantidadenova;
    
}

/**
 * 
 * @inheritDoc
 */
void removerProd(Encomendas *encomendas,int *idprocura,int numprocura){
    int pos;
    procuraEncomenda(encomendas,idprocura,&pos);
    
    
    encomendas->listaEncomendas[pos].prode[numprocura-1] = encomendas->listaEncomendas[pos].prode[encomendas->listaEncomendas->contadorprode-1];
    
    encomendas->listaEncomendas->contadorprode--;
}

//CRUD DE ENCOMENDAS.

/**
 * 
 * @inheritDoc
 */
void procuraEncomenda(const Encomendas *encomendas, const int *num, int *pos) {
    (*pos) = -1;
    int i = 0;
    while ((*pos) == -1 && i < encomendas->tame) {
        if ((*num) == (*encomendas).listaEncomendas[i].numencomenda) {

            (*pos) = i;
        }
        i++;
    }
}

/**
 * 
 * @inheritDoc
 */
int inserirEncomenda(Encomendas *listaencomendas, Encomenda *encomenda) {

    //verificar se nao ah repetidos 
    int pos;
    procuraEncomenda(listaencomendas, &(*encomenda).numencomenda, &pos);

    if (pos != -1) {
        return 0;
    }

    if (listaencomendas->contadore == listaencomendas->tame) {
        listaencomendas->listaEncomendas = (Encomenda *) realloc(listaencomendas->listaEncomendas, sizeof (Encomenda)*(listaencomendas->contadore + 5));
        listaencomendas->tame += 5;
    }

    //posso inserir 
    (*listaencomendas).listaEncomendas[(*listaencomendas).contadore++] = (*encomenda);
    return 1;
}
/**
 * 
 * @inheritDoc
 */
void registarEncomenda(Encomenda* encomenda, Produtos *produtos, Clientes *clientes) {
    char d;
    int pos;

    printf("Digite o seu id de cliente:\n- ");
    scanf("%d", &encomenda->id);
    limpaBuffer();
    procuraCliente(clientes, &encomenda->id, &pos);
    printf("Digite o numero da encomenda:\n- ");
    scanf("%d", &encomenda->numencomenda);
    limpaBuffer();
    printf("Digite o dia previsto de entrega :\n- ");
    scanf("%d", &encomenda->dataentrega.dia);
    limpaBuffer();
    printf("Digite o mes previsto de entrega :\n- ");
    scanf("%d", &encomenda->dataentrega.mes);
    limpaBuffer();
    printf("Digite o ano previsto de entrega :\n- ");
    scanf("%d", &encomenda->dataentrega.ano);
    limpaBuffer();

    imprimirTodosProdutos(produtos);

    do {
        prod temp;
        printf("Insira o codigo do seu produto  :\n- ");
        scanf("%s", temp.cod);
        limpaBuffer();
        printf("Insira a quantidade do seu produto  :\n- ");
        scanf("%d", &(temp.quantidadeprod));
        limpaBuffer();
         
        
        inserirProdutoEncomenda( encomenda,  &temp);
        printf("Deseja adicionar mais algum produto a sua encomenda s-sim n-nao \n-");
        scanf("%c", & d);
        limpaBuffer();
        
    } while (d != 'n' && d != 'N');
    clientes->listacliente[pos].nencomendas += 1;
}

/**
 * 
 * @inheritDoc
 */
int atualizarEncomendaDia(Encomendas *encomendas, int *numencomenda, int dianovo) {
    int pos;
    procuraEncomenda(encomendas, numencomenda, &pos);
    if (pos == -1) return 0;
    encomendas->listaEncomendas[pos].dataentrega.dia, dianovo;
    return 1;
}

/**
 * 
 * @inheritDoc
 */
int atualizarEncomendaMes(Encomendas *encomendas, int *numencomenda, int mesnovo) {
    int pos;
    procuraEncomenda(encomendas, numencomenda, &pos);
    if (pos == -1) return 0;
    encomendas->listaEncomendas[pos].dataentrega.mes, mesnovo;
    return 1;
}

/**
 * 
 * @inheritDoc
 */
int atualizarEncomendaAno(Encomendas *encomendas, int *numencomenda, int anonovo) {
    int pos;
    procuraEncomenda(encomendas, numencomenda, &pos);
    if (pos == -1) return 0;
    encomendas->listaEncomendas[pos].dataentrega.ano, anonovo;
    return 1;
}

/**
 * 
 * @inheritDoc
 */
int removerEncomenda(Encomendas *encomendas, int *numencomenda) {

    int pos;
    procuraEncomenda(encomendas, numencomenda, &pos);
    if (pos == -1) return 0;

    int i;
    for (i = pos; i < (encomendas->contadore - 1); i++) {


        encomendas->listaEncomendas[i] = encomendas->listaEncomendas[i + 1];

    }

    encomendas->contadore--;
    return 1;
}

