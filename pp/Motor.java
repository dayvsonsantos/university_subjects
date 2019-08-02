package modelo;

public class Motor {
	private String nome;
	private String combustivel;
	private double potencia;
	private double consumo;
	
	public Motor(String nome, String combustivel, double potencia, double consumo){
		this.nome = nome;
		this.combustivel = combustivel;
		this.potencia = potencia;
		this.consumo = consumo;
	}
	
	public void mostrarMotor(){
		System.out.println("Nome do Motor: "+this.nome);
		System.out.println("Combustivel: "+this.combustivel);
		System.out.println("Potencia: "+this.potencia);
		System.out.println("Consumo: "+this.consumo);
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getCombustivel() {
		return combustivel;
	}

	public void setCombustivel(String combustivel) {
		this.combustivel = combustivel;
	}

	public double getPotencia() {
		return potencia;
	}

	public void setPotencia(double potencia) {
		this.potencia = potencia;
	}

	public double getConsumo() {
		return consumo;
	}

	public void setConsumo(double consumo) {
		this.consumo = consumo;
	}
	
	
	

}
