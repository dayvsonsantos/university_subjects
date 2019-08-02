package modelo;

public class Gato extends Animal{
	
	public Gato(String nome, String cor, double peso) {
		super(nome, cor, peso);
	}

	public void emitirSom(){
		System.out.println("som do gato");
	}
	
	public void seLocomover(){
		System.out.println("O gato está se locomovendo");
	}

}
