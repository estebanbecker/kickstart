#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int NbTest;
    char data[30], line[10],col[10];
    int nb_line = 0;
    int nb_col = 0;
    int j,k,x,y;
    char str_grid[2200];
    int grid[1000][1000];
    int nb_up, nb_down, nb_left, nb_right;
    int score;

    scanf("%d ", &NbTest);

    for (int i = 0; i < NbTest; i++)
    {   
        score=0;
        fgets(&data, 29, stdin);

        j=0;
        while (data[j]!=' ' )
        {
            line[j]=data[j];
            j++;
        }

        line[j]='\0';
        nb_line = atoi(line);
        k=j;

        while (data[j]!='\n')
        {
            col[j-k]=data[j];
            j++;
        }
        col[j-k]='\0';

        nb_col = atoi(col);

        for(j=0 ; j<nb_line ; j++)
        {
            fgets(&str_grid, 2199, stdin);

            for(int k=0 ; k<nb_col ; k++)
            {
                grid[j][k]=str_grid[k*2]-'0';
            }
        }

        if(nb_col <= 1 || nb_line <= 1)
        {
            printf("Case #%d: 0\n", i+1);
            continue;
        }
        for(j=0 ; j<nb_line ; j++)
        {
            for(int k=0 ; k<nb_col ; k++)
            {
                x=j;
                y=k;
                if (grid[j][k]==1)
                {
                    nb_up = 0;
                    nb_down = 0;
                    nb_left = 0;
                    nb_right = 0;
                    while (y>=0)
                    {
                        if(grid[x][y]==1)
                        {
                            nb_up++;
                        }else{
                            break;
                        }
                        y--;
                    }
                    y=k;

                    while (y<nb_col)
                    {
                        if(grid[x][y]==1)
                        {
                            nb_down++;
                        }else{
                            break;
                        }
                        y++;
                    }
                    y=k;

                    while (x>=0)
                    {
                        if(grid[x][y]==1)
                        {
                            nb_left++;
                        }else{
                            break;
                        }
                        x--;
                    }

                    x=j;

                    while (x<nb_line)
                    {
                        if(grid[x][y]==1)
                        {
                            nb_right++;
                        }else{
                            break;
                        }
                        x++;
                    }

                    if (nb_up>=2 && nb_left>=4){
                        score+= min(nb_up,nb_left/2)-1;
                    }if (nb_up>=2 && nb_right>=4){
                        score+= min(nb_up,nb_right/2)-1;
                    }if (nb_down>=2 && nb_left>=4){
                        score+= min(nb_down,nb_left/2)-1;
                    }if (nb_down>=2 && nb_right>=4){
                        score+= min(nb_down,nb_right/2)-1;
                    }if (nb_left>=2 && nb_up>=4){
                        score+= min(nb_left,nb_up/2)-1;
                    }if (nb_left>=2 && nb_down>=4){
                        score+= min(nb_left,nb_down/2)-1;
                    }if (nb_right>=2 && nb_up>=4){
                        score+= min(nb_right,nb_up/2)-1;
                    }if (nb_right>=2 && nb_down>=4){
                        score+= min(nb_right,nb_down/2)-1;
                    }
                    
                }
            }
        }

        printf("Case #%d: %d\n", i+1, score);
    }   
}

int min(int a,int b){
    if (a<b){
        return a;
    }else{
        return b;
    }
}