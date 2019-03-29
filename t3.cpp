/***************
***
****************/

 #include <iostream>            // Para usar cout y cin
 #include <string>              // Para usar objetos string y todos sus menjurges
 #include <algorithm>           // Para usar el sort
 #include <vector>              // Para usar el Template vector

 using namespace std;           // Me ahorra la molestia de escribir std:: antes de cin, cout, etc.

vector<string> med;
vector<string>::iterator meds;
    int main(){
        int op, pos;
        bool stat;
        string trans;
        string busq;
        cout << "\t\talmacen de medicinas del hospital Chapalita\n";
    do{
           cout << "\n1. Agregar medicina\n2. Eliminar la ultima medicina\n3. Eliminar medicina especifica\n4. Editar medicina\n5. Insertar medicina\n6. Listar medicinas\n7. Numero de medicinas\n99. Salir\n\nOpcion: ";
           op = 0;
           cin >> op;
           cin.clear();
           cin.ignore();
           switch (op) {
                  case 1:
                       cout << "\nAgregar medicina\n\nnombre: ";
                       getline(cin,trans,'\n');
                       med.push_back(trans);// añade el registro
                  break;
                  case 2:
                       if (med.empty()) {
                          cout << "\nNo hay medicinas que eliminar\n";
                       } else {
                       med.pop_back(); // elimina el ultimo regustro
                       cout << "\nSe elemino el ultimo elemento";
                       }
                  break;
                  case 3:
                      if (med.empty()){ // si el vector esta vacio
                         cout << "\nNo hay medicinas que eliminar\n";
                      } else {
                        cout << "\nPor cual medio quiere eliminarlo:\n1. Nombre\n2.Numero\nOpcion: ";
                        cin >> op;
                        switch (op) {
                               case 1:
                                    cout << "¿Que nombre de medicina usted desea eliminar?\n";
                                    cin >> busq;
                                    for(int i = 0;i<med.size();i++){
                                            if (med[i] == busq){
                                               cout << "\t" << i++ << "." << med[i] << "\n¿desea eliminar este registro?\n1. si\t2. no\n";
                                               stat = true;
                                               cin >> op;
                                               if (op==1){
                                                  pos = i - 1;
                                                  meds = med.begin() + pos;
                                                  med.erase(meds);
                                                  cout << "Medicina borrada";
                                                          }
                                                  }
                                             }
                                    if (stat==false)
                                       cout << "no hubo medicina que borrar\n";
                                    stat = false;
                                    break;
                                    case 2:
                                         cout << "¿Que posicion desea borrar?\n";
                                         cin >> pos;
                                         pos + 1;
                                         meds = med.begin() + pos;
                                         cout << "\t" << pos << "." << med[pos] << "\n¿desea eliminar este registro?\n1. si\t2. no\n";
                                         cin >> op;
                                               if (op==1){
                                                  med.erase(meds);
                                                  cout << "Medicina borrada";
                                                          }
                                               }
                                    }
                  break;
                  case 4:
                      if (med.empty()){ // si el vector esta vacio
                         cout << "\nNo hay medicinas que eliminar\n";
                      } else {
                        cout << "\nPor cual medio quiere editar:\n1. Nombre\n2.Numero\nOpcion: ";
                        cin >> op;
                        switch (op) {
                               case 1:
                                    cout << "¿Que nombre de medicina usted desea editar?\n";
                                    cin >> busq;
                                    for(int i = 0;i<med.size();i++){
                                            if (med[i] == busq){
                                               cout << "\t" << i++ << "." << med[i] << "\n¿desea editar este registro?\n1. si\t2. no\n";
                                               stat = true;
                                               cin >> op;
                                               cin.clear();
                                               cin.ignore();
                                               if (op==1){
                                                  pos = i - 1;
                                                  meds = med.begin() + pos;
                                                  cout << "Con que nombre cambiara este registro: ";
                                                  getline(cin,trans,'\n');
                                                  *meds = trans;
                                                  cout << "Medicina cambiada";
                                                          }
                                                  }
                                             }
                                    if (stat==false)
                                       cout << "no hubo medicina que editar\n";
                                    stat = false;
                                    break;
                                    case 2:
                                         cout << "¿Que posicion desea editar?\n";
                                         cin >> pos;
                                         pos - 1;
                                         meds = med.begin() + pos;
                                         cout << "\t" << pos << "." << med[pos] << "\n¿desea editar este registro?\n1. si\t2. no\n";
                                         cin >> op;
                                         cin.clear();
                                         cin.ignore();
                                               if (op==1){
                                               cout << "Con que nombre cambiara este registro: ";
                                               getline(cin,trans,'\n');
                                               *meds = trans;
                                                  cout << "Medicina cambiada";
                                                          }
                                               }
                                    }
                  break;
                  case 5:
                       cout << "Posicion en la cual se insertara: ";
                       cin >> pos;
                       meds = med.begin() + pos;
                       cout << "Escribe el nombre a insertar: ";
                       getline(cin,trans,'\n');
                       med.insert(meds,trans);
                       cout << "Nombre insertado";
                  break;
                  case 6:
                       if (med.empty()){ // si el vector esta vacio
                         cout << "\nNo hay medicinas que mostrar\n";
                      } else {
                             for(int i = 0;i<med.size();i++){
                                     cout << med[i] << endl;
                                 }
                                 }
                  break;
                  case 7:
                       cout << "\nHay " << med.size() << " medicinas registradas\n"; // muestra cuantos hay
                  break;
                  default:
                          if (op!=99)
                          cout << "\nerror en la matrix, menso -__-\n";
                          }
    }while (op!=99);
    cout << "Adios\n\ninserte algo para salir\n";
    cin >> trans;
}
