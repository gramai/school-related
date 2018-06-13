/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp_11_e2;

/**
 *
 * @author root
 */
public class CarteDebit extends Carte {
    public CarteDebit(String iban, double somme){
        this.iban=iban;
        this.somme=somme;
    }
    public void retirer(double somme){
        System.out.println("You just got "+ somme + " without selling your soul!");
        
    }
    @Override
    public String toString(){
        return ("This is a debit card, you can put your life savings in it");
    }
    
}
