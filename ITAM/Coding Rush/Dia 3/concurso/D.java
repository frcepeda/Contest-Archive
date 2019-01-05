import java.util.*;

public class D {

    /**
     * Creates a new instance of <code>descargando</code>.
     */
    public D() {
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner lectura = new Scanner(System.in);

        String linea;
        Queue<String> cola = new LinkedList<String>();

        while(lectura.hasNext()){
        	linea = lectura.nextLine();

        	/*COMIENZA A PROGRAMAR EN ESTE LUGAR*/

        	if(linea.charAt(0) == 'D' ){
        		cola.offer(linea.substring(2));
        		System.out.println( "ok" );
        	}
        	else if(linea.charAt(0) == 'T' ){
        		System.out.println( "descargada " + cola.poll());
        	}
        	else if(linea.charAt(0) == 'C' ){
        		System.out.println("faltan " + cola.size() + " descarga(s)");
        	}
        	else if(linea.charAt(0) == 'X' ){
        		System.out.println(cola.size() + " descarga(s) abortadas");
        		break;
        	}

        	/*TERMINA LA SECCION PARA PROGRAMAR*/
        }
    }
}
