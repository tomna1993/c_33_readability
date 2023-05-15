#include <cs50.h>
#include <ctype.h>
// math.h included to use the round() function
#include <math.h>
#include <stdio.h>
#include <string.h>

int validate_text(string text);

int main(void)
{
	// Get text for validation
	string user_Text = get_string("Text: ");

	// Get sentence's grade 
	int grade = validate_text(user_Text);

	// Check and print grade
	if (grade < 1)
	{
		printf("Before grade 1\n");	
	}
	else if (grade > 16)
	{
		printf("Grade: 16+\n");	
	}
	else
	{
		printf("Grade: %i\n", grade);
	}	
	
	return 0;
}

int validate_text(string text)
{
	int letters = 0, words = 0, sentences = 0;

	int text_length = strlen(text);
	
	// Iterate through the given text
	for (int i = 0; i < text_length; i++)
	{
		// If character is between 'a' and 'z' or 'A' and 'Z', it is a letter
		if (isalpha(text[i]))
		{
			letters++;
		}
		// If character is space ' ' then, there was a word
		// Two spaces aren't accepted
		else if (isspace(text[i]) && !isspace(text[i-1]))
		{
			words++;
		}
		// If character is '.' or '!' or '?', there was a sentence
		else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
		{
			sentences++;
		}
	}
 
	// The last word is not counted because there is no space character after it
	// so we need to add one to the word variable to count it
	words++;

	// For debugging the code above
	// printf("letters: %i, words: %i, sentences: %i\n", letters, words, sentences);

	float avg_L = letters / (float) words * 100.0;

	float avg_S = sentences / (float) words * 100.0; 

	// Calculate the Coleman-Liau index
	float Coleman_Liau_formula = (0.0588 * avg_L) - (0.296 * avg_S) - 15.8;

	// Round the index to the nearest integer value and return it
	return round(Coleman_Liau_formula);
}
