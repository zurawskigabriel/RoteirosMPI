# Roteiro das Atividades de Laboratório - 1ª Aula MPI

**Prof. César A. F. De Rose**

---

## Objetivos

- Realizar um acesso remoto ao LAD com a conta de aluno/grupo e trocar a senha padrão (atentar para o uso da conta correta)
- Exercitar a compilação e a execução de código de um programa MPI tanto na máquina local como na máquina remota (LAD)
- Experimentar com diferentes números de processos executando em vários nós do cluster e observar como os processos são escalonados
- Implementar um pipeline básico a partir do pseudo código visto em aula

---

## Comandos de Referência

### Máquina Local

**Compilação:**
```bash
mpicc file.c -o file_exec
```

**Execução:**
```bash
mpirun -np 1 ./file_exec
```
> onde `np` é o número de processos que serão criados

### Máquina Remota (LAD)

**Compilação:**
```bash
ladcomp -env mpicc file.c -o file_exec
```

**Execução:**
```bash
srun -N 2 -n 2 ./file_exec
```
> onde `N` é o número de nodos e `n` o número total de processos que serão criados

---

## Atividades

### 0. Acessar o LAD

- Acessar o LAD com a conta de aluno (verificar instruções adicionais no Moodle)
- Trocar a senha padrão

### 1. Exercitar a Compilação na Máquina Local

- Compilar os programas `mpi_hello.c` e `hello_messages.c`
- Executar os programas com diferentes números de processos
- Observar o que acontece (atentar para as condições de corrida na execução - ordem de execução e impressão das mensagens)

### 2. Exercitar o Acesso às Máquinas do LAD

- Acessar a máquina `atlantica.lad.pucrs.br` com a sua conta `cp128xx` (onde `xx` é o número do grupo: 01, 02, 10, 15, etc.). Ver instruções no Moodle
- Alterar a senha com o comando:
  ```bash
  yppasswd
  ```
- Compilar o programa `mpi_hello.c` (diretório `exemplos/ether`) para execução na máquina grad com diferentes números de processos e nós do cluster
- Observar como os processos são escalonados (que processo fica em que máquina)

### 3. Compilar e Executar o Programa hello_messages.c

- Utilizar o programa `hello_messages.c` (diretório `exemplos/ether`) que utiliza as rotinas de envio e recebimento de mensagens
- Observar sua execução com diferentes números de processos em vários nós do cluster
- Analisar o comportamento da ordem das mensagens: Como se comportou? Por que isto acontece?
- Alterar o programa para que a ordem das mensagens possa mudar usando o parâmetro `MPI_ANY_SOURCE` no recebimento de mensagens
- Documentar o que aconteceu após a alteração

> **Nota:** Use o código do envio e recebimento de mensagens como base para o próximo exercício.

### 4. Implementar um Pipeline Básico

Escrever um programa MPI que implemente um pipeline básico que passe um inteiro de processo em processo. No estágio final este inteiro é mostrado na tela.

- Basear-se no pseudocódigo do pipeline (vídeo e arquivo no Moodle)
- Testar este programa com diferentes números de processos em vários nós do cluster
- Incluir funcionalidade nos estágios de forma que cada estágio intermediário incremente o inteiro em 1

---

**Última atualização:** terça-feira, 5 mai. 2026, 14:27