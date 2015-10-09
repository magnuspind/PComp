int blue = 9;
int green = 10;
int red = 11;

void setup(){
pinMode(red, OUTPUT);
pinMode(green, OUTPUT);
pinMode(blue, OUTPUT);
}
void loop(){
analogWrite(red, 100);
analogWrite(green, 100);
analogWrite(blue, 100);
}
