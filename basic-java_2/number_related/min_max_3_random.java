/*
English
Determine the maximum and minimum of 3 random, natural numbers between 0 and 100.

French
Déterminez le maximum et le minimum de 3
nombres aléatoires, naturelles, entre 0 et 100.

@author Grama Emanuel
 */
import java.lang.Math;
public class e_1 {
    public static void main(String[] args){
        int a,b,c,max;
        //Math.random() generates a random float between 0 and 1
        a=(int)(Math.random()*100);
        max=a;
        b=(int)(Math.random()*100);
        if(b>max){
            max=b;
        }
        c=(int)(Math.random()*100);
        if(c>max){
            max=c;
        }
        System.out.println(max);
    }
    
}
