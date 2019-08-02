package modelo;

public class Contato {
	
	private String nome;
	private String numFone;
	
	public Contato() {
		this.nome = "";
		this.numFone = "";
	}
	
	public Contato(String nome, String numFone) {
		this.nome = nome;
		this.numFone = numFone;
	}
	
	public void setNome(String nome){
		this.nome = nome;
	}
	
	public String getNome(){
		return this.nome;
	}
	
	public void setNumFone(String fone){
		this.numFone = fone;
	}
	
	public String getNumFone(){
		return this.numFone;
	}
	
	public void mostrarContato(){
		System.out.println("Nome: " + this.nome);
		System.out.println("Número de Telefone: " + this.numFone);
	}

}