package modelo;

abstract public class Animal {
	
	public String nome;
	public String cor;
	public double peso;
	
	public Animal() {
		this.nome = "";
		this.cor = "";
		this.peso = 0.0;
	}
	
	public Animal(String nome, String cor, double peso) {
		this.nome = nome;
		this.cor = cor;
		this.peso = peso;
	}

	public void emitirSom(){
		System.out.println("Som do animal");
	}
	
	abstract public void seLocomover();

}
