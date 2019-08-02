package modelo;

import java.text.SimpleDateFormat;
import java.util.Date;

public class Historico {

	private Date data;
	private String tipo;
	private double valor;
	private int contDestipo = -1;
	
	public Historico(String tipo, double valor, Date data) {
		this.data = data;
		this.tipo = tipo;
		this.valor = valor;
	}

	public Historico(String tipo, double valor, Date data, int contDestipo) {
		this.data = data;
		this.tipo = tipo;
		this.valor = valor;
		this.contDestipo = contDestipo;
	}

	public void mostarDados() {
		SimpleDateFormat form = new SimpleDateFormat("dd/MM/yyyy");		
		System.out.println("Data: " + form.format(this.data));
		System.out.println("Tipo: " + this.tipo);
		System.out.println("Valor: " + this.valor);
		if (this.contDestipo != -1) {
			System.out.println("Conta destino: " + this.contDestipo);
		}
	}
}
