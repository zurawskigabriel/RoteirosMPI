
Ir para o conteúdo principal
Condições de conclusão

int my_rank;      // Identificador deste processo
int proc_n;         // Numero de processos disparados pelo usuário na linha de comando (np)
int message;     // Buffer para as mensagens

MPI_Init(); // funcao que inicializa o MPI, todo o código paralelo esta abaixo

my_rank = MPI_Comm_rank();  // pega o numero do processo atual (rank)
proc_n    = MPI_Comm_size();  // pega informação do numero de processos (quantidade total)

// receber da esquerda

if ( my_rank == 0 )    // sou o primeiro?
     message = 0;      // sim, sou o primeiro, crio a mensagem sem receber
else
     MPI_Recv(message, my_rank-1); // não sou o primeiro, recebo da esquerda

// processo mensagem

message +=1; // incremento um na mensagem recebida

// enviar para a direita

if ( my_rank == proc_n-1 ) // sou o último?
     printf("Mensagem: ", message); // sim sou o último, apenas mostro mensagem na tela
else
     MPI_Send(message, my_rank+1); // não sou o último, envio mensagem para a direita

MPI_Finalize();
Última atualização: terça-feira, 5 mai. 2026, 14:27
