#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int Nb_test;
    int score;
    char input[123459],buffer1[123459],buffer2[123459],buffer3[5];
    int mem;
    int k;
    int len;


    scanf("%d ", &Nb_test);

    for(int i=0; i<Nb_test; i++){
        fgets(input, 123459, stdin);

        
            mem=0;
            int j=0;
            while(input[j]!='\n'){
                mem+=input[j]-'0';
                if (mem>9){
                    mem-=9;
                }
                j++;
            }
            input[j]='\0';
            

            
            score=9-mem;
            buffer3[0]=score+'0';
            buffer3[1]='\0';
            len=strlen(input);
            j=0;
            
            if(score==0){
                j=1;
                buffer2[0]=input[0];
                buffer2[1]='0';
                while (input[j]!='\0'){
                    buffer2[j+1]=input[j];
                    j++;
                }
                buffer2[j+1]='\0';
            }else{
                while (input[j]<=buffer3[0] && j<len){
                    buffer2[j]=input[j];
                    j++;
                }
                buffer2[j]=buffer3[0];
                while (input[j]!='\0'){
                    buffer2[j+1]=input[j];
                    j++;
                }
                buffer2[j+1]='\0';
            }

            /*while(buffer2[0]=='0'){
                for (k=0; k<j; k++){
                    buffer2[k]=buffer2[k+1];
                }
                buffer2[k]=buffer2[k+1];
            }*/

            if(buffer2[0]=='\0'){
                printf("Case #%d: 0\n", i+1);
            }else{
                printf("Case #%d: %s\n", i+1, buffer2);
            }
        
    }
}