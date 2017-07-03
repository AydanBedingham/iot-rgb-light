int redPin = 8;
int greenPin = 7;
int bluePin = 6;


void setupLight(){
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}

void setLightColorRed(){
  setColor(255, 0, 0);
}

void setLightColorGreen(){
  setColor(0, 255, 0);
}

void setLightColorBlue(){
  setColor(0, 0, 255);
}


void setLightColorYellow(){
  setColor(255, 255, 0);
}

void setLightColorOrange(){
  setColor(255, 140, 0);
}


void setLightColorTeal(){
  setColor(0, 255, 255);
}

void setLightColorNone(){
  setColor(0, 0, 0);
}



void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
