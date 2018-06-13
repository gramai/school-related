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
public class Programmeur extends Employe {
    public Programmeur (String nom, String prenom, int age, double salaire){
        super(nom,prenom,age,salaire);
    }
    
    @Override
    public double getSalaireNet(){
        return (salaireBrut-getTaxe());
    }
    
    @Override
    public String toString(){
         return "This is a programmer and has the net wage of " + getSalaireNet();
      }
    
}
