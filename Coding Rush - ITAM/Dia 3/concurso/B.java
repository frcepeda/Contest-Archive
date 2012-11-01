import java.util.*;

public class B {

    /**
     * Creates a new instance of <code>browsing</code>.
     */
    public B() {
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner lectura = new Scanner(System.in);
        boolean first = true;
        String linea, tmp = "";

        Stack<String> pila = new Stack<String>();

        while(lectura.hasNext()){
        	linea = lectura.nextLine();

        	/*COMIENZA A PROGRAMAR EN ESTE LUGAR*/

        	if(linea.charAt(0) == 'A'){
        		if (!first){
        			pila.push(tmp);
        		}
        		tmp = linea.substring(2);
        		first = false;
        	} else if(linea.charAt(0) == 'R' ){
        		if( pila.empty() ){
        			System.out.println("Sin historial");
        		}
        		else{
        			System.out.println(pila.pop());
        			first = true;
        		}
        	}

        	/*TERMINA LA SECCION PARA PROGRAMAR*/
        }
    }
}
