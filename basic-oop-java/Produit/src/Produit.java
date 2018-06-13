/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp_7;

/**
 *
 * @author Emanuel
 */
public class Produit {
    //3 private attributes: name(string), price(double, vat(int)
    //3 attributs prives: nom(string), prix(double), vat(int)
    private  String nom;
    private double prix_fabrication;
    private static int VAT=19;
    
    //constructor without parameters
    //constructor sans param.
    public Produit(){
        this.nom="Tricou";
        this.prix_fabrication=12.4;
    }
    
    //constructor with the two parameters
    //constructor avec les 2 param.
    public Produit (String nom, double prix_fabrication){
        this.nom=nom;
        this.prix_fabrication=prix_fabrication;
    }
    
    //3 methods
    //3 méthodes
    public Produit(String nom,double prix_fabrication,int VAT){
        this.nom=nom;
        this.prix_fabrication=prix_fabrication;
        this.VAT=VAT;
    }
    
    
    //3  getters
    public String getNom(){
        return this.nom;
       }
    public double getPrix (){
        return this.prix_fabrication;
    }
    public int getVAT(){
        return this.VAT;
    }
    
    
    //3 setters
    public void setNom(String nom){
        this.nom=nom;
    }
    public void setPrix(double prix_fabrication){
        this.prix_fabrication=prix_fabrication;
    }
    public void setVAT(int VAT){
        this.VAT=VAT;
    }
    
    public double prixDeVente(){
        double prixDeVente=prix_fabrication+5*prix_fabrication/100;
        prixDeVente=prixDeVente+prixDeVente*VAT/100;
        return prixDeVente;
    }
    
    //selling price with discount
    //prix de vente avec discount
    public double prixDeVente(int discount){
        double prixDeVente=prixDeVente();
        prixDeVente=prixDeVente-prixDeVente*discount/100;
        return prixDeVente;
    }
    
    
    
}
