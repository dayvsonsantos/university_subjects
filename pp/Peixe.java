package modelo;

public class Peixe extends Animal{
	
	public Peixe(String nome, String cor, double peso) {
		super(nome, cor, peso);
	}
	
	public void seLocomover(){
		System.out.println("O peixe está se locomovendo");
	}

}
