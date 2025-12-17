// Programación Dispositivos Electrónicos
// Profesor: Jorge Graña
// Facundo Tiburcio, Matias Pinto, Lautaro Scheffer.

#define N 10
int lista[N];      // lista de 10 números 
int valor = 0;     // contador para mostrar número 1,2,3...

//=======================================
void setup() {
  Serial.begin(9600);
  Serial.println("Inserta numeros:"); 
}
//=======================================

//=======================================
void loop() {
  cargarLista(lista, N);
  MostrarLista(lista, N);

  int resultado = sumarLista(lista, N);
  Serial.print("La suma de todos los elementos es: ");
  Serial.println(resultado);

  while(true); 
}
//=======================================


//======================================
// Cargar lista con datos ingresados por el usuario
void cargarLista(int lista[], int n) {
 int i ;
  
  valor = 0; // reiniciar numeración
  for (i = 0 ; i < n; i++) {
    Serial.print("numero ");
    Serial.print(++valor);
    Serial.print(": ");

    while (Serial.available() == 0);   
    lista[i] = Serial.parseInt();      
    Serial.println(lista[i]);
  }
  Serial.println("lista numeros:");
}
//============================================

//============================================
// Mostrar lista completa
void MostrarLista(int lista[], int n) {
  int i;
  for ( i = 0; i < n; i++) {
    Serial.print(lista[i]);
    Serial.print(" ");
  }
  Serial.println();
}

//============================================
// Nueva función: suma todos los elementos
int sumarLista(int *pLista, int n) {
  int suma = 0;
  int i;
  for ( i = 0; i < N; i++) {
    suma += pLista[i];
  }
  return suma;
}
//============================================
//Hecho por Matias Pinto
