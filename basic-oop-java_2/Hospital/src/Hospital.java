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
public class Hospital {
 private String name;
 private String address;

    public String getName() {
        return name;
    }

    public String getAddress() {
        return address;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setAddress(String address) {
        this.address = address;
    }
 
 public Hospital (String name, String address){
     this.name=name;
     this.address=address;
 }
}
