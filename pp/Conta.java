package modelo;

import java.util.Date;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Scanner;

public class Conta {
	
	public int num;
	public double saldo;
	public Date dataAbertura;
	protected Agencia agencia = new Agencia();
	
	protected Scanner input = new Scanner(System.in);
	protected ArrayList<Historico> transferencias = new ArrayList<Historico>();
	
	public Conta() {
		this.num = 0;
		this.saldo = 0;
	}
	
	public Conta(int num, double saldo) {
		this.num = num;
		this.saldo = saldo;
	}
	
	protected void criarConta() {
		System.out.println("Numero da Conta: ");
		this.num = this.input.nextInt();
		System.out.println("Saldo da conta: ");
		this.saldo = this.input.nextDouble();		
		this.dataAbertura = new Date();		
		this.agencia.criarAgencia();
	}
	
	protected void excluirConta() {
		this.num = 0;
		this.saldo = 0;
		this.dataAbertura = null;
		this.agencia = new Agencia();
		this.transferencias = new ArrayList<Historico>();
	}
	
	protected void mostrarConta() {
		System.out.println("Numero da Conta: " + this.num);
		System.out.println("Saldo da Conta: " + this.saldo);
		SimpleDateFormat form = new SimpleDateFormat("dd/MM/yyyy");
		System.out.println("Data: " + form.format(this.dataAbertura));
		this.agencia.mostrarAgencia();
	}

	public void creditar() {
		System.out.println("Insira o valor p/ creditar: ");
		double valor = this.input.nextDouble();
		this.saldo += valor;
		
		Date data = new Date();
		this.transferencias.add(new Historico("Credito", valor, data));
	}
	
	public void creditar(double valor) {
		this.saldo += valor;
		
		Date data = new Date();
		this.transferencias.add(new Historico("Credito", valor, data));
	}
	
	public void debitar() {
		System.out.println("Insira o valor p/ debitar: ");
		double valor = this.input.nextDouble();
		if(this.saldo >= valor){
			this.saldo -= valor;
		} else {
			System.out.println("Saldo insuficiente!!!");
		}
		
		Date data = new Date();
		this.transferencias.add(new Historico("Debito", valor, data));
	}
	
	public void debitar(double valor) {
		if(this.saldo >= valor){
			this.saldo -= valor;
		} else {
			System.out.println("Saldo insuficiente!!!");
		}
		
		Date data = new Date();
		this.transferencias.add(new Historico("Debito", valor, data));
	}
	
	public void transferir(Conta destino) {
		System.out.println("Insira o valor p/ transferir: ");
		double valor = this.input.nextDouble();
		if(this.saldo >= valor) {
			this.debitar(valor);
			destino.creditar(valor);
			Date data = new Date();
			this.transferencias.add(new Historico("Transferencia", valor, data, destino.num));
		} else {
			System.out.println("Saldo insuficiente!!!");
		}
	
	}
	
	public void consultarHistorico() {
		System.out.println("*******************************************************");
		System.out.println("HISTORICO");
		for (int i = 0; i < this.transferencias.size(); i++) {
			this.transferencias.get(i).mostarDados();
			System.out.println();
		}
		System.out.println("*******************************************************");
	}
}