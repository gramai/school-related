/*
English

Write a method of signature
public static int nbYears (double money, doube target, int intereset)
that calculates how many years one has to wait to have at least the
amount "target" of money in their account, if they deposit the sum
"money" at the begining of the first year and receive the procent "interest"
at the end of every year.
For example, calling nbYears(100, 200, 10) will return 8, because after the 
first year, one would have 110$, after two years 121$,.. after 8 years, 214.35$.

French
Écrivez une méthode de signature:
public static int nbYears ( double money, double
target, int interest)
qui calcule combien d'années au minimum je dois attendre
pour avoir au moins la somme d’argent « target » sur mon
compte si je verse la somme « money » au début de la
première année et si je touche « interest » pourcents
d'intérêts à la fin de chaque année. Par exemple, l' appel
nbYears (100, 200, 10) va renvoyer 8 puisque après la
première année, j'ai 110 € sur mon compte, ensuite, après
deux ans , j'ai 121 €, ... et après 8 ans, j'ai 214.35... €.

*/
package tp_5;

/**
 *
 * @author Emanuel
 */
public class d_5 {
    public static int nbYears(double money, double target, int interest){
        int c=0;
        while (money<target){
            c++;
            money=money+money*interest/100;
        }
     return c;   
    }
    public static void main (String[] args){
        double money=100,target=200;
        int interest=10;
        System.out.println(nbYears(money,target,interest));
    }
}
