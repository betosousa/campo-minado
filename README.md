# campo-minado

Jogo Campo minado em C++, utilizando SFML. 

Como power up, foi implementado um sistema de vidas extras para o jogador.

Este jogo contém 3 telas:

- um menu inicial, onde é possivel escolher os parâmetros do jogo (totais de colunas, linhas, bombas e vidas do jogador);

- um campo de jogo, onde inicialmente os locais do mapa estão fechados (amarelos) e o jogador pode clicar neles com o botão esquerdo para abri-los (pintando o local de azul), caso exista uma bomba, o local será pintado de vermelho e o jogador perderá uma vida. Também é possivel clicar com o botão direito para adicionar uma bandeira no local (pintando o local de verde);

- um painel de fim de jogo que aparece sobre o campo de jogo ao final da partida, com um botão para reinício da partida com os mesmos parâmetros definidos no menu inicial.
