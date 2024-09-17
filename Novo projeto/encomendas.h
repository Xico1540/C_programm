/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.h to edit this template
 */

/* 
 * File:   encomendas.h
 * Author: Xico
 *
 * Created on 15 de janeiro de 2023, 00:42
 */

#ifndef ENCOMENDAS_H
#define ENCOMENDAS_H
#include "structs.h"



//CRUD DE PRODUTOS DENTRO DE UMA ENCOMENDA
/**
 * @brief procura um produto numa certa encomenda
 * @details Compara o codigo inserido com os codigos da lista de produtos daquela encomenda em especifico e quando encontra um igual devolve a sua posiçao .
 * 
 * @param encomenda uma encomenda especifica
 * @param cod codigo do produto
 * @param pos posiçao retornada
 */
void procuraProd(Encomenda *encomenda ,char *cod, int *pos);
/**
 * @brief insere um produto numa certa encomenda
 * @details verifica senao existem repetidos , realloca memoria se necessario e insere.
 * 
 * @param encomenda encomenda especifica.
 * @param m produto na encomenda.
 * 
 * @return 0 se ja existir , 1 se for inserido.
 */
int inserirProdutoEncomenda(Encomenda * encomenda, prod * m);
/**
 * @brief alterar a quantidade de um certo produto dentro de uma certa encomenda.
 * @details vai a encomenda naquela posiçao e altera a quantidade do produto naquela posiçao .
 * 
 * @param encomendas lista de encomendas
 * @param idprocura o numero  da encomenda
 * @param numprocura o numerdo do produto dentro da encomenda
 * @param quantidadenova a nova quantidade
 */
void editarProdutoQuantidade(Encomendas *encomendas,int *idprocura,int numprocura,int quantidadenova);
/**
 * @brief remove um produto dentro de uma encomenda
 * @details vai a encomenda na posiçao devolvida pela funçao de procurar encomenda , ao produto na posicao escolhida e copia 
 * o ultimo produto para aquele local  , no fim retira 1 valor ao contador.
 * 
 * @param encomendas lista de encomendas
 * @param idprocura o numero da encomenda que procura
 * @param numprocura o numero do produto dentro da encomenda
 * 
 */
void removerProd(Encomendas *encomendas,int *idprocura,int numprocura);
/**
 * @brief procura uma encomenda
 * @details verifica senao existe nenhuma encomenda com o mesmo numero naquela lista de encomendas. 
 * 
 * 
 * @param encomendas lista de encomendas
 * @param num numero da encomenda 
 * @param pos retorna a posicao da encomenda na lista
 */




//CRUD DE ENCOMENDAS
/**
 * @brief Procura encomenda
 * @details Compara o codigo inserido com os codigos da lista de encomendas e quando encontra um igual retorna a posiçao .
 * 
 * @param encomendas lista de encomendas
 * @param num num da encomenda
 * @param pos posiçao retornada
 */
void procuraEncomenda(const Encomendas *encomendas, const int *num, int *pos);
/**
 * @brief insere uma encomenda
 * @details verifica senao existem repetidas , realloca memoria se necessario e insere.
 * 
 * @param listaencomendas lista de encomendas
 * @param encomenda encomenda a inserir
 * 
 * @return 0-se ja existir alguma encomenda com aquele codigo, 1- se inserir. 
 */
int inserirEncomenda(Encomendas *listaencomendas, Encomenda *encomenda);
/**
 * @brief regista uma encomenda
 * @details Pede todos os dados da encomenda e dos produtos inseridos nela, adicionando uma encomenda ao id do cliente.
 * @param encomenda encomenda a ser criada
 * @param produtos lista de produtos existentes
 * @param clientes a lista de clientes
 */
void registarEncomenda(Encomenda* encomenda,Produtos *produtos,Clientes *clientes);
/**
 * @brief atualiza o dia da encomenda
 * @details vai a encomenda naquela posiçao e muda o dia para o novo dia pedido ao utilizador
 * 
 * @param encomendas lista de encomendas
 * @param numencomenda numero da encomenda
 * @param dianovo dia novo
 * 
 * @return 0- se a encomenda nao existir , 1 - se alterar.
 */
int atualizarEncomendaDia(Encomendas *encomendas, int *numencomenda, int dianovo);
/**
 * @brief atualiza o mes da encomenda
 * @details vai a encomenda naquela posiçao e muda o mes para o novo mes pedido ao utilizador
 * 
 * @param encomendas lista de encomendas
 * @param numencomenda numero da encomenda
 * @param mesnovo novo mes
 * 
 * @return 0- se a encomenda nao existir , 1 - se alterar.
 */
int atualizarEncomendaMes(Encomendas *encomendas, int *numencomenda, int mesnovo);
/**
 * @brief atualiza o ano da encomenda 
 * @details vai a encomenda naquela posiçao e muda o ano para o novo ano pedido ao utilizador
 * 
 * @param encomendas lista de encomendas
 * @param numencomenda numero da encomenda
 * @param anonovo novo ano 
 * 
 * @return 0- se a encomenda nao existir , 1 - se alterar.
 */
int atualizarEncomendaAno(Encomendas *encomendas, int *numencomenda, int anonovo);
/**
 * @brief Remove uma encomenda
 * @details vai a posiçao da encomenda que e devolvida pela funçao procura encomenda, copia todas as encomendas uma posiçao para pras 
 * a partir daquela posiçao e remove um valor no contador
 * 
 * @param encomendas lista de encomendas
 * @param numencomenda numero da encomenda
 * 
 * @return 0 se nao existir a encomenda, 1- se remover.
 */
int removerEncomenda(Encomendas *encomendas, int *numencomenda);

#endif /* ENCOMENDAS_H */
