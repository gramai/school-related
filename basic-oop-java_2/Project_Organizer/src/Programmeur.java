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
public class Programmeur extends Employe {
    public Programmeur(String nom){
        super(nom);
    }
    
    @Override
    public double calculerSalaire(){
        return (3000+500*getNombreDeProjets());
    }
    
}
