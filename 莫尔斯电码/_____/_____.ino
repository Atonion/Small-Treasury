char Morse[][4] = 
{
  {'.', '-', '*', '*'}, //A
  {'-', '.', '.', '.'}, //B
  {'-', '.', '-', '.'}, //C
  {'-', '.', '.', '*'}, //D
  {'.', '*', '*', '*'}, //E
  {'.', '.', '-', '.'}, //F
  {'-', '-', '.', '*'}, //G
  {'.', '.', '.', '.'}, //H
  {'.', '.', '*', '*'}, //I
  {'.', '-', '-', '-'}, //J
  {'-', '.', '-', '*'}, //K
  {'.', '-', '.', '.'}, //L
  {'-', '-', '*', '*'}, //M
  {'-', '.', '*', '*'}, //N
  {'-', '-', '-', '*'}, //O
  {'.', '-', '-', '.'}, //P
  {'-', '-', '.', '-'}, //Q
  {'.', '-', '.', '*'}, //R
  {'.', '.', '.', '*'}, //S
  {'-', '*', '*', '*'}, //T
  {'.', '.', '-', '*'}, //U
  {'.', '.', '.', '-'}, //V
  {'.', '-', '-', '*'}, //W
  {'-', '.', '.', '-'}, //X
  {'-', '.', '-', '-'}, //Y
  {'-', '-', '.', '.'}  //Z
};
int pin = 13;
void dot() 
{  
  digitalWrite(pin, HIGH);  
  delay(250);   
  digitalWrite(pin, LOW);   delay(250); 
}   
void dash() 
{   
  digitalWrite(pin, HIGH);  
  delay(1000);   
  digitalWrite(pin, LOW);   
  delay(250); 
}
void setup()
{
   Serial.begin(9600);
   pinMode(pin, OUTPUT); 
}

void loop() 
{
  String str = ""; 
  String morse = ""; 
  int a,b , temp = 0;
  int n = 0;
  while (Serial.available() > 0)
  {
    temp = 1;  
    str += char(Serial.read());
    delay(2);
    n++;
  }

  if (temp) 
  {
    for (a = 0; a < n; a++)
    {
      for (b = 0; b < 4; b++)
      {
        if (str[a] >= 97 && str[a] <= 122)
        {
          morse += char(Morse[int(str[a] - 97)][b]);
        }
      }
      morse += ' ';
    }
    Serial.println(morse);
    for(a=0;a<=4*n;a++)
    {
      if(morse[a]=='.')
      dot();
     if(morse[a]=='-')
      dash();
    }
  }
  delay(2);
}
