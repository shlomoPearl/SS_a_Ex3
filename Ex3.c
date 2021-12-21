#include <stdio.h>
#include <string.h>

#define TXT 1024
#define WORD 30

static char txt[TXT] = {0};
static char word[WORD] = {0};
static int lenOfword=0;

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
        lenOfword++;
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
    int flag =1; // to know if this is the first gematria
    int start;
    int end;
    for(int i=0;i<WORD;i++){
        wordGematria += reValue(word[i]);
    }
    int i=0;
    while(txt[i] != '~'){
        int current = reValue(txt[i]); // replace to gimatria value
        if(current == wordGematria){
            if(flag == 1 ){
                printf("%c",txt[i]);
                flag = 0;
            }else{
                printf("~%c",txt[i]);
            }
        }
        if(current <=('z'%'a')+1 && current >= ('A'%'A')+1 && current<wordGematria){ //if current is char
            int j=i;
            start = j;
            while(counter < wordGematria && txt[j] != '~'){
                counter += reValue(txt[j]);
                j++;
            }
            end = j;
            if(counter == wordGematria){
                if(flag == 1){ // this is the first gematria
                    for(int k = start ; k < end; k++){
                        printf("%c",txt[k]);
                    }
                    flag = 0;
                }else{
                    printf("~");
                    for(int k = start ; k < end; k++){
                        printf("%c",txt[k]);
                    }
                } 
            }
            counter=0;
        }
        i++;
    }
    printf("\n");
}

char viceVersa(char c){
    if(c <= 'z'  && c >= 'a'){ // its lower case letter
        return ('z' - c +'a');
    }
    else{ //its upper case letter
        return ('Z' - c +'A');
    }
}

void atbash(){
    printf("Atbash Sequences: ");
    int flag;
    int firstFlag = 1;
    int counter;
    int start;
    char check1[WORD] ={0};
    char check2[WORD] ={0};
    for(int i = 0 ; i < lenOfword ; i++){
        check1[i] = viceVersa(word[i]);
        check2[i] = viceVersa(word[lenOfword -i -1]);
    }
    int i = 0;
    while(i<TXT){
        if(txt[i] == check1[0]){
            start = i;
            int j=0;
            counter =0;
            flag = 1;
            while(counter< lenOfword && start<TXT){
                if(txt[start]<= 'z' && txt[start]>='A'){
                    counter++;
                    if(txt[start] != check1[j] ){
                        flag =0;
                    }
                    j++;
                }
                start++;
            }
            if(flag == 1){
                if(firstFlag == 1){
                    for(int k=i;k<start;k++){
                        printf("%c",txt[k]);
                    }
                    firstFlag = 0;
                }else{
                    printf("%c",'~');
                    for(int k=i;k<start;k++){
                        printf("%c",txt[k]);
                    }
                }
            }
        }
        else if(txt[i] == check2[0]){
            start = i;
            int j=0;
            counter =0;
            flag = 1;
            while(counter< lenOfword && start<TXT){
                if(txt[start]<= 'z' && txt[start]>='A'){
                    counter++;
                    if(txt[start] != check2[j] ){
                        flag =0;
                    }
                    j++;
                }
                start++;
            }
            if(flag == 1){
                if(firstFlag == 1){
                    for(int k=i;k<start;k++){
                        printf("%c",txt[k]);
                    }
                    firstFlag = 0;
                }else{
                    printf("%c",'~');
                    for(int k=i;k<start;k++){
                        printf("%c",txt[k]);
                    }
                }
            }
        }
        i++;
    }
    printf("\n");
}


void anagram(){
    printf("Anagram Sequences: ");
    
}

int  main(){
    getWord();
    getTxt();
    gematria();
    atbash();
    anagram();
    return 0;
}