//Chandaralong Phe
//CS 21
//Midterm 
//10/15/2019
import java.util.*;
public class Midterm
{
    public static void main(String[] args)
    {
        Scanner get = new Scanner(System.in);
        System.out.println("What is your name?");
        String username = get.nextLine();
        System.out.println("How many scores do you have?");
        int numscores = get.nextInt();
        System.out.println("WELCOME \"" + username.toUpperCase() + "\"!\n");
        double average = calculate(numscores);
        System.out.printf("%s has an average of %.1f.\n", username, average);
        LetterGrade(username, average);
        studentStatus(username, average);
    }
    public static double calculate(int numscores)
    {
        System.out.println("Please Enter your Scores!");
        Scanner get = new Scanner(System.in);
        double totalscore = 0;
        for (int i = 1; i <= numscores; i++)
        {
            totalscore += get.nextDouble();
        }
        return totalscore/numscores;   
    }
    public static void LetterGrade(String username, double average)
    {
        char letter = '#';
        if ( average >= 90 && average <= 100.00  )
        {
            letter = 'A';
        }
        else if ( average >= 80 && average < 90  )
        {
            letter = 'B';
        }
        else if ( average >= 70 && average <= 80  )
        {
            letter = 'C';
        }
        else if ( average >= 60 && average <= 70  )
        {
            letter = 'D';
        }
        else if ( average >= 0 && average <= 59 )
        {
            letter = 'F';
        }
        else 
        {
            System.out.println("Invalid Input"); 
        }
        System.out.println(username.toUpperCase() + " YOUR GRADE IS: " + letter); 
    }
    public static void studentStatus(String username, double average)
    {
        String status = "";
        if ( average > (87.3) && average <= 100)
        {
            status = "ABOVE";
        }
        else if ( average == (87.1) || average == (87.2) || average == (87.3) )
        {
            status = "AT";
        }
        else if ( average < (87.1) )
        {
            status = "BELOW"; 
        }
        else 
        {
            System.out.println("Invalid Input"); 
        }
        System.out.println("\"" + username.toUpperCase() + "\"" + " YOU SCORED " + status + " THE CLASS AVERAGE.");    
    }
}