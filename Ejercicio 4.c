// Programacion de Dispositivos Electronicos
// Profesor: Jorge Graña
// Integrantes: Matias Pinto, Facundo Tiburcio, Lautaro Scheffer.

int N = 10;              // tamaño de la lista
int lista[10];           // arreglo de enteros
int* pLista = lista;     // puntero al arreglo

// Prototipos de funciones
int obtenerDato(int* pLista, int N, int M);
void mostrarLista(int* pLista, int N);
void cargarLista(int* pLista, int N);

//========================
void setup() {
  Serial.begin(9600);
}

//========================
void loop() {
  int M; // En esta variable voy a guardat la posicion del dato que quiero saber
  int valor; //En esta variable guardamos el contenido de la posicion M de la lista 
  cargarLista(pLista, N);
  delay(2000);
  // Mostrar lista completa
  mostrarLista(pLista, N);

  // Ejemplo: obtener el dato en la posición M
   M = 3; // posición que queremos consultar
   valor = obtenerDato(pLista, N, M);

  if (valor != -1) {
    Serial.print("El valor en la posicion ");
    Serial.print(M);
    Serial.print(" es: ");
    Serial.println(valor);
  } else {
    Serial.println("Error: posicion fuera de rango.");
  }
}
//===========================
void cargarLista(int *pLista, int N) {
  int i;
  Serial.println("Ingrese los valores de la lista:");
  for (i = 0; i < N; i++) {
    Serial.print("Numero ");
    Serial.print(i);
    Serial.print(": ");
    while (Serial.available() == 0);   // Espera entrada
    pLista[i] = Serial.parseInt();     // Guarda el número
    Serial.println(pLista[i]);
  }
  Serial.println("Lista cargada!");
}
//========================
void mostrarLista(int* pLista, int N) {
  int i;
  Serial.println("=== Lista de valores ===");
  for (i = 0; i < N; i++) {
    Serial.print("Numero ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(pLista[i]);
    delay(100);
  }
}
//========================
int obtenerDato(int* pLista, int N, int M) {
  if (M >= 0 && M < N) {
    return pLista[M];   // devuelve el valor en la posición M
  } else {
    return -1;          // error si está fuera de rango
  }
}

//hecho por Facundo Tiburcio

