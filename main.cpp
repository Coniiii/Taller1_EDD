#include <iostream>
#include <string>
#include <fstream>      //relacionada al manejo de archivos
#include <sstream>      //relacionada a string stream https://www.cplusplus.com/reference/sstream/
#include <vector>       //relacionada al manejo de vectores dinámicos
#include <limits>       //relacionada a los límites de valores
#include <stdlib.h>
#include <conio.h>
#include <locale.h>     //ingresar ñ
#include <vector>

#include "Fecha.h"
#include "Direccion.h"
#include "Elector.h"

int indice = 0; //indice del vector o cantidad actual de elementos en el vector
Elector electores[1000];
string nombreArchivo ="servel.txt";


void leerArchivo(string nombreArchivo, Elector p[] , int &indice );
void menu(int opc, string buscarRut, string comparar);
void volver(int opc);

void cantElectores(Elector p[], int indice);
void electoresComuna(Elector p[], int indice, string comparar);
void consultaDatos_rut(Elector p[], int indice, string buscarRut);
void votantesPorComuna(Elector p[], int indice);
void vocalesDeMesa(Elector p[], int indice);

using namespace std;


/*
Estructura de datos
Constanza Olivos Fernandez, rut 20.721.601-1
Profesor Mauro Castillo
Seccion 411
video: 
*/

int main()
{

    setlocale(LC_CTYPE, "Spanish");

    int opc=0;
    string comparar, buscarRut;
    //invocar funciones
    leerArchivo (nombreArchivo, electores , indice);
    menu(opc, buscarRut, comparar);
    return 0;
}

vector<string> split(string lineaASeparar, char delimitador) {
    vector<string> vector_interno;      //#include <vector>
    stringstream linea(lineaASeparar);  //#include <sstream>
    string parteDelString;

    while(getline(linea, parteDelString, delimitador))
        vector_interno.push_back(parteDelString);

    return vector_interno;
}

void leerArchivo(string nombreArchivo, Elector p[] , int &indice){
    ifstream archivo;
    string lineaObtenida;
    string palabra;

    Fecha objFecha;
    Direccion objDir;

    archivo.open(nombreArchivo, ios::in);

    if(archivo.fail()){
        cout<<"Error al abrir archivo"<<endl;
        exit(1);
    }


    getline(archivo, lineaObtenida);// se salta la primera linea del archivo

    if(archivo.is_open()==true) {
        while( getline(archivo, lineaObtenida, '\n')){
            //ahora recorremos la línea
            vector<string> data = split(lineaObtenida, ';');

            p[indice].set_rut(data[0].append("-").append(data[1]) );
            p[indice].set_nombres(data[2].append(" ").append(data[3]).append(" ").append(data[4]) );

            objFecha.set_dd(atoi(data[5].c_str() ));
            objFecha.set_mm(atoi(data[6].c_str() ));
            objFecha.set_aa(atoi(data[7].c_str() ));
            p[indice].set_fechaNac(objFecha);

            objDir.set_calle(data [8]);
            objDir.set_num(atoi(data[9].c_str() ));
            objDir.set_comuna(data [10]);
            p[indice].set_direc(objDir);

            //p[indice].set_comu2(data [10]);


            p[indice].set_habilitado(atoi(data[11].c_str() ));
            p[indice].set_vocal(atoi(data[12].c_str() ));
            p[indice].set_numMesa(atoi(data[13].c_str() ));


            indice++;
        }
    }
    archivo.close();
}

void menu(int opc, string buscarRut, string comparar){

while(opc<6)  // mientras opcion sea menor a 6 el menu deberia mostras 6 opciones
    {
        cout <<endl;
        cout << "                                  -----------------------" <<endl;
        cout << "                                  -   Menu Principal    -"<<endl;
        cout << "                                  -----------------------" <<endl<<endl;
        cout << "Ingrese el numero de la opcion que desea realizar: " << endl<<endl;
        cout << "1-.Cantidad de electores" << endl;
        cout << "2-.Electores por comuna" << endl;
        cout << "3-.Consulta de datos" << endl;
        cout << "4-.Votantes por comunas" << endl;
        cout << "5-.Vocales de Mesa" << endl;
        cout << "6-.Salir del programa" << endl<< endl<<"->";
        cout << "Ingrese una opcion: ";
        cin >> opc;

        switch(opc){
            //Se invocan funciones en cada caso del menu

            case 1:
            system("clear");//Limpiar pantalla
            cout <<endl;
            cout << "                                  ----------------------------" <<endl;
            cout << "                                  -   Cantidad de Electores  -"<<endl;
            cout << "                                  ----------------------------" <<endl<<endl;
            cantElectores(electores, indice);
            volver(opc);
            system("clear");//Limpiar pantalla
            break;

            case 2:
            system("clear");//Limpiar pantalla
            cout <<endl;
            cout << "                                  ----------------------------" <<endl;
            cout << "                                  -   Electores por Comuna   -"<<endl;
            cout << "                                  ----------------------------" <<endl<<endl;
            electoresComuna(electores, indice, comparar);
            //volver(opc);
            system("clear");//Limpiar pantalla
            break;

            case 3:
            system("clear");//Limpiar pantalla
            cout <<endl;
            cout << "                                  -----------------------------------------" <<endl;
            cout << "                                  -   Consulta de Datos a traves de Rut   -"<<endl;
            cout << "                                  -----------------------------------------" <<endl<<endl;
            consultaDatos_rut(electores, indice, buscarRut);
            //volver(opc);
            system("clear");//Limpiar pantalla
            break;

            case 4:
            system("clear");//Limpiar pantalla
            cout <<endl;
            cout << "                                  -----------------------------" <<endl;
            cout << "                                  -    Votantes por comuna    -"<<endl;
            cout << "                                  -----------------------------" <<endl<<endl;
            votantesPorComuna(electores, indice);
            volver(opc);
            system("clear");//Limpiar pantalla
            break;

            case 5:
            system("clear");//Limpiar pantalla
            cout <<endl;
            cout << "                                  ----------------------------------" <<endl;
            cout << "                                  -   Listado de vocales de mesa   -"<<endl;
            cout << "                                  ----------------------------------" <<endl<<endl;
            vocalesDeMesa(electores, indice);
            volver(opc);
            system("clear");//Limpiar pantalla
            break;

            case 6:
            break;

            default:cout<<endl<<"Opcion incorrecta, vuelva a ingresar"<<endl<<endl;
            opc=1;

        }//switch

    }//while


}

void cantElectores(Elector p[], int indice){// Cant. electores, total de personas habilitadas, cantidad de vocales

    int cont=0, cont2=0, a=0;

    while(a<indice){

        if(p[a].get_habilitado()==1){
            cont ++;
        }

        if(p[a].get_vocal()==1){
            cont2 ++;
        }

        a++;
    }
    cout<<"cantidad de electores:               "<<indice<<endl;
    cout<<"cantidad de electores habilitados:   "<<cont<<endl;
    cout<<"cantidad de vocales de mesa:         "<<cont2<<endl;

}

void electoresComuna(Elector p[], int indice, string comparar){//usca los votantes que viven en esa comuna y muestra los datos ordenados alfabeticamente por los nombres

    cout << endl <<"->Ingrese comuna a buscar en mayuscula y sin tildes: " << endl<< "ej: MAIPU" << endl<<"->";
    //fflush(stdin);
    getline(cin >> ws, comparar);

    int a=0;
    int opc=0;
    string aux, aux2;
    int aux5, aux6, aux7;
    Fecha aux3;
    Direccion aux4;

        for(int i=0;i<indice;i++){
        	    
            for(int j=0;j<indice-1;j++){
        		    
                if(p[j].get_nombres()> p[j+1].get_nombres()){
                    aux=p[j].get_nombres();
				    p[j].set_nombres(p[j+1].get_nombres());
                    p[j+1].set_nombres(aux);

                    aux2=p[j].get_rut();
                    p[j].set_rut(p[j+1].get_rut());
                    p[j+1].set_rut(aux2);

                    aux3=p[j].get_fechaNac();
                    p[j].set_fechaNac(p[j+1].get_fechaNac());
                    p[j+1].set_fechaNac(aux3);

                    aux4=p[j].get_direc();
                    p[j].set_direc(p[j+1].get_direc());
                    p[j+1].set_direc(aux4);

                    aux5=p[j].get_habilitado();
                    p[j].set_habilitado(p[j+1].get_habilitado());
                    p[j+1].set_habilitado(aux5);

                    aux6=p[j].get_vocal();
                    p[j].set_vocal(p[j+1].get_vocal());
                    p[j+1].set_vocal(aux6);

                    aux7=p[j].get_numMesa();
                    p[j].set_numMesa(p[j+1].get_numMesa());
                    p[j+1].set_numMesa(aux7);

                }
            }
        }

        while(a<indice){

            if(p[a].get_direc().get_comuna()==comparar){

                p[a].ver();
                opc=7;
            }

        a++;
        }
        
        if(opc==0){//ingresa un dato que no existe
            
            cout<<endl<<"Dato ingresado incorrecto "<<endl;
            volver(opc);
        }
        
        if(opc==7){//pregunta si quiere salir o seguir en el programa
            
            volver(opc);
        }
        

}



void consultaDatos_rut(Elector p[], int indice, string buscarRut){//Busca el rut ingresado en el archivo y muestra los datos del elector en pantalla

    int a=0, opc=0;

    cout << endl << "Ingrese rut a buscar sin puntos y con guion" << endl << "ej: 12345678-9" << endl << "->";
    fflush(stdin);
    cin >> buscarRut;

    while(a<indice){

        if(p[a].get_rut()==buscarRut){
            p[a].ver();
            opc=7;
        }

        a++;
    }
    if(opc==0){//ingresa un dato que no existe
            
        cout<<endl<<"Dato ingresado incorrecto "<<endl;
        volver(opc);
    }
    if(opc==7){//pregunta si quiere salir o seguir en el programa
            
        volver(opc);
    }
}

void votantesPorComuna(Elector p[], int indice){//Muestra en pantalla el número de votantes habilitados por comunas.-electores

    int cont=0, a, b;
    string *auxVec = new string[indice];

    for(int i=0; i<indice; i++){
        auxVec[i]=p[i].get_direc().get_comuna();
    }

    for(a=0; a<indice;a++){
        for(b=0; b<indice; b++){

            if( (p[a].get_direc().get_comuna()==auxVec[b]) && (auxVec[b]!="REPETIDO") && (p[b].get_habilitado() == 1)){ //compara los datos del arreglo con las comunas del objeto
                cont++;
                auxVec[b]="REPETIDO";//se pone repetido para que cuando la comuna vuelva a salir mas adelante no se tome en cuenta ya que no tendra el nombre de la comuna sino que dira repetido

            }

        }

        if(cont>0){//para que se imprima una vez la comuna
            cout << endl << "-En la comuna de " << p[a].get_direc().get_comuna() << " hay " << cont << " electores habilitados para votar " <<  endl;
        }
        cont = 0;
     }    //FOR a
     delete[] auxVec;  // Liberar la memoria
}

void vocalesDeMesa(Elector p[], int indice){ //Vocales de Mesa: Muestra en pantalla un listado de los vocales de mesa existentes por comuna
    
    int a=0;

    while(a<indice){

        if(p[a].get_vocal()==1){
            p[a].ver();
        }

        a++;
    }
}

void volver(int opc){
    
    int cont=0;
    while(cont==0){
        cout<<endl<<"Desea volver al menu principal"<<endl<<"1-.Si"<<endl<<"2-.No"<<endl<<endl<<"->Ingrese la opcion que desea: ";
        cin>>opc;
        cout<<endl;
        
        if(opc==1){
            opc=1;
            cont=3;
        }
        if(opc==2){
            exit(1);
        }
        if(opc>2){
            cout<<endl<<"Opcion ingresada incorrecta "<<endl;
        }
    }
    
}
