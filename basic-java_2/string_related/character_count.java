/*
English
Given the following string, count the number of aparitions of the 'a' character and 'e' respectively.
Print the number of apparitions of each letter.


French
Soit la chaine de caractères suivante. Vous devez la
parcourir et compter le nombre d’apparitions des
caractères ‘a’, respectivement ‘e’. Affichez le nombre
d’apparitions de chaque lettre.


"Le concept d’intelligence artificielle forte fait reference a une machine capable non seulement de produire un comportement intelligent, mais d’eprouver une impression d'une reelle conscience de soi ..."

@author Grama Emanuel
*/
import javax.swing.JOptionPane;
public class e_3 {
    public static void main(String[] args){
    String str = "Le concept d’intelligence artificielle forte fait reference a une machine capable non seulement de produire un comportement intelligent, mais d’eprouver une impression d'une reelle conscience de soi ...";
    int i,e=0,a=0;
    for(i=0;i<str.length();i++){
        if(str.charAt(i)== 'e' || str.charAt(i)=='E'){
            e++;
        }
        else if (str.charAt(i)=='a' || str.charAt(i)=='A' ){
            a++;
        }
    }
    System.out.println("'a' appears "+a+" times and e appears  "+ e+ " times ");
    }
}
