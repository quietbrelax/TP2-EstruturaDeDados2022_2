/*
-----------------------------------------------------
Arquivo Organizador.hpp referente ao TP2
Organizador de Vetores
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
#include "Celula.hpp"
#include "Registro.hpp"
#include "CadeiaString.hpp"
#include "Analista.hpp"

class Organizador {
  private:
    Celula* pilha;
    int tamPilha;
    Registro indicesMediana[7];

  public:
  //Funcoes de manutencao da classe
    Organizador();
    ~Organizador();
    void Limpa();

  //Funcoes de criacao do vetor aleatorio
    void criaVetorAleatorio(Registro *A, int tam);
    int existeNum(Registro *A, int tam, int n);

  //Metodos auxiliares
    void troca(Registro * A, int i, int , Analista *analista);
    void Particao(int Esq, int Dir, int *i, int *j, Registro *A, Analista *analista);
    void Ordena(int Esq, int Dir, Registro *A, Analista *analista);

    void particaoMediana(int Esq, int Dir, int *i, int *j, Registro *A, int tam, int tipo, Analista *analista);
    void Selecao(Registro *A, int n, int esq, int dir, Analista *analista);

    int mediana(int tam, Registro *A, int Esq, int Dir, int mediana, Analista *analista);
    int criaVetorIndices(Registro *A, int Esq, int Dir, int mediana, Analista *analista);

    void empilha(Celula n, Analista *analista);
    void desempilha(Celula * item, Analista *analista);
    void FPVazia();
    bool vazia();

    //Quicksorts
    void quicksortRecursivo(Registro *A, int n, Analista *analista);
  
    void quicksortMedianaDeTres(Registro *A, int inicio, int fim, int , Analista *analista);
    void quicksortMedianaDeCinco(Registro *A, int inicio, int fim, int tam, Analista *analista);
    void quicksortMedianaDeSete(Registro *A, int inicio, int fim, int tam, Analista *analista);
    void quicksortMediana(Registro *A, int inicio, int fim, int indice, int tam, Analista *analista);

    void quicksortSelecao(Registro *A, int n, int esq, int dir, int min, Analista *analista);

    void quicksortNaoRecursivo(Registro *A, int n, Analista *analista);

    void quicksortEmpilha(Registro *A, int n, Analista *analista);

  //Mergesort
    void merge(Registro *A, int Esq, int meio, int Dir, Analista *analista);
    void mergeSort(Registro *A, int comeco, int fim, Analista *analista);

  //Heapsort
    void heapify(Registro *A, int n, int i, Analista *analista);
    void heapSort(Registro *A, int n, Analista *analista);

};