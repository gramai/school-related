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
public class TestRectangle {
    public static void main (String[] args){
        Rectangle rectangle1=new Rectangle(20,30);
        Rectangle rectangle2=new Rectangle(40,40);
        
        System.out.println(rectangle1.toString());
        System.out.println(rectangle2.estCarre());
        System.out.println(rectangle2.Aire());
        System.out.println(rectangle1.Perimetre());
    }
}
