// Programación Dispositivos Electrónicos
// Profesor: Jorge Graña
// Facundo Tiburcio, Matias Pinto, Lautaro Scheffer.

#define N 4
int lista[N];
int valor = 0;
//=======================================

//=======================================
void setup() {
  Serial.begin(9600);
  Serial.println("Inserta 10 numeros:");
}

void loop() {
  cargarLista(lista, N);

  int nuevoTam = borrarRepetidos(lista, N);

  MostrarLista(lista, nuevoTam);

  while(true);
}
//=======================================

//=======================================
void cargarLista(int lista[], int n) {
  valor = 0; // para que muestre numero 1,2,3...
  for (int i = 0; i < n; i++) {
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
//=======================================

//=======================================
void MostrarLista(int lista[], int n) {
  for (int i = 0; i < n; i++) {
    Serial.print(lista[i]);
    Serial.print(" ");
  }
  Serial.println();
}

//=======================================
// BORRA REPETIDOS Y ACHICA LA LISTA
//=======================================
int borrarRepetidos(int pLista[], int n) {
  int i;
  int k;  
  int j;
  for (i = 0; i < n - 1; i++) {

    for (j = i + 1; j < n; j++) {

      if (pLista[i] == pLista[j]) {

        // Adelantar para borrar el repetido
        for (k = j; k < n - 1; k++) {
          pLista[k] = pLista[k + 1];
        }

        n--;    // achica la lista
        j--;    // revisar la nueva posición j
      }
    }
  }

  return n;   // devuelve los num
}
//=======================================
//Hecho por Matias Pinto
