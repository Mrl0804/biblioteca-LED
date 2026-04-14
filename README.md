#BIBLIOTECA LED

a biblioteca LED apresenta funcionalidades para arduino com esp 32.

a classe LED apresenta as seguintes funcoes:

-ligar o led continuamente
-ligar por tempo determinado
-apagar
-alternar o estado
-piscar continuamente
-piscar uma quantidade definida de vezes

o funcionamento é nao bloqueante, utilizando millis()
por isso, o método update() deve ser chamado repetidamente dentro do loop().