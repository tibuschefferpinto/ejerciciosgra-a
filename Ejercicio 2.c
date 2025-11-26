// Programación Dispositivos Electrónicos
// Profesor: Jorge Graña
// Facundo Tiburcio, Matias Pinto, Lautaro Scheffer.

#define N 10
int lista[N];      // lista de 10 números

//=======================================

//=======================================
void setup() {
  Serial.begin(9600);
}
//=======================================

//=======================================
void loop() {
 randomSeed(analogRead(0)); // inicializa semilla aleatoria con ruido analógico
 Serial.println("Generando lista aleatoria...");
 cargarListaRandom(lista, N, 5, 20); // números entre 5 y 20
 MostrarLista(lista, N);
}
//=======================================

//=======================================
// Función: carga valores aleatorios en la lista
void cargarListaRandom(int *pLista, int n, int m, int M) {
  int i;
  for (i = 0; i < n; i++) {
    pLista[i] = random(m, M + 1); // incluye el máximo
  }
  Serial.println("Lista cargada con valores aleatorios:");
}
//=======================================

//=======================================
// Función: muestra la lista en el monitor serial
void MostrarLista(int lista[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    Serial.print("Posicion ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.println(lista[i]);
  }
  Serial.println();
}
//=======================================
//Hecho por Matias Pinto
