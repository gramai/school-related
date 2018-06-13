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
import java.lang.Math;
public class Rectangle {
    public double longueur, largeur;
    
    public Rectangle(){
        this.longueur=20;
        this.largeur=15;
    }
    
    public Rectangle (double longueur, double largeur){
        this.longueur=longueur;
        this.largeur=largeur;
    }
    
    public Rectangle (Rectangle Rectangle){
        this.largeur=Rectangle.largeur;
        this.longueur=Rectangle.longueur;
    }
    
    public double getLargeur(){
        return Math.abs(this.largeur);
    }
    
    public double getLongueur(){
        return Math.abs(this.longueur);
    }
    
    public void setLargeur(double largeur){
        Math.abs(this.largeur=largeur);
    }
    
    public void setLongueur(double longueur){
        Math.abs(this.longueur=longueur);
    }
    
    public double Perimetre(){
        return 2*(this.getLongueur()+this.getLargeur());
    }
    
    public double Aire (){
        return (this.getLongueur()*this.getLargeur());
    }
    
    public boolean estCarre (){
        return this.getLongueur()==this.getLargeur();
    }
    
    @Override
    public String toString(){
        return "Rectangle largeur est "+this.getLargeur()+" et longueur est " + this.getLongueur();
    }
         
}