#include <iostream>
#include <stdio.h>
#include <math.h>
#include <random>   //para calcular a distribuição uniforme
#include <time.h>   //seed
using namespace std;

void parte1(){
    /* Parte 1:
     * (i) Calculo do valor do trabalho por interpolacao de Lagrange
     */
    
    // inicializmamos os vetores que contem os pares ordenados a serem interpolados
    float X[7] = {0, 5, 10, 15, 20, 25, 30};
    float y[7] = {0.0, 1.5297, 9.512, 8.7025, 2.8087, 1.0881, 0.3537};

    float prod = 1;
    float som = 0;
    int x = 1;
    
    // calculando os polinomios de Lagrange
    for (int j=0; j<7; j++){
        for (int i=0; i<7; i++){
            if (i != j){
                //cout << "X[i] = " << X[i] << ", X[j] = " << X[j] << endl;
                prod = prod * ((x-X[i])/(X[j]-X[i]));
                //cout << "polinomio atual com i = " << i << " eh " << produtorio << endl;
            }
        }
        som = prod * y[j];
        cout << "soma do trabalho ate x" << j << " = " << som << endl;
        prod = 1;
    }
    cout << "O valor da funcao interpolada eh " << som << "\n" << endl;
    
    /* (iia) Aproximacao do valor do trabalho usando regra do trapezio composta */
    float h = (X[0]-X[1])/6;
    float somatorio = (h/2)*y[0];
    for (int i=1;i<6;i++){
        somatorio += h*y[1];
    }
    somatorio += (h/2)*y[6];
    
    cout << "Aproximando pela regra do trapezio composta, o valor do trabalho equivale a " << somatorio << "\n" << endl;
    
    /* (iib) Aproximação por regra de Simpson composta */
    float som1 = 0;
    float som2 = 0;
    
    // primeiro somatorio = sum^{n-2}_{k=1} f(x_{2k-1})
    for (int i=0;i<=(6-2);i++){
        if (2*i-1>=0){
            som1 += y[2*i-1];
        }
    }
    som1 *= 4;
    
    // segundo somatorio = sum^{n/2-1}_{k=1} f(x_{2k})
    for (int i=0;i<=((6/2)-1);i++){
        som2 += y[2*i];
    }
    som2 *= 2;
    
    float sn;
    sn = (h/3)*(y[0]+y[6]+som1+som2);
    
    cout << "Aproximando pela regra de simpson composta, o valor do trabalho equivale a " << sn << "\n" << endl;

    return;
}

////////////// PARTE 2 //////////////

//ponteiro para uma funcao float que aceita float e int como parametro
typedef float (*fct_ptr)(float);

float seno(float x){
    return sin(x);
}

float x3(float x){
    return x*x*x;
}

float ex(float x){
    return exp(-x);
}

//distribuição uniforme
float distribuicao(){ 
    default_random_engine generator(time(NULL));
    float a = 0.0, b = 1.0;
    uniform_real_distribution<float> distribution(a, b);

    return distribution(generator);
}

//integral unidimensional
float uni(int n1, int n2, fct_ptr funcao){
    float somatorio = 0;
    for (int i = n1; i < n2; ++i) {
        float Ui = distribuicao();
        float g = funcao(Ui);
        somatorio += funcao(Ui)/(n2-n1);
    }
    return somatorio;
}

//integral multidimensional
float multi(int n1, int n2, int d, fct_ptr funcao){
    float somatorio = 0;
    for(int j = n1; j<n2; j++){
        float g = 1.0;
        for(int i = 0; i<d; i++){
            g *= funcao(distribuicao());  
        }
        somatorio += g;
    }
    return somatorio/(n2-n1);
}

void parte2(){
    // Parte 2: Integração por Monte Carlo

    //integrais unidimensionais
    float a = uni(0, 1, seno);
    cout << "Integral unidimensional de sin(): " << a << endl;
    float b = uni(3, 7, x3);
    cout << "Integral unidimensional de x^3(): " << b << endl;
    float c = uni(0, 100, ex);
    cout << "Integral unidimensional de e^-x(): " << c << "\n" << endl;

    //integrais multidimensionais
    int d = 2;
    float e = multi(0, 1, d, seno);
    cout << "Integral multidimensional de sin(): " << e << endl;
    float f = multi(3, 7, d, x3);
    cout << "Integral multidimensional de x^3(): " << f << endl;
    float g = multi(0, 100, d, ex);
    cout << "Integral multidimensional de e^-x(): " << g << endl;

    return;
}

int main(){

    parte1();
    parte2();

    return 1;
}
