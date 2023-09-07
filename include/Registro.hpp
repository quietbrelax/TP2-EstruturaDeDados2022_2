/*
-----------------------------------------------------
Arquivo Registro.hpp referente ao TP2
Caixa de Entrada de Emails
Materia Estrutura de Dados
Semestre 2022/02

Aluna: Maria Clara Oliveira Domingos Ruas
Matricula: 2021019572
-----------------------------------------------------

Projeto de organizacao de vetores


*/
#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include "CadeiaString.hpp"

//Classe dos elementos do vetor a ser ordenado

class Registro {
  private:
    float numeros[10];
    CadeiaString cadeias[15];
    
public:
    int chave = 0;

};