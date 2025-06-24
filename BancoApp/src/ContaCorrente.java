public class ContaCorrente {
    private String numeroConta;
    private String cpfTitular;
    private double saldo;

    public ContaCorrente(String numeroConta, String cpfTitular) {
        this.numeroConta = numeroConta;
        this.cpfTitular = cpfTitular;
        this.saldo = 0.0;
    }

    public String getNumeroConta() {
        return numeroConta;
    }

    public void setNumeroConta(String numeroConta) {
        this.numeroConta = numeroConta;
    }

    public String getCpfTitular() {
        return cpfTitular;
    }

    public double getSaldo() {
        return saldo;
    }

    public void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
        } else {
            System.out.println("Valor invalido para deposito");
        }
    }

    public void sacar(double valor) {
        double taxa = valor * 0.005;
        double total = valor + taxa;

        if (valor > 0 && total <= saldo) {
            saldo -= total;
        } else {
            System.out.println("Saque invalido ou saldo insuficiente");
        }
    }

    public void imprimirDados() {
        System.out.println("Numero da conta: " + numeroConta);
        System.out.println("CPF do titular: " + cpfTitular);
        System.out.printf("Saldo: R$ %.2f\n", saldo);
        System.out.println("---------------------------");
    }
}
