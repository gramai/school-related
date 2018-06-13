/*
English
Write a program that reads from user input two ArrayLists with 
certain numbers. Create a third ArrayList containing the commun
numbers of the first two lists.

French
Ecrivez un programme qui lit du clavier deux
ArrayList avec certains nombres. Créez un
troisième ArrayList contenant les nombres
communs des deux listes précédentes.
*/
package tp_6;

/**
 *
 * @author Emanuel
 */
import java.util.ArrayList;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class ex_1 {
    public static void main (String[] args) throws IOException{
        BufferedReader bf= new BufferedReader( new InputStreamReader(System.in));
       
        Scanner sc = new Scanner(System.in);
        Scanner sc2= new Scanner(System.in);
        ArrayList <Integer> list_1= new ArrayList <>();
        ArrayList <Integer> list_2= new ArrayList <>();
        ArrayList <Integer> list_3=new ArrayList <>();

        System.out.println("Insert elements of list 1, then press a non-numerical character followed by ENTER");
        while (sc.hasNextInt()){
            list_1.add(sc.nextInt());
        }
        
        System.out.println("Insert elements of list 2, then press a non-numerical character followed by ENTER");
        
        while (sc2.hasNextInt()){
            list_2.add(sc2.nextInt());
        }
        
        System.out.println("First list is " + list_1);
        System.out.println("Second list is " + list_2);
        
       int i,num;
       for(i=0;i< list_1.size();i++){
           num=list_1.get(i);
           if(list_2.contains(num)){
               list_3.add(num);
           }
       }
        System.out.println("The list having common elements from list 1 and list 2 is " + list_3);
        
        
        
        
    }
    
}
