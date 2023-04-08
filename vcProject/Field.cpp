#include "Field.h"

void Field::clear(){
    for (int i = 0; i < n; i++){
        delete[] arr[i];
    }
    delete[] arr;
}

void Field::copy(const Field & object){
    n = object.n;
    m = object.m;
    arr = new Cell*[n];
    for (int i = 0; i < m; i++){
        arr[i] = new Cell[m];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            arr[i][j] = object.arr[i][j];
        }
    }
}

void Field::move(Field && object){
    swap(n, object.n);
    swap(m, object.m);
    swap(arr, object.arr);
}

Field::Field(int n_size, int m_size){
    n = n_size;
    m = m_size;
    arr = new Cell*[n];
    for (int i = 0; i < m; i++){
        arr[i] = new Cell[m];
    }
}

Field::Field(const Field & object){
    copy(object);
}

Field & Field::operator=(const Field& object){
    if (this != &object){
        clear();
        copy(object);
    }
    return *this;
}

Field::Field(Field && object){
    move(std::move(object));
}

Field & Field::operator=(Field&& object){
    if (this != &object){
        clear();
        move(std::move(object));
    }
    return *this;
}

void Field::set_objectsofgame(vector<Object_of_game *> obj) {
    for (auto i : obj){
        srand(time(0));
        int x = rand() %(m-1);
        int y = rand() %(n-1);
        while (!(typeid((arr[y][x])) == typeid(Cell) && arr[y][x].get_objectofgame() == nullptr)) {
            x = rand() %(n-1);
            y = rand() %(m-1);
        }
        arr[y][x].set_objectofgame(i);
    }
}

Field::~Field(){
    clear();
}

//void Field::print_Field(){
//    for (int i = 0; i < n; i++){
//        for (int j = 0; j < m; j++){
//            cout << arr[i][j].get_condition();
//        }
//        cout << endl;
//    }
//}