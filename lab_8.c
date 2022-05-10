#include <stdio.h>
#include <string.h>
 
void search(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i;
    int j;
 	int c=0;
    for (i= 0; i <= N - M; i++) {
        
 		c++;
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;
 
        if (j == M)
            printf("Pattern at index %d \n", i);
            
    }
    printf("total search: %d",c);
}
 
int main()
{
    char txt[] = "AABAACAADAABAAABAA";
    char pat[] = "AABA";
    search(pat, txt);
    return 0;
}
