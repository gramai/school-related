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
public class CarteCredit extends Carte {
    double creditMaximal;
    
    public CarteCredit(String iban, double creditMaximal){
        this.iban=iban;
        this.creditMaximal=creditMaximal;
    }
    
    @Override
    public void retirer(double somme){
        if(somme<creditMaximal){
            System.out.println("You are now "+somme+" in debt. Congrats!");
        }
        else{
            System.out.println("You can't handle such a big loan");
        }
        
    }
    
    @Override
    public String toString(){
        return ("This card has maximum credit limit of " + creditMaximal);
    }
    
}
