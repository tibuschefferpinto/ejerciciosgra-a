// Programación Dispositivos Electrónicos
// Profesor: Jorge Graña
// Integrantes: Facundo Tiburcio, Matias Pinto, Lautaro Scheffer.

#define N 10
int lista[N];      // lista de 10 números 
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
  cargarLista(lista, N);       // cargar los números
  Serial.println("Lista original:");
  MostrarLista(lista, N);      // mostrar lista original

  // Calcular promedio
  float prom = Promedio(lista, N);
  Serial.print("El promedio de la lista es: ");
  Serial.println(prom);

  while(true);   // detener ejecución
}
//=======================================

//======================================
void cargarLista(int lista[], int n) {
  valor = 0;  // reiniciar contador
  int i; // repaso para asignar numeros
  for (i = 0 ; i < n; i++) {
    Serial.print("numero ");
    valor++;
    Serial.print(valor);
    Serial.print(": ");

    while (Serial.available() == 0);   // esperar entrada
    lista[i] = Serial.parseInt();      // leer número
    Serial.println(lista[i]);
  }
}
//============================================

//=======================================
void MostrarLista(int lista[], int n){ 
  int i; // repaso lista
  for ( i = 0; i < n; i++) {
    Serial.print(lista[i]);
    Serial.print(" ");
  }
  Serial.println();
}
//=======================================

//=======================================
// Función parametrizable que retorna el
// promedio de todos los datos de la lista
//=======================================
float Promedio(int *pLista, int n) {
  int suma = 0;
  int i; // repasa lista para sumar 
  for ( i = 0; i < n; i++) {
    suma += pLista[i];
  }
  return (float)suma / n;
}
//=======================================


