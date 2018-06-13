/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp_9;

/**
 *
 * @author Emanuel
 */
import java.util.GregorianCalendar;
public class Livre {
    private String titre;
    private Personne auteur;
    private String description;
    private int nombreDePages;
    private String ISBN;
    private int anneeApparition;
    private double prixUnit;
    private double prixDeVente;
    private double TVA;

    public String getTitre() {
        return titre;
    }

    public Personne getAuteur() {
        return auteur;
    }

    public String getDescription() {
        return description;
    }

    public int getNombreDePages() {
        return nombreDePages;
    }

    public String getISBN() {
        return ISBN;
    }

    public int getAnneeApparition() {
        return anneeApparition;
    }

    public double getPrixUnit() {
        return prixUnit;
    }

    public double getPrixDeVente() {
        return prixDeVente;
    }

    public double getTVA() {
        return TVA;
    }

    public void setTitre(String titre) {
        this.titre = titre;
    }

    public void setAuteur(Personne auteur) {
        this.auteur = auteur;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public void setNombreDePages(int nombreDePages) {
        this.nombreDePages = nombreDePages;
    }

    public void setISBN(String ISBN) {
        this.ISBN = ISBN;
    }

    public void setAnneeApparition(int anneeApparition) {
        this.anneeApparition = anneeApparition;
    }

    public void setPrixUnit(double prixUnit) {
        this.prixUnit = prixUnit;
    }

    public void setPrixDeVente(double prixDeVente) {
        this.prixDeVente = prixDeVente;
    }

    public void setTVA(double TVA) {
        this.TVA = TVA;
    }
    
    
    public Livre (String titre, int nombreDePages, String ISBN, int anneeApparition,double prixUnit, Personne auteur){
        this.titre=titre;
        this.nombreDePages=nombreDePages;
        this.ISBN=ISBN;
        this.anneeApparition=anneeApparition;
        this.prixUnit=prixUnit;
        this.auteur=auteur;
    }
    
    public void calculePrixVente(){
        this.prixDeVente=this.prixUnit+this.prixUnit*this.TVA/100;
    }
    
    
    
    
}
