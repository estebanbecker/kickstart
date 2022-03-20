#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int Nb_test;
    char valide[999999] , input[999999],*valide_lec,*input_lec;
    size_t valide_size=10005;
    int score;
    int j;


    scanf("%d", &Nb_test);
    
    getc(stdin);

    for(int i; i<Nb_test; i++){
        score=0;
        j=0;
        valide[j]=getc(stdin);
        while(valide[j]!='\n'){
            j++;
            valide[j]=getc(stdin);
        }
        valide[j]='\0';

        j=0;
        input[j]=getc(stdin);
        while(input[j]!='\n'){
            j++;
            input[j]=getc(stdin);
        }
        input[j]='\0';

        valide_lec=&valide[0];
        input_lec=&input[0];

        while (*input_lec != '\0')
        {
            if(*input_lec == *valide_lec){
                input_lec++;
                valide_lec++;
            }
            else{
                score++;
                input_lec++;
            }
        }
        if(*valide_lec != '\0'){
            printf("Case #%d: IMPOSSIBLE\n", i+1);
        }else{
            printf("Case #%d: %d\n", i+1, score);
        }
        
    }
}