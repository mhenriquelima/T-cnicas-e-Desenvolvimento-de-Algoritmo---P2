    #include <stdio.h>

    int main(){
        int x = 15;
        int y;
        int *xPtr;

        // obtem o endereco de x
        xPtr = &x;

        // coloca em y, o valor apontado por xPtr
        y = *xPtr;

        printf("endereco de x = %p \n", xPtr);
        printf("endereco de xPtr = %p \n", &xPtr);
        printf("valor apontado por xPtr = %d \n", *xPtr);
        printf("valor de y = %d \n", y);

        // altera o valor de x
        x = 100;

        printf("\n");
        printf("endereco de x = %p \n", xPtr);
        printf("endereco de xPtr = %p \n", &xPtr);
        printf("valor apontado por xPtr = %d \n", *xPtr);
        printf("valor de y = %d \n", y);

        //altera o valor apontado por xPtr
        *xPtr = 200;

        printf("\n");
        printf("endereco de x = %p \n", xPtr);
        printf("endereco de xPtr = %p \n", &xPtr);
        printf("valor apontado por xPtr = %d \n", *xPtr);
        printf("valor de y = %d \n", y);

        // altera o endereco armazenado em xPtr
        xPtr++;

        printf("\n");
        printf("endereco de x = %p \n", xPtr);
        printf("endereco de xPtr = %p \n", &xPtr);
        printf("valor apontado por xPtr = %d \n", *xPtr);
        printf("valor de y = %d \n", y);

        return 0;
    }