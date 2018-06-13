/*
English
Write a program that reads from user input a certain number of strings
and sorts them dynamically.
For exemple:
6
Shai
Ralph
Hillary
Tom
Barbara
Fred
Will produce this development in the arrays:
[Empty]
[Shai]
[Ralph, Shai]
[Hillary, Ralph, Shai]
[Hillary, Ralph, Shai, Tom]
[Barbara, Hillary, Ralph, Shai, Tom]
[Barbara, Fred, Hillary, Ralph, Shai, Tom] 

French
Ecrivez un programme qui lit du clavier un
certain nombre de Strings et fait le tri
dynamiquement, en insérant le String sur la
position correcte a chaque pas dans l’ArrayList.
Hint: Vous pouvez utiliser une méthode
appelée compareTo.
Par exemple:
6
Shai
Ralph
Hillary
Tom
Barbara
Fred
vont produire le développement suivant de l’ArrayList:
[Empty]
[Shai]
[Ralph, Shai]
[Hillary, Ralph, Shai]
[Hillary, Ralph, Shai, Tom]
[Barbara, Hillary, Ralph, Shai, Tom]
[Barbara, Fred, Hillary, Ralph, Shai, Tom] 


*/
package tp_6;

/**
 *
 * @author Emanuel
 */
import java.util.Scanner;
import java.util.ArrayList;
public class d_3 {
    public static void main (String[] args){
        int i,i2,n,ok,added=0;
        ArrayList <String> list = new ArrayList<>();
        String s;
        System.out.println("insert number of strings");
        Scanner sc= new Scanner(System.in);
        Scanner sc2 = new Scanner(System.in);
        n=sc.nextInt();
        i=0;
        String l1,l2;
        list.add(sc2.nextLine());
        i++;
        n--;
        System.out.println("List is "+ list);
        while(n>0){
            s=sc2.nextLine();
            System.out.println("NextLine is "+ s);
            for(i2=0;i2<i;i2++){
                l2=String.valueOf(s.charAt(0));
                l1=String.valueOf(list.get(i2).charAt(0));
                System.out.println(" l1 and l2 are " + l1 + l2);
                ok=l1.compareTo(l2);
                System.out.println("OK is " + ok);
                if(ok>0 ){
                    list.add(i2,s);
                    i2=i;
                }
                else if (i2+1==i){
                    list.add(i2+1,s);
                    i2=i;
                }
            }
            System.out.println("List is "+ list);
            i++;
            n--;
        }
        System.out.println("List is "+ list);
    }
}
