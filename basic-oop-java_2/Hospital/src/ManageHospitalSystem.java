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
public class ManageHospitalSystem {
    public static void main (String[] args){
        Hospital hospital = new Hospital("Sf. Ioan", "Soseaua Vitan-Barzesti");
        MedicalStaff medicalStaff=new MedicalStaff();
        Surgeon surgeon1=new Surgeon ("Heart");
        Surgeon surgeon2= new Surgeon ("Bone");
        FamilyDoctor familyDoctor1=new FamilyDoctor();
        
        medicalStaff.hireDoctor("101 A","Heart",surgeon1);
        medicalStaff.hireDoctor("235B","Brain",surgeon2);
        medicalStaff.hireDoctor("02H", familyDoctor1);
        
        
        System.out.println("Getting surgeon1 info: " + surgeon1.toString());
        
        System.out.println("Getting staff data" +"\r\n"+ medicalStaff.toString());
        
    }
}
