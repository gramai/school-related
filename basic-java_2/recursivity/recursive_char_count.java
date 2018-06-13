/*
English
Write a recursive function that calculates how many times a letter appears
in a text. The function has two parameters, the letter to count (char) and the
text (String)

French
Écrivez une fonction récursive qui calcule
combien de fois une lettre apparaît dans un
texte. La fonction a deux paramètres: la lettre
(char) et le texte (String).

*/
package tp_6;

/**
 *
 * @author Emanuel
 */
public class d_1 {
    public static int litere(String s,int i,int n){
        int fcount=0;
        switch (i){
            case 0:
                if(s.charAt(0)=='a'||s.charAt(0)=='A'){
                fcount=n+1;
                }
                else{
                    fcount=n;
                }
                break;
            default:
                if(s.charAt(i)=='a'||s.charAt(i)=='A'){
                    fcount=litere(s,i-1,n+1);
                }
                else{
                    fcount=litere(s,i-1,n);
                }
                
        }
        return fcount;
    }
    public static void main(String[] args){
        String s= "Ana are mere";
        int fcount=litere(s,s.length()-1,0);
        System.out.println(" 'a' appears " + fcount + " times");
    }
    
}
