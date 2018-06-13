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
public class Manager extends Employe {
    
    public Manager(String nom){
        super(nom);
    }
    
    @Override
    public double calculerSalaire(){
        return 4000+10*calculerBudgetTotal()/100;
    }
    
}
