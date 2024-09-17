/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.c to edit this template
 */

/* 
 * File:   gestaoproducao.c
 * Author: Xico
 * 
 * Created on 15 de janeiro de 2023, 20:53
 */

#include "gestaoproducao.h"
#include "structs.h"
#include "funcoes.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 
 * @inheritDoc
 */
void gestaoProducao(Encomendas * encomendas, Produtos *produtos, Componentes *componentes) {

    int i, j, k, d, f;
    Data dataEscolhida ;
    printf("\nDigite o dia em que a semana começa\n");
    scanf("%d",&dataEscolhida.dia);
    limpaBuffer();
    printf("\nDigite o mes em que a semana começa\n");
    scanf("%d",&dataEscolhida.mes);
    limpaBuffer();
    printf("\nDigite o ano em que a semana começa\n");
    scanf("%d",&dataEscolhida.ano);
    limpaBuffer();
    struct tm novaData = {.tm_mday = dataEscolhida.dia, .tm_mon = dataEscolhida.mes, .tm_year = dataEscolhida.ano};
    novaData.tm_mday += 7;
    mktime(&novaData);
    for (i = 0; i < encomendas->contadore; i++) {
        if ((encomendas->listaEncomendas[i].dataentrega.dia >= dataEscolhida.dia && encomendas->listaEncomendas[i].dataentrega.dia <= novaData.tm_mday &&
                encomendas->listaEncomendas[i].dataentrega.mes >= dataEscolhida.mes && encomendas->listaEncomendas[i].dataentrega.mes <= novaData.tm_mon &&
                encomendas->listaEncomendas[i].dataentrega.ano >= dataEscolhida.ano && encomendas->listaEncomendas[i].dataentrega.ano <= novaData.tm_year)) {
            printf("\n N.encomenda :%d\n",(i+1));
            for (j = 0; j < encomendas->listaEncomendas[i].contadorprode; j++) {
                for (k = 0; k < produtos->contadorp; k++) {
                    if (strcmp(produtos->listaProdutos[i].codProduto, encomendas->listaEncomendas[i].prode[j].cod) == 0) {
                        for (d = 0; d < produtos->listaProdutos[k].contadorcomp; d++) {
                            for (f = 0; f < componentes->contador; f++) {
                                if (strcmp(componentes->listacomponente[f].codMaterial, produtos->listaProdutos[k].composicao[f].codigo) == 0) {
                                    printf("codigo: %s\n", componentes->listacomponente[f].codMaterial);
                                    printf("descricao : %s\n", componentes->listacomponente[f].descricao);
                                    printf("unidade:%s\n", componentes->listacomponente[f].unidade);
                                    printf("Quantidade :%d\n", encomendas->listaEncomendas[d].prode[d].quantidadeprod * produtos->listaProdutos[f].composicao[j].quantidade);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}