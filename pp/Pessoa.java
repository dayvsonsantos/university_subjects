package modelo;

public class Pessoa {

	public String nome;
	public String cpf;
	
	public Pessoa(String nome, String cpf){
		this.nome = nome;
		this.cpf = cpf;
	}
	
	public void respirar(){
		System.out.println(this.nome + " Está respirando...");
	}
	
	public String obterDadosPessoa(){
		return this.nome+" "+this.cpf;
	}

}
