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
public class Personne {
 
    private String nom;
    private String prenom;

    
        
   public Personne (String nom, String prenom){
       this.nom=nom;
       this.prenom=prenom;
   }
    public String getNom() {
        return nom;
    }

    public String getPrenom() {
        return prenom;
    }

    public void setNom(String nom) {
        this.nom = nom;
    }

    public void setPrenom(String prenom) {
        this.prenom = prenom;
    }

   
   @Override
   public String toString(){
       return "Nom "+this.nom+" || Prenom " +this.prenom;
   }
   
}

