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
public abstract class Carte {
    protected String iban;
    protected double somme;

    public String getIban() {
        return iban;
    }

    public double getSomme() {
        return somme;
    }

    public void setIban(String iban) {
        this.iban = iban;
    }

    public void setSomme(double somme) {
        this.somme = somme;
    }
    
    
    
    public abstract void retirer(double somme);
    
    @Override
    public String toString(){
        return ("This card has got the iban : "+iban);
    }
}
