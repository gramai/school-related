/*
English
Write a program that, for a given n (integer, positive), determines if all
its divisords are prime numbers.

French
Ecrivez un programme qui pour un n donné (entier positif) détermine si
tous ses diviseurs sont premiers ou non.

*/
package tp3;

/**
 *
 * @author Grama Emanuel
 */
import javax.swing.JOptionPane;
import static java.lang.Integer.parseInt;
public class d_6 {
    public static void main (String[] args){
        String ni;
        int n,i,ok=0,i2,j,ok_gen;
        ni=JOptionPane.showInputDialog("Insert n");
        n=parseInt(ni);
        for(i=2;i<=n/2;i++){
            if(n%i==0){
               i2=i;
               for (j=2;j<=i2/2;j++){
                   if(i2%j==0){
                    ok=1;
                    break;
                    }
                }
            }
         }
        if(ok==1){
            System.out.println("not-prime");
        }
        else{
            System.out.println("prime");
        }
    }
}
