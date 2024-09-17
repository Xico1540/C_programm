/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.c to edit this template
 */

/* 
 * File:   produtos.c
 * Author: Xico
 * 
 * Created on 5 de janeiro de 2023, 16:49
 */

#include "produtos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "funcoes.h" 


//CRUD DOS COMPONENTES
/**
 * 
 * @inheritDoc
 */
void procuraComponente(Componentes *componentes, char *cod, int*pos) {
    (*pos) = -1;
    int i = 0;
    while ((*pos) == -1 && i < componentes->tamcomp) {
        if (strcmp(cod, (*componentes).listacomponente[i].codMaterial) == 0) {
            (*pos) = i;
        }
        i++;
    }
}

/**
 * 
 * @inheritDoc
 */
int inserirComponente(Componentes *listacomponentes, Componente *componente) {

    //verificar se nao ah repetidos 
    int pos;
    procuraComponente(listacomponentes, (*componente).codMaterial, &pos);

    if (pos != -1) {
        return 0;
    }

    if (listacomponentes->contador == listacomponentes->tamcomp) {
        listacomponentes->listacomponente = (Componente *) realloc(listacomponentes->listacomponente, sizeof (Cliente)*(listacomponentes->contador + 1));
        listacomponentes->tamcomp ++;
    }

    //posso inserir 
    (*listacomponentes).listacomponente[(*listacomponentes).contador++] = (*componente);
    return 1;
}

/**
 * 
 * @inheritDoc
 */
void registarComponente(Componente *componente) {
    printf("Digite o codigo do seu componente:\n- ");
    scanf("%s", &componente->codMaterial);
    limpaBuffer();
    printf("Digite a descricao do seu componente:\n- ");
    scanf("%s", &componente->descricao);
    limpaBuffer();
    printf("Insira UN- se unidade , PAR - se par :\n- ");
    scanf("%s", &componente->unidade);
    limpaBuffer();
}

/**
 * 
 * @inheritDoc
 */
int atualizarComponenteDescricao(Componentes *componentes, char *codMat, char descricaonova[]) {
    int pos;
    procuraComponente(componentes, codMat, &pos);
    if (pos == -1) return 0;
    strcpy(componentes->listacomponente[pos].descricao, descricaonova);
    return 1;
}

/**
 * 
 * @inheritDoc
 */
int atualizarComponenteUnidade(Componentes *componentes, char *codMat, char unidadenova[]) {
    int pos;
    procuraComponente(componentes, codMat, &pos);
    if (pos == -1) return 0;
    strcpy(componentes->listacomponente[pos].unidade, unidadenova);
    return 1;
}

/**
 * 
 * @inheritDoc
 */
int removerComponente(Componentes *componentes, char* codMat) {

    int pos;
    procuraComponente(componentes, codMat, &pos);
    if (pos == -1) return 0;

    int i;
    for (i = pos; i < (componentes->contador - 1); i++) {


        componentes->listacomponente[i] = componentes->listacomponente[i + 1];

    }

    componentes->contador--;

    return 1;
}



//CRUD DOS MATEIAIS USADOS NUM PRODUTO
/**
 * 
 * @inheritDoc
 */
void procuraComposicao(Produto *produto ,char *cod, int *pos){
    (*pos) = -1;
    int i = 0;
    while ((*pos) == -1 && i < produto->contadorcomp) {
        if (strcmp(cod, (produto+i)->composicao->codigo) == 0) {
            (*pos) = i;
        }
        i++;
    }
}

/**
 * 
 * @inheritDoc
 */
int inserirComposicaoProduto(Produto * produto, Materiais * m) {

    //verificar se nao ah repetidos 
    int pos;
    procuraComposicao(produto, m->codigo, &pos);

    if (pos != -1) {
        return 0;
    }
    
    if(produto->contadorcomp == produto->tamanhocomp){
    produto->composicao = (Materiais*) realloc(produto->composicao, sizeof (Materiais)*(produto->contadorcomp + 5));
    produto->tamanhocomp +=5;
    }
    
    //posso inserir 
    produto->composicao[produto->contadorcomp++] = *m;
    
    return 1;
}

/**
 * 
 * @inheritDoc
 */
void editarComposicaoQuantidade(Produtos *produtos,char *codMat,int numprocura,int quantidadenova){
    int pos;
    procuraProduto(produtos, codMat, &pos);
    produtos->listaProdutos[pos].composicao[numprocura-1].quantidade = quantidadenova;
    
}

/**
 * 
 * @inheritDoc
 */
int removerComposicao(Produtos *produtos,char *codMat,int numprocura){
    int pos;
    procuraProduto(produtos, codMat, &pos);
    
    
    produtos->listaProdutos[pos].composicao[numprocura-1] = produtos->listaProdutos[pos].composicao[produtos->listaProdutos->contadorcomp-1];
    
    produtos->listaProdutos->contadorcomp--;
}



//CRUD DE PRODUTOS
/**
 * 
 * @inheritDoc
 */
void procuraProduto(Produtos *produtos, char *cod, int*pos) {
    (*pos) = -1;
    int i = 0;
    while ((*pos) == -1 && i < produtos->tamprod) {
        if (strcmp(cod, (*produtos).listaProdutos[i].codProduto) == 0) {
            (*pos) = i;
        }
        i++;
    }
}



/**
 * 
 * @inheritDoc
 */
int inserirProduto(Produtos *listaprodutos, Produto *produto) {

    //verificar se nao ah repetidos 
    int pos;
    procuraProduto(listaprodutos, (*produto).codProduto, &pos);

    if (pos != -1) {
        return 0;
    }

    if (listaprodutos->contadorp == listaprodutos->tamprod) {
        listaprodutos->listaProdutos = (Produto *) realloc(listaprodutos->listaProdutos, sizeof (Cliente)*(listaprodutos->contadorp + 5));
        listaprodutos->tamprod += 5;
    }

    //posso inserir 
    (*listaprodutos).listaProdutos[(*listaprodutos).contadorp++] = (*produto);
    return 1;
}

/**
 * 
 * @inheritDoc
 */
void registarProduto(Produto *produto, Componentes *componentes, Componente *componente) {
    int op;
    char c, d;
    printf("Digite o codigo do Produto:\n- ");
    scanf("%s", &produto->codProduto);
    limpaBuffer();
    printf("Digite o nome do seu Produto:\n- ");
    scanf("%s", &produto->nomeProduto);
    limpaBuffer();
    printf("Digite as dimensoes do produto :\n-");
    scanf("%s", &produto->dimensoes);
    printf("Digite o preco do produto :\n- ");
    scanf("%f", &produto->preco);
    limpaBuffer();

    printf("|Escolha os materiais para o seu produto|\n");
    imprimirTodosComponentes(componentes);
    printf("A lista a cima tem todos os componentes que necessita  ? \n 1-sim 2-nao \n-");
    scanf("%d", &op);
    limpaBuffer();
    if (op == 2) {
        do {
            registarComponente(componente);
            inserirComponente(componentes, componente);
            printf("Deseja criar mais algum componente em falta? \n s-sim n-nao \n-");
            scanf("%c", &c);
            limpaBuffer();
        } while (c != 'n' && c != 'N');
    } else {

    }

    
    do {
        Materiais temp;
        
        printf("Digite o cod do componente a inserir no seu produto:\n- ");
        scanf("%s", temp.codigo);
        limpaBuffer();
        printf("Digite a quantidade do componente que deseja inserir:\n- ");
        scanf("%d", &(temp.quantidade));
        limpaBuffer();

        inserirComposicaoProduto( produto, &temp);
        printf("Deseja adicionar mais algum material ao seu produto? \n s-sim n-nao \n-");
        scanf("%c", & d);
        limpaBuffer();
       

    } while (d != 'n' && d != 'N');

}


/**
 * 
 * @inheritDoc
 */
int atualizarProdutonome(Produtos *produtos, char *codMat, char nomenovo[]) {
    int pos;
    procuraProduto(produtos, codMat, &pos);
    if (pos == -1) return 0;
    strcpy(produtos->listaProdutos[pos].nomeProduto, nomenovo);
    return 1;
}

/**
 * 
 * @inheritDoc
 */
int atualizarProdutodimensoes(Produtos *produtos, char *codMat, char novasdimensoes[]) {
    int pos;
    procuraProduto(produtos, codMat, &pos);
    if (pos == -1) return 0;
    strcpy(produtos->listaProdutos[pos].dimensoes , novasdimensoes);
    return 1;
}


/**
 * 
 * @inheritDoc
 */
int atualizarProdutoPreco(Produtos *produtos, char *codMat, float preconovo) {
    int pos;
    procuraProduto(produtos, codMat, &pos);
    if (pos == -1) return 0;
    produtos->listaProdutos[pos].preco = preconovo;
    return 1;
}

/**
 * 
 * @inheritDoc
 */
int removerProduto(Produtos *produtos, char* codMat) {

    int pos;
    procuraProduto(produtos, codMat, &pos);
    if (pos == -1) return 0;

    int i;
    for (i = pos; i < (produtos->contadorp - 1); i++) {


        produtos->listaProdutos[i] = produtos->listaProdutos[i + 1];

    }

    produtos->contadorp--;

    return 1;
}

/**
 * 
 * @inheritDoc
 */
void trocaProdutos(Produto *produto1, Produto *produto2) {
    Produto temp = *produto1;
    *produto1 = *produto2;
    *produto2 = temp;
}

/**
 * 
 * @inheritDoc
 */
void OrdenaProdutos(Produtos *produtos) {
    int i, j;
    for (i = 0; i < produtos->contadorp - 1; i++) {
        for (j = 0; j < produtos->contadorp - i - 1; j++) {
            if (produtos->listaProdutos[j].preco < produtos->listaProdutos[j+1].preco) {
                trocaProdutos(&produtos->listaProdutos[j], &produtos->listaProdutos[j + 1]);
            }
        }
    }
    
    imprimirTodosProdutos(produtos);
}