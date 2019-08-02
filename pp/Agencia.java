package modelo;

import java.util.Scanner;

public class Agencia {
	
	private Scanner input = new Scanner(System.in);
	private String endereco;
	private int numeroAgencia;
	
	public Agencia() {
		this.numeroAgencia = 0;
		this.endereco = "";
	}
	
	public Agencia(String endereco, int numeroAgencia) {
		this.endereco = endereco;
		this.numeroAgencia = numeroAgencia;
	}
	
	public void criarAgencia() {
		System.out.println("Inserir numero da Agencia: ");
		this.numeroAgencia = this.input.nextInt();
		this.input.nextLine();
		System.out.println("Endereço da agência: ");
		this.endereco = input.nextLine();
	}
	
	public void mostrarAgencia() {
		System.out.println("Numero da Agencia: " + this.numeroAgencia);
		System.out.println("Endereco: "+this.endereco);
	}
}

