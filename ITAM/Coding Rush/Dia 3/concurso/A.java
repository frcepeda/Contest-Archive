import java.util.*;

public class A {

    /**
     * Creates a new instance of <code>abreviando</code>.
     */
    public A() {
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
    	Scanner lectura = new Scanner(System.in);

    	String linea;

    	while(lectura.hasNext()){
    		linea = lectura.nextLine();

    		/*COMIENZA A PROGRAMAR EN ESTE LUGAR*/

    		// Recuerda que puedes utilizar las funciones
    		// charAt() y length() y todas los elementos aprendidos en CR


			int next = -1;
			while(true){
				linea = linea.substring(next+1);
				System.out.print(linea.charAt(0) + ".");
				next = linea.indexOf(' ');
				if (next == -1)
					break;
			}
			System.out.println();
    		/*TERMINA LA SECCION PARA PROGRAMAR*/
    	}
    }
}
