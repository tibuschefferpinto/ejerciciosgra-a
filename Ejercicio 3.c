//Programacion de Dispositivos Electronicos
//Profesor: Jorge Graña
//Matias pinto, Facundo Tiburcio, Lautaro Scheffer.
int lista[10] = {5, 12, 7, 9, 3, 15, 8, 6, 11, 4};
int* pLista = lista;
int N = 10;
//========================
void setup() {
  Serial.begin(9600);
}
//========================
void loop() {
  delay(1000);
  mostrarLista(pLista,N);
}
//========================
void mostrarLista(int* pLista, int N) {
  int i;
  for (i = 0; i < N; i++) {
    Serial.print("Numero ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(pLista[i]);
    delay(100);
  }
}

//Hecho por Lautaro Scheffer//
