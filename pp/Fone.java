package modelo;


public class Fone {
	
	private int ddd;
	private String numero;
	
	public Fone() {
		this.ddd = 0;
		this.numero = "";
	}

	public Fone(int ddd, String numero) {
		this.ddd = ddd;
		this.numero = numero;
	}
	
	public void mostrarFone(){
		System.out.println("("+ this.ddd + ") " + this.numero);
	}
	
	public int getDdd() {
		return ddd;
	}
	public void setDdd(int ddd) {
		this.ddd = ddd;
	}
	public String getNumero() {
		return numero;
	}
	public void setNumero(String numero) {
		this.numero = numero;
	}
	
	
	
	
	
}
