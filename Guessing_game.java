import java.util.*;
/*Chandaralong Phe
 *CS 21
 */
public class Guess
{
    public static final int range = 100; //Range of the Guessing numbers
    public static void main(String[] args)
    {
        instructions(); //Method Call to display an instruction of the game
        int guess = game(); //Executed game method and store the return value of tries into variable guess
        int totalguess = guess; // The sum of the number of total tries
        int maxguess = guess; // The largest number of tries
        int gameplay = 1; // Initialize the number of gameplay to 1 indicating the game has been played once
        System.out.println("You got it right in " + guess + " guesses" );
        Scanner get = new Scanner(System.in);
        System.out.print("\nDo you want to play again? Type Yes to continue and No to end the game.");
        while (get.hasNext()) //Test to see if the user type in the answer. It will be an infinite loop so we need a break statement
        {
            String answer = get.next().toLowerCase(); //Store the user input and make it lowercase
            if (answer.charAt(0) == 'y') //If the user type in "Yes" or "yes" 
            {
                int nextguess = game(); //Executed game method while storing the return value of tries in the next game into variable nextguess
                System.out.println("You got it right in " + nextguess + " guesses" ); 
                totalguess += nextguess; //Calculating the number of totalguesses in each gameplay
                maxguess = Math.max(maxguess,nextguess); //Compare and store the largest number of tries in each gameplay 
                gameplay++; //Iterate the number of gameplay
                System.out.print("\nDo you want to play again? Type Yes to continue and No to end the game. "); 
            }
            else if (answer.charAt(0) == 'n') //If the user type in "No" or "no" 
            {
                report(gameplay, totalguess, maxguess); //Call out the report method that will print out your game statistic 
                break; //break out of the while loop
            }
            else //Test if the user type in anything else beside yes or no
            {
                System.out.print("Invalid Response.\nDo you want to play again? Type Yes to continue and No to end the game. ");
            }
        }
    }
    public static void instructions() //Instruction method that will print out game instruction when called
    {
        System.out.println("This program allows you to play a guessing game.\nI will think of a number between 1 and " + range + "\nand will allow you to guess until you get it.\nFor each guess, I will tell you whether the\nright answer is higher or lower than your guess.");   
    }
    public static int game() //Game method that will return the number of tries in type int
    {
        Random r = new Random(); 
        Scanner get = new Scanner(System.in);
        int goal = r.nextInt(range) + 1; // Generate a random number from 1 to range inclusive
        System.out.println(); 
        System.out.println("I am thinking of a number... ");
        int counter = 0; 
        boolean win = false; //Initializing a boolean flag win to false
        while(win == false) 
        {
            System.out.print("Your guess? ");
            counter++;
            if (get.hasNextInt())
            {
                int guess = get.nextInt(); //Store the number you guessed
                if(guess > 0 && guess <= range && guess > goal)
                {
                    System.out.println("lower"); //Indicate that the correct number is higher than the number you just guessed
                }
                else if (guess > 0 && guess <= range && guess < goal)
                {
                    System.out.println("higher"); //Indicate that the correct number is higher than the number you just guessed
                }
                else if (guess == goal) 
                {
                    win = true; //Will break out of while loop 
                }
            }
            else 
            {
                System.out.print("Wrong Input! Please enter an integer. Your guess? ");
                get.next();
            }
        }
        return counter; //return the number of tries 
    }
    public static void report(int gameplay, int totalguess, int maxguess) //Method report to print out the statistic of the game 
    {
        double avg = ((double)(totalguess)/gameplay); //convert int into double
        System.out.println ("\nOverall results:");
        System.out.println("\ttotal games\t= " + gameplay);
        System.out.println("\ttotal guesses\t= " + totalguess);
        System.out.println("\tguesses/game\t= " + avg );
        System.out.println("\tmax guesses\t= " + maxguess );
    }
}
