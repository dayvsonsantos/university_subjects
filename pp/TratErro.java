import java.io.FileNotFoundException;
import java.io.FileReader;


public class TratErro {
	
	static int numero[] = {1,2,3};
	
	public void mostrarValor() throws Exception{
		for (int j = 0; j < numero.length; j++) {
			if (j > 3) {
				throw new Exception("Indice fora de limite");
			} else {
				System.out.println(numero[j]);			
			}
		}
	}

	public static void main(String[] args) {
			
		
		System.out.println(numero[0]);
		System.out.println(numero[1]);
		System.out.println(numero[2]);
		
		int i = 5571;		
		
		try {
		i = i / 0;
		
		System.out.println("Resultado de i: "+i);
		} catch (Exception e) {
			// TODO: handle exception
			System.out.println("divisao por zero: ");
		}
		/*try {
			System.out.println(numero[3]);
		} catch (Exception e) {
			// TODO: handle exception
			System.out.println("houve um erro!");
		}

		try {
			FileReader reader = new FileReader("test.txt");
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}*/
		System.out.println("Terminou");
	}

}
