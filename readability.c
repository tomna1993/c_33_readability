#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int validate_text(string text);

int main(void)
{
	// Get text for validation
	string user_Text = get_string("Text: ");

	// Validate text and print grade
	printf("Grade: %i\n", validate_text(user_Text));
}

int validate_text(string text)
{
	int letters = 0, words = 0, sentences = 0;

	int text_length = strlen(text);

	for (int i = 0; i < text_length; i++)
	{
		if ((text[i] >= 'a' && text[i] <= 'z') ||
			(text[i] >= 'A' && text[i] <= 'Z'))
		{
			letters++;
		}
		else if (text[i] == ' ')
		{
			words++;
		}
		else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
		{
			sentences++;
		}
	}

	words++;

	printf("letters: %i, words: %i, sentences: %i\n", letters, words, sentences);

	float avg_L = letters / (float) words * 100.0;

	float avg_S = sentences / (float) words * 100.0; 

	float Coleman_Liau_formula = (0.0588 * avg_L) - (0.296 * avg_S) - 15.8;

	return round(Coleman_Liau_formula);
}
