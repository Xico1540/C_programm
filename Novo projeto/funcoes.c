/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.c to edit this template
 */

/* 
 * File:   funcoes.c
 * Author: Xico
 * 
 * Created on 22 de dezembro de 2022, 22:00
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#include "structs.h"


/**
 * 
 * @inheritDoc
 */
void limpaBuffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

/**
 * 
 * @inheritDoc
 */
int obterInt(int minValor, int maxValor, char *msg) {
    int valor;
    printf(msg);
    while (scanf("%d", &valor) != 1 || valor < minValor || valor > maxValor) {
        puts(VALOR_INVALIDO);
        limpaBuffer();
        printf(msg);
    }
    limpaBuffer();
    return valor;
}

/**
 * 
 * @inheritDoc
 */
char obterCaratere(char *msg) {
    char c;
    printf(msg);
    while (scanf("%c", &c) != 'N' && c != 'n' && c != 's' && c != 'S') {
        puts(CARATERE_INVALIDO);
        limpaBuffer();
        printf(msg);
    }
    limpaBuffer();
    return c;
}

/**
 * 
 * @inheritDoc
 */
void procuraCliente(const Clientes *clientes, const int *num, int *pos) {
    (*pos) = -1;
    int i = 0;
    while ((*pos) == -1 && i < clientes->tamtotal) {
        if ((*num) == (*clientes).listacliente[i].id) {
            // Se encontrou o cliente pode retornar logo e para o While (e toda a função)
            (*pos) = i;
        }
        i++;
    }


}

/**
 * 
 * @inheritDoc
 */
int inserirCliente(Clientes *listacliente, Cliente *cliente) {

    //verificar se nao ah repetidos 
    int pos;
    procuraCliente(listacliente, &(*cliente).id, &pos);

    if (pos != -1) {
        return 0;
    }

    if (listacliente->inseridosc == listacliente->tamtotal) {
        listacliente->listacliente = (Cliente *) realloc(listacliente->listacliente, sizeof (Cliente)*(listacliente->inseridosc + 5));
        listacliente->tamtotal += 5;
    }

    //posso inserir 
    (*listacliente).listacliente[(*listacliente).inseridosc++] = (*cliente);
    return 1;
}

/**
 * 
 * @inheritDoc
 */
void registarCliente(Cliente *cliente) {
    printf("Digite o seu id:\n-");
    scanf("%d", &cliente->id);
    limpaBuffer();
    printf("Digite o seu nif:\n-");
    scanf("%d", &cliente->nif);
    limpaBuffer();
    printf("Digite o seu nome:\n-");
    scanf("%s", &cliente->nome);
    limpaBuffer();
    printf("Digite o seu morada:\n-");
    scanf("%s", &cliente->morada);
    limpaBuffer();
    printf("Digite o seu pais:\n-");
    scanf("%s", &cliente->pais);
    limpaBuffer();
    cliente->nencomendas = 0;
    strcpy(cliente->atividade, "Ativo");
}

/**
 * 
 * @inheritDoc
 */
int atualizarClienteNif(Clientes *clientes, int *idCliente, int nifnovo) {

    int pos;
    procuraCliente(clientes, idCliente, &pos);
    if (pos == -1) return 0;


    clientes->listacliente[pos].nif = nifnovo;


    return 1;
}

/**
 * 
 * @inheritDoc
 */
int atualizarClienteNome(Clientes *clientes, int *idCliente, char nomenovo[]) {
    int pos;
    procuraCliente(clientes, idCliente, &pos);
    if (pos == -1) return 0;
    strcpy(clientes->listacliente[pos].nome, nomenovo);
    return 1;
}

/**
 * 
 * @inheritDoc
 */
int atualizarClientePais(Clientes *clientes, int *idCliente, char paisnovo[]) {
    int pos;
    procuraCliente(clientes, idCliente, &pos);
    if (pos == -1) return 0;
    strcpy(clientes->listacliente[pos].pais, paisnovo);
    return 1;
}

/**
 * 
 * @inheritDoc
 */
int atualizarClienteMorada(Clientes *clientes, int *idCliente, char moradanova[]) {

    int pos;
    procuraCliente(clientes, idCliente, &pos);
    if (pos == -1) return 0;
    strcpy(clientes->listacliente[pos].morada, moradanova);
    return 1;
}

/**
 * 
 * @inheritDoc
 */
int removerCliente(Clientes *clientes, int *idCliente) {
    int i;
    int pos;
    procuraCliente(clientes, idCliente, &pos);
    if (pos == -1) return 0;


    if (clientes->listacliente[pos].nencomendas != 0) {
        strcpy(clientes->listacliente[pos].atividade, "Inativo");
        printf("\nEste cliente contem encomendas , logo o seu estado apenas passou para inativo\n");
    } else {
        for (i = pos; i < (clientes->inseridosc - 1); i++) {


            clientes->listacliente[i] = clientes->listacliente[i + 1];

        }

        clientes->listacliente[--(clientes->inseridosc)].id = -1;
    }

    return 1;
}

/**
 * 
 * @inheritDoc
 */
void trocaClientes(Cliente *cliente1, Cliente *cliente2) {
    Cliente temp = *cliente1;
    *cliente1 = *cliente2;
    *cliente2 = temp;
}

/**
 * 
 * @inheritDoc
 */
void OrdenaClientes(Clientes *clientes) {
    int i, j;
    for (i = 0; i < clientes->inseridosc - 1; i++) {
        for (j = 0; j < clientes->inseridosc - i - 1; j++) {
            if (clientes->listacliente[j].nencomendas < clientes->listacliente[j + 1].nencomendas) {
                trocaClientes(&clientes->listacliente[j], &clientes->listacliente[j + 1]);
            }
        }
    }
    
    imprimirTudo(clientes);
}