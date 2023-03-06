//
//  main.cpp
//  Overload
//
//  Created by Manuel Pastrana Blazquez.
//

#include <iostream>
#include <vector>

using namespace std;

class CVector {
private:
    vector<double> vec;
    int size;
public:
    CVector() { // Constructor por defecto
        size = 0;
    }
    CVector(int s) { // Constructor con parámetro
        size = s;
        vec.resize(size);
    }
    CVector(const CVector& v) { // Constructor de copia
        size = v.size;
        vec.resize(size);
        for (int i = 0; i < size; i++) {
            vec[i] = v.vec[i];
        }
    }
    ~CVector() { // Destructor
        vec.clear();
        //cout << "El destructor ha sido útil." << endl;
    }
    
    //  El destructor es útil porque garantiza que los recursos utilizados por un objeto sean liberados correctamente asi evita posibles problemas de memoria y hace mas eficiente el programa.
    
    int getSize() {
        return size;
    }
    double getNum(int pos) {
        if (pos < 0 || pos >= size) {
            throw 1;
        }
        return vec[pos];
    }
    void setNum(int pos, double value) {
        if (pos < 0 || pos >= size) {
            throw 2;
        }
        vec[pos] = value;
    }
    void setSize(int dimension) {
        size = dimension;
        vec.resize(size);
    }
    
    void setVec(vector<double> a) { // Función para asignar valores del vector
            vec = a;
        }
    
    CVector operator+(const CVector& b) {
        if (size != b.size) {
            throw 3;
        }
        CVector result(size);
        for (int i = 0; i < size; i++) {
            result.vec[i] = vec[i] + b.vec[i];
        }
        return result;
    }
    CVector& operator++() {
        for (int i = 0; i < size; i++) {
            vec[i]++;
        }
        return *this;
    }
    bool operator==(const CVector& b) {
        if (size != b.size) {
            throw "No se pueden comparar dos vectores de diferentes tamanios";
        }
        for (int i = 0; i < size; i++) {
            if (vec[i] != b.vec[i]) {
                return false;
            }
        }
        return true;
    }
    friend ostream& operator<<(ostream& os, const CVector& v);
};

ostream& operator<<(ostream& os, const CVector& v) {
    for (int i = 0; i < v.size; i++) {
        os << v.vec[i] << " ";
    }
    return os;
}

istream& operator>>(istream& is, CVector& v){
    vector<double> a(v.getSize());
    for (int i = 0; i < v.getSize(); i++) {
        is >> a[i];
    }
    v.setVec(a);
    return is;
}

int main() {
    int opcion;
    do {
        cout << "\n ‎ ------------------------------------------------------------------------------------------";
        cout << "\n ‎ ‎|‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎  ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎Menú                                          |";
        cout << "\n ‎ |----------------------------------------------------------------------------------------|";
        cout << "\n ‎ |‎ 1‎ |‎ ‎ ‎ Sumar dos vectores componente a componente‎ ‎  ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎ ‎|";
        cout << "\n ‎ |---|------------------------------------------------------------------------------------|";
        cout << "\n ‎ |‎ 2‎ |‎ ‎ ‎ Incrementar cada componente del vector  ‎                                         |";
        cout << "\n ‎ |---|------------------------------------------------------------------------------------|";
        cout << "\n ‎ |‎ 3‎ |‎ ‎ ‎ Comparar dos vectores por igualdad  ‎                                             |";
        cout << "\n ‎ |---|------------------------------------------------------------------------------------|";
        cout << "\n ‎ |‎ 0‎ |‎ ‎ ‎ FIN‎ ‎                                                                             |";
        cout << "\n ‎ ------------------------------------------------------------------------------------------";
        cout << "\n Ingrese una opción: ";
        cin >> opcion;
        switch (opcion) {
        case 1: {
            int size;
            cout << "Ingrese tamano del vector: ";
            cin >> size;
            CVector v1(size);
            cout << "Ingrese elementos del primer vector:\n";
            cin >> v1;
            CVector v2(size);
            cout << "Ingrese elementos del segundo vector:\n";
            cin >> v2;
            try {
                CVector v3 = v1 + v2;
                cout << "Vector 1: " << v1 << endl;
                cout << "Vector 2: " << v2 << endl;
                cout << "Resultado: " << v3 << endl;
            }
            catch (int e) {
                cerr << "Error: ";
                if (e == 3) {
                    cerr << "No se pueden sumar dos vectores de diferentes tamaños" << endl;
                }
            }
            break;
        }
        case 2: {
            int size;
            cout << "Ingrese tamano del vector: ";
            cin >> size;
            CVector v1(size);
            cout << "Ingrese elementos del vector:\n";
            cin >> v1;
            ++v1;
            cout << "Vector incrementado: " << v1 << endl;
            break;
        }
        case 3: {
            int size;
            cout << "Ingrese tamano del vector: ";
            cin >> size;
            CVector v1(size);
            cout << "Ingrese elementos del primer vector:\n";
            cin >> v1;
            CVector v2(size);
            cout << "Ingrese elementos del segundo vector:\n";
            cin >> v2;
            try {
                bool igualdad = (v1 == v2);
                cout << "Vector 1: " << v1 << endl;
                cout << "Vector 2: " << v2 << endl;
                if (igualdad) {
                    cout << "Los vectores son iguales\n";
                }
                else {
                    cout << "Los vectores son diferentes\n";
                }
            }
            catch (const char* msg) {
                cerr << msg << endl;
            }
            break;
        }
        case 0: {
            cout << "Programa terminado.\n";
            break;
        }
        default: {
            cout << "Opcion invalida, por favor ingrese una opcion valida.\n";
            break;
        }
        }
    } while (opcion != 0);
    return 0;
}
