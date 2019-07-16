//用4位8字数码管制作计时器，数码管的A1~A4对应9~12引脚，a~h对应1~8引脚
//每个非A引脚都串联一个电阻
//持续点亮第二个小数点作为分隔符

#define com1 9
#define com2 10
#define com3 11
#define com4 12

#define a 1
#define b 2
#define c 3
#define d 4
#define e 5
#define f 6
#define g 7
#define h 8

int n1=0;
int n2=0;
int n3=0;
int n4=0;

int table[20][8]={
{1,1,1,1,1,1,0,0},
{0,1,1,0,0,0,0,0},
{1,1,0,1,1,0,1,0},
{1,1,1,1,0,0,1,0},
{0,1,1,0,0,1,1,0},
{1,0,1,1,0,1,1,0},
{1,0,1,1,1,1,1,0},
{1,1,1,0,0,0,0,0},
{1,1,1,1,1,1,1,0},
{1,1,1,1,0,1,1,0}};//不带小数点的数字

void display(int com,int num)
{
  //清除余晖
  digitalWrite(a,0);
  digitalWrite(b,0);
  digitalWrite(c,0);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,0);
  digitalWrite(h,0);

  switch(com)
  {
    case 1:
      digitalWrite(com1,HIGH);
      digitalWrite(com2,LOW);
      digitalWrite(com3,LOW);
      digitalWrite(com4,LOW);
      break;
    case 2:
      digitalWrite(com1,LOW);
      digitalWrite(com2,HIGH);
      digitalWrite(com3,LOW);
      digitalWrite(com4,LOW);
      break;
    case 3:
      digitalWrite(com1,LOW);
      digitalWrite(com2,LOW);
      digitalWrite(com3,HIGH);
      digitalWrite(com4,LOW);
      break;
    case 4:
      digitalWrite(com1,LOW);
      digitalWrite(com2,LOW);
      digitalWrite(com3,LOW);
      digitalWrite(com4,HIGH);
      break;
    default:
      break;
  }

  digitalWrite(a,1-table[num][0]);
  digitalWrite(b,1-table[num][1]);
  digitalWrite(c,1-table[num][2]);
  digitalWrite(d,1-table[num][3]);
  digitalWrite(e,1-table[num][4]);
  digitalWrite(f,1-table[num][5]);
  digitalWrite(g,1-table[num][6]);
  digitalWrite(h,1-table[num][7]);
}

void setup()
{
  for (int i=1;i<=12;i++)
  {
    pinMode(i,OUTPUT);
  }
}

void loop() 
{
  n4+=4;
  if(n4>=10)
  {
    n4=n4-10;
    n3++;
  }
  if(n3==10)
  {
    n3=0;
    n2++;
  }
  if(n2==10)
  {
    n2=0;
    n1++;
  }
  if(n1==10)
  {
    n1=0;
  }
  for(int j=0;j<2;j++)
  {
    display(1,n1);
    delay(5);
    display(2,n2);
    delay(5);
    display(3,n3);
    delay(5);
    display(4,n4);
    delay(5);
  }
}
