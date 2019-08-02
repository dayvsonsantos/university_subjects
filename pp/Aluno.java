package Questoes;

public class Aluno {
	String nome;
	String endereco;
	String cpf;
	String fone;
	String date;
	String nomePai;
	String nomeMae;
	
	public Aluno() {
		
		this.nome = "";
		this.endereco = "";
		this.cpf = "";
		this.fone = "";
		this.date = "";
		this.nomePai = "";
		this.nomeMae = "";
		
	}
	
	public Aluno(String nome, String end, String cpf, String fone, String date, String np, String nm) {
		
		this.nome = nome;
		this.endereco = end;
		this.cpf = cpf;
		this.fone = fone;
		this.date = date;
		this.nomePai = np;
		this.nomeMae = nm;
		
	}
	
	void alterarFone(String fone) {
		this.fone = fone;
	}
	
	void alterarEndereco(String endereco) {
		this.endereco = endereco;
	}

	void alterarPai(String nomePai) {
		this.nomePai = nomePai;
	}

	void alterarMae(String nomeMae) {
		this.nomeMae = nomeMae;
	}
	
	void mostrarDadosAluno() {
		System.out.println("   Dados do aluno");
		System.out.println("Nome: " + nome);
		System.out.println("CPF: " + cpf);
		System.out.println("Fone: " + fone);
		System.out.println("Endereço: " + endereco);
		System.out.println("Data de nascimento: " + date);
		System.out.println("Nome da Mãe: " + nomeMae);
		System.out.println("Nome do Pai: " + nomePai);
	}

}
