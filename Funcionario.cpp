#include <iostream>
#include <string>

class Funcionario
{
    public:
        Funcionario();

        int getMatricula();
        void setMatricula(int m);

        std::string getNome();
        void getNome(std::string n);

        float getSalario();
        void getSalario(float s);

        virtual void getDados();
        virtual void showDados();

    protected:

        int matricula;
        std::string nome;
        int salario;

    private:
};

#include <stdio.h>

Funcionario::Funcionario()
{
    //ctor
}


int Funcionario::getMatricula(){

    return matricula;
}

void Funcionario::setMatricula(int m){

    matricula = m;
}

std::string Funcionario::getNome(){

    return nome;

}

void Funcionario::getNome(std::string n){

     nome = n;
}

float Funcionario:: getSalario(){

    return salario;
}

void Funcionario::getSalario(float s){

    salario = s;

}

void Funcionario::getDados(){

    std::cin >> matricula;
    std::cin.ignore();
    getline(std::cin,nome);
    fflush(stdout);
    std::cin >> salario;
    std::cin.ignore();
}

void Funcionario::showDados(){

    std::cout << getMatricula() << " - " << nome << " - R$ " << getSalario() << std::endl;

}

#include <iostream>

class Consultor : public Funcionario
{
    public:
        Consultor();

        float getSalario();

        float getSalario(float percentual);


    protected:

    private:
};

Consultor::Consultor()
{
    //ctor
}

float Consultor:: getSalario(){

    return salario + salario *  0.1;
}

float Consultor:: getSalario(float percent){

     return getSalario() + getSalario() * percent;
}


#include <iostream>
#include <string>


int main()
{
    Funcionario *c[1];
    
    c[1] = new Consultor();

    c[0]->getDados();
    c[1]->getDados();

    c[0]->showDados();
    c[1]->showDados();
    return 0;
}

