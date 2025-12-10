// Programacion de Dispositivos Electronicos
// Profesor: Jorge Graña
// Integrantes: Matias Pinto, Facundo Tiburcio, Lautaro Scheffer.

int N = 10;              // tamaño de la lista
int lista[10];           // arreglo de enteros
int* pLista = lista;     // puntero al arreglo

// Prototipos de funciones
void mostrarLista(int* pLista, int N);
void cargarLista(int* pLista, int N);
void ordenarListaAsc(int* pLista, int N);
//========================
void setup() {
  Serial.begin(9600);
}

//========================
void loop() {
  int M;       // posición a consultar
  int valor;   // contenido en la posición M
  int pos;     // posición encontrada de un valor buscado

  cargarLista(pLista, N);   // Cargar lista al inicio
  delay(3000);
  // Mostrar lista
  mostrarLista(pLista, N);
  // Ordenar lista en forma ascendente
  ordenarListaAsc(pLista, N);
  mostrarLista(pLista, N);
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


//========================
// Ordenar lista en forma ascendente
void ordenarListaAsc(int* pLista, int N) {
  int temp;
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N - i - 1; j++) {
      if (pLista[j] > pLista[j + 1]) {
        temp = pLista[j];
        pLista[j] = pLista[j + 1];
        pLista[j + 1] = temp;
      }
    }
  }
  Serial.println("Lista ordenada en forma ascendente!");
}
