/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp_10_d2;

/**
 *
 * @author Emanuel
 */
public class Employe {
    private int id;
    static int compter=0;
    private String nom;
    private String prenom;
    private int age;
    protected double salaireBrut;
    private double salaireNet;
    protected double impotSurRevenu;
    private double taxe;
    
    public Employe(){}
    
    public Employe (String nom, String prenom, int age, double salaireBrut){
        this.nom=nom;
        this.prenom=prenom;
        this.age=age;
        this.salaireBrut=salaireBrut;
        this.id=compter++;
        this.salaireNet=getSalaireNet();
        this.impotSurRevenu=getImpotSurRevenu();
    }
    public void augmenterSalaire(int pourcentage){
        salaireBrut=salaireBrut+salaireBrut*pourcentage/100;
    }
    
    @Override
    public String toString(){
        return "Employee with id "+id+" has the brut wage of " + salaireBrut + " and net wage of " + getSalaireNet();
    }

    public int getId() {
        return id;
    }

    public int getCompter() {
        return compter;
    }

    public String getNom() {
        return nom;
    }

    public String getPrenom() {
        return prenom;
    }

    public int getAge() {
        return age;
    }

    public double getSalaireBrut() {
        return salaireBrut;
    }

    public double getSalaireNet() {
        return (salaireBrut-getTaxe());
    }

    public double getImpotSurRevenu() {
        return getSalaireNet()*16/100;
    }

    public double getTaxe() {
        return salaireBrut*30/100;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setCompter(int compter) {
        this.compter = compter;
    }

    public void setNom(String nom) {
        this.nom = nom;
    }

    public void setPrenom(String prenom) {
        this.prenom = prenom;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setSalaireBrut(double salaireBrut) {
        this.salaireBrut = salaireBrut;
    }

    public void setSalaireNet(double salaireNet) {
        this.salaireNet = salaireNet;
    }

    public void setImpotSurRevenu(double impotSurRevenu) {
        this.impotSurRevenu = impotSurRevenu;
    }

    public void setTaxe(double taxe) {
        this.taxe = taxe;
    }
    
    
    
}
