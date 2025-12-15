//Programación Dispositivos Electronicos 
//Profesor: Jorge Graña
// Facundo Tiburcio, Matias Pinto, Lautaro Scheffer.
//=======================================

//=======================================
#define N 10
int lista[N];      // lista 10 números 
int valor = 0;     // contador para mostrar número 1,2,3...
//=======================================

//=======================================
void setup() {
  Serial.begin(9600);
  Serial.println("Inserta 10 numeros:"); 
  
}
//=======================================

//=======================================
void loop() {

  cargarLista(lista, N);
  MostrarLista(lista, N);

  Serial.println("Ingresa un valor a buscar: ");
  while (Serial.available() == 0);
  int buscado = Serial.parseInt();

  int pos = buscarPosicion(lista, N, buscado);

  Serial.print("Posicion: ");
  Serial.println(pos);

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
  int i ;
  for (i = 0; i < n; i++) {
    Serial.print(lista[i]);
    Serial.print(" ");
  }
  Serial.println();
}
//=======================================

//=======================================
//funcion busca la pocision
//=======================================
int buscarPosicion(int pLista[], int n, int valor) {
  int i;
  for (i = 0 ; i < n ; i++) {
    if (pLista[i] == valor) {
      return i + 1;    // posición (1..n)
    }
  }
  return -1;            // no encontrado
}
//=======================================
