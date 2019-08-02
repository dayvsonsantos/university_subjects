package produto;

import java.util.Scanner;
//import java.util.InputMismatchException;

public class Main {

	public static void main(String[] args) {
		Produtos[] vProd = {new Produtos(), new Produtos(), new Produtos()};
		Scanner entrada = new Scanner(System.in);
		
		for(int i = 0; i < vProd.length; i++) {
			System.out.println("Nome do Produto: ");
			vProd[i].nomeDoProduto = entrada.nextLine();
			System.out.println("Preco de Custo: ");
			vProd[i].precoCusto = entrada.nextDouble();
			System.out.println("Preco de Venda: ");
			vProd[i].alterarPreco(entrada.nextDouble());
			
			System.out.println("Margem de lucro: " + vProd[i].calcularMargemLucro());
			
			vProd[i].mostrarDadosProduto();
		}
	}
}
