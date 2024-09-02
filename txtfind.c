#include <stdio.h>
#include <string.h>

#define WORD 30 // The max size of a word
#define LINE 256 // The max size of a line
#define MAXLINES 250 // Max lines in the text
#define OPTION1 'a' // print lines
#define OPTION2 'b' // print word

char Line[LINE] = "";
char Word[WORD] = "";
char str[WORD] = "";
char option;

/*Declaration of the functions*/
 
int get_line();

int getword(char word[]);

int substring(char * str1, char * str2);

int similar(char *s, char *t, int n);

void print_lines();

void print_similar_words();

int run_options();

int main() {
    
    getword(str);
    scanf(" %c\n", &option);
    if (!run_options()){
        printf ("%c is not an option!",option);
    }
    return 0;
}

/* 
get_line function :
* get line from the text :
-for loop i to the max size of a line
-use scanf to scan the text into Line
-if the pointer (Line+i) = end of the file -> *(Line+i) = null , break
-if the pointer (Line+i) = '\n' -> *(Line+i) = null , break
*/ 
int get_line(){
    int i = 0;
    for(i=0;i<LINE;i++){
        if(scanf("%c" , (Line+i))== EOF){
            *(Line+i) = '\0';
            break;
        }
        if(*(Line+i) == '\n'){
            *(Line+(++i)) = '\0';
            break;
        }
    }
    return i;
}

/* 
getword function :
* gets word from the text :
-while loop i to the max size of a word
-use scanf to scan the text into word[]
-if the pointer (word+i) = end of the file || ' ' || '\t' || '\n' -> *(word+i) = null , break
-if the pointer (Line+i) = '\n' -> *(Line+i) = null , break
*/ 
int getword(char word[]) {
    int i = 0;
    while (i < WORD){
        if (scanf("%c", &word[i]) == EOF || word[i] == ' ' || word[i] == '\t' || word[i] == '\n'){
            word[i] = '\0';
            break;
        }
        i++;
    }
    if (i == WORD)
        word[i - 1] = '\0';
    return i;
}

/* 
substring function :
*check if the str2 contained in str1
-two for loops :
-in the first for loop, runs over all str1 chars (i) 
-in the second for loop,j:0->size of (str2)-1 ,check if *(str1+i+j)=*(str2+j) 
-if *(str1+i+j)=(str2+j) -> tempSize = tempSize+1
-in the end of the loops check if tempSize = size of str2(size of our word)
-if tempSize = size of our word....return true, else false
*/ 
int substring(char *str1, char *str2){
    int flag = 0;
    int tempSize = 0;
    int size_str1 = strlen(str1);
    int size_str2 = strlen(str2);
    if(size_str1 < size_str2){
        return flag;
    }
    for(int i=0;i<size_str1;i++){
        for(int j=0;j<size_str2;j++) {
            if (*(str1 + i + j) == *(str2 + j)) {
                tempSize++;
            }
            else{
                tempSize =0;
                break;
            }
        }
        if(tempSize == size_str2){
            flag = 1;
            break;
        }
    }
    return flag;
}
/* 
similar function :
* the function will check if it is possible to get string t from string s by deleting n chars  
-check if size of t + n equal to size of s 
-while loop runs over all string s (i : 0-> size of s) && lenres: 0-> size of t 
-if string s in index i equal to string t in index lenres -> lenres++
-i++
-if size of lenres equal to size of string t, return true 
*/ 
int similar(char *s, char *t, int n) {
    int lens = strlen(s), lent = strlen(t), lenres = 0, i = 0;
    if (lens != lent + n) {
        return 0;
    }
    while (i < lens && lenres < lent){
        if (*(s + i) == *(t + lenres))
            lenres++;
        i++;
    }
    return (lent == lenres);
}

/* 
print_lines function :
* gets lines from the text and prints the lines that contained our word
-while loop to gets all the lines from the text(use get_lines function)
-for each line, check if our word contained in this line(use substring function)
-if our word contained in this line ->print this line 
*/ 
void print_lines(){
    while(get_line()){
        if(substring(Line,str)){
            printf("%s",Line);
        }
    }
}
/* 
print_similar_words:
* gets word from the text and prints the word that similar to our word
-while loop to gets all the words from the text(use getword function)
-for each word, check if our word similar to this word by deleting one char(use similar function)
-if our word similar to this word -> print this word
*/
void print_similar_words() {
    while (getword(Word)) {
        if (similar(Word, str, 0) || similar(Word, str, 1))
            printf("%s\n", Word);
    }
}
/*
run_options function:
* gets input from the user
-OPTION1 print_lines
-OPTION2 print_similar_word
*/
int run_options() {
    switch (option) {
        case OPTION1:
            print_lines(str);
            return 1;
        case OPTION2:
            print_similar_words(str);
            return 1;
    }
    return 0;
}
