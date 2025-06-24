import java.util.ArrayList;

public class Banco {
    private int codigoIdentificador;
    private String nome;
    private final ArrayList<ContaCorrente> correntistas;

    public Banco(int codigoIdentificador, String nome) {
        this.codigoIdentificador = codigoIdentificador;
        this.nome = nome;
        correntistas = new ArrayList<>();
    }

    public int getCodigoIdentificador() {
        return codigoIdentificador;
    }

    public void setCodigoIdentificador(int codigoIdentificador) {
        this.codigoIdentificador = codigoIdentificador;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void abrirConta(ContaCorrente conta) {
        correntistas.add(conta);
    }

    public void encerrarConta(int indice) {
        if (indice >= 0 && indice < correntistas.size()) {
            correntistas.remove(indice);
        } else {
            System.out.println("Indice invalido para fechar conta");
        }
    }

    public ContaCorrente getCorrentista(String cpf) {
        for (ContaCorrente conta : correntistas) {
            if (conta.getCpfTitular().equals(cpf)) {
                return conta;
            }
        }
        return null;
    }

    public void exibeCorrentistas() {
        System.out.println("=== Lista de correntistas ===");
        for (ContaCorrente conta : correntistas) {
            conta.imprimirDados();
        }
    }
}
