# Hidroponia Automatizada

## Sobre o projeto:
Este projeto consiste em um sistema de irrigação e monitoramento de um cultivo em hidroponia, que é uma forma de cultivo dentro de estufas sem uso de solo. Pela falta de alguns componentes no simulador, foram utilizados outros componentes disponíveis para fazer a sua simulação da forma mais adequada possível, como por exemplo o sensor de pH que foi substituído por um ***potenciômetro*** que tem seu valores variando de ***0 até 14***, e também a valvula solenóide que foi substituída por um ***motor CC***.

## Componentes:
Para desenvolver este protótipo, foi utilizado:

+ Um sensor de temperatura;
+ Um LCD;
+ Dois potenciômetros;
+ Um motor CC;
+ Um relé;
+ Um resistor;
+ Um buzzer.

## Como funciona?
Para montar o protótipo, você pode verificar o projeto já montado no simulador, que será exibido posteriormente no arquivo. Bom, o propósito deste protótipo é fazer o monitoramento e a irrigação de cultivos hidropônicos, então vamos explicar em duas partes, o ***monitoramento*** e a outra parte que é a ***irrigação***:

### Monitoramento
+ O ***sensor de pH*** (Potenciômetro na protoboard à esquerda) recebe o valor do pH da água do subtrato nutritivo no meio hidropônico, para saber se a água que circula no cultivo está nas condições adequadas ou não;
+ O ***sensor de temperatura*** recebe o valor da temperatura do ambiente para saber se está nas condições adequadas ou não;
+ Estas duas medidas são exibidas em um ***LCD*** que mostra se o pH e a temperatura estão no nível recomendado ou não;
+ Caso alguma das medidas não esteja nos conformes, além do aviso visual no ***LCD***, um buzzer começa a tocar para fazer o aviso sonoro.

### Irrigação
+ Um ***relé*** é utilizado como um interruptor para a ativação do motor CC;
+ A ***bomba de irrigação*** (Motor CC), quando ligada com a ativação do relé, começa a irrigar o cultivo, com um tempo pré definido até ter a sua ativação e também da duração da irrigação no código-fonte;
+ Importante lembrar que o ***LCD*** atualiza as suas mensagens a cada 5 segundos, mostrando quando a irrigação está sendo feita ou não, o pH e a temperatura.

## Como utilizar o projeto pelo simulador:
Para começar, entre no link abaixo:
+ https://www.tinkercad.com/things/8NqB1GetlE6

Agora, já no simulador, basta clicar no canto superior direito em "Iniciar simulação" ou clicar na tecla "S". Feito isso, agora você consegue ver o protótipo funcionando, podendo mudar a temperatura clicando no sensor de temperatura, e também o pH girando o potenciômetro ao lado deste sensor. 

## Link do vídeo:
+ https://www.youtube.com/watch?v=wFY6m9hp4sc
