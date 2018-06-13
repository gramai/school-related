/*
English 
Solve a second degree ecuation

French
Résolvez une équation du deuxième degré.

*/
package tp3;

/**
 *
 * @author Grama Emanuel
 */
import  javax.swing.JOptionPane;
import static java.lang.Double.parseDouble;
import java.lang.Math;
public class d_3 {
    public static void main(String[] args){
        String a,b,c;
        double ad,bd,cd,d;
        a=JOptionPane.showInputDialog("First coeff");
        b=JOptionPane.showInputDialog("Second coeff");
        c=JOptionPane.showInputDialog("Third coeff");
        ad=parseDouble(a);
        bd=parseDouble(b);
        cd=parseDouble(c);
        //ax^2+bx+c=0;
        d=bd*bd-4*ad*cd;
        if(d<0){
            System.out.println("solution is complex");
            System.out.println("First solution is ("+(-bd)+" + "+Math.sqrt(-d)+"i"+")/"+2*ad);
            System.out.println("Second solution is ("+(-bd)+" "+(-Math.sqrt(-d))+"i"+")/"+2*ad);
        }
        else{
            System.out.println(2*ad);
            System.out.println(bd);
            System.out.println(cd);
            System.out.println(d);
            System.out.println("First solution is "+(((-bd)+Math.sqrt(d))/(2*ad)));
            System.out.println("Second solution is "+(((-bd)-Math.sqrt(d))/(2*ad)));
        }
    }
}
