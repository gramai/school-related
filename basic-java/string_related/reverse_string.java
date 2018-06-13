/*
English
Write a method having the signature 
          public static String reverse(String str)
that returns the reverse of a string. That means that it
constructs another string of the str read from right-to-left.
For example, calling reverse("Hello World"); will return
the string dlroW olleH.

French
Écrivez une méthode de signature »
public static String reverse (String str)
qui permet d'inverser une chaîne de caractères, c'est-
à-dire construire une chaîne de caractères
correspondant à str lue de droite à gauche. Par
exemple, l'appel reverse("Bonjour Monde"); renvoie la
chaine de caractères ednoM ruojnoB.

*/

/**
 *
 * @author Emanuel
 */
public class d_3 {
    public static String reverse (String str){
        String str2;
        int i;
        str2=str.substring(str.length()-1,str.length());
        for(i=str.length()-2;i>=0;i--){
            str2=str2+str.substring(i,i+1);
        }
        System.out.println(str);
        System.out.println(str2);
        return str2;
    }
   public static void main(String[] args){
       String str="abcdef";
       reverse(str);
   } 
}
