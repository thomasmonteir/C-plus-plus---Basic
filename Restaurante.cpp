#ifndef PEDIDO_H
#define PEDIDO_H
#include <string>
#include <iostream>

class Pedido
{
    public:

        Pedido();
        Pedido(int numero,std::string descricao,int quant ,double preco);
        virtual ~Pedido();

        virtual double getTotal();
        int getNumero();
        std::string getDescricao();
        int getQuant();
        double getPreco();
        void setNumero(int n);
        void setDescricao(std::string d);
        void setQuant(int q);
        void setPreco(double p);

    protected:

    private:
        int numero;
        std::string descricao;
        int quant;
        double preco;
};

#endif // PEDIDO_H

//#include "Pedido.h"

Pedido::Pedido()
{

}

Pedido::Pedido(int n,std::string d,int q ,double p)
{
    numero = n;
    descricao = d;
    quant = q;
    preco = p;
}

Pedido::~Pedido()
{
    //dtor
}

double Pedido::getTotal(){
    float preco2;
    preco2 = quant * preco;

    return preco2;

}

int Pedido::getNumero(){

    return numero;

}

std::string Pedido::getDescricao(){

    return descricao;

}

int Pedido::getQuant(){

    return quant;

}

double Pedido::getPreco(){

    return preco;

}

void Pedido::setNumero(int n){

    numero = n;

}

void Pedido::setDescricao(std::string d){

    descricao = d;

}

void Pedido::setQuant(int q){

    quant = q;

}

void Pedido::setPreco(double p){

    preco = p;

}

#ifndef MESADERESTAURANTE_H
#define MESADERESTAURANTE_H
//#include "Pedido.h"


class MesaDeRestaurante : public Pedido
{
    public:
        MesaDeRestaurante();

        virtual void adicionaPedido(Pedido p);
        void zeraPedidos();
        double calculaTotal();
        void exibeConta();

    private:
        Pedido pedidos[100];
};

#endif // MESADERESTAURANTE_H

//#include "MesaDeRestaurante.h"
#include <iostream>

using namespace std;


MesaDeRestaurante::MesaDeRestaurante()
{
    //ctor
}

void MesaDeRestaurante::adicionaPedido(Pedido p){
    int mudou = 0;

    for(int i = 0; i < 100; i++){
        if(pedidos[i].getDescricao() == p.getDescricao()){
            pedidos[i].setQuant(p.getQuant() + pedidos[i].getQuant());
            mudou = 1;
            break;
        }
    }

    if(mudou == 0){
        for(int i = 0; i < 100; i++){
            if(pedidos[i].getQuant() == 0){
                pedidos[i] = p;
                break;
            }
        }
    }
}

void MesaDeRestaurante::zeraPedidos(){
    for(int i = 0; i < 100; i++){
        pedidos[i].setQuant(0);
    }
}

double MesaDeRestaurante::calculaTotal(){
    double total = 0;

    for(int i = 0; i < 100; i++){
        total += pedidos[i].getTotal();
    }
    return total;
}

void MesaDeRestaurante::exibeConta(){
    for(int i = 0; i < 100; i++){
        if(pedidos[i].getQuant() != 0){
            cout << pedidos[i].getNumero() << " - " << pedidos[i].getDescricao() << " - " <<
            pedidos[i].getQuant() << " - " << pedidos[i].getPreco() << " - R$ " << pedidos[i].getTotal() << endl;
        }
    }
}

#ifndef RESTAURANTE_H
#define RESTAURANTE_H
//#include "MesaDeRestaurante.h"

class Restaurante : public MesaDeRestaurante
{
    public:
        Restaurante();

        MesaDeRestaurante mesas[20];

        void adicionaPedido(Pedido p, int indMesa);
        double calculaTotalRestaurante();
        MesaDeRestaurante getMesa(int indMesa);
        void exibeConta2();

};

#endif // RESTAURANTE_H

//#include "Restaurante.h"
//#include "MesaDeRestaurante.h"
#include <iostream>

using namespace std;

Restaurante::Restaurante()
{
    //ctor
}

void Restaurante::adicionaPedido(Pedido p, int indMesa){
    mesas[indMesa].adicionaPedido(p);
}

double Restaurante::calculaTotalRestaurante(){
    double total = 0;

    for(int i = 0; i < 20; i++){
       if(mesas[i].calculaTotal() > 0){
            total += mesas[i].calculaTotal();
       }
    }

    return total;
}

MesaDeRestaurante Restaurante::getMesa(int indMesa){
    return mesas[indMesa];
}

void Restaurante::exibeConta2(){
    int i;
    for(i = 0; i < 20; i++){
        if(mesas[i].calculaTotal() > 0){
            cout << "Mesa " << i << endl;
            mesas[i].exibeConta();
            cout << "Total: R$ " << mesas[i].calculaTotal() << "\n" << endl;
        }
    }
}

int main()
{
    int numItem, numMesa, quantPedido;
    double preco; //totalPedido;
    string descricao;
    Restaurante restaurante;

    for(int i = 0; i < 20; i++){
        restaurante.mesas[i].zeraPedidos();
    }


   while(1){

        cin >> numItem;
        if(numItem < 0){
            break;
        }

        cin.ignore();
        getline(cin, descricao);
        cin >> quantPedido;
        cin >> preco;
        cin >> numMesa;
        cin.ignore();
        //if( quantPedido < 0 || preco < 0 || numMesa < 0){
        //    break;
        //}

        Pedido p(numItem, descricao, quantPedido, preco);
        restaurante.adicionaPedido(p, numMesa);

    }

    restaurante.exibeConta2();
    cout << "Total Restaurante: R$ " << restaurante.calculaTotalRestaurante() << endl;


    return 0;
}
