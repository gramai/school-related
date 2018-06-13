/*
English
Write a recursive function that calclates the n'th element of an arithmetic 
progression of ratio r. Then, in the main metod of the program, consider the 
list v with 5 elements: v={2,4,6,8,10}
Verify if the elements of the list are in arithmetical progression and 
calculate the sixth element of the progression, using the written function.
Hint:
ak = a1 + (k - 1)r, ak is the k'th element of the arithmetical progression
a1 is the first element of the progression
r is the ratio.

French
Écrivez une fonction récursive qui calcule le
n-ième élément d'une suite arithmétique. La
fonction a deux paramètres: le premier
élément de la suite et la raison r. Puis, dans la
méthode main du programme, considérez le
tableau v avec 5 éléments: v={2,4,6,8,10}.
Vérifiez si les éléments du tableau sont en
suite arithmétique et calculez le sixième
élément de la suite, à l'aide de votre fonction.
Rappel: ak = a1 + (k - 1)r, ak est le k-ième
élément de la suite arithmétique a, a1 est le
premier élément de la suite arithmétique et r
est la raison.


*/
package tp_6;

/**
 *
 * @author Emanuel
 */
public class ex_4 {
    public static double elemn(double e1, double r,int n){
        double ef;
        switch (n){
            case 1:
                ef=e1;
                break;
            default:
                ef=r+elemn(e1,r,n-1);
                break;
        }
        return ef;
    }
    public static void main (String[] args){
    int [] v = {2,4,6,8,10};
    int i,ok=1;
    for(i=1;i<v.length;i++){
        if(v[i]!=elemn(v[0],v[1]-v[0],i+1)){
            ok=0;
        }
    }
    if(ok==1){
        System.out.println("This is an arithmetical progression, the ratio is "+ elemn(v[0],v[1]-v[0],6));
        
    }
    else{
        System.out.println("No arithmetical progression.");
    }
    
    }
}
