/*
-----------------------------------------------------
Arquivo Organizador.cpp referente ao TP2
Implementacao das funcoes do Organizador de Vetores
Materia Estrutura de Dados
Semestre 2022/02

Aluna: Maria Clara Oliveira Domingos Ruas
Matricula: 2021019572
-----------------------------------------------------

Projeto de organizacao de vetores


*/

#include "Organizador.hpp"
#include "Celula.hpp"
#include "Registro.hpp"
#include "CadeiaString.hpp"
#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include "memlog.h"
#include "Analista.hpp"

//Funcoes de manutencao da classe

    Organizador::Organizador(){
        tamPilha = 0;
    }

    Organizador::~Organizador(){
        Limpa();
    }

    void Organizador::Limpa(){
        free(pilha);
    }

//Funcoes de criacao do vetor aleatorio

    void Organizador::criaVetorAleatorio(Registro *A, int tam){
        int ran;
        for (int i = 0; i < tam; ++i)
	    {
            ran = rand();
	        A[i].chave = ran;
	    }

    }

    int Organizador::existeNum(Registro *A, int tam, int n){ 
        for (int i = 0; i < tam; ++i)
	    {
		    if(A[i].chave == n){
                return 1;
            }
        }
	    return 0;
    }

//Metodos auxiliares

    void Organizador::troca(Registro *A, int i, int j, Analista *analista){
        int temp = A[i].chave;
        //LEMEMLOG((long int)(&(A[i])), sizeof(Registro), 0);
        A[i].chave = A[j].chave;
        //LEMEMLOG((long int)(&(A[j])), sizeof(Registro), 0);
        A[j].chave = temp;
        //ESCREVEMEMLOG((long int)(&(A[i])), sizeof(Registro), 0);
        //ESCREVEMEMLOG((long int)(&(A[j])), sizeof(Registro), 0);

        analista -> analisaCopia();
        analista -> analisaCopia();
        analista -> analisaCopia();
    }

    void Organizador::Particao(int Esq, int Dir, int *i, int *j, Registro *A, Analista *analista){
        int x;
        *i = Esq;
        *j = Dir;
        x = A[(*i + *j) / 2].chave; 
        analista -> analisaCopia();
        //LEMEMLOG((long int)(&(A[(*i + *j)/2])), sizeof(Registro), 0);
        do{
            while (x > A[*i].chave){
                //LEMEMLOG((long int)(&(A[*i])), sizeof(Registro), 0);
                (*i)++;
                analista -> analisaComp();
            }
            
            while (x < A[*j].chave){
                //LEMEMLOG((long int)(&(A[*j])), sizeof(Registro), 0);
                (*j)--;
                analista -> analisaComp();
            }
            
            if (*i <= *j)
            {
                analista -> analisaComp();
                troca(A, *i, *j, analista);
                (*i)++;
                (*j)--;
            }
            analista -> analisaComp();
        } while (*i <= *j);
}

    void Organizador::Ordena(int Esq, int Dir, Registro *A, Analista *analista){
        int i, j;
        Particao(Esq, Dir, &i, &j, A, analista);
        if (Esq < j)
            Ordena(Esq, j, A, analista);
        if (i < Dir)
            Ordena(i, Dir, A, analista);
    }



    void Organizador::particaoMediana(int Esq, int Dir, int *i, int *j, Registro *A, int tam, int tipo, Analista *analista) {

        int x;
        *i = Esq;
        *j = Dir;
        int med = mediana(tam, A, Esq, Dir, tipo, analista);
        x = A[med].chave;
        //LEMEMLOG((long int)(&(A[med])), sizeof(Registro), 0);
        analista -> analisaCopia();
        do{
            while (x > A[*i].chave){
                //LEMEMLOG((long int)(&(A[*i])), sizeof(Registro), 0);
                (*i)++;
                analista -> analisaComp();
            }
            
            while (x < A[*j].chave){
                //LEMEMLOG((long int)(&(A[*j])), sizeof(Registro), 0);
                (*j)--;
                analista -> analisaComp();
            }
            
            if (*i <= *j)
            {
                troca(A, *i, *j, analista);
                (*i)++;
                (*j)--;
            }
        } while (*i <= *j);
    }

    void Organizador::Selecao(Registro *A, int n, int esq, int dir, Analista *analista){
        int i, j, min;

        for (i = esq; i < dir - 1; i++)
        {
            min = i;
            for (j = i + 1; j < dir; j++)
            {
                //LEMEMLOG((long int)(&(A[j])), sizeof(Registro), 0);
                //LEMEMLOG((long int)(&(A[min])), sizeof(Registro), 0);
                analista -> analisaComp();
                if(A[j].chave < A[min].chave){
                    min = j;
                }
            }
        troca(A, i, min, analista);
    
        }
  
    }



    int Organizador::mediana(int tam, Registro *A, int Esq, int Dir, int mediana, Analista *analista){
        int tamVetor = criaVetorIndices(A, Esq, Dir, mediana, analista);
      
        int medianaIndice;
        int maiores, menores;
        for(int i = 0; i < tamVetor; i++)
        {
            maiores = 0;
            menores = 0;
            
            for (int j = i + 1; j < tamVetor; j++)
            {
                //LEMEMLOG((long int)(&(A[indicesMediana[i].chave])), sizeof(Registro), 0);
                //LEMEMLOG((long int)(&(A[indicesMediana[j].chave])), sizeof(Registro), 0);
                analista -> analisaComp();
                if(A[indicesMediana[i].chave].chave > A[indicesMediana[j].chave].chave){
                    menores++;
                }
                else{
                    maiores++;
                }
            }
            if(menores == maiores){
                medianaIndice = indicesMediana[i].chave;
                break;
            }
        }

        return medianaIndice;

    }

    int Organizador::criaVetorIndices(Registro* A, int Esq, int Dir, int mediana, Analista *analista){
        int tamVetor = 0;
        int tam = Dir - Esq + 1;
        analista -> analisaComp();
        if(tam > mediana){
            for (int i = 0; i < mediana; i++)
            {
                indicesMediana[i].chave = int(rand() % tam) + Esq;
                analista -> analisaCopia();
                tamVetor++;
                if(existeNum(indicesMediana, tamVetor - 1, indicesMediana[i].chave)){
                    i--;
                    tamVetor--;
                }
            }

        }
        else if(tam > 1){
            for (int i = 0; i < tam; i++)
            {
                analista -> analisaCopia();
                indicesMediana[i].chave = int(rand() % tam) + Esq;
                tamVetor++;
            }
        
        }
        return tamVetor;
    }



    void Organizador::empilha(Celula item, Analista *analista){
        pilha[tamPilha] = item;

        tamPilha++;

        analista -> analisaCopia();
    }

    void Organizador::desempilha(Celula * item, Analista *analista){
        item -> Dir = pilha[tamPilha - 1].Dir; 
        item -> Esq = pilha[tamPilha - 1].Esq; 
        tamPilha--;


        analista -> analisaCopia();
        analista -> analisaCopia();
    
    }

    void Organizador::FPVazia(){
        tamPilha = 0;
    }

    bool Organizador::vazia(){
        if(tamPilha != 0){
            return false;
        }

        return true;
    }

    /*----------------- Quicksorts --------------------*/

//Quicksort Recursivo

    void Organizador::quicksortRecursivo(Registro *A, int n, Analista *analista){

        Ordena(0, n - 1, A, analista);

    }

//Quicksort Mediana

    void Organizador::quicksortMedianaDeTres(Registro *A, int inicio, int fim, int tam, Analista *analista) {
        int i, j;

        particaoMediana(inicio, fim, &i, &j, A, tam, 3, analista);
        if (inicio < j)
            quicksortMedianaDeTres(A, inicio, j, j - inicio, analista);
        if (i < fim)
            quicksortMedianaDeTres(A, i, fim, tam - j + inicio, analista);
    }
    void Organizador::quicksortMedianaDeCinco(Registro *A, int inicio, int fim, int tam, Analista *analista) {
        int i, j;
            particaoMediana(inicio, fim, &i, &j, A, tam, 5, analista);
        if (inicio < j)
            quicksortMedianaDeCinco(A, inicio, j, j - inicio, analista);
        if (i < fim)
            quicksortMedianaDeCinco(A, i, fim, tam - j + inicio, analista);
        
    }
    void Organizador::quicksortMedianaDeSete(Registro *A, int inicio, int fim, int tam, Analista *analista) {
        int i, j;
            particaoMediana(inicio, fim, &i, &j, A, tam, 7, analista);
        if (inicio < j)
            quicksortMedianaDeCinco(A, inicio, j, j - inicio, analista);
        if (i < fim)
            quicksortMedianaDeCinco(A, i, fim, tam - j + inicio, analista);
    }

    void Organizador::quicksortMediana(Registro *A, int inicio, int fim, int indice, int tam, Analista *analista) {
        if (inicio < fim) {
        if(indice == 3){
            quicksortMedianaDeTres(A, inicio, fim, tam, analista);
        }
        else if(indice == 5){
            quicksortMedianaDeCinco(A, inicio, fim, tam, analista);
        }
        
        else{
            quicksortMedianaDeSete(A, inicio, fim, tam, analista);
        }
        }
    }

//Quicksort Selecao

    void Organizador::quicksortSelecao(Registro *A, int n, int esq, int dir, int min, Analista *analista){
        if(n <= min){
            Selecao(A, n, esq, dir, analista);
            return;
        }
        
            int i, j;
            Particao(esq, dir, &i, &j, A, analista);
            quicksortSelecao(A, (n/2) + 1, 0, j, min, analista);
            quicksortSelecao(A, n/2, i, n, min, analista);
        
    }

//Quicksort nao Recursivo

    void  Organizador::quicksortNaoRecursivo(Registro *A, int n, Analista *analista){
        pilha = new Celula[n];
        Celula item;
        int esq, dir, i, j;
        FPVazia();
        esq = 0;
        dir = n - 1;
        item.Dir = dir;
        item.Esq = esq;
        empilha(item, analista);
        do
            if (dir > esq)
            {
                Particao(esq, dir, &i, &j, A, analista);
                if ((j - esq) > (dir - i))
                {
                    item.Dir = j;
                    item.Esq = esq;
                    empilha(item, analista);
                    esq = i;
                }
                else
                {
                    item.Esq = i;
                    item.Dir = dir;
                    empilha(item, analista);
                    dir = j;
                }
            }
            else
            {
                desempilha(&item, analista);
                dir = item.Dir;
                esq = item.Esq;
            }
        while (!vazia());
    }

//Quicksort empilha

    void Organizador::quicksortEmpilha(Registro *A, int n, Analista *analista){
        pilha = new Celula[n];
        Celula item;
        int esq, dir, i, j;
        FPVazia();
        esq = 0;
        dir = n - 1;
        item.Dir = dir;
        item.Esq = esq;
        empilha(item, analista);
        do{
            if (dir > esq)
            {
                Particao(esq, dir, &i, &j, A, analista);
                if ((j - esq) < (dir - i))
                {
                    item.Dir = j;
                    item.Esq = esq;
                    empilha(item, analista);
                    esq = i;
                }
                else
                {
                    item.Esq = i;
                    item.Dir = dir;
                    empilha(item, analista);
                    dir = j;
                }
            }
            else
            {
                desempilha(&item, analista);
                dir = item.Dir;
                esq = item.Esq;
            }
        } while (!vazia());
    }

/*---------------------Mergesort---------------------*/

    void Organizador::merge(Registro *A, int Esq, int meio, int Dir, Analista *analista){
        int subVetorUm = meio - Esq + 1;
        int subVetorDois = Dir - meio;
 
        int *VetorEsq = new int[subVetorUm],
            *VetorDir = new int[subVetorDois];
 
        for (int i = 0; i < subVetorUm; i++){
            VetorEsq[i] = A[Esq + i].chave;
            analista -> analisaCopia();
        }
        
        for (int j = 0; j < subVetorDois; j++){
            VetorDir[j] = A[meio + 1 + j].chave;
            analista -> analisaCopia();
        }
        
 
        int idSubVetorUm = 0;
        int idSubVetorDois = 0;
        int idVetorMerged = Esq;
 
        while (idSubVetorUm < subVetorUm && idSubVetorDois < subVetorDois) {
            if (VetorEsq[idSubVetorUm] <= VetorDir[idSubVetorDois]) {
                A[idVetorMerged].chave = VetorEsq[idSubVetorUm];
                idSubVetorUm++;
                analista -> analisaCopia();
            }
            else {
                A[idVetorMerged].chave = VetorDir[idSubVetorDois];
                idSubVetorDois++;
                analista -> analisaCopia();
            }
            idVetorMerged++;
        }

        while (idSubVetorUm < subVetorUm) {
            A[idVetorMerged].chave = VetorEsq[idSubVetorUm];
            idSubVetorUm++;
            idVetorMerged++;

            analista -> analisaCopia();
        }

        while (idSubVetorDois < subVetorDois) {
            A[idVetorMerged].chave = VetorDir[idSubVetorDois];
            idSubVetorDois++;
            idVetorMerged++;

            analista -> analisaCopia();
        }

        delete[] VetorEsq;
        delete[] VetorDir;
    }
 
    void Organizador::mergeSort(Registro *A, int comeco, int fim, Analista *analista){
        if (comeco >= fim)
            return;
    
        int meio = comeco + (fim - comeco) / 2;
        mergeSort(A, comeco, meio, analista);
        mergeSort(A, meio + 1, fim, analista);
        merge(A, comeco, meio, fim, analista);
    }

/*--------------------Heapsort-----------------------*/


    void Organizador::heapify(Registro *A, int n, int i, Analista *analista){ 

        int maior = i;

        int l = 2 * i + 1;

        int r = 2 * i + 2;
 
        analista -> analisaComp();
        if (l < n && A[l].chave > A[maior].chave) 
            maior = l; 
 
        analista -> analisaComp();
        if (r < n && A[r].chave > A[maior].chave) 
            maior = r; 

        if (maior != i) { 
            troca(A, i, maior, analista); 
            heapify(A, n, maior, analista); 
        } 
    } 

    void Organizador::heapSort(Registro *A, int n, Analista *analista){ 
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(A, n, i, analista); 
        } 

        for (int i = n - 1; i >= 0; i--) 
        { 
            troca(A, 0, i, analista); 
            heapify(A, i, 0, analista); 
        } 
    } 
