#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <stack>

using namespace std;



/* Definição da classe Aresta
 * Métodos
 *      Aresta(int peso, int val, Aresta * prox) -- CONSTRUTOR
 *      getVal()
 *      -- retorna inteiro
 *      -- pega valor da aresta
 *
 *      getProx()
 *      -- retorna * Aresta
 *      -- pega o próximo na lista de adjacencia
 *
 *
 * */

const int SIZE = 100;


 /*
  * ======= DEFININDO CLASSE ARESTA ======
  *
  */

class Aresta{
    int peso;
    int val;
    Aresta * prox;


public:
    Aresta();
    Aresta(int peso, int val, Aresta * prox);
    int getVal();
    void setProx(Aresta * prox);
    Aresta * getProx();
    void printLista(Aresta * a);
};

/*
 * MÉTODOS
*/

Aresta::Aresta(){

};

Aresta::Aresta(int peso, int val, Aresta * prox){
    this->peso = peso;
    this->val = val;
    this->prox = prox;

};

int Aresta::getVal(){
    return this->val;
}

void Aresta::setProx(Aresta * prox){
    this->prox = prox;
}

Aresta * Aresta::getProx(){
    return this->prox;
}

void Aresta::printLista(Aresta * a){
    if(a->getProx()!=NULL){
        printf(" -> %d",a->getProx()->getVal());
        printLista(a->getProx());
    }else{
        printf("\n\n");
    }
}

/*
======= END CLASSE ARESTA ======
*/




//=======================
/*DEFINIÇÃO DA CLASSE NÓ
//=======================
    Métodos:
 * setAresta(Aresta * a);
 *
 *
 * printNo();
 * -- Sem retono
 * -- Printa arestas adjacentes ao nó
 */
class No
{
    int a;
    int grau;
    No* prox;
    Aresta* aresta;
    Aresta * ultimo;

public:

        No(); // construtor default definido pelo usuário
        No(int a, int grau, No* prox, Aresta * aresta);
        int getVal();

        int getGrau();
        void setGrau(int grau);

        No* getProx();
        Aresta* getAresta();
        Aresta* getUltimo();
        void setProx(No * no);
        void setAresta(Aresta * a);
        void setUltimo(Aresta * a);
        void printNoArestas();
};



//
// ======== MÉTODOS NÓ ===========
//

No* No::getProx(){
    return this->prox;
}

int No::getVal(){
    return this->a;
};


int No::getGrau(){
    return this->grau;
};

void No::setGrau(int grau){
    this->grau = grau;
};

Aresta * No::getAresta(){
    return this->aresta;
}

Aresta * No::getUltimo(){
    return this->ultimo;
}

void No::setProx(No * no){
    this->prox = no;
}
//Metodo de inserção de aresta
void No::setAresta(Aresta * a){
    this->aresta = a;
}

//Metodo de inserção de ponteiro para ultima noAresta
void No::setUltimo(Aresta * a){
    this->ultimo = a;
}


void No::printNoArestas(){
    printf("%d",this->a);

    if(this->aresta!=NULL){
        printf(" -> %d",this->aresta->getVal());
        this->aresta->printLista(this->aresta);

    }else{
        printf("\n\n");
    }

}

//====== CONTRUTOR ==========
No::No()
{
};

No::No(int a, int grau, No * prox, Aresta * aresta){
    this->a = a;
    this->prox = prox;
    this->aresta = aresta;
    this->grau = grau;
}


//
// ======== FIM MÉTODOS NÓ ===========
//





//================================
//===== COMEÇO CLASSE GRAFO  =====
//================================

class Grafo{
     int nNos;
     int nArestas;
     bool flagDir;
     int grauGrafo;
     No * lista;
     No * ultimo;

public:
    //DECLARAÇÃO DOS MÉTODOS
    Grafo();
    Grafo(int nNos, int nArestas, bool flagDir, int grauGrafo, No * lista,No * ultimo);

    int getnNos();
    void setnNos(int nNos);

    int getGrau();
    void setGrau(int grauGrafo);

    int getnArestas();
    void setnArestas(int nArestas);

    No * getLista();
    void printGrafo();


    No * getNoGrafo(int nVal);

    void addNo(No * no);
    void removeNo(No* lista, int nVal);

    void addAresta(Aresta * a, int n);
    void removeAresta(No * no, Aresta * a, int n);
    void removeTodaAresta(No * no, Aresta * a, int n);
    void verificaKRegular();

    void buscaProfundidade(int v);


};

//CÓDIGO DOS MÉTODOS
Grafo::Grafo(){

}

Grafo::Grafo(int nNos, int nArestas, bool flagDir, int grauGrafo, No * lista, No * ultimo){
        this->nNos = nNos;
        this-> nArestas = nArestas;
        this->flagDir = flagDir;
        this->grauGrafo = grauGrafo;
        this->lista= lista;
        this->ultimo = ultimo;
}

void Grafo::addNo(No * no){

    //VERIFICANDO SE O NÓ JA EXISTE NO GRAFO;
    //if(this->getNoGrafo(no->getVal()) !=NULL){

        if(this->ultimo==NULL){
            this->lista = no;
            this->ultimo = no;
        }else{
            this->ultimo->setProx(no);
            this->ultimo = no;
        }

    //}
}


void Grafo::removeNo(No * lista, int nVal){

    //VERIFICA SE A LISTA É VAZIA
    if(lista!=NULL){

    //VERIFICA SE O NÓ É O PRIMEIRO
    if(lista->getVal()==nVal){
            this->lista = lista->getProx();
        }else{

            //Verifica so existe proximo
            if(lista->getProx()!=NULL){
                //achou a aresta a ser removida
                if(lista->getProx()->getVal()==nVal){

                    //verifica se é a ultima aresta
                    if(lista->getProx()->getProx()!=NULL){
                            lista->setProx(lista->getProx()->getProx());
                        }else{
                         lista->setProx(NULL);
                    }

                //SE NÃO É IGUAL VAI PARA O PROXIMO DA LISTA
                }else{
                    this->removeNo(lista->getProx(),nVal);
                }

            }
        }
    }
    //REMOVENDO ARESTAS QUE LINCAVAM NO NÓ


}

int Grafo::getnNos(){
    return this->nNos;
}
void Grafo::setnNos(int nNos){
    this->nNos = nNos;
}


int Grafo::getGrau(){
    return this->grauGrafo;
}
void Grafo::setGrau(int grauGrafo){
    this->grauGrafo = grauGrafo;
}



int Grafo::getnArestas(){
    return  this->nArestas;
}

void Grafo::setnArestas(int nArestas){
    this->nArestas = nArestas;
}

No * Grafo::getLista(){
    return this->lista;
}

//AUXILIAR Para printat noós
void printNo_(No * n){


        n->printNoArestas();
        if(n->getProx()!=NULL){
            printNo_(n->getProx());
        }

}

//printa grafo na tela
void Grafo::printGrafo(){

   printNo_(this->lista);
        //this->lista->printNo();


}



//RETORNA O NÓ A PARTIR DE BUSCA PELO VALOR DO NÓ
No * getNo(No * n, int nVal){

    if(n->getVal()==nVal){
        return n;
    }else{
        if(n->getProx()!=NULL){
            getNo(n->getProx(),nVal);
        }
    }
}

//RETORNA O NÓ A PARTIR DE BUSCA PELO VALOR DA ARESTA
Aresta * getAresta(Aresta * n, int nVal){

    if(n->getVal()==nVal){
        return n;
    }else{
        if(n->getProx()!=NULL){
            getAresta(n->getProx(),nVal);
        }
    }
}



No * Grafo::getNoGrafo(int nVal){
    return getNo(this->lista, nVal);
}



void Grafo::addAresta(Aresta * a, int n){



    No * findNo = getNo(this->lista,n);

    //VERIFICA SE NÓ JÁ POSSUI LISTA ENCADEADA DE ARESTAS
    //SE NAO POSSI LISTA ENCADEADA, COLOCA ARESTA NO NO, E APONTA ULTIMO PARA A MESMA ARESTA
    if(findNo->getAresta()==NULL){
           findNo->setAresta(a);
           findNo->setUltimo(a);
    }else{
            findNo->getUltimo()->setProx(a);
            findNo->setUltimo(a);
    }
    findNo->setGrau(findNo->getGrau()+1);


}


void Grafo::removeTodaAresta(No * no, Aresta * a, int n){
        if(no!=NULL){

            this->removeAresta(no,a,n);
            if(no->getProx()!=NULL){
                this->removeAresta(no->getProx(),no->getProx()->getAresta(),n);
            }
        }


}

void Grafo::removeAresta(No * no, Aresta * a, int n){

    //se for o primeiro
    if(no->getAresta()->getVal()==n){
        no->setAresta(no->getAresta()->getProx());
    }else{
        if(a->getProx()->getVal()==n){
            a->setProx(a->getProx()->getProx());
        }else{
            if(no->getProx()!=NULL){
                this->removeAresta(no->getProx(),a->getProx(),n);

            }
        }

    }

    //VERIFICA SE NÓ JÁ POSSUI LISTA ENCADEADA DE ARESTAS
    //SE NAO POSSI LISTA ENCADEADA, COLOCA ARESTA NO NO, E APONTA ULTIMO PARA A MESMA ARESTA

    /*
        if(a->getVal()==n){
                no->setAresta(a->getProx());
        }else{
        if(a->getProx()!=NULL){
                if(a->getProx()->getVal()==n){
                            a->setProx(a->getProx()->getProx());
                    }else{
                        this->removeAresta(no,a->getProx(),n);
                }
            }
        }
         * */




}




void verificaGraus(No * no, int grau){
    if(no!=NULL){
        if(no->getGrau()==grau){
        //printf("Igual \n");
        verificaGraus(no->getProx(),grau);
        }else{
        printf("Grafo nao eh K-Regular \n");
        }
    }else{
        //chegou ao final da lista sem entrar no NÃO.
        printf("Grafo eh K-regular \n");
    }
}

void Grafo::verificaKRegular(){
    int nArestas;
    verificaGraus(this->getLista(),this->getLista()->getGrau());


}


//DECLARANDO AS FUNÇÕES
void buscaNoP(No * no, int busca, No * lista, bool *visitados);
void verificaProxAresta(Aresta * aresta, int busca, No * lista, bool *visitados);



void verificaProxAresta(Aresta * aresta, int busca, No * lista, bool *visitados){
    if(visitados[aresta->getVal()]==true){
        printf("%d->",aresta->getVal());
        verificaProxAresta(aresta->getProx(),busca,lista,visitados);
    }else{
        printf("%d->",aresta->getVal());
        No * findNo = getNo(lista,aresta->getVal());

        //se a proxima aresta no ramo nao é vazia
        visitados[aresta->getVal()]=true;
        buscaNoP(findNo, busca, lista, visitados);
            //alguma coisa

    }
}

void buscaNoP(No * no, int busca, No * lista, bool *visitados){

    if(visitados[no->getVal()] != true){

        visitados[no->getVal()] = true;
        if(no->getVal()!=busca){
            if(no->getAresta()!=NULL){

                printf("%d->",no->getAresta()->getVal());
                No * findNo = getNo(lista,no->getAresta()->getVal());

                //VERIFICA SE NÓ AINDA NAO FOI VISITADO
                if(visitados[no->getAresta()->getVal()]==false){
                    buscaNoP(findNo,busca,lista,visitados);
                }else{
                    verificaProxAresta(no->getAresta()->getProx(),busca,lista, visitados);
                }

            }else{
                printf("Nao tem mais\n");
            }
        }else{
                printf("Encontrou %d \n",no->getVal());
        }
    }else{
        //SE NO JÁ FOI VISITADO
    }
}

void Grafo::buscaProfundidade(int v){
    stack<int> pilha;
    bool visitados[50000] = {false};
    int busca = 7;



    //visitados[1] = 22;
    pilha.push(v);
    No * findNo;
    Aresta * aresta;

    findNo = getNo(this->lista,v);
    aresta = findNo->getAresta();
    visitados[v]=true;
    printf("visitado: %d \n",v);

    while(true){


    //verifica se aresta ja foi visitada
        if(visitados[aresta->getVal()]==false){
            //marca aresta como visitada
            visitados[aresta->getVal()]=true;
            printf("visitado: %d \n",aresta->getVal());

            v = aresta->getVal();
            pilha.push(v);
            aresta = getNo(this->lista,v)->getAresta();


        }else{
            //se proximo da aresta ja foi visitado
            //verifica se existe aresta pra frente
            if(aresta->getProx()!=NULL){
                aresta = aresta->getProx();
            }else{
                //se nao existe para while

                pilha.pop();
                if(!pilha.empty()){
                    aresta =  getNo(this->lista,pilha.top())->getAresta();
                }else{
                    break;
                }
            }

        }
    }


}



//================================
//======= FIM CLASSE GRAFO  ======
//================================




//FUNÇÃO CRIA GRAFO
//PARAMETROS
//int nNos = Numero de nós do Grafo
//array




 int main(int argc, char** argv){


   /*
    * ======= INICIO PROCEDIMENTO DE CARREGAR AQUIVO ======
    *
    * */


    std::ifstream file("File.txt");
    int number_of_lines = 0;
    string line;

    while (file.good()){
        getline(file, line);
        ++number_of_lines;

	}
	//PEGANDO NA PRIMEIRA LINHA DO ARQUIVO O NUMERO DE NÓS
    int nNos;
    file.clear();
    file.seekg(0, ios::beg);
    if(file.is_open()){
        file >> nNos;
    }

    Grafo gr = Grafo(nNos,NULL,true,0,NULL,NULL);


    //Criando lista encadeada dos nós
    for (int i = 1; i<nNos+1; ++i){

        No * addNo = new No(i,0,NULL,NULL);
        gr.addNo(addNo);

    }



    printf("Numero de nos: %d \n",nNos);

    file.clear();
    file.seekg(1, ios::beg);
    int number_of_arestas = 0;



    int start_s=clock();
    while (file.good()){
            getline(file, line);
            ++number_of_arestas;

                int n1,n2;
                file >> n1;
                file >> n2;

                Aresta * a1 = new Aresta(NULL,n1,NULL);
                Aresta * a2 = new Aresta(NULL,n2,NULL);
                //INSERINDO A IDA E A VOLTA

                gr.addAresta(a1,n2);
                gr.addAresta(a2,n1);


    }


    int stop_s=clock();
    cout << "Tempo para criar grafo: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

    printf("Numero de arestas: %d \n",number_of_arestas);


    printf("=== Trabalho Grafos ===\n\n");
    printf("1 - Inserir Grafo\n");
    printf("2 - Listar Grafo\n");
    printf("3 - Add Aresta \n");
    printf("4 - Remove Aresta \n");
    printf("5 - Remove No \n");
    printf("7 - Verifica K-regular \n");
    printf("8 - Busca Profundidade \n");
    while(1){
    printf("Comando: ");
    int cmdg;
    scanf("%d", &cmdg);


    if(cmdg==2){

        gr.printGrafo();

    }

    if(cmdg==3){

        printf("Digite o no: ");
        int _no;
        cin >> _no;

        printf("Digite o valor: ");
        int _valor;
        cin >> _valor;


    }

     if(cmdg==4){
            printf("Digite o no: ");
            int _no;
            cin >> _no;

            printf("Digite a aresta: ");
            int _aresta;
            cin >> _aresta;

            // === verifica se existe o nó
            if(gr.getNoGrafo(_no)!=NULL){
                gr.removeAresta(gr.getNoGrafo(_no),gr.getNoGrafo(_no)->getAresta(),_aresta);
            //REMOVENDO A VOLTA
            }
            if(gr.getNoGrafo(_aresta)!=NULL){
                gr.removeAresta(gr.getNoGrafo(_aresta),gr.getNoGrafo(_aresta)->getAresta(),_no);
           }
        }


        if(cmdg==5){
            printf("Digite o no a ser removido");
            int _no;
            cin >> _no;
            gr.removeNo(gr.getLista(),_no);
            //gr.removeTodaAresta(gr.getLista(),gr.getLista()->getAresta(),_no);

        }

        if(cmdg==6){
            printf("Digite o no a ser removido");
            int _no;
            cin >> _no;
            //gr.removeNo(gr.getLista(),_no);
            gr.removeTodaAresta(gr.getLista(),gr.getLista()->getAresta(),_no);

        }

         if(cmdg==7){

            //gr.removeNo(gr.getLista(),_no);
            gr.verificaKRegular();

        }

        if(cmdg==8){

            //gr.removeNo(gr.getLista(),_no);
            gr.buscaProfundidade(1);

        }

    }



}
