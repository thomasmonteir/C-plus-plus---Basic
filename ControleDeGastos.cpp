#include <string>

using namespace std;

class Despesa
{
public:
    Despesa();

    void setNome(string nome);
    void setValor(float valor);
    void setTipoDeGasto(string setTipoDeGasto);

    string getNome();
    float getValor();
    string getTipoDeGasto();    

private:
    string nome;
    float valor;
    string tipoDeGasto;

};


Despesa::Despesa(){
    valor = 0;
}

void Despesa::setNome(string nome){
    this-> nome = nome;
}

void Despesa::setValor(float valor){
    this-> valor = valor;
}

void Despesa::setTipoDeGasto(string tipo){
    tipoDeGasto = tipo;
}

string Despesa::getNome(){
    return nome;
}

float Despesa::getValor(){
    return valor;
}

string Despesa::getTipoDeGasto(){
    return tipoDeGasto;
}  

using namespace std;

class ControleDeGastos
{
public:
    ControleDeGastos();

    void setDespesa(Despesa d, int pos);
    Despesa getDespesa(int pos);
    float calcultaTotalDespesas();
    float calculaTotalDespesas(string tipo);
    bool existeDespesaDoTipo(string tipo);
    
private:
    Despesa despesas[100];

};

#include <iostream>

using namespace std;

ControleDeGastos::ControleDeGastos(){
    for(int i = 0; i < 100; i++){
       despesas[i].setValor(0);
    }
    
}

void ControleDeGastos::setDespesa(Despesa d, int pos){
    despesas[pos] = d;
}

Despesa ControleDeGastos::getDespesa(int pos){
    return despesas[pos];
}

float ControleDeGastos::calcultaTotalDespesas(){
    float total = 0;

    for(int i = 0; i < 100; i++){
        total = total + despesas[i].getValor();
    }

    return total;

}
float ControleDeGastos::calculaTotalDespesas(string tipo){
    float custo = 0;

    for(int i = 0; i < 100; i++){
        if(despesas[i].getTipoDeGasto() == tipo){
            custo += despesas[i].getValor();
        }
    }

    return custo;

}

bool ControleDeGastos::existeDespesaDoTipo(string tipo){

    for(int i = 0; i < 100; i++){
        if(despesas[i].getTipoDeGasto() == tipo){
            return true;
        }
    }

    return false;

}

using namespace std;

int main(){
    int N;
    string nome, tipo;
    float valor;

    ControleDeGastos buscar;

    cin >> N;
    cin.ignore();

    Despesa conta[N];
    
    for(int i = 0; i < N; i++){
        getline(cin, tipo);
        conta[i].setNome(tipo);

        cin >> valor;
        cin.ignore();
        conta[i].setValor(valor);       

        getline(cin, tipo);
        conta[i].setTipoDeGasto(tipo);

        buscar.setDespesa(conta[i], i);
    }

    cin >> tipo;    

    if(buscar.existeDespesaDoTipo(tipo)){
        for(int i = 0; i < N; i++){
            if(conta[i].getTipoDeGasto() == tipo){
                cout << conta[i].getNome() << ", " << "R$ " << conta[i].getValor() << endl;
            }
        }        

    }else{
        cout << "Nenhuma despesa do tipo especificado" << endl;

    }

    cout << "Total: " << buscar.calculaTotalDespesas(tipo) << "/" <<  buscar.calcultaTotalDespesas() << endl;

    return 0;
}
