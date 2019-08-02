package produto;

public class Produtos {
	String nomeDoProduto;
	double precoCusto;
	private double precoVenda;
	private double margemLucro;
	
	void alterarPreco(double parametro) {
		precoVenda = parametro;
	}

	double calcularMargemLucro() {
		margemLucro = (precoVenda - precoCusto);
		return margemLucro;
	}
	
	void mostrarDadosProduto() {
		System.out.println("Nome do Produto: " + nomeDoProduto);
		System.out.println("Preço de Custo: " + precoCusto);
		System.out.println("Preço de Venda: " + precoVenda);	
	}
	
}
