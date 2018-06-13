/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp_9;

/**
 *
 * @author Emanuel
 */
import java.util.ArrayList;
import java.util.GregorianCalendar;
public class TP_9 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Personne personne1=new Personne("Mihai","Kogalniceanu");
        Personne personne2=new Personne("George","Calinescu"); 
        
        Livre livre1= new Livre("Pe margine",231,"ADA413",1911,84,personne1);
        Livre livre2=new Livre("Sub stele", 113,"RO921ISNA",1877,13,personne2);
  
        DescriptionLivre description1 = new DescriptionLivre(livre1,"This book was great!");
        DescriptionLivre description2= new DescriptionLivre(livre1, "I didn't really enjoy is that much");
        DescriptionLivre description3=new DescriptionLivre(livre2,"Cool!");
        
        Catalogue catalogue= new Catalogue();
        catalogue.ajouterDescription(description1);
        catalogue.ajouterDescription(description2);
        catalogue.ajouterDescription(description3);
        
        ArrayList <DescriptionLivre> descriptionFound=new ArrayList<>();
        descriptionFound=catalogue.rechercer(personne2);
        System.out.println("Printng descriptions for person1");
        int i;
        for(i=0;i<descriptionFound.size();i++){
            System.out.println(descriptionFound.get(i).toString());
        }
        
        
        System.out.println("Printing descriptions for name");
        descriptionFound=catalogue.rechercher("Sub stele");
        for(i=0;i<descriptionFound.size();i++){
            System.out.println(descriptionFound.get(i).toString());
        }
        
       
        catalogue.afficherContenu();
        
    }
    
}
