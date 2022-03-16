#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct to_check{
    int x;
    int y;

    struct to_check *next;
}to_check;

typedef struct to_check_list{
    to_check *head;
    to_check *tail;
}to_check_list;


to_check_list add_tail(to_check_list list, int x, int y){
    to_check *new_node = malloc(sizeof(to_check));
    new_node->x = x;
    new_node->y = y;
    new_node->next = NULL;

    if(list.head == NULL){
        list.head = new_node;
        list.tail = new_node;
    }
    else{
        list.tail->next = new_node;
        list.tail = new_node;
    }
    return list;
}
to_check_list remove_head(to_check_list list){
    to_check *tmp ;
    if(list.head == NULL){
        return list;
    }
    tmp= list.head->next;

    if(list.head == NULL){
        list.tail = NULL;
    }
    free(list.head);
    list.head = tmp;
    return list;
}

int main(){
    int NbTest;
    char data[25], line[10],col[10];
    int nb_line = 0;
    int nb_col = 0;
    int j,k,l;
    char str_grid[2500];
    int grid[300][300];
    char buffer[11];
    unsigned long int score;

    scanf("%d ", &NbTest);

    for (int i = 0; i < NbTest; i++)
    {   
        score=0;
        fgets(data, 29, stdin);

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
            fgets(str_grid, 2499, stdin);
            l=0;
            for(int k=0 ; k<nb_col ; k++)
            {
                int m=0;
                while (str_grid[l]!=' ' && str_grid[l]!='\0')
                {
                    buffer[m]=str_grid[l];
                    l++;
                    m++;
                }
                buffer[m]='\0';
                l++;
                
                grid[j][k]=atoi(buffer);
                   
            }
        }

        if(nb_col <= 1 && nb_line <= 1)
        {
            printf("Case #%d: 0\n", i+1);
            continue;
        }
        to_check_list head;
        head.head = NULL;
        head.tail = NULL;

        for(j=0;j<nb_line;j++){
            for(int k=0;k<nb_col;k++){
                if(j==0 && k==0){
                    if (grid[j][k]>grid[j+1][k]+1 || grid[j][k]>grid[j][k+1]+1){
                        head=add_tail(head,j,k);
                    }
                }else if(j==0 && k==nb_col-1){
                    if (grid[j][k]>grid[j+1][k]+1 || grid[j][k]>grid[j][k-1]+1){
                        head=add_tail(head,j,k);
                    }
                }else if(j==nb_line-1 && k==0){
                    if (grid[j][k]>grid[j-1][k]+1 || grid[j][k]>grid[j][k+1]+1){
                        head=add_tail(head,j,k);
                    }
                }else if(j==nb_line-1 && k==nb_col-1){
                    if (grid[j][k]>grid[j-1][k]+1 || grid[j][k]>grid[j][k-1]+1){
                        head=add_tail(head,j,k);
                    }
                }else if(j==0 && k!=0 && k!=nb_col-1){
                    if (grid[j][k]>grid[j+1][k]+1 || grid[j][k]>grid[j][k-1]+1 || grid[j][k]>grid[j][k+1]+1){
                        head=add_tail(head,j,k);
                    }
                }else if(j==nb_line-1 && k!=0 && k!=nb_col-1){
                    if (grid[j][k]>grid[j-1][k]+1 || grid[j][k]>grid[j][k-1]+1 || grid[j][k]>grid[j][k+1]+1){
                        head=add_tail(head,j,k);
                    }
                }else if(k==0 && j!=0 && j!=nb_line-1){
                    if (grid[j][k]>grid[j-1][k]+1 || grid[j][k]>grid[j+1][k]+1 || grid[j][k]>grid[j][k+1]+1){
                        head=add_tail(head,j,k);
                    }
                }else if(k==nb_col-1 && j!=0 && j!=nb_line-1){
                    if (grid[j][k]>grid[j-1][k]+1 || grid[j][k]>grid[j+1][k]+1 || grid[j][k]>grid[j][k-1]+1){
                        head=add_tail(head,j,k);
                    }
                }else{
                    if (grid[j][k]>grid[j-1][k]+1 || grid[j][k]>grid[j+1][k]+1 || grid[j][k]>grid[j][k-1]+1 || grid[j][k]>grid[j][k+1]+1){
                        head=add_tail(head,j,k);
                    }
                }
            }
        }
        while(head.head != NULL){
            int check=0;
            if(head.head->x != 0){
                while(grid[head.head->x][head.head->y]>grid[head.head->x-1][head.head->y]+1){
                    ++grid[head.head->x-1][head.head->y];
                    score+=1;
                    check=1;
                }if(check==1){
                    head=add_tail(head,head.head->x-1,head.head->y);
                    check=0;
                }
                
            }if(head.head->y != 0){
                while(grid[head.head->x][head.head->y]>grid[head.head->x][head.head->y-1]+1){
                    ++grid[head.head->x][head.head->y-1];
                    score+=1;
                    check=1;
                }if(check==1){
                    head=add_tail(head,head.head->x,head.head->y-1);
                    check=0;
                }
                
            }if(head.head->x != nb_line-1){
                while(grid[head.head->x][head.head->y]>grid[head.head->x+1][head.head->y]+1){
                    ++grid[head.head->x+1][head.head->y];
                    score+=1;
                    check=1;
                }if(check==1){
                    head=add_tail(head,head.head->x+1,head.head->y);
                    check=0;
                }
            }if(head.head->y != nb_col-1){
                while(grid[head.head->x][head.head->y]>grid[head.head->x][head.head->y+1]+1){
                    ++grid[head.head->x][head.head->y+1];
                    score+=1;
                    check=1;
                }if(check==1){
                    head=add_tail(head,head.head->x,head.head->y+1);
                    check=0;
                }
            }
            head=remove_head(head);
        }
        printf("Case #%d: %lu\n", i+1, score);
    }
}


