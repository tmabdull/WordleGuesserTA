// Other functions...

// Function to submit guesses
void gameLoop() {
	char guess[WORD_LENGTH + 1] = {0};
	int guesses = 0;
	int scan = 0;

	//Taha: Create a string array (2D array) that is equal to the return value of filterWords using the impossible_array which is intially blank
	// filterWords() will return a list of possible guesses -- 1 of these words is the correct answer
	char **testGuesses = filterWords(impossible_array);
	int testGuesses_counter = 0; //Taha: Indexing var to be used in the while loop
	
	//Taha: This for loop was originally in a different location that caused error (I think the computer guessed the same thing repeatedly)
	for (unsigned int i = 0; i < 26; i++) {
		if (alpha[i] == '_') {
			impossible_array[impossible_current] = (char) ('a' + i);
			impossible_current++;
		}
	}

	puts(
		"word\tunused alphabet" EOL
		"====\t===============");
	while (guesses < MAX_TRIES && strcmp(guess, word)) {
		printf("Guess %i: ", guesses + 1);

		strcpy(guess,testGuesses[testGuesses_counter]); //Taha: Assigns guess with a word from the filterWords() results
		testGuesses_counter++; //Taha: Increment to go to the next word

        toLower(guess);
        //Do not bother doing all the test logic if we've found the word.
        if (strcmp(guess, word)) {
            if (isWord(guess) && hasWord(guess)) {
                ++guesses;
                //TODO: Check guess against word
                if (checkWord(guess)) {
                    removeAlpha(guess);
                    printf("\t%s\n", alpha);
                }
            } else {
                puts("Word not in list");
            }
        }
	}
	if (strcmp(guess, word)) {
		printf("You lose. The word was %s\n", word);
	} else {
		puts("You win");
	}
}

// Other functions...
