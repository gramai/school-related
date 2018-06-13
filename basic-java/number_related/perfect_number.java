/*
English
Write a program that prints all the perfect numbers between 1 and n 
(given positive integer). A number is considered to be perfect if it is 
equal to the sum of its divisors, starting with 1.

French
Ecrivez un programme qui affiche tous les nombres parfaits compris
entre 1 et n (un entier positif). Un nombre parfait est égal à la somme de
ses diviseurs, en commençant par 1. 

*/
package tp3;

/**
 *
 * @author Grama Emanuel
 */
import javax.swing.JOptionPane;
import static java.lang.Integer.parseInt;
public class all_perfect_numbers {
    public static void main(String[] args){
        String ni;
        int n,i,i2,sum,ok;
        ni=JOptionPane.showInputDialog("Write n");
        n=parseInt(ni);
        System.out.println("1");
        for(i=2;i<=n;i++){
            sum=0;
            for(i2=1;i2<=i/2;i2++){
                if(i%i2==0){
                    sum=sum+i2;
                }
            }
            if(sum==i){
                System.out.println(i);
            }
        }
    }
    
}
