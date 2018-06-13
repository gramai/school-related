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
import java.util.ArrayList;
public class TestProduit {
    public static void main(String[] args){
        Produit mouse=new Produit("Mouse",21);
        Produit keyboard=new Produit("Keyboard", 50);
        System.out.println("Les produits "+ mouse.getNom()+" et "+ keyboard.getNom()+" ont le total suivant: "+ (mouse.getPrix()+keyboard.getPrix()));
        
        System.out.println(" prixDeVente() est " + mouse.prixDeVente() + " prixDeVente(10) est "  + mouse.prixDeVente(10));
        
        ArrayList <Produit> list = new ArrayList<>();
        list.add(mouse);
        list.add(keyboard);
        int i;
        for(i=0;i<list.size();i++){
            System.out.println("Nom d'objet est " + list.get(i).getNom()+ " prix de fabrication est "+ list.get(i).getPrix()+" prix de vente est " + list.get(i).prixDeVente());
            
        }
        if (list.get(0).getPrix()<list.get(1).getPrix()){
            System.out.println("Nom d'objet est " + list.get(1).getNom()+ " prix de fabrication est "+ list.get(1).getPrix()+" prix de vente est " + list.get(1).prixDeVente()); 
        }
        else{
             System.out.println("Nom d'objet est " + list.get(0).getNom()+ " prix de fabrication est "+ list.get(0).getPrix()+" prix de vente est " + list.get(0).prixDeVente());
           
        }
        
        
        
        
    
    
    }
}
