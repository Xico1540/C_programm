/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file_header.h to edit this template
  */

/* 
 * File:   funcoes.h
 * Author: Xico
 *
 * Created on 22 de dezembro de 2022, 22:00
 */

#ifndef FUNCOES_H
#define FUNCOES_H

#include "structs.h"
/**
 *@brief Define que LER_UTILIZADOR vai ser a mensagem escrita a frente.
 * 
 */
#define LER_UTILIZADOR " ---- Bem vindo á Moveis para Todos ----- \n Qual o seu tipo de utilizador:\n -1-Admin-\n -2-Cliente\n -3-Funcionario\n-:"

/**
 *@brief Define o valor maximo possivel no menu para escolher o tipo de utilizador.
 * 
 */
#define VALOR_MAX_USERS 3
/**
 *@brief Define o valor minimo possivel no menu para escolher o tipo de utilizador.
 * 
 */
#define VALOR_MIN_USERS 1

/**
 *@brief Define o valor maximo possivel no menu de admin para escolher o que pretender gerir na empresa.
 * 
 */
#define VALOR_MAX_ADMIN 3
/**
 *@brief Define o valor minimo possivel no menu de admin para escolher o que pretender gerir na empresa.
 * 
 */
#define VALOR_MIN_ADMIN 0
/**
 *@brief Define que ADMIN_MENU vai ser a mensagem para perguntar o tipo de gestao que o admin prentende fazer.
 * 
 */

#define ADMIN_MENU "Bem vindo administrador, o que pretende fazer na :\n1 - Gestao de clientes \n2 - Gestao de Produtos \n3 - Gestao de Producao\n0 - Voltar\n-"  

/**
 *@brief Define que GESTAO_CLIENTE vai ser a mensagem para perguntao ao admin o que pretende gerir nos clientes.
 * 
 */
#define GESTAO_CLIENTE "----Gestao de clientes---- \n Pretende:\n0- voltar\n1 - Criar novo cliente\n2 - Editar cliente\n3 - Remover cliente\n4 - Imprimir lista de clientes\n5 - Ordenar clientes por ordem decrescente de encomendas\n-"
/**
 *@brief Define o valor maximo possivel no menu de gestao de clientes para permitir ao admin escolher o que pretender gerir em relacao a clientes.
 * 
 */
#define VALOR_MAX_GERIRCLIENTEMENU 5
/**
 *@brief Define o valor minimo possivel no menu de gestao de clientes para permitir ao admin escolher o que pretender gerir em relacao a clientes.
 * 
 */
#define VALOR_MIN_GERIRCLIENTEMENU 0


/**
 *@brief Define que GESTAO_PRODUTOS vai ser a mensagem para perguntao ao admin o que pretende gerir nos Produtos.
 * 
 */
#define GESTAO_PRODUTOS "-----Gestao de Produtos----\n Pretende para a gestao dos produtos:\n0-voltar\n1 - Criar um material \n2 - Editar um material\n3 - Remover material\n4 - Listar materiais\n5 - Criar produto\n6 - Editar produto\n7 - Remover produto\n8 - Listar produtos\n9 - Ordenar produtos por preço descendente\n-"
/**
 *@brief Define o valor maximo possivel no menu de gestao de produtos para permitir ao admin escolher o que pretender gerir em relacao aos produtos.
 * 
 */
#define VALOR_MAX_GERIRPRODUTO 9
/**
 *@brief Define o valor minimo possivel no menu de gestao de produtos para permitir ao admin escolher o que pretender gerir em relacao aos produtos.
 * 
 */
#define VALOR_MIN_GERIRPRODUTO 0

/**
 *@brief Define o valor maximo possivel no menu de cliente para escolher o que pretende fazer na empresa.
 * 
 */
#define VALOR_MAX_CLIENTE 2
/**
 *@brief Define o valor minimo possivel no menu de cliente para escolher o que pretende fazer na empresa.
 * 
 */
#define VALOR_MIN_CLIENTE 0
/**
 *@brief Define que o MENU_CLIENTE vai ser a mensagem para perguntar ao cliente o que ele pretende fazer.
 * 
 */
#define MENU_CLIENTE "Bem vindo Cliente, o que procura :\n1 -Gerir cliente\n2-Encomendas\n0 -Voltar\n-"
/**
 *@brief Define o valor maximo possivel no menu de cliente para escolher o que pretende fazer em relaçao aos seus dados de cliente.
 * 
 */
#define VALOR_MAX_GERIRCLIENTE 3
/**
 *@brief Define o valor minimo possivel no menu de cliente para escolher o que pretende fazer em relaçao aos seus dados de cliente.
 * 
 */
#define VALOR_MIN_GERIRCLIENTE 0
/**
 *@brief Define que o GERIR_CLIENTE vai ser a mensagem para perguntar ao cliente o que ele pretende fazer em relaçao aos seus dados de cliente..
 * 
 */
#define GERIR_CLIENTE "----Gerir cliente---- \n Deseja:\n0-voltar\n1 - Registar-me como novo cliente\n2 - Editar os meus dados pessoais \n3 - Remover me da lista de clientes\n-"

/**
 *@brief Define o valor maxmimo possivel no menu de encomendas para escolher o que pretende fazer em relaçao a encomendas.
 * 
 */
#define VALOR_MAX_ENCOMENDAS 4
/**
 *@brief Define o valor maxmimo possivel no menu de encomendas para escolher o que pretende fazer em relaçao a encomendas.
 * 
 */
#define VALOR_MIN_ENCOMENDAS 0
/**
 *@brief Define que o ENCOMENDAS vai ser a mensagem para perguntar ao cliente o que ele pretende fazer na aba encomendas.
 * 
 */
#define ENCOMENDAS "-----Encomendas---- \n Escolha a opcao relativa a sua encomenda:\n0-voltar\n1 - Registar encomenda\n2 - Alterar encomenda\n3 - Eleminar encomenda\n4- Listar encomendas\n-"
/**
 *@brief Define o valor  minimo possivel  no menu do funcionario para escolher o que pretende fazer.
 * 
 */
#define VALOR_MIN_FUN 0
/**
 *@brief Define o valor  maximo possivel  no menu do funcionario para escolher o que pretende fazer.
 * 
 */
#define VALOR_MAX_FUN 4
/**
 *@brief Define que o FUNCIONARIO vai ser a mensagem para perguntar ao funcionario o que ele pretende fazer.
 * 
 */
#define FUNCIONARIO "-----------Bem vindo Funcionario ------------\n O que pretende fazer :\n0 - Voltar\n1 - Dar entrada ou saida\n2 - Ver lista de produtos\n3 - Ver lista de componentes\n4 - Ver lista de encomendas\n-"
/**
 *@brief Define que CARATERE é a mensagem para perguntar se o utilizador continua na aplicaçao .
 * 
 */
#define CARATERE "Pretende continuar na aplicacao digite n-nao ,s-sim:\n-"
/**
 *@brief Define que VALOR_INVALIDO  é a mensagem que informa que inseriu um valor invalido .
 * 
 */
#define VALOR_INVALIDO "O valor inserido é inválido, digite um valor válido.\n"
/**
 *@brief Define que CARATERE_INVALIDO  é a mensagem que informa que inseriu um caratere unvalido .
 * 
 */
#define CARATERE_INVALIDO "Caratere inserido é invalido,digite um caratere correto.\n"

/**
 * @brief  Limpa o Buffer.
 * @details Sempre que existir Lixo no Buffer e executar a funçao ele é limpo.
 */
void limpaBuffer();
/**
 * @brief  Obter um numero Inteiro.
 * @details Esta funçao recebe um valor verifica se é do tipo inteiro e se esta entre os valores maximo e minimo recebidos como argumentos.
 * 
 * @params minValor Valor minimo permitido que seja inserido.
 * @params maxValor Valor maximo permitido que seja inserido.
 * @params msg Mensagem a pedir o valor ao utilizador.
 * 
 * @return Valor Devolve o valor que foi inserido depois do processo todo de verificação
 * 
 */
int obterInt(int minValor, int maxValor, char *msg);
/**
 * @brief  Ler um caratere.
 * @details Recebe um caratere e verifica se ele não é diferente de s/S ou n/N.
 * 
 * @params msg Mensagem a pedir o que o utilizador insira o caratere.
 * 
 * @return c Devolve o caratere depois de verificar.
 */
char obterCaratere(char*msg);
/**
 * @prief  Procura um cliente na lista de clientes.
 * @details A posiçao começa com um valor e eu enquanto a pos for igual ao valor inicial, e o i que é iniciado a zero for menor que o tamanho da lista ,
 * verifica se o numero do cliente que deseja procurar é igual a algum dos que existe na lista clientes , e devolve a posiçao dele na lista .
 * 
 * @params lista cliente  Lista dos clientes .
 * @params num  Numero inserido que vai ser o id que deseja procurar. 
 * @params pos A posicao onde se encontra o cliente que vai ser devolvida. 
 * 
 * 
 */
void procuraCliente(const Clientes* listacliente, const int* num, int* pos);
/**
 * @brief  Insere um cliente na lista .
 * @details Esta função chama a funçao de procurar o cliente retorna a posicao ,verifica se a posiçao nao e -1,  verifica se a memoria reservada para a lista na main
 * é igual ao contador , se for reserva mais 5 espaços na memoria, e por fim adiciona o cliente na lista e aumenta o contador.  
 * 
 * @params lista cliente Lista de clientes.
 * @params cliente Um cliente apenas.
 * 
 * 
 * @return Devolve 0 se ja existir alguem com aquele id e nao adiciona , e devolve 1 se adicionou .
 */
int inserirCliente(Clientes* listacliente, Cliente* cliente);
/**
 * @brief Guarda e regista os dados do cliente. 
 * @details Esta função pede todos os dados que um cliente pode ter num certo sitio , e depois guarda os numa variavel , que quando chama a funçao inserir insere todos os dados registados aqui.<
 * 
 * @params Cliente Recebe a struct cliente. 
 */
void registarCliente(Cliente* cliente);
/**
 * @brief  Remove o cliente da lista ou muda o seu estado para inativo .
 * @details Esta funçao chama a funçao procuracliente que devolve a posicao na lista do cliente que o utilizador quer remover , verifica se esse cliente 
 * ja tem alguma encomenda registada , se tiver altera o estado para inativo senao apaga o cliente da lista passando os clientes a partir da posicao dele,
 * todos uma posicao pra tras , no fim retira um valor no contador.
 * 
 * @params clientes Lista dos clientes.
 * @params idcliente Id do cliente a remover pedido ao utilizador.
 * 
 * @return 0 se a posiçao for -1 , 1 se remover ou se alterar o estado para inativo.
 */
int removerCliente(Clientes *clientes, int *idCliente);
/**
 * @brief Atualizar o nif do cliente .
 * @details Chama a funçao procuracliente , devolve a posição exata dele e altera o nif para o novo nif inserido pelo utilizador.
 * 
 * @param clientes lista dos clientes.
 * @param idCliente id do cliente a procurar.
 * @param nifnovo novo nif inserido pelo utilizador
 * 
 * @return 0 se o cliente nao existir , 1 se alterar o nif .  
 */
int atualizarClienteNif(Clientes *clientes, int *idCliente,int nifnovo);
/**
 * @brief Atualizar o nome do cliente .
 * @details Chama a funçao procuracliente , devolve a posição exata dele e altera o nome para o novo nome inserido pelo utilizador.
 * 
 * @param clientes lista dos clientes.
 * @param idCliente id do cliente a procurar.
 * @param nomenovo novo nome inserido pelo utilizador
 * 
 * @return 0 se o cliente nao existir , 1 se alterar o nome .  
 */
int atualizarClienteNome(Clientes *clientes, int *idCliente,char nomenovo[]);
/**
 * @brief Atualizar o pais do cliente .
 * @details Chama a funçao procuracliente , devolve a posição exata dele e altera o pais para o novo pais inserido pelo utilizador.
 * 
 * @param clientes lista dos clientes.
 * @param idCliente id do cliente a procurar.
 * @param paisnovo novo pais inserido pelo utilizador
 * 
 * @return 0 se o cliente nao existir , 1 se alterar o pais .  
 */
int atualizarClientePais(Clientes *clientes, int *idCliente,char paisnovo[]);
/**
 * @brief Atualizar a morada do cliente .
 * @details Chama a funçao procuracliente , devolve a posição exata dele e altera a morada para a morada nova inserido pelo utilizador.
 * 
 * @param clientes lista dos clientes.
 * @param idCliente id do cliente a procurar.
 * @param moradanova nova morada inserida pelo utilizador
 * 
 * @return 0 se o cliente nao existir , 1 se alterar a morada .  
 */
int atualizarClienteMorada(Clientes *clientes, int *idCliente,char moradanova[]);

/**
 * @brief ordena os clientes 
 * @details troca para um temporiario o primeiro ,troca o segundo para o primeiro , e depois troca o segundo para temporario.
 * 
 * 
 * @param cliente1 cliente da lista
 * @param cliente2 cliente da lista
 */
void trocaClientes(Cliente *cliente1, Cliente *cliente2);
/**
 * @brief ordena e imprime
 * @details verifica o numero de encomendas dos clientes , chama a funçao que troca os clientes de posiçao 
 * e no final imprime a lista dos clientes.
 * 
 * @param clientes lista de clientes
 */
void OrdenaClientes(Clientes *clientes);



#endif /* FUNCOES_H */
