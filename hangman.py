# print('HANGMAN')
# word = "cading is hard"
# guess = 0
# counter = 0
# for i in range(6):
#     guesses = raw_input('Type in your guess')
#     for i in range(len(word)):
#         if word[i] == guesses:
#             print('congrats you got one word')


#             counter = counter + 1


#             print(counter)
#             i = i + 1
#             for i in range(counter):
#                 word2 = word[:]
#                 word2 = word2[:i]
#                 print(word2)
#     guess = guess + 1

def deleteletter(letter, word, frequency):
    for i in range(frequency):
        # newWord = word[:]
        for i in range(len(word)):
            if word[i].lower() == letter.lower():
                word = word[:i] + word[i + 1:]

                break
    return word



# 1. use for loop to go through every letter of the word and take out the letter that was inputted
def trials(guessLetter, word):
    token = 0
    for i in range(len(word)):
        if guessLetter.lower() == word[i].lower():
            return 1

    if token != 1:
        return 2




def main():
    print("Hangman")
    word = 'cdaagh'

    numOfGuesses = 6
    while(numOfGuesses != 0):
        guess = input('Please type in your guess')
        if trials(guess, word) == 1:
            print("congrats you have guessed one letter")
            word = deleteletter(guess, word, 4)
            print(word)


        elif trials(guess, word) == 2:
            print('sorry try again')
            numOfGuesses = numOfGuesses - 1
            print(word)
        elif word == '':
            print('congrats you have successfully completed the game')
    if numOfGuesses == 0:
        print("Gameover")G

main()



