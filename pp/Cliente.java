package modelo;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class Cliente {
	private String nome;
	private String cpf;
	private String telefone;
	private String endereco;
	private String dataNascimento;
	private Poupanca poupanca;
	private Corrente corrente;
	private boolean valida;
	public int CLI_idCliente = 0;
	private int opcao;
	private Scanner input = new Scanner(System.in);
	private SimpleDateFormat dtaSimple = new SimpleDateFormat("dd/MM/yyyy");
	
	public Cliente() {
		this.nome = "";
		this.cpf = "";
		this.telefone = "";
		this.endereco = "";
		this.dataNascimento = "";
	}
	
	public Cliente(String nome, String cpf, String telefone, String endereco, String dataNascimento) {
		this.nome = nome;
		this.cpf = cpf;
		this.telefone = telefone;
		this.endereco = endereco;
		this.dataNascimento = dataNascimento;
	}
	
	public void criarCliente() {	
		System.out.println("DADOS PESSOAIS DO CLIENTE");
		System.out.println("Infome o nome do cliente: ");
		this.nome = this.input.nextLine();
		
		this.valida = false;
		while(!this.valida) {
			System.out.println("Informe o cpf do cliente: ");
			this.cpf = this.input.nextLine();
			
			this.valida = this.cpf.matches("\\d{3}\\.\\d{3}\\.\\d{3}\\-\\d{2}");
			if(!this.valida)
				System.out.println("CPF invalido, insira novamente no formato(xxx.xxx.xxx-xx)!!!");
		}
		
		this.valida = false;
		while(!this.valida){
			System.out.println("Informe o telefone do cliente: ");
			this.telefone = this.input.next();
			this.valida = this.telefone.matches("\\d{4}\\-\\d{4}");
			if(!this.valida)
				System.out.println("Telefone inválido, insira novamente no formato(xxxx-xxxx)!!!");
		}
		
		this.valida = false;
		while(!this.valida){
			System.out.println("Informe a data de nascimento do cliente: ");
			this.dataNascimento = input.next();
			this.dtaSimple.setLenient(false);
			try {
				Date data = this.dtaSimple.parse(this.dataNascimento);
			  	this.valida = true;
			} catch(ParseException e) {
				this.valida = false;
				System.out.println("Data inválida, insira novamente no formato(xx/xx/xxxx)!!!\n");
			}
			
		}
		this.input.nextLine();
		System.out.println("Endereço: ");
		this.endereco = input.nextLine();
	}
	
	public void editarCliente() {
		System.out.println("Qual dado você quer ditar");
		System.out.println("1. Nome");
		System.out.println("2. Telefone");
		System.out.println("3. Endereço");
		System.out.println("Resposta: ");
		this.opcao = input.nextInt();
		this.input.nextLine();
		switch(this.opcao){
			case 1:
				System.out.println("Infome o novo nome do cliente: ");
				this.nome = this.input.nextLine();
				break;
			case 2:
				this.valida = false;
				while(!this.valida){
					System.out.println("Informe o novo telefone do cliente: ");
					this.telefone = this.input.next();
					this.valida = this.telefone.matches("\\d{4}\\-\\d{4}");
					if(!this.valida)
						System.out.println("Telefone inválido, insira novamente no formato(xxxx-xxxx)!!!");
				}
				break;
			case 3:
				System.out.println("Informe o novo dados do endereco do cliente: ");
				this.endereco = this.input.nextLine();
				break;
			case 4:
				break;
			default:
				System.out.println("Opção inválida!!!");
		}
	}
	
	public void mostrarCliente() {
		System.out.println("CLIENTE");
		System.out.println("Identificador: "+this.CLI_idCliente);
		System.out.println("Nome: " + this.nome);
		System.out.println("CPF: " + this.cpf);
		System.out.println("Telefone: " + this.telefone);
		System.out.println("Data de Nascimento: " + this.dataNascimento);
		System.out.println("Endereco: "+this.endereco);
		
		if(this.poupanca != null) {
			this.poupanca.mostrarContaPoupanca();
		}
		
		if(this.corrente != null) {
			this.corrente.mostrarContaCorrente();
		}
	}
	
	public boolean jaTemContaCorrente() {
		if(this.corrente == null) {
			return false;
		}
		else return true;
	}
	
	public boolean jaTemContaPoupanca() {
		if(this.poupanca == null) {
			return false;
		}
		else return true;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getCpf() {
		return cpf;
	}

	public void setCpf(String cpf) {
		this.cpf = cpf;
	}

	public String getTelefone() {
		return telefone;
	}

	public void setTelefone(String telefone) {
		this.telefone = telefone;
	}

	public String getDataNascimento() {
		return dataNascimento;
	}

	public void setDataNascimento(String dataNascimento) {
		this.dataNascimento = dataNascimento;
	}
	
	public Poupanca getPoupanca() {
		if(poupanca == null) poupanca = new Poupanca();
		return poupanca;
	}
	
	public void setPoupanca(Poupanca poupanca) {
		this.poupanca = poupanca;
	}
	
	public Corrente getCorrente() {
		if(corrente == null) corrente = new Corrente();
		return corrente;
	}
	
	public void setCorrente(Corrente corrente) {
		this.corrente = corrente;
	}
}