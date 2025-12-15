// Programación Dispositivos Electrónicos
// Profesor: Jorge Graña
// Integrantes: Facundo Tiburcio, Matias Pinto, Lautaro Scheffer.

#define N 10
int lista[N];      
int valor = 0;     
//======================================

//======================================
void setup() {
  Serial.begin(9600);
  Serial.println("Inserta 10 numeros:"); 
}
//======================================+

//======================================
void loop() {
  cargarLista(lista, N);
  MostrarLista(lista, N);
  int maximo = MaximoLista(lista, N);   // llamada a la nueva función
  Serial.print("El valor maximo es: ");
  Serial.println(maximo);

  while(true); 
}
//======================================

//======================================
void cargarLista(int lista[], int n) {
  int i;
  valor = 0; // reinicio el contador
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
//======================================

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
// Función parametrizable que retorna el máximo
int MaximoLista(int pLista[], int n) {
  int i;
  int max = pLista[i];   // inicializo con el primer elemento
  for (i = 0; i < n; i++) {
    if (pLista[i] > max) {
      max = pLista[i];
    }
  }
  return max;
}
