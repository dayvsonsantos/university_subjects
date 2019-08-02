package modelo;

public class Corrente extends Conta{
	
	private double valorManutencao;
	
	public Corrente() {
		super();
		this.valorManutencao = 0;
	}
	
	public Corrente(int num, double saldo, double valorManutencao) {
		super(num, saldo);
		this.valorManutencao = valorManutencao;
	}
	
	public void mostrarContaCorrente() {
		System.out.println("CONTA CORRENTE");
		this.mostrarConta();
		System.out.println("Valor de manutenção da conta: " + this.valorManutencao);
	}
	
	public void criarContaCorrente() {
		System.out.println("DADOS DA CONTA CORRENTE");
		this.criarConta();
		System.out.println("Valor manutenção da conta: ");
		this.valorManutencao = this.input.nextDouble();
	}
	
	public void excluirContaCorrente() {
		this.excluirConta();
		this.valorManutencao = 0;
	}
	public void calcularValorManutencao() {
		this.debitar(this.valorManutencao);
	}

	public double getValorManutencao() {
		return this.valorManutencao;
	}

	public void setValorManutencao(double valorManutencao) {
		this.valorManutencao = valorManutencao;
	}
}
