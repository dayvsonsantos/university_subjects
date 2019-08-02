package modelo;

public class Automovel {
	
	String motorista;
	String cor;
	Motor motor;
	
	public Automovel(String motorista, String cor, String nome, String combustivel, double potencia, double consumo){
		this.motorista = motorista;
		this.cor = cor;
		this.motor = new Motor(nome, combustivel, potencia, consumo);
	}

	
	public void mostrarAutomovel(){
		System.out.println("Motorista: "+this.motorista);
		System.out.println("Cor: "+this.cor);
		motor.mostrarMotor();
	}
	
}
