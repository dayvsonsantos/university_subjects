package modelo;

public class Engenheiro extends Pessoa {
	
	public int numCrea;
	
	public Engenheiro(int numCrea, String nome, String cpf){
		super(nome, cpf);
		this.numCrea = numCrea;
	}
	
	public void projetar(){
		System.out.println(this.nome +" Está projetando...");
	}
	
	public void setNumCrea(int numCrea){
		this.numCrea = numCrea;
	}
	
	public void emitirAvaliacaoTecnica(){
		System.out.print("O engenheiro " +this.nome);
		System.out.println(" cpf: " +this.cpf + " esta emintindo");
	}

}
