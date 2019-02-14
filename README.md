# ICGAtividade01
	Primeira atividade da disciplina de introdução a computação gráfica onde deverá ser implementado os algoritmos fundamentais, utilizando a rasterização de pontos e linhas.
	
	Atividade 01: Nesta primeira atividade deve-se implementar algoritmos fundamentais utilizados em computação gráfica, utilizando a rasterização de pontos e linhas, onde deverão ser desenhados triângulos através da rasterização das linhas .

Como os atuais sistemas operacionais não permitem que o usuário tenha acesso direto à memória, foi disponibilizado uma framework para tal acesso. Para este trabalho serão desenvolvidas as seguintes funções: 

• PutPixel: Função que rasteriza um ponto na memória de vídeo, recebendo como parâmetros a posição do pixel na tela (x,y) e sua cor (RGBA). 

Para a rasterização de um pixel utilizaremos o ponteiro Fbptr que passa as coordenadas do ponto (x,y) e sua cor.  

Dificuldades: A principal deificuldade foi na utilização do framework, 

Função PutPixel escrita em linguagem C: 
















• DrawLine: Função que rasteriza uma linha na tela, recebendo como parâmetros os seus vértices e sua cor e atraves so algoritimo de Bresenham. Para a rasterização de uma linha Bresheram recebe como parâmetros as coordenadas dos pontos inicial e final para traçar a reta. utilizando apenas variáveis inteiras e permite que o cálculo de um próximo ponto seja feito de forma incremental.  

![funcao drawline](https://user-images.githubusercontent.com/45613409/52754823-a179c980-2fda-11e9-96db-76da7a7e39b1.png)


Trecho de codigo da funcao drawline, chamada da função e resultado. 

   
• DrawTriangle: Função que desenha as arestas de um triângulo na tela, recebendo como parâmetros as posições dos três vértices e a sua cor. Para a criação da função DrawTriangle foi utilizada a função DrawLine passando com referencia os pontos de cada vértice do triangulo desejado, ligando o ponto 1 ao ponto 2, o ponto 2 ao ponto 3 e o ponto 3 ao ponto 1.















Dificuldades 
  
No desenvolvimento do trabalho a maior dificuldade foi na criação da função DrawLine, uma vez que o algoritmo de Bresenham visto em sala tratava apenas do primeiro octante e não desenhava as retas para os demais. Após realizar uma pesquisa vi que o problema poderia ser resolvido utilizando de um artifício, variável de decisão para descobrir em que octante está o ponto inicial, para o desenvolvimento do resto da função. 

Resultado Final

















Referências 

[1]https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
[2]www.demic.fee.unicamp.br/~jeff/ArquivosIndex/Bresenham 
[3]Notas de Aulas do professor Christian Azambuja Pagot 
[4]Notas de Aulas da professora Liliane dos Santos

