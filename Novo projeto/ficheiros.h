/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.h to edit this template
 */

/* 
 * File:   ficheiros.h
 * Author: Xico
 *
 * Created on 22 de dezembro de 2022, 22:01
 */

#ifndef FICHEIROS_H
#define FICHEIROS_H
#include "structs.h"
/**
 * @brief Carrega os clientes do ficheiro para memoria .
 * @param clientes lista de  clientes
 */
void lerClientes(Clientes *clientes);
/**
 * @brief Guarda a lista de clientes da memoria para o ficheiro.
 * @param clientes lista de  clientes
 */
void registarClientes(Clientes*clientes);
/**
 * @brief Guarda as encomendas da memoria para o ficheiro
 * @param encomendas lista de encomendas
 */
void registarEncomendas(Encomendas *encomendas);
/**
 * @brief Carrega as encomendas do ficheiro para a memoria.
 * @param encomendas lista de  encomendas
 */
void lerEncomendas(Encomendas *encomendas);
/**
 * @brief Carrega a lista de materiais do ficheiro para a memoria.
 * @param componentes lista de  componentes
 */
void lerMateriais(Componentes *componentes);
/**
 * @brief Guarda a lista de materiais da memoria para o ficheiro
 * @param componentes lista de  componentes
 */
void registarMateriais(Componentes *componentes);
/**
 * @brief Guarda num ficheiro todas as açoes do funcionario.
 * @param id id do funcionario
 * @param msg a mensagem que vai guardar no ficheiro.
 * @param nomeficheiro o nome que o ficheiro txt tem 
 */
void logs(int *id, char *msg, char *nomeficheiro);
/**
 * @brief Le o ficheiro texto de produtos
 * @param produtos lista de produtos
 */
void lerFicheiroMoveis(Produtos * produtos);
/**
 * @brief Guarda tudo de produtos no ficheiro texto
 * @param produtos lista de produtos
 */
void escreverFicheiroMovel(Produtos *produtos);
#endif /* FICHEIROS_H */
