//Felipe Quezada
//Chandaralong Phe 
//CS 21
import java.util.*;

public class Quiz
{
    public static void main(String [] args)
    {
        System.out.println("\tFelipe's and Long's Life Quiz \n \n");
        String [][] quest = new String [10][4]; //Q&A arrays
        String [] ans = new String [10]; //Correct answer arrays
        questionArray(quest); 
        ansArray(ans);
        print(quest, ans);
    }
    public static void questionArray(String [][] quest) //Method to store Questions and Answers into a two dimensional arrays 
    {
        quest[0][0] = "What is Long's favorite food?\n ";
        quest[0][1] = "\tA. Sushi ";
        quest[0][2] = "\tB. Bibimbap ";
        quest[0][3] = "\tC. Taco ";
        
        quest[1][0] = "What is Felipe's favorite hobbie?\n ";
        quest[1][1] = "\tA. Playing soccer";
        quest[1][2] = "\tB. Working Out";
        quest[1][3] = "\tC. Doing puzzles";
        
        quest[2][0] = "What is Long's most favorite show?\n ";
        quest[2][1] = "\tA. Friends";
        quest[2][2] = "\tB. Rick and Morty";
        quest[2][3] = "\tC. The Office";
        
        quest[3][0] = "What sport has Felipe played?\n ";
        quest[3][1] = "\tA. Football";
        quest[3][2] = "\tB. Baseball";
        quest[3][3] = "\tC. Basketball";
        
        quest[4][0] = "What subject does Long hate?\n ";
        quest[4][1] = "\tA. Math";
        quest[4][2] = "\tB. Chemistry";
        quest[4][3] = "\tC. Physic";
        
        quest[5][0]= "How long has Felipe been alive?\n ";
        quest[5][1] = "\tA. 19 years";
        quest[5][2] = "\tB. 21 years";
        quest[5][3] = "\tC. 20 years";
        
        quest[6][0] = "What is Long's biggest fear?\n";
        quest[6][1] = "\tA. Ghost";
        quest[6][2] = "\tB. Bugs";
        quest[6][3] = "\tC. Death";
        
        quest[7][0] = "What other language does Felipe know?\n";
        quest[7][1] = "\tA. Spanish";
        quest[7][2] = "\tB. Japanese";
        quest[7][3] = "\tC. French";
        
        quest[8][0] = "How often is Long late for class?\n ";
        quest[8][1] = "\tA. Never";
        quest[8][2] = "\tB. Almost Never";
        quest[8][3] = "\tC. Most of the time";
        
        quest[9][0] = "What was Felipe's first gaming console?\n\n ";
        quest[9][1] = "\tA. GameBoy";
        quest[9][2] = "\tB. Original Xbox";
        quest[9][3] = "\tC. Wii";
    }
    public static void ansArray(String[] ans) // Method to store correct answer into an array
    {
        ans[0] = "A";
        ans[1] = "B";
        ans[2] = "B";
        ans[3] = "B";
        ans[4] = "C";
        ans[5] = "C";
        ans[6] = "B";
        ans[7] = "A";
        ans[8] = "C";
        ans[9] = "A";
    }
    public static void print(String [][] questAns, String [] ans) //Method to print out the Q&A + user input + print result
    {
        Scanner input = new Scanner(System.in);
        int row = 0;
        int correct = 0;
        int incorrect = 0;
        while (row < questAns.length)
        {
            for (int col = 0 ; col < questAns[row].length; col++ )
            {
                System.out.println(questAns[row][col]);
            }
            System.out.print("\nPlease Choose A, B, or C. Enter response : ");
            String answer = input.next();
            while(!answer.equalsIgnoreCase("a") && !answer.equalsIgnoreCase("b") && !answer.equalsIgnoreCase("c")) //Validating User input
            {
                System.out.print("Invalid response! Choose A, B, or C: ");
                answer = input.next();
            }       
            if (answer.equalsIgnoreCase(ans[row]))
            {
                System.out.println("\nCorrect!\n");
                correct++;
            }
            else
            {
                System.out.println("\nThe correct answer is " + ans[row] + ".\n" );
                incorrect++;
            } 
            row++;
        }
        System.out.println("Result: \nNumber of anwers you got correct = " + correct);
        System.out.println("Number of anwers you got incorrect = " + incorrect);
    } 
}
