#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char LETTERS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char WORDS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.?!';-:\"";
char SENTENCES[] = ".?!";

int k;
int n = 1;

char letters[100000];
char words[100000];
char sentences[100000];

int totalLetters = 0;
int totalWords = 0;
int totalSentences = 0;

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Get input words from user
    string text = get_string("Text: ");


    //passes the users text to the function count_letters
    int lettercount = count_letters(text);
    //printf("%i letters\n", lettercount);

    //passes the users text to the function count_words
    int wordcount = count_words(text);
    //printf("%i words\n", wordcount);

    //passes the users text to the function count_sentences
    int sentencecount = count_sentences(text);
    //printf("%i sentences\n", sentencecount);

    double L = ((float) lettercount/wordcount) * 100.0;          //calculates L using the given formula, casting lettercount as a float
    //printf("L = %f\n", L);

    double S = ((float) sentencecount/wordcount) *100.0;         //calculates S using the given formula, casting sentencecount as a float
    //printf("S = %f\n", S);

    double index = 0.0588 * L - 0.296 * S - 15.8;                //calculates index using the given formula
    int grade = round(index);                                    //rounds grade to the near integer

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text)
{
        //Converts the given words to all caps

        int i = 0;
        while (text[i])
    {
        char CAP = text[i];
        char UP = toupper(CAP);
        text[i] = UP;
        i = i + 1;
    }

    totalLetters = 0;
    for (int j = 0; j < strlen(text); j++)      //sets up the outer most loop to check each char of the users text string
    {
         for (k = 0; k < strlen(LETTERS); k++)  //sets up the nested loop to to check each char in the users text against the LETTERS array
         {
               if (text[j] == LETTERS[k])       //if the current char  matches any letters in the LETTERS array, set n = 0 and exit loop
               {
                   n = 0;
                   break;
               }                                //if no match is found, set n = 1;
                   n = 1;
         }
         if (n == 0)                            //if n = 0; populate the current letter array index with 1
         {
            letters[j] = 1;
         }
         else
         {
            letters[j] = 0;                       //if n = 1, set the current index of the letter array to 0
         }
         totalLetters = totalLetters + letters[j];    //add the current lettercount to the total letters
    }
    return totalLetters;
}

int count_words(string text)
{
    totalWords = 0;
    for (int j = 0; j < strlen(text); j++)      //sets up the outer most loop to check each char of the users text
    {
         for (k = 0; k < strlen(WORDS); k++)   //sets up the nested loop to to check each char in the users text against the WORDS array
         {
               if (text[j] == WORDS[k])        //if the current char matches any chars in the WORDS array, set n = 0 and exit loop
               {
                   n = 0;
                   break;
               }                                //if no match is found, set n = 1;
                   n = 1;
         }
         if (n == 0)                            //if n = 0; populate the current word array index with 1
         {
            letters[j] = 0;
         }
         else
         {
            letters[j] = 1;                       //if n = 1, set the current index of the word array to 0
         }
         totalWords = totalWords + letters[j];    //add the current word count to the total words
    }
    return totalWords+1;
}

int count_sentences(string text)
{
    totalSentences = 0;
    for (int j = 0; j < strlen(text); j++)          //sets up the outer most loop to check each sentence of the users text
    {
         for (k = 0; k < strlen(SENTENCES); k++)    //sets up the nested loop to to check each sentence in the users text against the sentence array
         {
               if (text[j] == SENTENCES[k])         //if the current char matches any chars in the sentence array, set n = 0 and exit loop
               {
                   n = 0;
                   break;
               }                                    //if no match is found, set n = 1;
                   n = 1;
         }
         if (n == 0)                                //if n = 0; populate the current sentence array index with 1
         {
            sentences[j] = 1;
         }
         else
         {
            sentences[j] = 0;                               //if n = 1, set the current index of the sentence array to 0
         }
         totalSentences = totalSentences + sentences[j];    //add the current sentence count to the total sentences
    }
    return totalSentences;
}
