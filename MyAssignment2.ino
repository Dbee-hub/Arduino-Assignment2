//Task5
 
int segmentPins[] = {2, 3, 4, 5, 6, 7, 9};   
int numSegments = 7;

byte digits[10][7] = {
    {1, 1, 1, 1, 1, 1, 0},   // 0
    {0, 1, 1, 0, 0, 0, 0},   // 1
    {1, 1, 0, 1, 1, 0, 1},   // 2
    {1, 1, 1, 1, 0, 0, 1},   // 3
    {0, 1, 1, 0, 0, 1, 1},   // 4
    {1, 0, 1, 1, 0, 1, 1},   // 5
    {1, 0, 1, 1, 1, 1, 1},   // 6
    {1, 1, 1, 0, 0, 0, 0},   // 7
    {1, 1, 1, 1, 1, 1, 1},   // 8
    {1, 1, 1, 1, 0, 1, 1}    // 9
};
 
int buzzerPin = 8;
 
void showDigit(int n) {
    if (n < 0 || n > 9) return;
    for (int i = 0; i < numSegments; i++) {
        digitalWrite(segmentPins[i], digits[n][i]);
    }
}


void clearDisplay() {
    for (int i = 0; i < numSegments; i++) {
        digitalWrite(segmentPins[i], LOW);
    }
}
 
void setup() {
    Serial.begin(9600);
 
    pinMode(buzzerPin, OUTPUT);
    for (int i = 0; i < numSegments; i++) {
        pinMode(segmentPins[i], OUTPUT);
    }
 
    Serial.println("=== Beeping Countdown Starting ===");
 
  
    for (int count = 9; count >= 1; count--) {
        Serial.print("Counting: ");
        Serial.println(count);
 
        showDigit(count);                // Show current value
        tone(buzzerPin, 1000, 200);      // Play 1000 Hz tone for 200ms
        
        
      
        delay(850);                      
        clearDisplay();                 
        delay(150);                      
    }
    
    
    Serial.println("Counting: 0"); 
    showDigit(0);                        // Show 0
    tone(buzzerPin, 1500, 1000);         // Play longer 1500 Hz completion tone
    delay(1000);                         // Wait for completion tone to finish
    
    Serial.println("=== Countdown Complete ===");
}

void loop() { 
    // Kept empty as requirements dictate running the sequence exactly once
}