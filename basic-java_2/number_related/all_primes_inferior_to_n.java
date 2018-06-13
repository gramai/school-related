/*
English
Write a program that for a given number n (integer positive), generates and 
prints all the prime numbers inferior to n.

French
Ecrivez un programme qui pour un n donné (entier positif) génère et
imprime tous les nombres premiers inférieurs à n.

*/
package tp3;

/**
 *
 * @author Grama Emanuel
 */
import static java.lang.Integer.parseInt;
import javax.swing.JOptionPane;
public class d_5 {
    public static void main(String[] args){
        int ni,ok=0,i;
        String n;
        n=JOptionPane.showInputDialog("Insert n");
        ni=parseInt(n);
        while(ni>1){
            ok=0;
            for(i=2;i<=ni/2;i++){
                if(ni%i==0){
                    ok=1;
                    i=ni/2+1;
                }
            }
            if(ok==0){
                    System.out.println(ni);
                }
            ni--;
        }
    }
}
