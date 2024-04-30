#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include "inicio.h"
#include "quiz.h"

void delay(int ms){
    #ifdef _WIN32
    Sleep(ms);
    #else
    usleep(ms * 1000);
    #endif
}
void explicacaoGame(){
    // coloquem os prints aqui
    printf("Lorem ipsum dolor sit amet. Eum dolorem ipsa aut iste Quis est impedit dolores est error nobis.");
    printf("Ut aliquam voluptate et exercitationem beatae ea reprehenderit repudiandae rem quisquam voluptatem aut rerum exercitationem."); 
    printf("Et magni suscipit est quae asperiores ut itaque eius eum fugit itaque in inventore ipsam aut tempora dolore et officia dolores.");
    printf("Et mollitia omnis sit omnis fugiat sed nisi numquam?\n"); // print de teste
}

void carregando(){
    for(int i=0; i<5; i++){
        limpa();
        abertura();
        explicacaoGame();
        printf(".");
        fflush(stdout);
        delay(600);

        printf(".");
        fflush(stdout);
        delay(600);

        printf(".");
        fflush(stdout);
        delay(600);
    }
}