#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include<math.h>

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************


struct cor{
	int R, G, B, A;
};
	cor R = {255,0,0,255};
	cor G = {0,255,255,255};
	cor B = {0,0,255,255};
	cor A = {255,255,255,255};


void PutPixel(int x, int y, cor cor){
	int canPixel = x*4 + 4*y*IMAGE_WIDTH;

	FBptr[canPixel + 0] = cor.R;
	FBptr[canPixel + 1] = cor.G;
	FBptr[canPixel + 2] = cor.B;
	FBptr[canPixel + 3] = cor.A;
	
	
}

//------------------------
void DrawLine(int x1, int y1, int x2, int y2, cor c1, cor c2) {
 
int d,dx,dy,x,y,incx,incy,incE, incNE;
cor cor = c1;
float interpoR = ((float) c2.R - c1.R) / dx;
float interpoG = ((float) c2.G - c1.G) / dx;
float interpoB = ((float) c2.B - c1.B) / dx;
float interpoA = ((float) c2.A - c1.A) / dx;
 
x = x1;
y = y1;
dx = x2-x1;	//inicialização das variaveis 
dy = y2-y1;
incx = 1;
incy = 1;

PutPixel(x, y,cor); //Plota o primeiro valor estabelecido

    if(x2 >= x1){
        dx=x2-x1;  //estabelecendo o módulo de dx
        incx = 1; 

    }else{
        dx=x1-x2;
        incx =-1;
	}
    if(y2 >= y1){
        dy =(y2-y1); //estabelecndo o módulo de dy
        incy = 1; 
     }else{
        dy = (y1-y2);
        incy = - 1; 
        x = x1;
        y = y1;
    }

PutPixel(x, y, cor); //Plota o primeiro valor


    if (dx==0){ //para define uma coluna
        if (incy > 0){
            for (y=y1;y<=y2;y++){
		cor.R += (char) interpoR;
		cor.G += (char) interpoG;
		cor.B += (char) interpoB;
		cor.A += (char) interpoA;
                PutPixel(x, y, cor);
       	    }

	}else{
            for (y=y2;y<=y1;y++){
		cor.R += (char) interpoR;
		cor.G += (char) interpoG;
		cor.B += (char) interpoB;
		cor.A += (char) interpoA;
                PutPixel(x, y, cor);
	    }
   	 }
	
    }else{

	if(dy==0){ //para define uma linha
		if (incx > 0){
	            for(x=x1;x<=x2;x++){
			cor.R += (char) interpoR;
			cor.G += (char) interpoG;
			cor.B += (char) interpoB;
			cor.A += (char) interpoA; 
			PutPixel(x, y, cor);
		}

    }else{
            for(x=x2;x<=x1;x++){
		cor.R += (char) interpoR;
		cor.G += (char) interpoG;
		cor.B += (char) interpoB;
		cor.A += (char) interpoA;
                PutPixel(x, y, cor);
 		}
    }
    
	}else{
        if(dx >= dy){ //se a inclinação for diferente de 0 ou 90 graus temos que decidir qual pixel pintar utilizando uma variavel de decisao 
            d = (2*dy - dx); //valor de decisão inicial
            incE = 2*dy; //incremento em direção a E
            incNE = 2*(dy-dx); //incremento em direção a NE
    
     while(x!= x2){
        if(d <= 0){ //verifica em que quadrante está o ponto medio 
            d += incE; //escolhe E (pixel de baixo)
            x += incx; //incrementa ou decrementa x
	}else{
            d += incNE; //escolhe NE (pixel de cima)
            x += incx;
            y += incy; //incrementa ou decrementa y

        }
	 	cor.R += (char) interpoR;
		cor.G += (char) interpoG;
		cor.B += (char) interpoB;
		cor.A += (char) interpoA;
         PutPixel(x, y, cor);
    }

    }else{
	    d = (2*dx - dy);
            incE = 2*dx;
            incNE= 2*(dx - dy);

    while(y!= y2){
        if(d <= 0){
            d += incE; //escolhe E
            y += incy;

	}else{
            d += incNE; //escolhe NE
            y += incy;
            x += incx;

             }
		cor.R += (char) interpoR;
		cor.G += (char) interpoG;
		cor.B += (char) interpoB;
		cor.A += (char) interpoA;
	 PutPixel(x, y, cor);
          }
        }
      } 	
    }
  }
    
    
void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, cor c1, cor c2){
	DrawLine(x1, y1, x2, y2, G, B); 
	DrawLine(x2, y2, x3, y3, B, A);  
	DrawLine(x3, y3, x1, y1, B, R);  
} 

#endif // _MYGL_H_

