/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.c to edit this template
 */

/* 
 * File:   structs.c
 * Author: Xico
 * 
 * Created on 22 de dezembro de 2022, 22:01
 */

#include "structs.h"
#include <stdio.h>

/**
 * 
 * @inheritDoc
 */
void imprimirCliente(const Cliente * cliente) {
    printf("Cliente: \n\tId:%d\n\tNif:%d\n\tNome:%s\n\tMorada:%s\n\tPais:%s\n\tNumero de encomendas:%d\n\tAtividade:%s\n",
            cliente->id, cliente->nif, cliente->nome, cliente->morada, cliente->pais, cliente->nencomendas, cliente->atividade);
}

/**
 * 
 * @inheritDoc
 */
void imprimirTudo(const Clientes* clientes) {
    if (clientes->inseridosc == 0) {
        printf("Nao existem clientes registados\n");

    } else {
        printf("\n TODOS OS ClIENTES\n");
        for (int i = 0; i < clientes->inseridosc; i++) {
            imprimirCliente(&(clientes->listacliente[i]));
        }
    }
}

/**
 * 
 * @inheritDoc
 */
void imprimirComponente(const Componente* componente) {
    printf("Componente: \n\tCodigo:%s\n\tDescricao:%s\n\tUnidades:%s\n",
            componente->codMaterial, componente->descricao, componente->unidade);
}

/**
 * 
 * @inheritDoc
 */
void imprimirTodosComponentes(const Componentes * componentes) {
    if (componentes->contador == 0) {
        printf("Nao existem componentes registados\n");

    } else {
        printf("\n TODOS OS COMPONENTES\n");
        for (int i = 0; i < componentes->contador; i++) {
            imprimirComponente(&(componentes->listacomponente[i]));
        }
    }
}

/**
 * 
 * @inheritDoc
 */
void imprimirProduto(const Produto* produto) {
    int i;
    printf("Produto: \n\tCodigo:%s\n\tNome:%s\n\tDimensoes:%s\n\tPreco:%.1f€\n",
            produto->codProduto, produto->nomeProduto,produto->dimensoes, produto->preco);
    printf("Componentes Inseridos\n");
    for (i = 0; i < produto->contadorcomp; i++) {
        printf("\n\tNumero:%d\n\tCodido componente:%s\n\tQuantidade:%d\n",(i+1), produto->composicao[i].codigo, produto->composicao[i].quantidade);

    }
}

/**
 * 
 * @inheritDoc
 */
void imprimirTodosProdutos(const Produtos *produtos) {
    if (produtos->contadorp == 0) {
        printf("Nao existem produtos registados\n");

    } else {
        printf("\n TODOS OS PRODUTOS\n");
        for (int i = 0; i < produtos->contadorp; i++) {
            imprimirProduto(&(produtos->listaProdutos[i]));
        }
    }
}

/**
 * 
 * @inheritDoc
 */
void imprimirEncomenda(const Encomenda* encomenda) {
    int i;
    printf("Encomdenda: \n\tId do cliente:%d\n\tCod encomenda:%d\n\tData de entrega:%d/%d/%d\n",
            encomenda->id, encomenda->numencomenda, encomenda->dataentrega.dia, encomenda->dataentrega.mes, encomenda->dataentrega.ano);
    printf("Produtos Inseridos\n");
    for (i = 0; i < encomenda->contadorprode; i++) {
        printf("\n\tNumero:%d\n\tCodido Produto:%s\n\tQuantidade:%d\n", (i+1),encomenda->prode[i].cod, encomenda->prode[i].quantidadeprod);

    }
}

/**
 * 
 * @inheritDoc
 */
void imprimirTodasEncomendas(const Encomendas *encomendas) {
    if (encomendas->contadore == 0) {
        printf("Nao existem encomendas registadas\n");

    } else {
        printf("\n TODOS AS ENCOMENDAS\n");
        for (int i = 0; i < encomendas->contadore; i++) {
            imprimirEncomenda(&(encomendas->listaEncomendas[i]));
        }
    }
}