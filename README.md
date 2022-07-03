# EP3-MAC210

<h3>Integrantes:

Sabrina Araújo     NUSP: 12566182

Samantha Miyahira NUSP: 11797261


## Parte 1 : Computando Trabalho

### Interpolação por Newton

### Integração numérica utilizando a regra do trapézio composto

### Integração numérica utilizando a regra de Simpson composto



## Parte 2: Integração por Monte Carlo

### Integrais unidimensionais
A integração por Monte Carlo utilizada consiste em inscrever a função que desejamos integrar em um retângulo e depois estimar a proporção entre área abaixo da curva da função e a área total do retângulo.

No algoritmo, calculamos o valor máximo H que a função pode ter e a partir disso obtemos a área do retângulo em que a função está inscrita. Então, geramos n pontos x (x ∈ [a, b]) e y (y ∈ [0, H]) dentro desse retângulo com distribuição uniforme em [0,1]. Para (x,y) gerado, se y <= f(x), então o ponto está abaixo ou em f(x) e somamos em um o número de pontos em/ou embaixo de f(x) e o número de pontos no retângulo. Caso contrário, somente somamos o número de pontos no retângulo. Ao final da iteração, calculamos a proporção entre o número de pontos em/ou embaixo de f(x) e o número de pontos no retângulo, e multiplicamos pela área do retângulo ((b-a)*H), assim, temos o valor aproximado da integral.


1. $\int_{0}^{1}sin(x)dx$

2. $\int_{3}^{7}x^3dx$

3. $\int_{0}^{\infty }e^-xdx$

4. (formula)
