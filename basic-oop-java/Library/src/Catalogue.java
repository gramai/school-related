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
public class Catalogue {
    ArrayList <DescriptionLivre> description= new ArrayList<>();
    
     public Catalogue(){};
    
    public void ajouterDescription(DescriptionLivre description){
        this.description.add(description);
    }
    public void afficherContenu(){
        int i;
        System.out.println("Printing descriptions...");
        for(i=0;i<description.size();i++){
            System.out.println(this.description.get(i));  
        }
    }
    
    public ArrayList<DescriptionLivre> rechercher(String titre){
        int i;
        ArrayList<DescriptionLivre> descriptionLivre=new ArrayList<>();
        for(i=0;i<description.size();i++){
            if(description.get(i).getLivre().getTitre().equals(titre)) {
                descriptionLivre.add(description.get(i));
            }
        }
        return descriptionLivre;
    }
    
    public ArrayList<DescriptionLivre>rechercer(Personne personne){
        int i;
        ArrayList<DescriptionLivre> descriptionLivre=new ArrayList<>();
        for(i=0;i<description.size();i++){
            if(description.get(i).getLivre().getAuteur().equals(personne)) {
                descriptionLivre.add(description.get(i));
            }
        }
        return descriptionLivre;
    }
    
        public ArrayList<DescriptionLivre>rechercer(Personne personne, String titre){
        int i;
        ArrayList<DescriptionLivre> descriptionLivre=new ArrayList<>();
        for(i=0;i<description.size();i++){
            if(description.get(i).getLivre().getAuteur().equals(personne)&&description.get(i).getLivre().getTitre().equals(titre)) {
                descriptionLivre.add(description.get(i));
            }
        }
        return descriptionLivre;
    }
       
    
}
