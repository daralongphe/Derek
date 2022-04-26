//Chandaralong Phe
//CS 21
import java.util.*;
import java.io.*;

public class ScanFile
{
    public static void main (String[] args) throws FileNotFoundException
    {
        int line = 0;
        String[] bowler_id = new String[50];
        String[] full_name = new String[50];
        int[] score = new int[50];
        Scanner read = new Scanner(new File("bowlingscores.txt"));
        while(read.hasNextLine())
        {
            String linescan = read.nextLine();
            Scanner get = new Scanner(linescan);
            while (get.hasNext())
            {
                score[line] = get.nextInt();
                bowler_id[line] = get.next();
                full_name[line] = get.nextLine();
            }
            line++;
        }
        printRoster(full_name, bowler_id);
        printLowest(full_name, bowler_id, score);
        printHighest(full_name, bowler_id, score);
    }
    public static void printRoster(String[] name, String[] id)
    {
        for(int i =0; i < name.length; i++)
        {
            if (name[i] != null)
            {
                System.out.println( (i+1) + ". " + id[i] + " " + name[i]);
            }
        }
    }
    public static void printLowest(String[] name, String[] id, int[] score)
    {
        int val = score[0];
        for(int i =0; i < name.length; i++)
        {
            if (name[i] != null)
            {
                if(score[i] < val)
                {
                    val = score[i];
                }
            }
        }
        System.out.println("\nLowest Score Player(s): ");
        for(int i =0; i < name.length; i++)
        {
            if (name[i] != null)
            {
                if(score[i] == val)
                {
                    System.out.println( score[i] + " " +id[i] + " " + name[i] );
                }
            }
        }
    }
    public static void printHighest(String[] name, String[] id, int[] score)
    {
        int val = score[0];
        for(int i =0; i < name.length; i++)
        {
            if (name[i] != null)
            {
                if(score[i] > val)
                {
                    val = score[i];
                }
            }
        }
        System.out.println("\nHighest Score Player(s): ");
        for(int i =0; i < name.length; i++)
        {
            if (name[i] != null)
            {
                if(score[i] == val)
                {
                    System.out.println( score[i] + " " +id[i] + " " + name[i] );
                }
            }
        }
    }
}

