package modelo;

public class Professor extends Pessoa{
	
	public String titulacao;
	
	public Professor(String titulacao, String nome, String cpf){
		super(nome, cpf);
		this.titulacao = titulacao;
	}
	public void corrigirProva(){
		System.out.println("professor: "+ this.nome+" está corrigindo prova...");
	}

}
