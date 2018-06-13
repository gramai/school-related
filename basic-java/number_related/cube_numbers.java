/*
English
Use a while loop to print the numbers and their cubes as follows

1		1
2		8
3		27
4		64
5		125
6		216
7		343	
8		512
9		729
10		1000

French
Utilisez la boucle while pour afficher le
nombre et son cube comme il suit:

Use a while loop to print the numbers and their cubes as follows: 

1		1
2		8
3		27
4		64
5		125
6		216
7		343	
8		512
9		729
10		1000

*/
import java.lang.Math;
public class e_4 {
    public static void main (String[] args){
        int i=1;
        while (i<=10){
            System.out.println(i+"		"+(int)Math.pow(i,3));
            i++;
        }
        
    }
    
}
