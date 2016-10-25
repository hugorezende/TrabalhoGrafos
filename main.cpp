#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;



/* Defini��o da classe Aresta
 * M�todos
 *      Aresta(int peso, int val, Aresta * prox) -- CONSTRUTOR
 *      getVal()
 *      -- retorna inteiro
 *      -- pega valor da aresta
 *
 *      getProx()
 *      -- retorna * Aresta
 *      -- pega o pr�ximo na lista de adjacencia
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
 * M�TODOS
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
/*DEFINI��O DA CLASSE N�
//=======================
    M�todos:
 * setAresta(Aresta * a);
 *
 *
 * printNo();
 * -- Sem retono
 * -- Printa arestas adjacentes ao n�
 */
class No
{
    int a;
    int grau;
    No* prox;
    Aresta* aresta;
    Aresta * ultimo;

public:

        No(); // construtor default definido pelo usu�rio
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
// ======== M�TODOS N� ===========
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
//Metodo de inser��o de aresta
void No::setAresta(Aresta * a){
    this->aresta = a;
}

//Metodo de inser��o de ponteiro para ultima noAresta
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
// ======== FIM M�TODOS N� ===========
//





//================================
//===== COME�O CLASSE GRAFO  =====
//================================

class Grafo{
     int nNos;
     int nArestas;
     bool flagDir;
     int grauGrafo;
     No * lista;
     No * ultimo;

public:
    //DECLARA��O DOS M�TODOS
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

    void buscaProfundidade();


};

//C�DIGO DOS M�TODOS
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

    //VERIFICANDO SE O N� JA EXISTE NO GRAFO;
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

    //VERIFICA SE A LISTA � VAZIA
    if(lista!=NULL){

    //VERIFICA SE O N� � O PRIMEIRO
    if(lista->getVal()==nVal){
            this->lista = lista->getProx();
        }else{

            //Verifica so existe proximo
            if(lista->getProx()!=NULL){
                //achou a aresta a ser removida
                if(lista->getProx()->getVal()==nVal){

                    //verifica se � a ultima aresta
                    if(lista->getProx()->getProx()!=NULL){
                            lista->setProx(lista->getProx()->getProx());
                        }else{
                         lista->setProx(NULL);
                    }

                //SE N�O � IGUAL VAI PARA O PROXIMO DA LISTA
                }else{
                    this->removeNo(lista->getProx(),nVal);
                }

            }
        }
    }
    //REMOVENDO ARESTAS QUE LINCAVAM NO N�


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

//AUXILIAR Para printat no�s
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



//RETORNA O N� A PARTIR DE BUSCA PELO VALOR DO N�
No * getNo(No * n, int nVal){

    if(n->getVal()==nVal){
        return n;
    }else{
        if(n->getProx()!=NULL){
            getNo(n->getProx(),nVal);
        }
    }
}

//RETORNA O N� A PARTIR DE BUSCA PELO VALOR DA ARESTA
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

    //VERIFICA SE N� J� POSSUI LISTA ENCADEADA DE ARESTAS
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

    //VERIFICA SE N� J� POSSUI LISTA ENCADEADA DE ARESTAS
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
        //chegou ao final da lista sem entrar no N�O.
        printf("Grafo eh K-regular \n");
    }
}

void Grafo::verificaKRegular(){
    int nArestas;
    verificaGraus(this->getLista(),this->getLista()->getGrau());


}


//DECLARANDO AS FUN��ES
void buscaNoP(No * no, int busca, No * lista, bool *visitados);
void verificaProxAresta(Aresta * aresta, int busca, No * lista, bool *visitados);



void verificaProxAresta(Aresta * aresta, int busca, No * lista, bool *visitados){
    if(visitados[aresta->getVal()]==true){
        printf("%d->",aresta->getVal());
        verificaProxAresta(aresta->getProx(),busca,lista,visitados);
    }else{
        printf("%d->",aresta->getVal());
        No * findNo = getNo(lista,aresta->getVal());
        buscaNoP(findNo, busca, lista, visitados);
    }
}

void buscaNoP(No * no, int busca, No * lista, bool *visitados){

    visitados[no->getVal()] = true;

    if(no->getVal()!=busca){
        if(no->getAresta()!=NULL){

            printf("%d->",no->getAresta()->getVal());
            No * findNo = getNo(lista,no->getAresta()->getVal());

            //VERIFICA SE N� AINDA NAO FOI VISITADO
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
}

void Grafo::buscaProfundidade(){

    bool visitados[10] = {false};
    int busca = 7;

    //visitados[1] = 22;

    No * findNo = getNo(this->lista,1);

    buscaNoP(findNo,busca,this->lista, visitados);

    for(int i=0;i<10;i++){
        printf("visitado: %d - %d \n",i,visitados[i]);
    }

}



//================================
//======= FIM CLASSE GRAFO  ======
//================================




//FUN��O CRIA GRAFO
//PARAMETROS
//int nNos = Numero de n�s do Grafo
//array




 int main(int argc, char** argv){


   /*
    * ======= INICIO PROCEDIMENTO DE CARREGAR AQUIVO ======
    *
    * */


    std::ifstream file("FileArvore.txt");
    int number_of_lines = 0;
    string line;

    while (file.good()){
        getline(file, line);
        ++number_of_lines;

	}
	//PEGANDO NA PRIMEIRA LINHA DO ARQUIVO O NUMERO DE N�S
    int nNos;
    file.clear();
    file.seekg(0, ios::beg);
    if(file.is_open()){
        file >> nNos;
    }

    Grafo gr = Grafo(nNos,NULL,true,0,NULL,NULL);


    //Criando lista encadeada dos n�s
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

            // === verifica se existe o n�
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
            gr.buscaProfundidade();

        }

    }



}
