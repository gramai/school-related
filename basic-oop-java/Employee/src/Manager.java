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
public class Manager extends Employe{
    private int prime;
    public Manager (String nom, String prenom, int age, double salaireBrut, int prime){
        super(nom,prenom,age,salaireBrut);
        this.prime=prime;
    }
    
    @Override
    public double getSalaireNet(){
        double salaire;
        salaire=(getSalaireBrut() + prime-getTaxe()-prime*30/100);
        return salaire;
    }
    
    @Override
    public String toString(){
        return "This is a manager and has the net wage of " + getSalaireNet();
    }
    
}
