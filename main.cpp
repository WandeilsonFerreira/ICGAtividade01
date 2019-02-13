#include "main.h"


//-----------------------------------------------------------------------------
void MyGlDraw(void){
	 PutPixel(150,100, B); 	 
	 DrawLine(256,256,0,0,R,G);
	 DrawTriangle(10,500,100,500,10,400, R, G);
	 DrawTriangle(300,500,400,400,500,500, R, G);
	 DrawTriangle(500,200,500,50,300,50, R, G);
}
//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{	 
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;	

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}

