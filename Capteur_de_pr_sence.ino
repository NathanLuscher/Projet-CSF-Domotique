#define Broche_Echo A3 // Broche Echo du HC-SR04 sur D7 //
#define Broche_Trigger A2 // Broche Trigger du HC-SR04 sur D8 //

// Definition des variables



long Duree;
long Distance;

void setup()
{
pinMode(Broche_Trigger, OUTPUT); // Broche Trigger en sortie //
pinMode(Broche_Echo, INPUT); // Broche Echo en entree //
Serial.begin (115200);
}

void loop() {

// Debut de la mesure avec un signal de 10 µS applique sur TRIG //

digitalWrite(Broche_Trigger, LOW); // On efface l'etat logique de TRIG //
delay(100);

digitalWrite(Broche_Trigger, HIGH); // On met la broche TRIG a "1" pendant 10µS //
delay(100);
digitalWrite(Broche_Trigger, LOW); // On remet la broche TRIG a "0" //

// On mesure combien de temps le niveau logique haut est actif sur ECHO //
Duree = pulseIn(Broche_Echo, HIGH);
Serial.println(Duree);
// Calcul de la distance grace au temps mesure //
Distance = Duree*0.034/2; // *** voir explications apres l'exemple de code *** //



  // Affichage dans le moniteur serie de la distance mesuree //
  Serial.print("Distance mesuree :");
  Serial.print(Distance);
  Serial.println("cm");


  delay(1000); // On ajoute 1 seconde de delais entre chaque mesure //
}
