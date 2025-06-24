import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Banco banco = new Banco(101, "Nubank");
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("\nMENU BANCO:");
            System.out.println("1 - Abrir conta");
            System.out.println("2 - Depositar");
            System.out.println("3 - Sacar");
            System.out.println("4 - Mostrar correntistas"); 
            System.out.println("5 - Fechar conta");
            System.out.println("0 - Sair");
            System.out.print("Escolha uma opcao: ");

            int opcao = scanner.nextInt();
            scanner.nextLine();

            if (opcao == 0) {   
                System.out.println("Saindo...");
                break;
            }

            switch (opcao) {
                case 1:
                    System.out.print("Numero da conta: ");
                    String num = scanner.nextLine();
                    System.out.print("CPF do titular: ");
                    String cpf = scanner.nextLine();
                    ContaCorrente conta = new ContaCorrente(num, cpf);
                    banco.abrirConta(conta);
                    System.out.println("Conta aberta.");
                    break;

                case 2:
                    System.out.print("CPF para deposito: ");
                    String cpfDep = scanner.nextLine();
                    ContaCorrente contaDep = banco.getCorrentista(cpfDep);
                    if (contaDep != null) {
                        System.out.print("Valor para depositar: ");
                        double val = scanner.nextDouble();
                        scanner.nextLine();
                        contaDep.depositar(val);
                    } else {
                        System.out.println("Conta nao encontrada.");
                    }
                    break;

                case 3:
                    System.out.print("CPF para saque: ");
                    String cpfSaq = scanner.nextLine();
                    ContaCorrente contaSaq = banco.getCorrentista(cpfSaq);
                    if (contaSaq != null) {
                        System.out.print("Valor para sacar: ");
                        double val = scanner.nextDouble();
                        scanner.nextLine();
                        contaSaq.sacar(val);
                    } else {
                        System.out.println("Conta nao encontrada.");
                    }
                    break;

                case 4:
                    banco.exibeCorrentistas();
                    break;

                case 5:
                    System.out.print("Indice da conta para fechar (comeca em 0): ");
                    int idx = scanner.nextInt();
                    scanner.nextLine();
                    banco.encerrarConta(idx);
                    break;

                default:
                    System.out.println("Opcao invalida.");
            }
        }

        scanner.close();
    }
}
