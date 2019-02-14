# ICGAtividade01
	Primeira atividade da disciplina de introdução a computação gráfica onde deverá ser implementado os algoritmos fundamentais, utilizando a rasterização de pontos e linhas.
	
	Atividade 01: Nesta primeira atividade deve-se implementar algoritmos fundamentais utilizados em computação gráfica, utilizando a rasterização de pontos e linhas, onde deverão ser desenhados triângulos através da rasterização das linhas .

Como os atuais sistemas operacionais não permitem que o usuário tenha acesso direto à memória, foi disponibilizado uma framework para tal acesso. Para este trabalho serão desenvolvidas as seguintes funções: 

• PutPixel: Função que rasteriza um ponto na memória de vídeo, recebendo como parâmetros a posição do pixel na tela (x,y) e sua cor (RGBA). 

Para a rasterização de um pixel utilizaremos o ponteiro Fbptr que foi disponibilizado no framework, passando para a função PutPixel as coordenadas do ponto (x, y) bem como a cor desejada (R,G,B,A); Para a implementação de tal função utilizamos a seguinte função matemática: x*4 + 4*y*h para localizar o local de impressão do pixel em uma tela delimitada.

Função PutPixel escrita em linguagem C: 
















• DrawLine: Função que rasteriza uma linha na tela, recebendo como parâmetros os seus vértices 
(inicial e final, representados respectivamente pelas tuplas (x0,y0) e (x1,y1)), e as cores (no 
formato RGBA) de cada vértice. As cores dos pixels ao longo da linha rasterizada devem ser 
obtidas através da interpolação linear das cores dos vértices. O algoritmo de rasterização a ser 
implementado deve ser o algoritmo de Bresenham! 
  
Para a rasterização de uma linha utilizaremos o algoritmo de Bresheram que recebe como parâmetros as coordenadas dos pontos inicial e final para traçar a reta. O Algoritmo de Bresenham é um algoritmo clássico para traçar curvas, ele usa apenas variáveis inteiras e permite que o cálculo de um próximo ponto seja feito de forma incremental. 

Suponha que a tela possua igual densidade de pixels na horizontal e na vertical. O algoritmo assume que a inclinação da linha está entre zero (0) e um (1), (outras inclinações podem ser tratadas por
simetria). O ponto (x1,y1) seria o inferior esquerdo, e (x2,y2) o superior direito. 






















Assumindo que o pixel que acabou de ser selecionado é P, em (xp,yp), e o próximo deve ser escolhido entre o pixel à direita superior a M (pixel S) e o pixel à direita inferior a M (pixel I). Seja Q o ponto de intersecção entre a reta e a coluna x = xp +1 da malha, e M o ponto intermediário entre os
pixels S e I, o que se faz é observar de que lado da reta está o ponto M. É fácil verificar que se M está acima de Q, o pixel I está mais próximo da reta; se M está abaixo de Q, S está mais próximo.

O algoritmo se torna pouco eficiente para traçar retas em todas os quadrantes, uma vez que temos que utilizar de uma variável de decisão  ( d = (2*dx - dy);) para determinar em que octante a reta será traçada .   











Utilizaremos a variável de decisao para verificar em em qual lado da reta o pixel será plotado,  da seguinte forma:
Se d>0 incrementa - se  NE;
Se d<0 incrementa E;
Se d=0 pode ser o E. 
O incremento de NE e N é feito pelas seguintes expressões, respectivamente:  
           incNE=2*(dy-dx);
           incE=2dy;
Com isso poderemos traçar retas em qualquer octante da tela de exibição.
Trecho do código da função Drawline que mostra como é calculada a variável de decisão: 












.  
• DrawTriangle: Função que desenha as arestas de um triângulo na tela, recebendo como parâmetros as posições dos três vértices (xa,ya), (xb,yb) e (xc,yc) bem como as cores (RGBA) de cada um dos vértices. As cores dos pixels das arestas do triângulo devem ser obtidas através da interpolação linear das cores de seus vértices. Não é necessário o preenchimento do triângulo!

Para a criação da função DrawTriangle foi utilizada a função DrawLine passando com referencia os pontos de cada vértice do triangulo desejado, ligando o ponto 1 ao ponto 2, o ponto 2 ao ponto 3 e o ponto 3 ao ponto 1.















Dificuldades 
  
No desenvolvimento do trabalho a maior dificuldade foi na criação da função DrawLine, uma vez que o algoritmo de Bresenham visto em sala tratava apenas do primeiro octante e não desenhava as retas para os demais. Após realizar uma pesquisa vi que o problema poderia ser resolvido utilizando de um artifício, variável de decisão para descobrir em que octante está o ponto inicial, para o desenvolvimento do resto da função. 

Resultado Final

















Referências 

[1]https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
[2]www.demic.fee.unicamp.br/~jeff/ArquivosIndex/Bresenham 
[3]Notas de Aulas do professor Christian Azambuja Pagot 
[4]Notas de Aulas da professora Liliane dos Santos

