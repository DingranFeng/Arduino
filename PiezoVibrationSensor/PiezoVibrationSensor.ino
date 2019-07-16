int ledPin=9;
int piezoPin=5;//压电盘接在模拟引脚上
int threshold=88;//传感器产生动作的阈值
int sensorValue=0;//从传感器读出的值的变量
float ledValue=0;//LED的亮度

void setup() 
{
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,HIGH);
  delay(1000);
  digitalWrite(ledPin,LOW);//LED长亮一次表示程序开始

}

void loop() 
{
  sensorValue=analogRead(piezoPin);
  if (sensorValue>=threshold)
  {
    ledValue=255;//若检测到敲击，设置亮度为最大值
  }
  analogWrite(ledPin,int(ledValue));
  ledValue=ledValue-0.05;
  if (ledValue<=0){ledValue=0;}
}
