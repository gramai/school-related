/*
English
Write a method of signature
public static int binToDec (String bin)
that takes as parameter a string formed 
only by '0' and '1', representing a binary number.
The function will convert the binary number to decimal.
For example, calling binToDec("001001"), returns 9

French
Écrivez une méthode de signature
public static int binToDec (String bin)
qui prend en paramètre une chaîne de caractères formées
uniquement de 0 et 1 représentant un nombre binaire et qui
le convertit dans un nombre décimal.
Par exemple l'appel binToDec("001001") renvoie 9 (23 + 20).

*/
package tp_5;

/**
 *
 * @author Emanuel
 */
import javax.swing.JOptionPane;
import static java.lang.Integer.parseInt;
import java.lang.Math;
public class d_4 {
    public static double binToDec(String bin){
        int i;
        double c=-1,nl,dec=0;
        for(i=bin.length()-1;i>=0;i--){
            c++;
            nl=parseInt(bin.substring(i,i+1));
            if (nl==1){
                dec= dec + Math.pow(2,c);
            }
        }
        
        return dec;
    }
    public static void main (String[] args){
        String bin;
        bin="011001";
        System.out.println(binToDec(bin));
    }
}
