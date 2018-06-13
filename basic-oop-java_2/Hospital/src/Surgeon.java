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
public class Surgeon extends Doctor {
    private String specialization;

    public Surgeon (String specialization){
        super();
        this.specialization=specialization;
    }
    public String getSpecialization() {
        return specialization;
    }

    public void setSpecialization(String specialization) {
        this.specialization = specialization;
    }
    @Override
    public void treatPatient(){}
      
}
