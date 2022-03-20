#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int Nb_test;
    int score;
    char input[100],buffer1[50],buffer2[50];
    int mem1,mem2,buffer5,buffer4,buffer3;

    scanf("%d ", &Nb_test);

    for( int i=0;i<Nb_test;i++){
        fgets(input, 100, stdin);
        int j=0;
        int k=0;
        while (input[j]!=' '){
            buffer1[j]=input[j];
            j++;
        }
        buffer1[j]='\0';
        j++;
        while (input[j]!='\0'){
            buffer2[k]=input[j];
            k++;
            j++;
        }
        buffer2[k]='\0';
        
        mem1=atoi(buffer1);
        mem2=atoi(buffer2);

        score=0;

        for(int l=0;l<mem2-mem1+1;l++){
            buffer4=mem1+l;
            buffer5=0;
            buffer3=1;
            while(buffer4>0){
                buffer5+=buffer4%10;
                buffer3*=buffer4%10;
                buffer4/=10;
            }
            if(buffer5!=0){
                if(buffer3%buffer5==0){
                    score++;
                }
            }
            
        }
        printf("Case #%d: %d\n", i+1, score);

    }
}