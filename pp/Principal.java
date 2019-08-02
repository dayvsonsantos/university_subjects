package excucao;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.Scanner;

import modelo.Cliente;
import modelo.Conta;

public class Principal {
	
	private static int i;
	private static int j;
	private static int opcaoMenu;
	private static int opcaoConta;
	private static int numConta;
	private static int tipoConta = 0;
	private static Scanner input = new Scanner(System.in);
	private static ArrayList<Cliente> clientes = new ArrayList<Cliente>();
	
	private static void menuPrincipal() {
		System.out.println("Digite uma das opções abaixo");
		System.out.println("1 - Cadastrar Cliente");
		System.out.println("2 - Editar Cliente");
		System.out.println("3 - Exluir Cliente");
		System.out.println("4 - Visualizar Clientes");
		System.out.println("5 - Criar Conta Corrente");
		System.out.println("6 - Criar Conta Poupança");
		System.out.println("7 - Excluir Conta Corrente");
		System.out.println("8 - Excluir Conta Poupança");
		System.out.println("9 - Mostrar Histórico");
		System.out.println("10 - Mostrar Conta Corrente");
		System.out.println("11 - Mostrar Conta Poupança");
		System.out.println("12 - Movimentar Conta");
		System.out.println("13 - Sair");
		System.out.println("Resposta: ");
		opcaoMenu = input.nextInt();
	}
	
	private static void menuConta() {
		//System.out.println("----------------------------");
		System.out.println("Digite uma das opções abaixo");
		System.out.println("1 - Creditar Conta Corrente");
		System.out.println("2 - Debitar Conta Corrente");
		System.out.println("3 - Transferir Conta Corrente");
		System.out.println("4 - Creditar Conta Poupança");
		System.out.println("5 - Debitar Conta Poupança");
		System.out.println("6 - Transferir Conta Poupança");
		System.out.println("7 - Sair");
		System.out.println("Resposta: ");
		opcaoConta = input.nextInt();
		//System.out.println("----------------------------\n");
	}

	private static void cadastrarCliente() {
		boolean foiCadastrado = false;
		Cliente cliente = new Cliente();
		cliente.criarCliente();
		
		for (i = 0; i < clientes.size(); i++) {
			if( clientes.get(i).getCpf().equals(cliente.getCpf()) ) {
				System.out.println("Cliente já está cadastrado!!!");
				foiCadastrado = true;
				break;
			}
		}
		
		if(!foiCadastrado){
			clientes.add(cliente);
			int tam = clientes.size();
			clientes.get(tam-1).CLI_idCliente = tam-1;
			System.out.println("Cliente Cadastrado!!!");
		}
	}
	
	private static void editaCliente() {
		
		System.out.println("Informe o cod identificador do cliente: ");
		i = input.nextInt();
		
		if(i >= clientes.size() || i < 0){
			System.out.println("Codigo Inválido!!!");
		}else{
			clientes.get(i).editarCliente();
			System.out.println("Cliente editado!!!");
		}
	}
	
	private static void excluirCliente() {
		System.out.println("Informe o cod identificador do cliente: ");
		i = input.nextInt();
		
		if(i >= clientes.size() || i < 0){
			System.out.println("Codigo Inválido!!!");
		}else{
			clientes.remove(i);
			System.out.println("Cliente removido!!!");
		}
	}
	
	private static void visualizarCliente() {
		for(int i = 0; i < clientes.size(); i++) {
			clientes.get(i).mostrarCliente();
		}
	}
	
	private static void criarPoupanca() {
		System.out.println("Informe o cod identificador do cliente: ");
		i = input.nextInt();
		
		if(i >= clientes.size() || i < 0){
			System.out.println("Codigo Inválido!!!");
		}else{
			if(clientes.get(i).jaTemContaCorrente()){
				System.out.println("Cliente já possui conta Poupança");
			}else{
				clientes.get(i).getPoupanca().criarContaPoupanca();
				System.out.println("Poupança criada!!!");
			}
		}
	}
	
	private static void criarCorrente() {
		System.out.println("Informe o cod identificador do cliente: ");
		i = input.nextInt();
		
		if(i >= clientes.size() || i < 0){
			System.out.println("Codigo Inválido!!!");
		}else{
			if(clientes.get(i).jaTemContaCorrente()){
				System.out.println("Cliente já possui conta Corrente");
			}else{
				clientes.get(i).getCorrente().criarContaCorrente();
				System.out.println("Corrente cirada!!!");
			}
		}
	}
	
	private static void excluirPoupanca() {
		System.out.println("Informe o cod identificador do cliente: ");
		i = input.nextInt();
		
		if(i >= clientes.size() || i < 0){
			System.out.println("Codigo Inválido!!!");
		}else{
			if(clientes.get(i).jaTemContaPoupanca()){
				clientes.get(i).getPoupanca().excluirContaPoupanca();
				System.out.println("Conta ecluida!!!");
			}else{
				System.out.println("Cliente não possui conta Poupanca");
			}
		}
		
	}
	
	private static void excluirCorrente() {
		System.out.println("Informe o cod identificador do cliente: ");
		i = input.nextInt();
		
		if(i >= clientes.size() || i < 0){
			System.out.println("Codigo Inválido!!!");
		}else{
			if(clientes.get(i).jaTemContaCorrente()){
				clientes.get(i).getCorrente().excluirContaCorrente();
				System.out.println("Conta excluida!!!");
			}else{
				System.out.println("Cliente não possui conta Corrente");
			}
		}
		
	}
	
	private static void creditarCorrente() {
		System.out.println("Informe o cod identificador do cliente: ");
		i = input.nextInt();
		
		if(i >= clientes.size() || i < 0){
			System.out.println("Codigo Inválido!!!");
		}else{
			if(clientes.get(i).jaTemContaCorrente()){
				clientes.get(i).getCorrente().creditar();
				System.out.println("Credito realizado com sucesso!!!");
			}else{
				System.out.println("Cliente não possui conta Corrente");
			}
		}
	}
	
	private static void debitarCorrente() {
		System.out.println("Informe o cod identificador do cliente: ");
		i = input.nextInt();
		
		if(i >= clientes.size() || i < 0){
			System.out.println("Codigo Inválido!!!");
		}else{
			if(clientes.get(i).jaTemContaCorrente()){
				clientes.get(i).getCorrente().debitar();
				System.out.println("Debito Realizado com sucesso!!!");
			}else{
				System.out.println("Cliente não possui conta Corrente");
			}
		}
	}
	
	
	
	private static void transferirCorrente() {
		System.out.println("Informe o cod identificador do cliente: ");
		i = input.nextInt();
		
		if(clientes.get(i).jaTemContaCorrente()){
			System.out.println("Informe o tipo de conta destino");
			System.out.println("1 - Corrente");
			System.out.println("2 - poupança");
			tipoConta = input.nextInt();
			
			System.out.println("Informe o numero da conta destino: ");
			numConta = input.nextInt();
			
			switch(tipoConta){
				case 1:
					for(j = 0; j < clientes.size(); j++) {
						if(clientes.get(j).jaTemContaCorrente()){
							if(clientes.get(j).getCorrente().num == numConta){
								clientes.get(i).getCorrente().transferir(clientes.get(j).getCorrente());
								System.out.println("Transferido com sucesso!!!");
								break;
							}
						}
					}
					
					if (j == clientes.size() && clientes.size() != 0) {
						System.out.println("Cliente não encontrado!!!");
					}
					break;
				case 2:
					for(j = 0; j < clientes.size(); j++) {
						if(clientes.get(j).jaTemContaPoupanca()){
							if(clientes.get(j).getPoupanca().num == numConta){
								clientes.get(i).getCorrente().transferir(clientes.get(j).getPoupanca());
								System.out.println("Transferido com sucesso!!!");
								break;
							}
						}
					}
					if (j == clientes.size() && clientes.size() != 0) {
						System.out.println("Cliente não encontrado!!!");
					}
					break;
				default:
					System.out.println("Opção de conta inválida!!!");
			}
			
		}else{
			System.out.println("Cliente não possui conta Corrente!!!");
		}
		
	}
	
	private static void transferirPoupanca() {
		System.out.println("Informe o cod identificador do cliente: ");
		i = input.nextInt();
		
		if(clientes.get(i).jaTemContaPoupanca()){
			System.out.println("Informe o tipo de conta destino");
			System.out.println("1 - Corrente");
			System.out.println("2 - poupança");
			tipoConta = input.nextInt();
			
			System.out.println("Informe o numero da conta destino: ");
			numConta = input.nextInt();
			
			switch(tipoConta){
				case 1:
					for(j = 0; j < clientes.size(); j++) {
						if(clientes.get(j).jaTemContaCorrente()){
							if(clientes.get(j).getCorrente().num == numConta){
								clientes.get(i).getPoupanca().transferir(clientes.get(j).getCorrente());
								System.out.println("Transferido com sucesso!!!");
								break;
							}
						}
					}
					if (j == clientes.size() && clientes.size() != 0) {
						System.out.println("Cliente não encontrado!!!");
					}
					break;
				case 2:
					for(j = 0; j < clientes.size(); j++) {
						if(clientes.get(j).jaTemContaPoupanca()){
							if(clientes.get(j).getPoupanca().num == numConta){
								clientes.get(i).getPoupanca().transferir(clientes.get(j).getPoupanca());
								System.out.println("Transferido com sucesso!!!");
								break;
							}
						}
					}
					if (j == clientes.size() && clientes.size() != 0) {
						System.out.println("Cliente não encontrado!!!");
					}
					break;
				default:
					System.out.println("Opção de conta inválida!!!");
			}
		}else{
			System.out.println("Cliente não possuir conta Poupança!!!");
		}
	}
	
	
	private static void creditarPoupanca() {
		System.out.println("Informe o cod identificador do cliente: ");
		i = input.nextInt();
		
		if(i >= clientes.size() || i < 0){
			System.out.println("Codigo Inválido!!!");
		}else{
			if(clientes.get(i).jaTemContaPoupanca()){
				clientes.get(i).getPoupanca().creditar();
			}else{
				System.out.println("Cliente não possui conta Poupança!!!");
			}
		}
	}
	
	private static void debitarPoupanca() {
		System.out.println("Informe o cod identificador do cliente: ");
		i = input.nextInt();
		
		if(i >= clientes.size() || i < 0){
			System.out.println("Codigo Inválido!!!");
		}else{
			if(clientes.get(i).jaTemContaCorrente()){
				clientes.get(i).getCorrente().debitar();
			}else{
				System.out.println("Cliente não possui conta Poupança!!!");
			}
		}
	}
	
	//=============================================================================================================================
	private static void mostrarHistorico() {
		System.out.println("Informe o cod identificador do cliente: ");
		i = input.nextInt();
		
		System.out.println("Historico de corrente ou poupança(1/2)?: ");
		int t_conta = input.nextInt();
		
		if(t_conta == 1) {
			clientes.get(i).getCorrente().consultarHistorico();
		} else if(t_conta == 2) {
			clientes.get(i).getPoupanca().consultarHistorico();
		}
		
	}
	
	private static void mostrarContaCorrente() {
		System.out.println("Informe o cod identificador do cliente: ");
		i = input.nextInt();
		if (clientes.get(i).jaTemContaCorrente()) {
			clientes.get(i).getCorrente().mostrarContaCorrente();
		} else {
			System.out.println("Cliente não possui conta Corrente!!!");
		}
	}
	
	private static void mostrarContaPoupanca() {
		System.out.println("Informe o cod identificador do cliente: ");
		i = input.nextInt();
		if (clientes.get(i).jaTemContaPoupanca()) {
			clientes.get(i).getPoupanca().mostrarContaPoupanca();
		} else {
			System.out.println("Cliente não possui conta Poupança!!!");
		}
	}
	
	private static void movimentarConta() {
		menuConta();
		System.out.println("*******************************************************");
		switch(opcaoConta){
			case 1:
				creditarCorrente();
				break;
			case 2:
				debitarCorrente();
				break;
			case 3:
				transferirCorrente();
				break;
			case 4:
				creditarPoupanca();
				break;
			case 5:
				debitarPoupanca();
				break;
			case 6:
				transferirPoupanca();
				break;
			case 7:
				break;
			default: 
				System.out.println("Opção inválida!!!");
		}
	}
	
	public static void main(String[] args) {
				
		do{
			System.out.println("*******************************************************");
			menuPrincipal();
			System.out.println("*******************************************************");
			switch(opcaoMenu){
				case 1:
					cadastrarCliente();
					break;
				case 2:
					editaCliente();
					break;
					
				case 3:
					excluirCliente();
					break;
					
				case 4:
					visualizarCliente();
					break;
				case 5:
					criarCorrente();
					break;
				case 6:
					criarPoupanca();
					break;
				case 7:
					excluirCorrente();
					break;
				case 8:
					excluirPoupanca();
					break;					
				case 9:
					mostrarHistorico();
					break;
				case 10:
					mostrarContaCorrente();
					break;
				case 11:
					mostrarContaPoupanca();
					break;
				case 12:
					movimentarConta();
					break;
				case 13:
					break;
				default:
					System.out.println("Opção inválida");
			}
		}while(opcaoMenu != 13);
		
		
	}

}
