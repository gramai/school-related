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
public class DescriptionLivre {
    private String presentation;
    private Livre livre;

    public DescriptionLivre(Livre livre, String presentation){
        this.livre=livre;
        this.presentation=presentation;
    }
    public DescriptionLivre(){}
    
    public String getPresentation() {
        return presentation;
    }

    public void setPresentation(String presentation) {
        this.presentation = presentation;
    }
    public void setLivre(Livre livre){
        this.livre=livre;
    }
    public Livre getLivre(){
        return this.livre;
    }
    
    
    
    @Override
    public String toString(){
        return "Description for the book " + this.livre.getTitre() +" is : "+this.presentation;
    }
   
    
}
