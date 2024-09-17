/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.h to edit this template
 */

/* 
 * File:   gestaoproducao.h
 * Author: Xico
 *
 * Created on 15 de janeiro de 2023, 20:53
 */

#ifndef GESTAOPRODUCAO_H
#define GESTAOPRODUCAO_H
#include "structs.h"
/**
 * @brief Esta funçao serve para gerir a produçao de uma semana
 * @details Primeiro inserimos a data onde começa a semana , a funçao verifica se a data nao e maior que as inseridas nas encomendas
 * depois compara o cod do produto na lista de produtos com o cod do produto inserido na encomenda , de seguida compara o cod do material que o produto usa  
 * com o cod do material existente na lista de materiais imprimindo assim o seu codigo,descriçao,unidade e a quantidade multiplicando a quantidade de material 
 * que o produto usa com a quantidade pedida daquele tipo de produto.
 * 
 * @param encomendas struct encomendas
 * @param produtos struct produtos
 * @param componentes struct produtos
 */
void gestaoProducao(Encomendas *encomendas, Produtos *produtos, Componentes *componentes);
#endif /* GESTAOPRODUCAO_H */
