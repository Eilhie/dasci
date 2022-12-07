#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){  
    int T;
    FILE *file = fopen("testdata.in", "r");  
    fscanf(file, "%d\n", &T);     
    for(int i=0; i<T; i++){ 
        int changed[26] = {0};   
        char string[100];     
        int N;         
        fscanf(file, "%s\n", string);      
        fscanf(file, "%d\n", &N);    
        int len = strlen(string);        
        for(int j=0; j<N; j++){                          
            char from;            
            char to;                         
            fscanf(file, "%c %c\n", &from, &to);   
            if(!changed[from-'A']){
                changed[from-'A']=1;
                for (int k = 0; k < len; k++){                                              
                    if (string[k] == from){                         
                        string[k] = to;
                    }                 
                } 
            }
        }             
        int frequency[26] = {0};        
        for (int j = 0; j < len; j++){                             
            frequency[string[j] - 'A']++;            
        }             
        for (int j = 0; j < 26; j++){                            
            if(frequency[j]){
                printf("%c %d\n", 'A'+j, frequency[j]);
            }          
        }         
    }     
    return 0; 
}