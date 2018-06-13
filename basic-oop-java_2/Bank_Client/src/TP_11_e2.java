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
public class TP_11_e2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        GregorianCalendar gc = new GregorianCalendar();
        gc.set(1998,11,20);
        
        Addresse addresse = new Addresse("Ideciu de Jos",1,"Principala");
        
        Client client = new Client ("Grama",gc,"198123151231",addresse);
        
        CarteCredit c = new CarteCredit("RO19231KAIA21",10000);
        CarteDebit d = new CarteDebit("RO17123JSAHA2451",200);
        
        client.ajouterCarte(c);
        client.ajouterCarte(d);
        client.afficherDetail();
    }
    
}
