/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.h to edit this template
 */

/* 
 * File:   produtos.h
 * Author: Xico
 *
 * Created on 5 de janeiro de 2023, 16:49
 */

#ifndef PRODUTOS_H
#define PRODUTOS_H
#include "structs.h"
//CRUD DE COMPONENTES   
/**
 * @brief Procura um componente
 * @details Compara o codigo inserido com os codigos dos componenetes na lista de produtos , e quando encontra retorna a sua posiçao
 * 
 * @param listacomponentes lista de componentes
 * @param cod codigo do material 
 * @param pos posiçao retornada apos procurar
 */
void procuraComponente(Componentes *listacomponentes ,char *cod,int*pos);
/**
 * @brief Insere um componente
 * @details Verifica senao existem componentes com o mesmo codigo , realloca memoria se necessario para a lista de 
 * componentes e insere
 * 
 * @param listacomponentes lista de componentes
 * @param componente material a inserir
 * @return 0 - se ja existir , 1-se inserido.
 */
int inserirComponente(Componentes *listacomponentes, Componente *componente);
/**
 * @brief Regista um componente 
 * @details Pede todos os dados do componente
 * 
 * @param componente componente
 */
void registarComponente(Componente *componente);
/**
 * @brief Atualizar a descriçao de um componente
 * @details  vai ao componente na posiçao retornada pelo procura componente e muda a descriçao para uma nova inserida pelo
 * utilizador.
 * 
 * @param componentes lista de componentes
 * @param codMat codigo do componente
 * @param descricaonova nova descriçao
 * 
 * @return 0- se nao existir , 1- se alterar. 
 */
int atualizarComponenteDescricao(Componentes *componentes, char *codMat, char descricaonova[]);
/**
 * @brief Atualizar a Unidade de um componente.
 * @details vai ao componente na posiçao retornada pelo procura componente e muda a unidade
 * para a inserida pelo utilizador.
 * 
 * @param componentes lista de componentes
 * @param codMat codigo do componente
 * @param unidadenova nova unidade
 * 
 * @return 0- se nao existir , 1- se alterar.  
 */
int atualizarComponenteUnidade(Componentes *componentes, char *codMat, char unidadenova[]);
/**
 * @brief remove um componente
 * @details procura o componente , percorre todos os componentes e a partir da posiçao retornada pelo 
 * procura componente ele copia uma posiçao para tras todas as informaçoes do componente seguinte removendo no 
 * fim um valor ao contador .
 * 
 * @param componentes lista de componentes
 * @param codMat codigo do componente
 * @return 0 - se nao existir , 1-se remover.
 */
int removerComponente(Componentes *componentes, char* codMat);


//CRUD DE COMPONENTES EM CADA PRODUTO 

/**
 * @brief insere um componente num produto .
 * @details verifica senao existe nenhum componente com o mesmo codigo, naquele determinado produto,
 * realloca memoria se necessario e insere
 * 
 * @param produto produto especifico.
 * @param m componente
 * 
 * @return 0-se ja existir, 1- se inserido.
 */
int inserirComposicaoProduto(Produto * produto, Materiais * m);
/**
 * @brief procura um componente num determinado produto 
 * @details Compara o cofigo inserido com os codidos da lista de componentes daquele produto , e retorna a posiçao .
 * 
 * @param produto produto especifico
 * @param cod codigo do componente que procura
 * @param pos posiçao retornada do componente
 */
void procuraComposicao(Produto *produto ,char *cod, int *pos); 
/**
 * @brief Atualiza a quantidade de um componente num certo produto
 * @details Acede a posicao do componente atraves do procura produto, e altera a 
 * quantidade para a nova quantidade inserida pelo utilizador.
 * 
 * @param produtos lista de produtos
 * @param codMat cod do produto
 * @param numprocura numero do componente
 * @param quantidadenova nova quantidade
 */
void editarComposicaoQuantidade(Produtos *produtos,char *codMat,int numprocura,int quantidadenova);
/**
 * @brief remove um componente de um determinado produto .
 * @details Acede a posiçao atraves do procura Produto e copia os dados do ultimo componente do produto
 * para a posiçao do componente que deseja remover , retirando um valor ao contador.
 * 
 * @param produtos lista de produtos
 * @param codMat cod fo produto em especifico
 * @param numprocura numero do componente
 * 
 * @return 0- se nao existir, 1 - se removido
 */
int removerComposicao(Produtos *produtos,char *codMat,int numprocura);


/**
 * @brief Procura um produto
 * @details compara o codigo inserido com o  codigo na lista de produtos e retorna a posiçao dele
 * 
 * @param listaprodutos lista de produtos 
 * @param cod codigo do produto que procura
 * @param pos posiçao retornada
 */
void procuraProduto(Produtos *listaprodutos,char *cod,int*pos);
/**
 * @brief Insere um produto.
 * @details Verifica senao existem produtos repetidos, realloca memoria se necessario
 * e insere o produto na lista.
 * 
 * @param listaprodutos lista de produtos
 * @param produto produto a inserir
 * 
 * @return 0- se ja existir , 1 -se inserido. 
 */
int inserirProduto(Produtos *listaprodutos, Produto *produto);
/**
 * @brief Regista um produto 
 * @details Pede todos os dados do produto que quer inserir,caso nao estejam ja inseridos todos os componentes
 * na lista de componentes permite que ele os crie durante o registo.
 * 
 * @param produto Produto a registar 
 * @param componentes lista de componentes existentes
 * @param componente componente
 */
void registarProduto(Produto *produto,Componentes *componentes,Componente *componente);
/**
 * @brief Atualiza o nome do produto 
 * @details Acede a posiçao do produto a partir da funçao procura produto ,
 * e altera o nome  para o novo nome que o utilizador inserir
 * 
 * @param produtos lista de produtos 
 * @param codMat Codigo do produto a procurar
 * @param nomenovo Novo nome
 * 
 * @return 0- se nao existir , 1 - se alterar.
 */
int atualizarProdutonome(Produtos *produtos, char *codMat, char nomenovo[]);
/**
 * @brief Atualiza as dimensoes do produto 
 * @details Acede a posiçao do produto a partir da funçao procura produto ,
 * e altera as dimensoes  para as novas dimensoes que o utilizador inserir
 * 
 * @param produtos lista de produtos
 * @param codMat Codigo do produto a procurar
 * @param novasdimensoes Novas dimensoes
 * 
 * @return 0- se nao existir , 1 - se alterar.
 */
int atualizarProdutodimensoes(Produtos *produtos, char *codMat, char novasdimensoes[]);
/**
 * @brief Atualiza o preco do produto 
 * @details Acede a posiçao do produto a partir da funçao procura produto ,
 * e altera o preco  para o novo preco que o utilizador inserir
 * 
 * @param produtos lista de produtos
 * @param codMat Codigo do produto a procurar
 * @param preconovo novo preco
 * 
 * @return 0- se nao existir , 1 - se alterar.
 */
int atualizarProdutoPreco(Produtos *produtos, char *codMat, float preconovo);
/**
 * @brief Remove um produto.
 * @details Acede a posiçao do produto atraves da funçao procura produto ,e copia todos os dados 
 * dos produtos seguintes para a posiçao anterior a partir da posiçao daquele produto.
 * 
 * @param produtos lista de produtos
 * @param codMat codigo do produto a remover
 * 
 * @return 0- senao existir, 1 -se removido.
 */
int removerProduto(Produtos *produtos, char* codMat);

/**
 * @brief Troca as posiçoes dos produtos
 * @details troca para um temporiario o primeiro ,troca o segundo para o primeiro , e depois troca o segundo para temporario.
 * 
 * @param produto1  produto 1
 * @param produto2  produto 2
 */
void trocaProdutos(Produto *produto1, Produto *produto2);
/**
 * @brief Ordena os produtos
 * @details  verifica o preco dos produtos , chama a funçao que troca os produtos de posiçao 
 * e no final imprime a lista dos produtos.
 * 
 * @param produtos lista de produtos.
 */
void OrdenaProdutos(Produtos *produtos);
        

#endif /* PRODUTOS_H */
