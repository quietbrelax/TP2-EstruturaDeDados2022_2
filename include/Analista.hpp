/*
-----------------------------------------------------
Arquivo Analista.hpp referente ao TP2
Analista de parâmetros
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
#include <chrono>
#include <ctime> 

class Analista {
  private:

    std::chrono::_V2::system_clock::time_point comeco;
    std::chrono::_V2::system_clock::time_point fim;
    int comparacoes;
    int copias;

public:
  //Construtor
    Analista();

  //Atualizacao e definicao de valores
    void pegaTempoIncial();
    void pegaTempoFinal();
    void analisaComp();
    void analisaCopia();

  //Retorno
    std::chrono::duration<double> getTempo();
    int getComp();
    int getCopia();
  
  //Reinicializacao
    void reset();
    

};