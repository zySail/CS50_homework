#include <cs50.h>
#include <stdio.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
void Grade(int letter, int words, int sentence);

int main(void)
{
    string text = get_string("Text:");
    printf("%d letters\n", count_letters(text));
    printf("%d words\n", count_words(text));
    printf("%d sentences\n", count_sentences(text));
    Grade(count_letters(text), count_words(text), count_sentences(text));
    printf("\n");
}

int count_letters(string text){
    char letter;
    int i = 0 , number = 0;
    do{
        letter = text[i];
        if((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')){
            number++;
        }
        i++;
    }while(letter != '\0');
    return number;
}

int count_words(string text){
    int i = 0 , number = 1;
    char letter;
    do{
        letter = text[i];
        if(letter == ' '){
            number++;
        }
        i++;
    }while(letter != '\0');
    return number;
}

int count_sentences(string text){
    int i = 0 , number = 0;
    char letter;
    do{
        letter = text[i];
        if(letter == '?' || letter == '.' || letter == '!'){
            number++;
        }
        i++;
    }while(letter != '\0');
    return number;
}

void Grade(int letter, int words, int sentence){
    double L = 100.0 / words * letter;
    double S = 100.0 / words * sentence;
    int index = (int)(0.0588 * L - 0.296 * S - 15.8 + 0.5);
    if(index >= 16){
        printf("Grade 16+");
    }
    else if(index < 1){
        printf("Before Grade 1");
    }
    else{
        printf("Grade %d", index);
    }
}
