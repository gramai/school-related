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
import java.util.GregorianCalendar;
import java.util.ArrayList;
public class Client {
    private String nom;
    private GregorianCalendar anniversaire;
    private String cnp;
    private Addresse addresse;
    private ArrayList <Carte> cartes = new ArrayList<>();
    
    public Client(String nom, GregorianCalendar anniversaire, String cnp, Addresse addresse){
        this.nom=nom;
        this.anniversaire=anniversaire;
        this.cnp=cnp;
        this.addresse=addresse;
    }
    
    public boolean ajouterCarte(Carte c){
            cartes.add(c);
            return true;
    }
    
    public void afficherDetail(){
        for (int i=0;i<cartes.size();i++){
            System.out.println(cartes.get(i).toString());
        }
    }
}
