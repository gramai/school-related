/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp_09_d_2;

/**
 *
 * @author Emanuel
 */
public class Doctor {
    private int id;
    static int idCurrentDoctor=1;
    protected String office;
    
    public Doctor(){
    id=idCurrentDoctor++;
    }
    
    public void setOffice(String office){
        this.office=office;
    }
    public int getId(){
        return this.id;
    }
    public void treatPatient(){}
    
    @Override
    public String toString(){
        return "Doctor id is " + this.id;
    }
    
    
}
