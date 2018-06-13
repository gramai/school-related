/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp_10_d2;

/**
 *
 * @author Emanuel
 */
public class TP_10_d2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Employe employe1 = new Employe("Gheorghe","Zamfir",67, 2213.4);
        Manager manager1 = new Manager("Mihai","Zula",27, 1013,200);
        Programmeur programmer1 = new Programmeur("Mircea","Alexandrescu",67, 1013.4);
        
        System.out.println(employe1.toString());
        System.out.println(manager1.toString());
        System.out.println(programmer1.toString());
    }
    
}
