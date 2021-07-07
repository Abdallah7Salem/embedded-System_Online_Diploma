// C Program To Check Vowel Or Consonant 

#include "stdio.h"

void main()
{
	char c;
	printf("Enter an alphabet: ");
	scanf("%c", &c);
	
	switch(c)
	{
	case 'a':
		printf("a is a vowel.");
		break;
	
	case 'o':
		printf("o is a vowel.");
		break;
	
	case 'i':
		printf("i is a vowel.");
		break;
	
	case 'e':
		printf("e is a vowel.");
		break;
	
	case 'u':
		printf("u is a vowel.");
		break;
		
	default:
		printf("%c is a consonant.", c);
	}
}