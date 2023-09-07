/*
-----------------------------------------------------
Arquivo Analista.cpp referente ao TP2
Implementacao das funcoes da Estrutura Analista
Materia Estrutura de Dados
Semestre 2022/02

Aluna: Maria Clara Oliveira Domingos Ruas
Matricula: 2021019572
-----------------------------------------------------

Projeto de organizacao de vetores


*/

#include "Analista.hpp"
#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime> 


   Analista::Analista(){
        comparacoes = 0;
        copias = 0;
    }


    void Analista::pegaTempoIncial(){
        comeco = std::chrono::system_clock::now();
    }

    void Analista::pegaTempoFinal(){
        fim = std::chrono::system_clock::now();
    }

    void Analista::analisaComp(){
        comparacoes++;
    }

    void Analista::analisaCopia(){
        copias++;
    }



    std::chrono::duration<double> Analista::getTempo(){
        return fim - comeco;
    }

    int Analista::getComp(){
        return comparacoes;
    }

    int Analista::getCopia(){
        return copias;
    }

    void Analista::reset(){
        comparacoes = 0;
        copias = 0;
    }