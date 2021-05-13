#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void calcular2(char *,unsigned int *);
int main(){

    
    char cadena[101];
    
    printf("Bienvenido: \n");
    printf("Ingrese la cadena de caracteres que desea empaquetar: ");
    scanf("%s", cadena);
   

    unsigned int *vector2 = (unsigned int* )calloc(25, sizeof(int));
   
    int tam = sizeof(cadena);

    calcular2(cadena,vector2);
    
    int i =0;
    while(i<25 && vector2[i] != 0){
        if (vector2[i+1] == 0){
           printf("%X ",vector2[i]); 
        }
        else{
           printf("%X ,",vector2[i]);
        }
        i++;
    }


    system("Pause");
    
}



void calcular2(char * cadena,unsigned int * vector){


    unsigned int rearmado;
    int comparar;
    __asm
    
    {
        mov eax, cadena
        mov ecx,comparar
        mov edx,vector
        inicio_while:
        cmp [eax], 0
        je fin_while
                movzx ecx,[eax]
                shl ecx,24
                or rearmado,ecx
                add eax,1
                movzx ecx,[eax]
                shl ecx,16
                or rearmado,ecx
                add eax,1
                movzx ecx,[eax]
                shl ecx,8
                or rearmado,ecx
                add eax,1
                movzx ecx,[eax]
                or rearmado,ecx
                mov ebx,rearmado 
                mov [edx],ebx
                add eax,2
                add edx,4
                jmp inicio_while
        fin_while:       

    }


     
}