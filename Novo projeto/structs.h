/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.h to edit this template
 */

/* 
 * File:   structs.h
 * Author: Xico
 *
 * Created on 22 de dezembro de 2022, 22:01
 */

#ifndef STRUCTS_H
#define STRUCTS_H
/**
 * @brief Define a capacidade de alguns arrays 
 * 
 * 
 */
#define MAX 30


/**
 * @brief struct cliente
 * @details todas as informacoes que um cliente pode ter
 * 
 */
typedef struct{
    int id;
    int nif;
    char nome[MAX];
    char morada[MAX];
    char pais[MAX];
    int nencomendas;
    char atividade[7];
       
}Cliente;
/**
 * @brief struct clientes
 * @details contem uma lista de clientes o tamanho dela e o contador que e a posição onde estamos a trabalhar.
 * 
 */
typedef struct{
   Cliente *listacliente;
   int inseridosc, tamtotal;   
}Clientes;

/**
 * @brief struct componente
 * @details todas as informacoes que um componente pode ter.
 * 
 */
typedef struct {
    char codMaterial[20];
    char descricao[20];
    char unidade[3];
}Componente;
/**
 * @brief struct componentes
 * @details contem uma lista de componentes o tamanho dela e o contador que e a posição onde estamos a trabalhar.
 * 
 */
typedef struct{
    Componente *listacomponente;
    int contador,tamcomp;
}Componentes;

/**
 * @brief struct Materiais
 * @details todas as informacoes que um material inserido vai ter.
 * 
 */
typedef struct{
    char codigo[20];//codcomponentes
    int quantidade;  
}Materiais;
/**
 * @brief struct Produto
 * @details todas as informacoes que um Produto pode ter, contendo ainda uma lista de materiais inseridos.
 * 
 */
typedef struct {
    char codProduto[30];
    char nomeProduto[20];
    char dimensoes [20];
    float preco;
    Materiais *composicao;
    int tamanhocomp;
    int contadorcomp;
}Produto;
  /**
 * @brief struct Produtos
 * @details contem uma lista de produtos  o tamanho dela e o contador que e a posição onde estamos a trabalhar.
 * 
 */  
typedef struct {
    Produto *listaProdutos;
    int contadorp,tamprod;
}Produtos;


/**
 * @brief struct Data 
 * @details para definir um dia um mes e um ano .
 * 
 */
typedef struct{
    int dia,mes,ano;
}Data;
/**
 * @brief struct prod
 * @details Contem a informação que vai ser inserida na encomenda para defenir o produto usado.
 * 
 */
typedef struct{
    char cod[20];//codigo do produto
    int quantidadeprod;
}prod; 
/**
 * @brief struct Encomenda
 * @details todas as informacoes que uma encomenda pode ter, contendo ainda uma lista com os produtos de cada encomenda.
 * 
 */
typedef struct {                                           
  int numencomenda;                                        
  Produto produtos[10];
  prod *prode;
  Data dataentrega;
  int tamanhoprode;
  int contadorprode;
  int id;
}Encomenda;
/**
 * @brief struct encomendas
 * @details contem uma lista de encomendas o tamanho dela e o contador que e a posição onde estamos a trabalhar.
 * 
 */
typedef struct {
    Encomenda *listaEncomendas;
    int contadore,tame;
}Encomendas;

/**
 * @brief Imprime um cliente
 * @param cliente struct cliente
 * 
 */
void imprimirCliente(const Cliente *cliente);
/**
 * @brief Imprime Todos os clientes
 * @param clientes struct clientes
 * 
 */
void imprimirTudo (const Clientes *clientes);
/**
 * @brief Imprime um componente
 * @param componente struct componente
 * 
 */
void imprimirComponente(const Componente *componente);
/**
 * @brief Imprime Todos os componentes
 * @param componentes struct componentes
 * 
 */
void imprimirTodosComponentes(const Componentes *componentes);
/**
 * @brief Imprime um produto
 * @param produto struct produto
 * 
 */
void imprimirProduto(const Produto *produto);
/**
 * @brief Imprime Todos os produtos
 * @param produtos struct produtos
 * 
 */
void imprimirTodosProdutos(const Produtos *produtos);
/**
 * @brief Imprime uma encomenda
 * @param encomenda struct encomenda
 * 
 */
void imprimirEncomenda(const Encomenda *encomenda);
/**
 * @brief Imprime Todas as encomendas
 * @param encomendas struct encomendas
 * 
 */
void imprimirTodasEncomendas(const Encomendas *encomendas);
#endif /* STRUCTS_H */
