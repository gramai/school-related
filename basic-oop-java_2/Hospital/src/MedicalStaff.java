/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tp_09_d_2;

import java.util.ArrayList;

/**
 *
 * @author Emanuel
 */
public class MedicalStaff {
    private int noDoctors;
    private Hospital hospital;
    private ArrayList <Doctor> doctors= new ArrayList<>();
    
    public MedicalStaff(){};
    
    public void hireDoctor(String office, String specialization, Surgeon surgeon){
        surgeon.setOffice(office);
        surgeon.setSpecialization(specialization);
        doctors.add(surgeon);
        this.noDoctors++;
    }
    
    public void hireDoctor(String office,Doctor doctor){
        doctor.setOffice(office);
        doctors.add(doctor);
        this.noDoctors++;
    }
    
    @Override
    public String toString(){
        int i;
        String staff="";
        for(i=0;i<doctors.size();i++){
            staff=staff.concat(doctors.get(i).getId() + " " + doctors.get(i).office + "\r\n");
        }
        return staff;
    }
    
    public void setHospital(Hospital hospital){
        this.hospital=hospital;
    }
    
}
