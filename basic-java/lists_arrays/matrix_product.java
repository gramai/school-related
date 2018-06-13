/*

English
Calculate the product of two matrixes

French
Calculez le produit de deux matrices.

*/
package tp_4;

import static java.lang.Integer.parseInt;
import javax.swing.JOptionPane;

/**
 *
 * @author Grama Emanuel
 */
public class d_1 {
   public static void main(String[] args){
               int m,n,i,j,m2,n2; 
        m=parseInt(JOptionPane.showInputDialog("Insert 1st mat line nr "));
        n=parseInt(JOptionPane.showInputDialog("Insert 1st mat col nr "));
        m2=parseInt(JOptionPane.showInputDialog("Insert 2nd mat line nr "));
        n2=parseInt(JOptionPane.showInputDialog("Insert 2nd mat col nr "));
        if(n!=m2){
            System.out.println("Error!");
        }
        
        double [][] matrix_1=new double[m][n];
        double [][] matrix_2=new double[m2][n2];
        double [][] matrix_prod=new double[m][n2];
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                matrix_1[i][j]=Double.parseDouble(JOptionPane.showInputDialog("Insert matrix_1 element with ind = "+ i + " "+ j));
                }
        }
        for(i=0;i<m2;i++){
            for(j=0;j<n2;j++){
                matrix_2[i][j]=Double.parseDouble(JOptionPane.showInputDialog("Insert matrix_2 element with ind = "+ i + " "+ j));
            }
        }
        int i2,j2,m3,n3;
        double sum=0;
        for (i=0;i<m;i++){
            for(j=0;j<n2;j++){
                sum=0;
                for(i2=0;i2<m;i2++){
                    sum=sum+matrix_1[i][i2]*matrix_2[i2][j];
                }
                matrix_prod[i][j]=sum;
            }
        }
        for(i=0;i<m;i++){
            for(j=0;j<n2;j++){
                System.out.print(matrix_prod[i][j]+" ");
            }
            System.out.println();
        }
   } 
}

