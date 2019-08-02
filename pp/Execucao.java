package execucao;

import java.util.Scanner;

import modelo.Calculadora;

public class Execucao {
	
	public static void main(String[] args) {
		Calculadora calc1 = new Calculadora();
		Scanner entrada = new Scanner(System.in);
		double a = 0, b = 0;
		
		//for(int i = 0; i < 10; i++)	calc1.gerarRandomico();
		
		calc1.mostraTipo();
		calc1.alteraTipo(entrada.nextLine());
		calc1.mostraTipo();
		
		do{
			a = entrada.nextDouble();
			b = entrada.nextDouble();
			
			System.out.println("Soma: " + calc1.soma(a, b));
			System.out.println("Subtracao: " + calc1.subtracao(a, b));
			System.out.println("Multiplicao: " + calc1.multiplicacao(a, b));
			System.out.println("Divisao: " + calc1.divisao(a, b));
			System.out.println("Gerar Random: " + calc1.gerarRandomico(a, b));
			System.out.println("Exponenciacao: " + calc1.exponenciacao(a, b));
			System.out.println("Raiz Quadrada: " + calc1.raizquadrada(a));
			
			
		}while(a != 0 && b != 0);
	}
	
	
}
