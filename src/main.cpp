/*
-----------------------------------------------------
Arquivo Main.cpp referente ao TP2
Materia Estrutura de Dados
Semestre 2022/02

Aluna: Maria Clara Oliveira Domingos Ruas
Matricula: 2021019572
-----------------------------------------------------

Projeto de organizacao de vetores


*/

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <chrono>
#include <ctime> 
#include "Organizador.hpp"
#include "Celula.hpp"
#include "Registro.hpp"
#include "CadeiaString.hpp"
#include "Analista.hpp"


#include "memlog.h"


using namespace std;
char LOGNOME[100];
int RANGE = 0;



int main(int argc, char *argv[]) {
  /*
  Descricao: programa principal da aplicacao
  Entradas: 
  Saídas: 0
  */

  std::string i = "-i";
  std::string o = "-o";
  std::string v = "-v";
  std::string s = "-s";
  std::string k = "-k";
  std::string m = "-m";
  std::string l = "-l";
  std::string p = "-p";
  std::string nomeArqIn;
  std::string nomeArqOut;
  int med, seed, version, tamSel, qntTestes, tamVetor;
  Organizador org;
  Registro * teste;
  Analista analista;
  

  for(int j = 0; j < argc; j++){
    if(argv[j] == v){
      version = std::stoi(argv[j + 1]);
    }

    if(argv[j] == s){
      seed = std::stoi(argv[j + 1]);
    }

    if(argv[j] == k){
      med = std::stoi(argv[j + 1]);
    }

    if(argv[j] == m){
      tamSel = std::stoi(argv[j + 1]);
    }

    if(argv[j] == i){
      nomeArqIn = argv[j + 1];
    }

    if(argv[j] == o){
      nomeArqOut = argv[j + 1];
    }

    //Comando para geracao de log
    /*
    if(argv[j] == l){
      RANGE = 1;
    }
    if(argv[j] == p){
      strcpy(LOGNOME, argv[j + 1]);
    }
    */
    
  }

  /*
  iniciaMemLog(LOGNOME);

  if(RANGE){
    ativaMemLog();
  }
  else{
    desativaMemLog();
  }
  */

  srand(seed);

  std::ifstream MyReadFile(nomeArqIn);
  std::ofstream MyWriteFile(nomeArqOut);

  MyReadFile >> qntTestes;

  for (int i = 0; i < qntTestes; i++)
  {
    MyReadFile >> tamVetor;
    teste = new Registro[tamVetor];
    if(version == 1){
        org.criaVetorAleatorio(teste, tamVetor);
        analista.pegaTempoIncial();
        org.quicksortRecursivo(teste, tamVetor, &analista);
        analista.pegaTempoFinal();
        MyWriteFile << "v " << version << " " << analista.getTempo().count() << " " << analista.getComp() << " " << analista.getCopia() << "\n";
        analista.reset();
    }

    if(version == 2){
        org.criaVetorAleatorio(teste, tamVetor);
        analista.pegaTempoIncial();
        org.quicksortMediana(teste, 0, tamVetor - 1, med, tamVetor, &analista);
        analista.pegaTempoFinal();
        MyWriteFile << "v " << version << " " << analista.getTempo().count() << " " << analista.getComp() << " " << analista.getCopia() << "\n";
        analista.reset();
    }

    if(version == 3){
        org.criaVetorAleatorio(teste, tamVetor);
        analista.pegaTempoIncial();
        org.quicksortSelecao(teste, tamVetor, 0, tamVetor - 1, tamSel, &analista);
        analista.pegaTempoFinal();
        MyWriteFile << "v " << version << " " << analista.getTempo().count() << " " << analista.getComp() << " " << analista.getCopia() << "\n";
        analista.reset();
    }

    if(version == 4){
        org.criaVetorAleatorio(teste, tamVetor);
        analista.pegaTempoIncial();
        org.quicksortNaoRecursivo(teste, tamVetor, &analista);
        analista.pegaTempoFinal();
        MyWriteFile << "v " << version << " " << analista.getTempo().count() << " " << analista.getComp() << " " << analista.getCopia() << "\n";
        analista.reset();
    }

    if(version == 5){
        org.criaVetorAleatorio(teste, tamVetor);
        analista.pegaTempoIncial();
        org.quicksortEmpilha(teste, tamVetor, &analista);
        analista.pegaTempoFinal();
        MyWriteFile << "v " << version << " " << analista.getTempo().count() << " " << analista.getComp() << " " << analista.getCopia() << "\n";
        analista.reset();
    }

    if(version == 6){
        org.criaVetorAleatorio(teste, tamVetor);
        analista.pegaTempoIncial();
        org.mergeSort(teste, 0, tamVetor - 1, &analista);
        analista.pegaTempoFinal();
        MyWriteFile << "v " << version << " " << analista.getTempo().count() << " " << analista.getComp() << " " << analista.getCopia() << "\n";
        analista.reset();
    }
    if(version == 7){
        std::cout << i << std::endl;
        org.criaVetorAleatorio(teste, tamVetor);
        analista.pegaTempoIncial();
        org.heapSort(teste, tamVetor, &analista);
        analista.pegaTempoFinal();
        MyWriteFile << "v " << version << " " << analista.getTempo().count() << " " << analista.getComp() << " " << analista.getCopia() << "\n";
        analista.reset();
    }

  }
  
  MyReadFile.close();
  MyWriteFile.close();



  free(teste);

  //return finalizaMemLog();
  return 0;
}
