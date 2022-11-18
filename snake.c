#include<stdio.h>
#include<stdlib.h> // Para função srand() e system()
#include<windows.h> // Para função SetConsoleCursorPosition()
#include<conio.h> // Para função getch() e kbhit()
#include<time.h> // Para função rand()

// Variáveis
int c[300][2], pontos=1, cx=2, cy=2;
int alimento[2], velo=150;

// FUNÇÕES
void gotoxy(int x, int y){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

void snake(){
    int i;
    for(i=0; i<pontos; i++){
        gotoxy(c[i][0],c[i][1]);
        printf("%c",219);
    }
}

void atualizaPontuacao(){
    int i;
    gotoxy(c[pontos][0],c[pontos][1]);
    printf(" ");
    for(i=pontos; i>=0; i--){
        c[i+1][0] = c[i][0];
        c[i+1][1] = c[i][1];
    }
}

int analizaPontuacao(){
    int i, retorno=0;
    for(i=1; i<pontos; i++){
        if(cx==c[i][0] && cy==c[i][1]){
            retorno=1;
        }
    }
    return retorno;
}

void geraAlimento(){
    gotoxy(alimento[0],alimento[1]);
    printf(" ");
    srand(time(NULL));
    alimento[0] = (rand() % 48) +1;
    alimento[1] = (rand() % 18) +1;
    gotoxy(alimento[0],alimento[1]);
    printf("%c",4);
}

int main(){
    int i, Fimdojogo=0;
    int tecla;

    for(i=0; i<50; i++){
        gotoxy(i,0);
        printf("%c",219);
        Sleep(5);
    }
    for(i=0; i<20; i++){
        gotoxy(50,i);
        printf("%c",219);
        Sleep(5);
    }
    for(i=50; i>=0; i--){
        gotoxy(i,20);
        printf("%c",219);
        Sleep(05);
    }
    for(i=20; i>0; i--){
        gotoxy(0,i);
        printf("%c",219);
        Sleep(5);
    }
    geraAlimento();
    snake();
    tecla='d';
    while(Fimdojogo==0){
        gotoxy(52,2);
        printf("Pontos: %d\t",pontos);
        gotoxy(52,4);
        printf("Desenvolvido por Victor Manoel");
        c[0][0]=cx;
        c[0][1]=cy;
        if(kbhit())
            tecla=getch();

        if(tecla=='w' || tecla=='W' || tecla==72){
            cy--;
            if(cy==0) break;
        }
        if(tecla=='a' || tecla=='A' || tecla==75){
            cx--;
            if(cx==0) break;
        }
        if(tecla=='s' || tecla=='S' || tecla==80){
            cy++;
            if(cy==20) break;
        }
        if(tecla=='d' || tecla=='D' || tecla==77){
            cx++;
            if(cx>=50) break;
        }

        if(cx==alimento[0] && cy==alimento[1]){
            pontos++;
            if(velo>50) velo-=10;
            geraAlimento();
        }
        Fimdojogo=analizaPontuacao();
        atualizaPontuacao();
        snake();
        gotoxy(50,20);
        Sleep(velo);
    }
    system("cls");
    printf("Voce perdeu! Fez %d pontos.\n",pontos);
    system("pause");
}
