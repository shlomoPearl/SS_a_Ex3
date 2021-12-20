#include <stdio.h>
#include <string.h>

#define TXT 1024
#define WORD 30

char txt[TXT] = {0};
char word[WORD] = {0};

void getTxt(){
    int i=0;
    while( i<TXT){
        scanf("%c",&txt[i]);
        if(txt[i] == '~')break;
        i++;
    }
}

void getWord(){
    int j=0;
    while(j<WORD){
        scanf("%c",&word[j]);
        if(word[j] == '\n' || word[j] == '\t' || word[j] == ' ')break;
        j++;
    }
}

int reValue(int g){
    if(g <'A' || g >'z'){
        return 0;
    }
    else if(g >='A' && g<= 'Z'){
        return (g % 'A')+1;
    }
    return (g % 'a')+1;
}

void gematria(){
    printf("Gematria Sequences: ");
    int wordGematria = 0;
    int counter = 0;
    char ans[TXT]={0};
    int tmp = 0;
    int start;
    int end;
    for(int i=0;i<WORD;i++){
        wordGematria += reValue(word[i]);
    }
    int i=0;
    while(txt[i] != '~'){
        int current = reValue(txt[i]); // replace to gimatria value
        if(current <=('z'%'a')+1 && current >= ('A'%'A')+1 && current<wordGematria){ //if current is char
            int j=i;
            start = j;
            while(counter < wordGematria && txt[j] != '~'){
                counter += reValue(txt[j]);
                j++;
            }
            end = j;
            if(counter == wordGematria){
                for(int k = start ; k < end; k++){
                    printf("%c",txt[k]);
                }
                printf("%c",'~');
            }
            counter=0;
        }
        i++;
    }
    printf("\n");
}


int  main(){
    getWord();
    getTxt();
    gematria();
    return 0;
}