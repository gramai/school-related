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
import java.util.ArrayList;
public abstract class Employe {
    private String nom;
    private int nombreDeProjets;
    private ArrayList<Projet> projets=new ArrayList<>();
    
    public int getNombreDeProjets(){
        this.nombreDeProjets=projets.size();
        return nombreDeProjets;
    }
    
    public Employe (String nom){
        this.nom=nom;
    }
    
    public void addProjet(Projet p){
        projets.add(p);
    }
    
    public int calculerBudgetTotal(){
        int i,budgetTotal=0;
        for(i=0;i<projets.size();i++)
            budgetTotal=budgetTotal+projets.get(i).getBudget();
        return budgetTotal;
    }
    public void afficherProjets(){
        int i;
        for(i=0;i<projets.size();i++)
            System.out.println(projets.get(i).toString());
    }

    public String getNom() {
        return nom;
    }

   
    
    public abstract double calculerSalaire();
}
