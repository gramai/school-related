/*

@author Grama Emanuel
English
Write a program that prints the following examples:

French
Ecrivez un programme qui affiche les
exemples suivants:


*
* *
* * *  
* * * *
* * * * *
* * * * * *
* * * * * * *
* * * * * * * *
* * * * * * * * *
* * * * * * * * * *

* * * * * * * * * *
* * * * * * * * *
* * * * * * * *
* * * * * * *
* * * * * *
* * * * *
* * * *
* * *  
* *
*

 */
/**
 *
 * @author Grama Emanuel
 */
public class e_6 {
    public static void main(String[] args){
        int i,i2;
        for(i=1;i<=10;i++){
            i2=i;
            while(i2>0){
                System.out.print("* ");
                i2--;
            }
            System.out.println();
        }
        
        System.out.println();
        for(i=10;i>=1;i--){
            i2=i;
            while(i2>0){
                System.out.print("* ");
                i2--;
            }
            System.out.println();
        }
    }
}
