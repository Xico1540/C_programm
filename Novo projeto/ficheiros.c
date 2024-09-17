/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.c to edit this template
 */

/* 
 * File:   ficheiros.c
 * Author: Xico
 * 
 * Created on 22 de dezembro de 2022, 22:01
 */

#include "ficheiros.h"
#include "structs.h"
#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encomendas.h"
#include <time.h>

/**
 * 
 * @inheritDoc
 */
void lerClientes(Clientes *clientes) {
    FILE *fp;
    int i, j;
    fp = fopen("clientes.bin", "rb");
    if (fp == NULL) {
        printf("\nNao conseguiu abrir o ficheiro\n");
    } else {
        fread(&j, sizeof (int), 1, fp);
        for (i = 0; i < j; i++) {
            Cliente temp;
            fread(&(temp.id), sizeof (int), 1, fp);
            fread(&(temp.nif), sizeof (int), 1, fp);
            fread(temp.nome, sizeof (char)*MAX, 1, fp);
            fread(temp.morada, sizeof (char)*MAX, 1, fp);
            fread(temp.pais, sizeof (char)*MAX, 1, fp);
            fread(&(temp.nencomendas), sizeof (int), 1, fp);
            fread(temp.atividade, sizeof (char)*7, 1, fp);
            inserirCliente(clientes, &temp);
        }
    }
    fclose(fp);
}

/**
 * 
 * @inheritDoc
 */
void registarClientes(Clientes*clientes) {
    FILE * fp;
    int i;
    fp = fopen("clientes.bin", "wb");
    if (fp == NULL) {
        printf("\nNao conseguiu abrir o ficheiro\n");
    } else {
        fwrite(&clientes->inseridosc, sizeof (int), 1, fp);
        for (i = 0; i < clientes->inseridosc; i++) {
            fwrite(&clientes->listacliente[i].id, sizeof (int), 1, fp);
            fwrite(&clientes->listacliente[i].nif, sizeof (int), 1, fp);
            fwrite(clientes->listacliente[i].nome, sizeof (char)*MAX, 1, fp);
            fwrite(clientes->listacliente[i].morada, sizeof (char)*MAX, 1, fp);
            fwrite(clientes->listacliente[i].pais, sizeof (char)*MAX, 1, fp);
            fwrite(&clientes->listacliente[i].nencomendas, sizeof (int), 1, fp);
            fwrite(clientes->listacliente[i].atividade, sizeof (char)*7, 1, fp);
        }
    }
    fclose(fp);


}

/**
 * 
 * @inheritDoc
 */
void lerMateriais(Componentes *componentes) {
    FILE *fp;
    int i;
    if (fp == NULL) {
        printf("\nNao conseguiu abrir o ficheiro\n");
    } else {

        fp = fopen("materiais.bin", "rb");
        fread(&componentes->contador, sizeof (int), 1, fp);
        for (i = 0; i < componentes->contador; i++) {
            fread(componentes->listacomponente[i].codMaterial, sizeof (char)*20, 1, fp);
            fread(componentes->listacomponente[i].descricao, sizeof (char)*20, 1, fp);
            fread(componentes->listacomponente[i].unidade, sizeof (char)*20, 1, fp);
        }
        fclose(fp);
    }
}

/**
 * 
 * @inheritDoc
 */
void registarMateriais(Componentes *componentes) {
    FILE *fp;
    int i;
    if (fp == NULL) {
        printf("\nNao conseguiu abrir o ficheiro\n");
    } else {
        fp = fopen("materiais.bin", "wb");
        fwrite(&componentes->contador, sizeof (int), 1, fp);
        for (i = 0; i < componentes->contador; i++) {
            fwrite(componentes->listacomponente[i].codMaterial, sizeof (char)*20, 1, fp);
            fwrite(componentes->listacomponente[i].descricao, sizeof (char)*20, 1, fp);
            fwrite(componentes->listacomponente[i].unidade, sizeof (char)*20, 1, fp);
        }
        fclose(fp);
    }
}


/**
 * 
 * @inheritDoc
 */
void lerFicheiroMoveis(Produtos * produtos) {
    int i = 0;
    FILE * fMoveis;
    
    fMoveis = fopen("produtos.csv", "r");

    fscanf(fMoveis, "%*[^\n]\n");

    while (!feof(fMoveis)) {
     produtos->listaProdutos[i].composicao = (Materiais *) malloc(1 * sizeof (Materiais));


        fscanf(fMoveis, "%[^;];%[^;];%[^;];%.2f[^;];%[^;];%d[^\n]\n", produtos->listaProdutos[i].codProduto,
                produtos->listaProdutos[i].nomeProduto, produtos->listaProdutos[i].dimensoes,&produtos->listaProdutos[i].preco, 
                &produtos->listaProdutos[i].contadorcomp, produtos->listaProdutos[i].composicao[0].codigo, produtos->listaProdutos[i].composicao[0].quantidade);

        produtos->listaProdutos[i].composicao = (Materiais *) realloc(produtos->listaProdutos[i].composicao, (produtos->listaProdutos[i].contadorcomp +1) * sizeof (Materiais));

        
        for (int j = 1; j < produtos->listaProdutos[i].contadorcomp; j++) {
          

            fscanf(fMoveis, ";;;;%[^;];%d[^\n]\n", produtos->listaProdutos[i].composicao[j].codigo,
                   produtos->listaProdutos[i].composicao[j].quantidade);       
        }
         
        i++;
    }

    fclose(fMoveis);
}




/**
 * 
 * @inheritDoc
 */
void escreverFicheiroMovel(Produtos *produtos) {
   
    FILE *fMoveis;
    fMoveis = fopen("produtos.csv", "w");

    fprintf(fMoveis, "Cod_Produto;Produto;Dimensoes;Preco;Cont_Materiais;Cod_Material;Quantidade\n");
    for (int i = 0; i < produtos->contadorp; i++) {
        fprintf(fMoveis, "%s;%s;%s;%.2f;%d;%s;%d\n", produtos->listaProdutos[i].codProduto,
                produtos->listaProdutos[i].nomeProduto,produtos->listaProdutos[i].dimensoes, produtos->listaProdutos[i].preco, 
                produtos->listaProdutos[i].contadorcomp,produtos->listaProdutos[i].composicao[0].codigo,produtos->listaProdutos[i].composicao[0].quantidade);

        for (int j = 1; j < produtos->listaProdutos[i].contadorcomp; j++) {
            fprintf(fMoveis, ";;;;%s;%d\n",produtos->listaProdutos[i].composicao[j].codigo,produtos->listaProdutos[i].composicao[j].quantidade );
        }
    }
    fclose(fMoveis);
}


/**
 * 
 * @inheritDoc
 */
void registarEncomendas(Encomendas *encomendas) {
    FILE *fp;
    int i, j;
    fp = fopen("encomendas.bin", "wb");
    if (fp == NULL) {
        printf("\nNao conseguiu abrir o ficheiro\n");
    } else {
        fwrite(&encomendas->contadore, sizeof (int), 1, fp);
        for (i = 0; i < encomendas->contadore; i++) {
            fwrite(&encomendas->listaEncomendas[i].id, sizeof (int), 1, fp);
            fwrite(&encomendas->listaEncomendas[i].numencomenda, sizeof (int), 1, fp);
            fwrite(&encomendas->listaEncomendas[i].dataentrega.dia, sizeof (int), 1, fp);
            fwrite(&encomendas->listaEncomendas[i].dataentrega.mes, sizeof (int), 1, fp);
            fwrite(&encomendas->listaEncomendas[i].dataentrega.ano, sizeof (int), 1, fp);
            fwrite(&encomendas->listaEncomendas[i].contadorprode, sizeof (int), 1, fp);
        


        for (j = 0; j < encomendas->listaEncomendas[i].contadorprode; j++) {
            fwrite(encomendas->listaEncomendas[i].prode[j].cod, sizeof (char)*20, 1, fp);
            fwrite(&encomendas->listaEncomendas[i].prode[j].quantidadeprod, sizeof (int), 1, fp);
            
        }

        }
    }
    fclose(fp);
}
/**
 * 
 * @inheritDoc
 */
void lerEncomendas(Encomendas *encomendas) {
    FILE *fp;
  
    
    int i, k,j;
    fp = fopen("encomendas.bin", "rb");
    if (fp == NULL) {
        printf("\nNao conseguiu abrir o ficheiro\n");
    } else {
        fread(&k, sizeof (int), 1, fp);
        for (i = 0; i < k; i++) {
            Encomenda tempe;
            fread(&(tempe.id), sizeof (int), 1, fp);
            fread(&(tempe.numencomenda), sizeof (int), 1, fp);
            fread(&(tempe.dataentrega.dia), sizeof (int), 1, fp);
            fread(&(tempe.dataentrega.mes), sizeof (int), 1, fp);
            fread(&(tempe.dataentrega.ano), sizeof (int), 1, fp);
            fread(&(tempe.contadorprode), sizeof (int), 1, fp);
            for (j = 0; j < encomendas->listaEncomendas[i].contadorprode; j++) {
                prod temp;
                fread(temp.cod, sizeof (char)*20, 1, fp);
                fread(&(temp.quantidadeprod), sizeof (int), 1, fp);
                inserirProdutoEncomenda(&tempe, &temp);
            }

            inserirEncomenda(encomendas, &tempe);
        }

    }
    fclose(fp);
}



/**
 * 
 * @inheritDoc
 */
void logs(int *id,char *msg, char *nomeficheiro) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    FILE *fp = fopen(nomeficheiro, "a");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }
    
    fprintf(fp, "%d-%02d-%02d %02d:%02d:%02d - id do funcionario :"
            "%d ,%s\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec,*id, msg);

    fclose(fp);
}


//Tentativa de Import Files
/*void importarProdutosMateriais(Produtos *prodVenda, char *caminhoFicheiro) { ///////TESTAR

    FILE* ficheiro = fopen(caminhoFicheiro, "r");
    fscanf(ficheiro, "%*[^\n]\n");
    prodVenda->listaProdutos = (Produto *) malloc(1000);

    int indexProduto = 0, indexComposicao = 0;

    while (!feof(ficheiro)) {
        prodVenda->listaProdutos[indexProduto].composicao = (Materiais *) malloc(1 * sizeof (Materiais));

        fscanf(
                ficheiro,
                "%[^;];%[^;];%[^;];%f;%[^;];%[^;];%d;%[^;]\n",
                &prodVenda->listaProdutos[indexProduto].codProduto,
                &prodVenda->listaProdutos[indexProduto].nomeProduto,
                &prodVenda->listaProdutos[indexProduto].dimensoes,
                &prodVenda->listaProdutos[indexProduto].preco,
                &prodVenda->listaProdutos[indexProduto].composicao[indexComposicao].codigo,
                &prodVenda->listaProdutos[indexProduto].composicao[indexComposicao].descricao,
                &prodVenda->listaProdutos[indexProduto].composicao[indexComposicao].quantidade,
                &prodVenda->listaProdutos[indexProduto].composicao[indexComposicao].unidade);

        int i;
        for (i = indexComposicao++; i < 15; i++) {
            fscanf(
                    ficheiro,
                    ";;;;%[^;];%f;%[^;];%[^;];%d;%[^;]\n",
                    &prodVenda->listaProdutos[indexProduto].composicao[indexComposicao].codigo,
                    &prodVenda->listaProdutos[indexProduto].composicao[indexComposicao].descricao,
                    &prodVenda->listaProdutos[indexProduto].composicao[indexComposicao].quantidade,
                    &prodVenda->listaProdutos[indexProduto].composicao[indexComposicao].unidade);
        }

        indexComposicao = 0;
        indexProduto++;
    }

    fclose(ficheiro);
}
*/