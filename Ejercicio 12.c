//Programación Dispositivos Electronicos 
//Profesor: Jorge Graña
// Facundo Tiburcio, Matias Pinto, Lautaro Scheffer.

#define N 10
int lista[N];      // lista 10 números 
int valor = 0;     // contador para mostrar número 1,2,3...

void setup() {
  Serial.begin(9600);
  Serial.println("Inserta 10 numeros:"); 
}
//=======================================

//=======================================
void loop() {
  valor = 0;                   // Reinicia contador visual
  cargarLista(lista, N);
  MostrarLista(lista, N);

  invertirLista(lista, N);    // Ahora sí invierte de verdad

  Serial.println("Lista invertida:");
  MostrarLista(lista, N);     // Mostrar ya invertida

  while(true); 
}
//=======================================

//======================================
void cargarLista(int lista[], int n) {
  int i;
  for (i = 0 ; i < n; i++) {
    Serial.print("numero ");
    valor++;
    Serial.print(valor);
    Serial.print(": ");

    while (Serial.available() == 0);
    lista[i] = Serial.parseInt();
    Serial.println(lista[i]);
  }
  Serial.println("lista numeros:");
}
//============================================

//=======================================
void MostrarLista(int lista[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    Serial.print(lista[i]);
    Serial.print(" ");
  }
  Serial.println();
}
//=======================================

//=======================================
// Función que invierte realmente el arreglo en memoria
void invertirLista(int lista[], int n) {
  int i;
  int pos;
  for (i = 0; i < n / 2; i++) {
    pos = lista[i];
    lista[i] = lista[n - 1 - i];
    lista[n - 1 - i] = pos;
  }
}
