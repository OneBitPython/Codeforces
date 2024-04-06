# Importing modules

from random import randrange, choice





# Introduction to script

def intro():

    intro_str = [

        "In this python project, we have two games to play:",

        "1. Rock Paper Scissors",

        "2. Guess the number",

        "",

        "To play rock-paper-scissors, type 1",

        "To play guess the number, type 2"

    ]

    for i in intro_str:

        print(i)





# Function to accept which game the user wants to play

def accept_game():

    while True:

        g = input("\nEnter 1 or 2 for the game, and 0 to quit the program:\t")

        if g not in ['0', '1', '2']:

            print('Please enter 0, 1 or 2')

            continue

        return int(g)





# Rock Paper Scissors function

def rock_paper_scissors():

    order_of_winning = {

        "rock": "scissor",

        "scissor": "paper",

        "paper": "rock"

    }

    while True:

        print("If you want to exit the game, enter 'quit'")

        user_play = input("\nEnter your play: rock, paper, scissor (or quit);\nYour play:\t")

        if user_play.lower() == 'quit':

            print("Thank you for playing! You may now play the other game.\n\n")

            break

        if user_play.lower() not in ['rock', 'paper', 'scissor']:

            print("Please enter rock, paper or scissor")

            continue

        comp_play = choice(['rock', 'paper', 'scissor'])

        print(f"Computer plays:\t{comp_play}")

        if user_play == comp_play:

            print("Tie!")

        elif user_play != order_of_winning[comp_play]:

            print("You win!")

        else:

            print("Computer wins!")

    print("Thank you for playing! You may now play the other game.\n\n")





# Guess the number function

def guess_the_number():

    meta_range = 1000

    while True:

        no_tries = 0

        starting_range = randrange(0, meta_range)

        number = randrange(starting_range, starting_range + meta_range)

        print(f"\n The computer has an integer between {starting_range} and {starting_range + meta_range}")

        while True:

            user_guess = input("Enter your guess:\t")

            if not user_guess.isnumeric():

                print("Your guess must be an integer!")

                continue

            no_tries += 1

            if int(user_guess) == number:

                print(f"\nGood job! You got it in {no_tries} tries!")

                break

            elif int(user_guess) < number:

                print("Your guess is lower than my number!")

            else:

                print("Your guess is higher than my number!")

        print("\nWould you like to play again?")

        play_again = input("Enter 'yes' to play again, anything else to quit:\t")

        if play_again.lower() != 'yes':

            break

    print("Thank you for playing! You may now play the other game.\n\n")





intro()

while True:

    game = accept_game()

    if game == 0:

        print("We hope you had fun!")

        print("Exiting the program")

        break

    elif game == 1:

        rock_paper_scissors()

    else:

        guess_the_number()