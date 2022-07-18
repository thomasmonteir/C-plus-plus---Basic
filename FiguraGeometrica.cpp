#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include <string>


class FiguraGeometrica
{
    public:
        FiguraGeometrica();
        virtual float calcularArea() = 0;
        virtual void lerAtributos() = 0;
        std::string getNome();

    protected:
        std::string nome;
        int tipo;

    private:
};

#endif // FIGURAGEOMETRICA_H

FiguraGeometrica::FiguraGeometrica()
{
    //ctor
}

std::string FiguraGeometrica::getNome()
{
    return nome;
}

#ifndef TRIANGULO_H
#define TRIANGULO_H
//#include "FiguraGeometrica.h"


class Triangulo : public FiguraGeometrica
{
    public:
        Triangulo();
        float calcularArea();
        void lerAtributos();
        float altura;
        float base;

};

#endif // TRIANGULO_H

//#include "Triangulo.h"
#include <iostream>

using namespace std;

Triangulo::Triangulo()
{
  
}

float Triangulo::calcularArea()
{
    return (base*altura)/2;
}

void Triangulo::lerAtributos()
{
    cin >> base;
    cin >> altura;
}

#ifndef QUADRADO_H
#define QUADRADO_H
//#include "FiguraGeometrica.h"


class Quadrado : public FiguraGeometrica
{
    public:
        Quadrado();
        float calcularArea();
        void lerAtributos();
        float lado;
};

#endif // QUADRADO_H

//#include "Quadrado.h"
#include <iostream>

using namespace std;

Quadrado::Quadrado()
{
   
}

float Quadrado::calcularArea()
{
    return lado*lado;
}

void Quadrado::lerAtributos()
{
    cin >> lado;
}

#ifndef RETANGULO_H
#define RETANGULO_H
//#include "FiguraGeometrica.h"


class Retangulo : public FiguraGeometrica
{
    public:
        Retangulo();
        float calcularArea();
        void lerAtributos();
        float ladoMaior;
        float ladoMenor;
};

#endif // RETANGULO_H

//#include "Retangulo.h"
#include <iostream>

using namespace std;

Retangulo::Retangulo()
{
    
}

float Retangulo::calcularArea()
{
    return ladoMaior*ladoMenor;
}

void Retangulo::lerAtributos()
{
    cin >> ladoMaior;
    cin >> ladoMenor;
}

#ifndef CIRCULO_H
#define CIRCULO_H
//#include "FiguraGeometrica.h"


class Circulo : public FiguraGeometrica
{
    public:
        Circulo();
        void lerAtributos();
        float calcularArea();
        float raio;
};

#endif // CIRCULO_H

//#include "Circulo.h"
#include <iostream>

using namespace std;

Circulo::Circulo()
{
    
}

float Circulo::calcularArea()
{
    return 3.14*(raio*raio);
}

void Circulo::lerAtributos()
{
    cin >> raio;
}

using namespace std;

int main()
{
    int type = 1;
    
    FiguraGeometrica *f[4];

    f[0] = new Quadrado();

    f[1] = new Retangulo();

    f[2] = new Triangulo();

    f[3] = new Circulo();

    while(type != 0){
        cin >> type;

        switch(type){
            case 1:
                f[0]->lerAtributos();
                cout << "Quadrado polimórfico de área " << f[0]->calcularArea() << endl;
                break;
            case 2:
                f[1]->lerAtributos();
                cout << "Retângulo polimórfico de área " << f[1]->calcularArea() << endl;
                break;
            case 3:
                f[2]->lerAtributos();
                cout << "Triângulo polimórfico de área " << f[2]->calcularArea() << endl;
                break;
            case 4:
                f[3]->lerAtributos();
                cout << "Círculo polimórfico de área " << f[3]->calcularArea() << endl;
                break;
            default:
                break;
        }
    }

    return 0;
}
