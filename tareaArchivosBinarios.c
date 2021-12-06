#include <stdio.h>
#include <string.h>

typedef struct 
{
    int calificacion;
    char alumno[50];
} Promedio;

int main()
{
    FILE *archivo;
    int alumnos;
    int valor = 0;
    int valorRegreso;
    int arreglo[50];
    int prom = 0, promfinal;
    Promedio promedio, promedioLeido;
    int i;
    int j = 1;

    archivo = fopen("promedio.dat", "wb"); // Crea el archivo siempre

    printf("¿Cuántos alumnos quieres insertar?: ");
    scanf("%d", &alumnos);

    for(int i = 1; i <= alumnos; i++)
    {
        printf("Dame el nombre del alumno número %d: ", i);
        scanf("%s", promedio.alumno);

        printf("Dame la calificacion: ");
        scanf("%d", &promedio.calificacion);

        fwrite(&promedio, sizeof(Promedio), 1, archivo);
    }

    fclose(archivo);

    archivo = fopen("promedio.dat", "rb"); //Si el archivo no existe y lo intento abrir con r, me regresa null

    do
   {
      
       fread(&promedioLeido, sizeof(Promedio), 1, archivo);
       arreglo[j] = promedioLeido.calificacion;
       j++;

   }while(!feof(archivo) && j <= alumnos);

    fclose(archivo);

    for(int k = 1; k <= alumnos; k++)
    {
        prom = prom + arreglo[k];
    }

    promfinal = prom/alumnos;

    printf("El promedio de los alumnos es: %d\n", promfinal);

    return 0;

}