
// Link para TinkerCad: https://www.tinkercad.com/things/4ai5TPi13NF
float distancia = 0;
float area = 3 * pow(PI, 2);
float altura = 100;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Limpar o trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Define o pino Trigger para HIGH por 10 microsegundos
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Le o pin echo e retorna o tempo em microsegundos
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  distancia = 0.01743 * readUltrasonicDistance(7, 7) - 3.87;
  float volume = distancia * area;
  float volumeMax = altura * area;
  float porcentagem = 100 - (volume / volumeMax) * 100;
  if (porcentagem >= 100) porcentagem = 100;
  else if (porcentagem <= 0) porcentagem = 0;
  /*Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");
  Serial.print("Volume: ");
  Serial.print(volume);
  Serial.println(" m3");*/
  Serial.print("Tanque: ");
  Serial.print(porcentagem);
  Serial.println(" %");
  
  delay(100); // Wait for 100 millisecond(s)
}