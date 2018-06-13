/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp_13_e1;

/**
 *
 * @author root
 */
import java.util.Scanner;
import java.io.IOException;
import java.io.File;
public class TP_13_e1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        try {
            File file=new File("/home/emanuel/Desktop/UPB/TP/probleme curs/TP_13_e1/src/tp_13_e1/input.txt");
            Scanner sc = new Scanner(file);
            String projet;
            int budget;
            Manager manager1=new Manager("Gheorghe");
            Programmeur programmeur1=new Programmeur("Alex");
            while(sc.hasNext()){ 
                projet=sc.next();
                budget=Integer.parseInt(sc.next());
                manager1.addProjet(new Projet(projet,budget));
                programmeur1.addProjet(new Projet(projet,budget));
            }
            System.out.println("The mananger with the name " + manager1.getNom() + " has "+ manager1.getNombreDeProjets() + " projects and the salary of "+ manager1.calculerSalaire());
            System.out.println("The programmer with the name " + programmeur1.getNom() + " has "+ programmeur1.getNombreDeProjets() + " projects and the salary of "+ programmeur1.calculerSalaire());
        }
        catch (Exception e){
            System.out.println(e);
        }
    }
    
}
