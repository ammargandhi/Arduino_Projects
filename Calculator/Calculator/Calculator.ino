#include <LiquidCrystal.h> 
#include <Keypad.h> 

LiquidCrystal lcd(11,12, 17, 16, 15, 14); 
const byte ROWS = 4; 
const byte COLS = 4; 


char keys [ROWS] [COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'C', '0', '=', 'S'}
};
byte rowPins[ROWS] = {9 ,8 ,7 ,6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 


Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


boolean valOnePresent = false;
boolean next = false;
boolean final = false;
String num1, num2;
int ans;
char op;

void setup(){
  lcd.begin(16,2);
  lcd.setCursor(15,0);
  lcd.print("CaLcUlAtOr");
  for(int i=0; i< 26 ; i++){
    lcd.scrollDisplayLeft();
    delay(300);
  }
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("CaLcUlAtOr");
  for(int i=0; i< 26 ; i++){
    lcd.scrollDisplayRight();
    delay(300);
  }
  
  lcd.clear(); 
  lcd.cursor();
}

void loop(){
  char key = myKeypad.getKey();

  if (key != NO_KEY && (key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'||key=='0')){
    if (valOnePresent != true){
      num1 = num1 + key;
      int numLength = num1.length();
      lcd.setCursor(15 - numLength, 0); //to adjust one whitespace for operator
      lcd.print(num1);
    }
    else {
      num2 = num2 + key;
      int numLength = num2.length();
      lcd.setCursor(15 - numLength, 1);
      lcd.print(num2);
      final = true;
    }
  }

  else if (valOnePresent == false && key != NO_KEY && (key == '*' || key == '-' || key == '+')){
    if (valOnePresent == false){
      valOnePresent = true;
      op = key;
      lcd.setCursor(15,0);
      lcd.print(op);
    }
  }

else if(valOnePresent!=true && key!=NO_KEY && (key=='S'))

{
  op=key;
  lcd.print(op);
  final=true;
}

  else if (final == true && key != NO_KEY && key == '='){
    if (op == '+'){
      ans = num1.toInt() + num2.toInt();
    }
    else if (op == '-'){
      ans = num1.toInt() - num2.toInt();
    }
    else if (op == '*'){
      ans = num1.toInt() * num2.toInt();
    }
    else if (op == 'S'){
      ans = sqrt(num1.toInt());
    }   
      lcd.clear();
      lcd.setCursor(15,0);
      lcd.autoscroll();
      lcd.print(ans);
      lcd.noAutoscroll();
  }
  else if (key != NO_KEY && key == 'C'){
    lcd.clear();
    valOnePresent = false;
    final = false;
    num1 = "";
    num2 = "";
    ans = 0;
    op = ' ';
  }
}


