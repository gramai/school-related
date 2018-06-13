/*
English
The following table contains the grades obtained by students at the calculus
exam:
int[] note = {7, 8, 6, 10, 9, 6, 5, 5, 6, 7, 7, 7, 7, 6,
6, 6};
a) Calculate the mean
b) Calculate the mode of the numbers ( the mode is the most common element of
   the table)
c) Calculate the median of the numbers ( the median is the grade placed at the
   middle of the sorted table)


French
Soit le tableau suivant, ayant les notes obtenus
par les étudiants a l’examen d’Analyse:
int[] note = {7, 8, 6, 10, 9, 6, 5, 5, 6, 7, 7, 7, 7, 6,
6, 6};
a) Calculez la moyenne arithmétique
b) Calculez le « mode » de ces nombres (Le
mode = la valeur la plus fréquente)
c) Calculez la « médiane» de ces nombres (La
médiane = la note située au milieu du tableau,
après son tri; si le nombre d’éléments est pair, la
médiane est la moyenne arithmétique des nombres
situés au milieu)



*/
package tp_4;

/**
 *
 * @author Grama Emanuel
 */
import java.util.Arrays;
public class e_5 {
    public static void main(String[] args){
        int[] note= {7, 8, 6, 10, 9, 6, 5, 5, 6, 7, 7, 7, 7, 6, 6, 6};
        int [] freq=new int[11];
        int i,med=0,max=0, len=note.length;
        double id;
        for(i=0;i<len;i++){
            med=med+note[i];
            freq[note[i]]++;
        }
        for(i=1;i<11;i++){
            if(freq[i]>max){
                max=i;
            }
        }
        id=med;
        id=id/len;
        System.out.println("The mean is " + id + " and the most frequent grade is " + max);
        Arrays.sort(note);
        double sum;
        if(len%2==0){
            sum=(note[len/2]+note[len/2+1])/2;
        }
        else{
            sum=note[len/2];
        }
        System.out.println("The median is : "+sum);
        
    }
    
}
