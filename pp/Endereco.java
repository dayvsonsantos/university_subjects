package modelo;

import java.util.Scanner;

public class Endereco {
	
	private int num;
	private String rua;
	private String bairro;
	private String cep;
	Scanner input = new Scanner(System.in);
	
	public void criarEnd(){
		System.out.println("  Número: ");
		num = input.nextInt();
		input.nextLine();
		System.out.println("  Rua: ");
		rua = input.nextLine();
		System.out.println("  Bairro: ");
		bairro = input.nextLine();
		
		boolean valida = false;
		
		while(!valida) {
			System.out.println("  Cep: ");
			cep = input.next();
			valida = cep.matches("\\d{4}-\\d{3}");
			if(!valida)
				System.out.println("Cep inválido, insira novamente!!!");
		}
	}
	
	public void mostrarEndereco() {
		System.out.println("ENDEREÇO");
		System.out.println(" Numero: " + this.num);
		System.out.println(" Rua: " + this.rua);
		System.out.println(" Bairro: " + this.bairro);
		System.out.println(" Cep: " + this.cep);
	}

	public int getNum() {
		return num;
	}
	
	public void setNum(int num) {
		this.num = num;
	}
	
	public String getRua() {
		return rua;
	}
	
	public void setRua(String rua) {
		this.rua = rua;
	}
	
	public String getBairro() {
		return bairro;
	}
	
	public void setBairro(String bairro) {
		this.bairro = bairro;
	}
	
	public String getCep() {
		return cep;
	}
	
	public void setCep(String cep) {
		this.cep = cep;
	}
}
