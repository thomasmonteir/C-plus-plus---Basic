#include <iostream>

using namespace std;


int main(){

    int sal,empre,parc;
    float f,div,porcen;

    do{

    cin >> sal;

    }while(sal <= 0);

    do{

    cin >> empre;

    }while(empre <= 0);

    do{

    cin >> parc;

    }while(parc <= 0);


    div = empre*1.0/parc*1.0;


    porcen = (div * 100) * 1.0/sal*1.0;



    if(porcen <= 30.0){

        cout << "Emprestimo pode ser concedido";

    }else{

        cout << "Emprestimo nao pode ser concedido";

    }

	return 0;
}
