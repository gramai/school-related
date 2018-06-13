/*
English
Use a recursive function to calculate the polynom of Hermite, knowing that:
H0 (x) = 1, H1(x) = x, H2(x) = x^2 - 1, for all n >= 1
Hn+1(x) + nH-1(x) = xHn(x)

French
Utilisez une fonction récursive pour calculer
les polynômes d’Hermite. On sait que:
H0 (x) = 1, H1(x) = x, H2(x) = x^2 - 1, pour tout n >= 1
Hn+1(x) + nH-1(x) = xHn(x)

*/
package tp_6;

/**
 *
 * @author Emanuel
 */
import java.util.Scanner;
public class ex_3 {
    
    public static double hermite (int n,double x){
        double x1=0,h;
        switch (n) {
            case 1:
                h=x;
                break;
            case 0:
                h=1;
                break;
            default:
                h=x*hermite(n-1,x)-(n-1)*hermite(n-2,x);
                break;
        }
        return h;
    }
    public static void main (String[] args){
        int n;
        double h,x;
        Scanner sc = new Scanner (System.in);
        System.out.println("Insert n + x + char + enter ");
        n=sc.nextInt();
        x=sc.nextInt();
        h=hermite(n,x);
        System.out.println(h);
    }
}
