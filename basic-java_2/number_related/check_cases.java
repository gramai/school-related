/*
English
Write a program that gets three natural numbers as imput and verifies if those 
three numbers correspond to the values 1,2,3 , independent of the order
they are entered
 
French
Ecrivez un programme qui lit trois nombres naturels (avec JOptionPane).
Il vérifie si ces trois numéros correspondent aux valeurs 1, 2, 3,
indépendamment de leur ordre et affiche un message suggestif.

*/

/**
 *
 * @author Grama Emanuel
 */
import static java.lang.Integer.parseInt;
import javax.swing.JOptionPane;
public class d_1 {
    public static void main(String[] args){
        String a,b,c;
        int ai,bi,ci;
        int[] v;
        v=new int[10];
        a=JOptionPane.showInputDialog("Write first number");
        b=JOptionPane.showInputDialog("Write second number");
        c=JOptionPane.showInputDialog("Write third number");
        ai=parseInt(a);
        bi=parseInt(b);
        ci=parseInt(c);
        v[ai]=1;
        v[bi]=1;
        v[ci]=1;
        if(v[1]==v[2]&&v[2]==v[3]&&v[1]==1){
            System.out.println("TRUE");
        }
        else{
        System.out.println("FALSE");    
        }
        
    }
}
