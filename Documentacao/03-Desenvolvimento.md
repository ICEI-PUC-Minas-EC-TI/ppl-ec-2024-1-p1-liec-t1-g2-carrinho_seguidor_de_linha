
# Materiais

Os materiais utilizados no projeto foram:
- 1x Kit chassi 4WD Robô para Arduíno
- 4x Motores DC 3-6v 
- 1x Protoboard dupla
- 1x Esp-32
- 1x Módulo Ponte-H L298N
- 1x Soquete para bateria de 9v
- 1x Soquete para 4 pilhas AA (1,5v)
- 1x Buzzer
- 2x Sensores de Obstáculos Reflexivos Infravermelhos
- Jumpers

# Desenvolvimento

Após estabalecer o escopo do projeto, como foi descrito na seção de "metodologias ágeis", o grupo começou a trabalhar na montagem do robô. Mais detalhes foram especificados na seção a seguir "Montagem". Depois de finalizarmos a montagem do robô e realizarmos vários testes para averiguar o funcionamento do Hardware, começamos o desenvolvimento do aplicativo, que será mais detalahdo na seção a seguir "Desenvolvimento do Aplicativo". O próximo passo foi o desenvolvimento do código, que será mais detalahdo na seção "Desenvolvimento do Código". Por fim, realizamos a integração entre o aplicativo e o robô através de pequenas alterações no código do robô. Mais detalhes foram fornecidos na sessão "Comunicação entre App e Hardware". 

## Desenvolvimento do Aplicativo

### Interface

O aplicativo possui uma tela que consiste em 3 setas (uma para frente, uma para direita e outra para a esquerda). Além disso possuim a logo da PUC, tudo isso dentro de um Table Arrangement. Também possui o nome da disciplina e um botão que procura os dispositivos aptos a conectar via Bluetooth.

### Código

O botão para conectar via Bluetooth apresenta ao clicar no botão uma lista dos dispositivos aptos a conectar. Já os botões de movimento do carrinho enviam variáveis do tipo "int" para orientar a direção que deve ser executada, sendo '2' para frente, '3' para direita e '4' para esquerda.

## Desenvolvimento do Hardware

### Montagem

Primeiramente montamos o Kit chassi 4wd e colocamos os 4 motores acoplados ao kit. O próximo passo foi fixar a protoboard deupla na parte superior do Kit chassi, conectar o ESP-32 na protoboard, conectar os polos negativo e positivo do soquete da bateria de 9v em um do par de fileiras de negativos e positivos da protoboard, e conectar os polos positivo e negativo do soquete das 4 pilhas AA no par de fileiras de positivos e negativos oposto da protoboard. Em seguida, fixamos os cabos dos quatro motores na ponte-H (apenas percebemos que essa não é uma montagem adequada após realizarmos os testes com os motores, mais adiante), conectamos ambos os polos negativos dos dois motores da esquerda no borne OUT 1 da ponte-H. Os polos positivos dos motores da esquerda foram conectados no borne OUT 2 da pone-H; enquanto que os polos positivos do par de motores da direita foram conectados no borne OUT 3, e os negativos, no borne OUT 4. Depois, seguimos com as conexões da ponte-H, conectando o borne de alimentação dos motores "VCC" no soquete da bateria de 9v, o borne GND, no ground comum do robô, e o borne de alimentação lógica da ponte-H "V_logic" na alimentação do soquete de 4 pilhas AA. Ainda nas conexões da ponte-H, conectamos os pinos ENA, IN1, IN2, IN3, IN4 e ENB, nas portas do ESP-32; e retiramos o jumper "Regulador V_Logic", finalizando assim as conexões que foram feitas na parte inferior do robô. O próximo passo foi ligar o positivo do soquete de pilhas na porta "Vin" do ESP-32, e a porta "GND" no ground comum do robô. Em seguida, realizamos as conexões de ambos os sensores infravermelhos, conectando ambas as entradas "Vcc" nos 6v fornecidos pelas pilhas, e ambas as entradas "GND" no groud comum do robô. Ainda nas conexões dos sensores infravermelhos, conectamos cada uma das entradas "OUT" em uma porta do ESP-32. Finalmente, conectamos o polo positivo do buzzer em uma das portas do ESP-32, e o polo negativo foi conectado do ground comum do robô.  

### Desenvolvimento do Código

Descreva como foi o desenvolvimento do código do arduino/ESP.

## Comunicação entre App e Hardware

Descreva como foi o processo de comunicação entre App e arduino/ESP.
