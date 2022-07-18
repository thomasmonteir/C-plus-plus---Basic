#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>


class Endereco
{
    public:
        Endereco();
        virtual ~Endereco();

        void setDados();

        const std::string toString() const
        {

            std::ostringstream buffer;
            buffer << std::fixed << std::showpoint
            << rua << ", " << numero << ", " << bairro << ". " << cidade << " - " << estado << ". CEP: " << cep << std::endl<< std::endl;

            return buffer.str();
        }

    protected:

    private:
        std::string rua;
        std::string numero;
        std::string bairro;
        std::string cidade;
        std::string estado;
        std::string cep;
};

Endereco::Endereco()
{
    //ctor
}

Endereco::~Endereco()
{
    //dtor
}

void Endereco::setDados()
{
    getline(std::cin,rua);
    getline(std::cin,numero);
    getline(std::cin,bairro);
    getline(std::cin,cidade);
    getline(std::cin,estado);
    getline(std::cin,cep);
}



class Pessoa
{
    public:
        Pessoa(std::string nome,Endereco endereco,std::string tel);
        virtual ~Pessoa();

        void setNome(std::string n);
        void setEndereco(Endereco e);
        void setTel(std::string t);
        std::string getNome();
        Endereco getEndereco();
        std::string getTel();

        const std::string toString() const
        {

            std::ostringstream buffer;
            buffer << std::fixed << std::showpoint
            << nome << ", " << tel << std::endl;

            return buffer.str();
        }


    protected:

    private:

        std::string nome;
        Endereco endereco;
        std::string tel;

};


#include <string>

Pessoa::Pessoa(std::string nome,Endereco endereco,std::string tel)
{
    this->nome = nome;
    this->endereco = endereco;
    this->tel = tel;
}

Pessoa::~Pessoa()
{
    //dtor
}


void Pessoa::setNome(std::string n){

    nome = n;

}
void Pessoa::setEndereco(Endereco e){

    endereco = e;

}
void Pessoa::setTel(std::string t){

    tel = t;

}

std::string Pessoa::getNome(){

    return nome;

}
Endereco Pessoa::getEndereco(){

    return endereco;

}
std::string Pessoa::getTel(){

    return tel;

}

#include <string>

//#include "Endereco.h"
//#include "Pessoa.h"

using namespace std;

int main()
{

    Endereco a;
    std::string nome,tel;
    Pessoa b(nome,a,tel);

    int c;


    std::cin >> c;
    std::cin.ignore();

    for(int i = 0;i < c;i++){
    getline(cin,nome);
    b.setNome(nome);
    fflush(stdout);
    getline(cin,tel);
    b.setTel(tel);
    a.setDados();
    std::cout << b.toString();
    std::cout << a.toString();
    }

    return 0;
}
