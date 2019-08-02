package modelo;

public class Cobra extends Animal{
	
	public Cobra(String nome, String cor, double peso) {
		super(nome, cor, peso);
	}
	
	public void emitirSom(){
		System.out.println("som da cobra");
	}
	
	public void seLocomover(){
		System.out.println("A cobra está se locomovendo");
	}

}
