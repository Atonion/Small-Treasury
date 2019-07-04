void setup()

{

  pinMode(5, OUTPUT);

  pinMode(6, OUTPUT);

  pinMode(9, OUTPUT);

  pinMode(10, OUTPUT);

  Serial.begin(9600);

}

void forward(){

  digitalWrite(6,LOW);

  digitalWrite(5,HIGH);

  digitalWrite(10,LOW);

  digitalWrite(9,HIGH);

}

void backward(){

  digitalWrite(6,HIGH);

  digitalWrite(5,LOW);

  digitalWrite(10,HIGH);

  digitalWrite(9,LOW);

}

void left(){

  digitalWrite(6,LOW);

  digitalWrite(5,LOW);

  digitalWrite(10,LOW);

  digitalWrite(9,HIGH);

}

void right(){

  digitalWrite(6,HIGH);

  digitalWrite(5,LOW);

  digitalWrite(10,LOW);

  digitalWrite(9,LOW);

}

void stop(){

  digitalWrite(6,LOW);

  digitalWrite(5,LOW);

  digitalWrite(10,LOW);

  digitalWrite(9,LOW);

}





void loop(){

  if (Serial.available()>0){

     char command;

     command = Serial.read();

    switch (command){

    case 'f':forward();break;

    case 'b':backward();break;

    case 'l':left();break;

    case 'r':right();break;

    case 's':stop();break;

    default :break;

    }

  }

}
