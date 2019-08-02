package modelo;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Poupanca extends Conta{
	
	private String dataAniversario;
	private double jurosRendimento;
	private double valorCalculo;
	
	public Poupanca() {
		super();
		this.dataAniversario = "";
		this.jurosRendimento = 0;
	}
	
	public Poupanca(int num, double saldo, String dataAniversario, double jurosRendimento) {
		super(num, saldo);
		this.dataAniversario = dataAniversario;
		this.jurosRendimento = jurosRendimento;
	}
	
	public void criarContaPoupanca() {
		SimpleDateFormat dtaSimple = new SimpleDateFormat("dd/MM/yyyy");
		System.out.println("\nDADOS DA CONTA POUPANÇA");
		this.criarConta();
		
		boolean valida = false;
		while(!valida){
			System.out.println("Data de aniversario da conta: ");
			this.dataAniversario = this.input.next();
			dtaSimple.setLenient(false);
			try {
			  Date data = dtaSimple.parse(this.dataAniversario);
			  valida = true;
			} catch(ParseException e) {
			  valida = false;
			  System.out.println("Data inválida, insira novamente no formato(xx/xx/xxxx)!!!\n");
			}
		}
		
	
		System.out.println("Juros rendimento: ");
		this.jurosRendimento = this.input.nextDouble();
	}
	
	public void excluirContaPoupanca() {
		this.excluirConta();
		this.dataAniversario = "";
		this.jurosRendimento = 0;
		this.valorCalculo = 0;
	}
	
	public void mostrarContaPoupanca() {
		System.out.println("CONTA POUPANÇA");
		this.mostrarConta();
		System.out.println("Data de Aniversário da Conta: " + this.dataAniversario);
		System.out.println("Juro de Rendimenro: " + this.jurosRendimento);
	}
	
	public void cadlcularRendimento() {
		this.valorCalculo = saldo + saldo*jurosRendimento;
	}
	
	public void acrescentarValorConta() {
		this.creditar(valorCalculo);
	}

	public String getDataAniversario() {
		return dataAniversario;
	}

	public void setDataAniversario(String dataAniversario) {
		this.dataAniversario = dataAniversario;
	}

	public double getJurosRendimento() {
		return jurosRendimento;
	}

	public void setJurosRendimento(double jurosRendimento) {
		this.jurosRendimento = jurosRendimento;
	}
}
