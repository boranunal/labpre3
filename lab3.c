#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define SIZE 2000
#define WORDSIZE 20

char text[SIZE];
char *helper;

void fillText();
void printText();
void countCharacters(int *charCountP);
void countWords(int *wordCountP);
int searchWord(char *searchedWordP, int *startP, int *endP);
void removeSpaces();
void runLab3();
char *word;

int main()
{
	word = (char *) malloc(WORDSIZE * sizeof(char));
	fillText();
	/*runLab3();*/	/* Uncomment this line when you complete your functions */
	/*printText();*/
	return 0;
}

void runLab3()
{
	int wordCount=0, characterCount=0, startIndex, endIndex;
	scanf("%s", word);
	printText();
	countCharacters(&characterCount);
	countWords(&wordCount);
	printf("%d\n", characterCount);
	printf("%d\n", wordCount);
	if(searchWord(word, &startIndex, &endIndex))
		printf("%s %d %d\n", word, startIndex, endIndex);
	else
		printf("No result\n");
	removeSpaces();
	printText();
}

void countCharacters(int *charCountP)
{
	int i, count = 0;
	for(i=0; text[i]!='\n'; ++i){
		if(!isspace(text[i])) ++count;
	}
	charCountP = &count;
}

void countWords(int *wordCountP)
{
	int i, count = 0;
	for(i=0; text[i]!='\n'; ++i){
		if(isalnum(text[i]) || ispunct(text[i])) {
			if(isspace(text[i+1]) || text[i+1] == '\n') ++count;
		}
	}
	wordCountP = &count;
}

int searchWord(char *searchedWordP, int *startP, int *endP)
{
	int i = 0;
	while(text[i] != '\n'){
		if(isalnum(text[i])){
			for(j = 0; !isspace(text[i+j]); ++j){
				if(text[i+j]==searchedWordP[j])
			}
		}
	}
	++i;
}

void removeSpaces()
{
	/* Your code here */
}

void fillText()
{
	int i;
	helper = (char *) malloc(SIZE * sizeof(char));

	helper = "My         message is that we'll be watching you. This is all wrong. I shouldn't be up here. I should be back in school on the other side of the ocean. Yet you all come to us young people for hope. How dare you! You have stolen my dreams           and my childhood with your empty words. And yet I'm one of the lucky ones. People are suffering. People are dying. Entire ecosystems are         collapsing. \n";

	for(i=0; ; i++)
	{
		text[i] = helper[i];
		if(helper[i] == '\n')
			break;
	}
}

void printText()
{
	int i;
	for(i=0; i<SIZE; i++)
	{
		printf("%c", text[i]);
		if(text[i] == '\n')
			break;
	}
}
