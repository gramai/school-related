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
public class Projet {
    private String nom;
    private int budget;
    
    public Projet (String nom, int budget){
        this.nom=nom;
        this.budget=budget;
    }
    
    public int getBudget(){
        return budget;
    }

    @Override
    public String toString() {
        return "Projet{" + "nom=" + nom + ", budget=" + budget + '}';
    }
    
    
}
