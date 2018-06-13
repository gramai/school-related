/*

English
Write a program that:
a) Reads from user input the element of a matrix, A[NxN], where N <= 15
b) Prints the matrix
c) Calculates and prints the product of the elements that are pair
d) Calculates and prints the sum of the squares of the numbers situated in the
   areas as described bellow ( '1' is in area '0' is not), the two cases taken
   separately
    
     Zone 1
   1 1 1 1 1
   1 1 1 1 0
   1 1 1 0 0
   1 1 0 0 0 
   1 0 0 0 0

     Zone 2
   1 1 1 1 1 
   0 1 1 1 0
   0 0 1 0 0 
   0 0 0 0 0 
   0 0 0 0 0
 
  e)Form and print the vector V where its elements are the elements that are
    impair and negative of the matrix A
  f)Determines, if it exists, the greatest common divisor of the two greatest
    elements of the vector V
  g)Calculates and prints the transposed matrix of C where C is 
        C = A + 𝐴 ^ 2 + A ^ 3

French
On demande d’écrire un programme qui doit :
a) Lire du clavier les éléments d’une matrice (des nombres
réels), A[NxN], où N<=15.
b) Afficher la matrice A
c) Calculer et afficher le produit des éléments qui sont des
nombres pairs
d) Calculer et afficher la somme des carrés des éléments
positifs situés dans les zones indiquées de la matrice A (les deux
cas pris séparément).

       1

   1 1 1 1 1
   1 1 1 1 0
   1 1 1 0 0
   1 1 0 0 0 
   1 0 0 0 0


       2

   1 1 1 1 1 
   0 1 1 1 0
   0 0 1 0 0 
   0 0 0 0 0 
   0 0 0 0 0

e) Former et afficher le vecteur V dont les éléments sont les
éléments impairs et négatifs de la matrice A.
f) Déterminer, s’il existe, le plus grand diviseur commun de
des deux plus grands éléments du vecteur V.
g) Calculer et afficher la matrice transposée de la matrice
C = A + 𝐴 ^ 2 + A ^ 3


*/
package tp_4;

/**
 *
 * @author Grama Emanuel
 */
import static java.lang.Integer.parseInt;
import javax.swing.JOptionPane;
import java.util.Arrays;
public class d_2 {
    public static void main (String[] args){
       //a) Read from user input the element of a matrix, A[NxN], where N <= 15
       int n,i,j;
       n=parseInt(JOptionPane.showInputDialog("Insert the number of rows and collums"));
       double [][] matrix=new double[n][n];
       for (i=0;i<n;i++){
           for(j=0;j<n;j++){
               matrix[i][j]=Double.parseDouble(JOptionPane.showInputDialog("Insert element of ind" +i +" "+ j));
           }
       }
       //b) Print the matrix
        for(i=0;i<n;i++){
           for(j=0;j<n;j++){
               System.out.print(matrix[i][j]+" ");
           }
           System.out.println();
       }
       //c) Calculate and print the product of the elements that are pair
        double prod=1;
       for(i=0;i<n;i++){
           for(j=0;j<n;j++){
               if(matrix[i][j]%2==0){
                   prod=prod*matrix[i][j];
               }
           }
       }
       System.out.println(prod);
       
       //d) Calculates and prints the sum of the squares of the numbers 
       //   situated in the two Zones (Zone 1 and Zone 2)
       double sum=0;
       for(i=0;i<n;i++){
           for(j=0;j<n;j++){
               if(i<=j&& matrix[i][j]>=0){
               sum=sum+matrix[i][j];   
               }
           }
       }
       
      System.out.println("suma zone 1= "+ sum);
      sum=0;
      for(i=0;i<n;i++){
          for(j=0;j<n;j++){
              if(j>i-1 && j<n-i && i<=n/2 && matrix[i][j]>=0){
                  sum=sum+matrix[i][j];
                   
              }
          }
      }
      System.out.println("suma zone 2= "+ sum);
      
    // e)Form and print the vector V where its elements are the elements that are
    //  impair and negative of the matrix A
    double [] v=new double[n*n];
      int k=0;
      for(i=0;i<n;i++){
          for(j=0;j<n;j++){
              if(matrix[i][j]<0&& (matrix[i][j]%2==1 || matrix[i][j]%2==-1) ){
                  v[k]=matrix[i][j];
                  k++;
              }
          }
      }
      double [] v2=new double[k];
      for(i=0;i<v2.length;i++){
          v2[i]=v[i];
      }
      for(i=0;i<v2.length;i++){
          System.out.print(v2[i]+" ");
      }
      
      //f)Determine, if it exists, the greatest common divisor of the two greatest
      // elements of the vector V
      double max1=v[0],max2=v2[1];
      for(i=0;i<v2.length;i++){
          if (v2[i]>max1){
              max1=v2[i];
          }
      }
      for(i=0;i<v2.length;i++){
          if(v2[i]>max2&&v2[i]<max1){
              max2=v2[i];
          }
      }
      double a,b,c;
      a=max1;
      b=max2;
      a=-a;
      b=-b;
      if(b>a){
          c=a;
          a=b;
          b=c;
      }
      while(a!=b){
      c=a-b;
      a=b;
      b=c;
        if(b>a){
          c=a;
          a=b;
          b=c;
      }
      }
      System.out.println("max 1 is "+ max1+ " max 2 is "+ max2 + "biggesst div is "+ a);
      
      //g)Calculate and print the transposed matrix of C where C is 
      //  C = A + 𝐴 ^ 2 + A ^ 3
        double [][] matrix_2=new double[n][n];
        double [][] matrix_3=new double[n][n];
        double [][] matrix_c=new double[n][n];
        double [][] matrix_ct=new double[n][n];
        int i2,j2;
        for (i=0;i<n;i++){
            for(j=0;j<n;j++){
                sum=0;
                for(i2=0;i2<n;i2++){
                    sum=sum+matrix[i][i2]*matrix[i2][j];
                }
                matrix_2[i][j]=sum;
            }
        }
        
        for (i=0;i<n;i++){
            for(j=0;j<n;j++){
                sum=0;
                for(i2=0;i2<n;i2++){
                    sum=sum+matrix_2[i][i2]*matrix[i2][j];
                }
                matrix_3[i][j]=sum;
            }
        }
      
        for (i=0;i<n;i++){
            for(j=0;j<n;j++){
                matrix_c[i][j]=matrix[i][j]+matrix_2[i][j]+matrix_3[i][j];
            }
        }
        
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                matrix_ct[j][i]=matrix_c[i][j];
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                System.out.print(matrix_ct[i][j]+ " ");
            }
            System.out.println();
            
        }
    }
}