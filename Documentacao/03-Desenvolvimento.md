
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

O primeiro passo do código foi incluir a biblioteca <Arduino.h> e, para facilitar a configuração e a utilização dos motores, criar uma classe no código denominada "DCMotor" que contém as variáveis necessárias de cada motor, além de métodos públicos que ajudam a controlar os motores. As variáveis da classe são "spd" que irá armazenar a velocidade desejada no motor, "pin1" e "pin2", que irão armazenar respectivamete os valores de IN1 e IN2 de cada par de motor, e "atv" que irá armazenar o valor do ativador de cada par de motor (ENA ou ENB). Os métodos dessa classe são: "Pinout", um método que recebe por parâmetro o valor das portas em que foram conectados os "INs" de cada par de motor CC e o valor da porta em que foi conectado o ativador de cada par de motor (ENA ou ENB), e define tais pinos como portas do tipo OUTPUT, além de armazenar esses valores nas variáveis pin1, pin2 e atv de cada objeto DCMotor. Outro método dessa classe é "Speed" que recebe por parâmetro um valor inteiro entre 0 e 255 para agregá-lo à variável spd do objeto motor que será usada para controlar a velocidade de rotação desse motor específico. Por fim temos três métodos que não recebem nenhum valor por parâmetro, apenas usam os valores armazenados nas variáveis pin1, pin2, atv, e spd para realizar os movimentos rotacionais dos motores. Tais métodos são o "Forward" que irá girar o objeto motor para frente, o "Backward" que irá girar o objeto motor para trás, e o "Stop" que irá parar qualquer movimento rotacional que o objeto motor esteja fazendo. É importante ressaltar que a direção de rotação dos motores pode ser invertida a depender das conexões dos polos positivo e negativo do motor na ponte-H, no caso do nosso trabalho, o movimento do par de motores da esquerda estava invertido com relação ao par de motores da direita, por isso utilizamos no código a função "Backward" com esses motores mesmo se referindo à um movimento do robô para frente. Após terminar de criar a classe "DCMotor" criamos dois objetos motores: "Motor1" e "Motor2", cada um se referindo à um par de motores do robô. Dessa forma, o nosso código sempre controla pares de motores através dos pinos da ponte-H, e não 4 motores isoladamente. Depois, ciramos duas variáveis para representar as portas em que foram conectados cada um dos sensores infravermelhos: "sensorD" e "sensorE", e criamos uma variável para representar a porta onde foi conectado o polo positivo do buzzer: "buzzer". Em seguida no código, dentro do "void setup{}" chamamos os métodos "pinout" de cada objeto motor criado para definirmos os valores das variáveis, pin1, pin2 e atv. Além disso, ainda no "void setup{}" definimos os pinos das portas dos sensores infravermelhos como portas do tipo "INPUT" e o pino da porta do buzzer como uma porta do tipo "OUTPUT". Por fim, faltava implementar no "void loop{}" a lógica necessária para integrar o robô com o aplicativo do APP Inventor. Tal processo foi descrito na seção a seguir "Comunicação entre App e Hardware".  

## Comunicação entre App e Hardware

Para realizar a conexão entre o App e o ESP-32, escolhemos utilizar a comunicação via bluetooth. Para tal, incluímos a biblioteca <BluetoothSerial.h> e criamos uma variável chamada "BTSerial". Em seguida, adicionamos no "void setup{}" a função "Serial.begin()" para iniciar uma comunicação serial com o ESP, no caso, seria uma comunicação via bluetooth, e iniciamos a variável criada BTSerial como uma comunicação serial com o nome de "Carrinho_Linha".

Agora, restava apenas armazenar o dado recebido por essa comunicação serial, no caso o dado enviado pelo aplicativo do APP Inventor, em uma variável e implementar a lógica que iria determinar a função que os motores do robô iriam realizar de acordo com o valor armazenado na variável. Para implementar isso, dentro do "void loop{}" , primeiramente verificamos se a entrada serial estava rcebendo dados através da comunicação serial, e, se estivesse, armazenamos esse dado em uma variável criada chamada "entrada". Após isso, implementamos a lógica que averigua qual o valor armazenado na variável entrada e realiza diferentes métodos dos objetos motores de acordo. Mais especificamente, se o valor armazenado for "1" (o valor enviado pelo APP quando nenhum dos botões está apertado) o método para parar os motores é acionado; se o valor armazenado for "2" (o valor enviado pelo APP quando o botão de andar para frente está apertado) o método de girar ambos os motores para frente é acionado; se o valor armazenado for "3" (o valor enviado pelo APP quando o botão de ir para a direita está aepertado) o método de girar para frente os motores da esquerda apenas são acionados de forma a fazer o carrinho virar para a direita; se o valor armazenado for "4" (o valor enviado pelo APP quando o botão de ir para a esquerda está apertado) o método de girar para frente os motores da direita apenas são acionados de forma a fazer o carrinho virar para a esquerda.

Por fim, implementamos a lógica que, independentemente do valor armazenado na variável entrada, sempre que o valor enviado para o ESP por um dos sensores infravermelhos for do tipo HIGH, ou seja, não estiver identificando nenhum objeto a sua frente (no caso de estar sobre a fita isolante preta), acionar o buzzer, para emitir o barulho identificando a fita preta.  
