#include "sortAlgorithm.h"
#include "DataGenerator.cpp"
#include "sortAlgorithm.cpp"

int main(){
    ofstream data;
    data.open("data.txt");
    if(!data.is_open()){
        cout << "Error opening file to write result." << endl;
        return 0;
    }
    vector<string>Algorithms = {"Seclection Sort","Merge Sort","Heap Sort", "Quick Sort","Bubble Sort","Insertion Sort", "Binary Insertion Sort"};
    vector<string> DataOrders = {"Random","Ascending","Descending","Prox Ascending"};
    vector<int> DataSizes = {3000,10000,30000,100000,300000};
    for(int DataOrder = 0; DataOrder < DataOrders.size(); DataOrder++){
        cout << "Data order: " << DataOrders[DataOrder] << endl;
        data << "Data order: " << DataOrders[DataOrder] << endl;
        for(int DataSize: DataSizes){
            cout << "Data Size: " << DataSize << endl;
            for(int i = 0; i < Algorithms.size(); i++){
                cout << Algorithms[i] << ":\t";
                data << Algorithms[i] << ":\t";
                int * a = new int[DataSize];
                GenerateData(a,DataSize,DataOrder);
                auto start = chrono::high_resolution_clock::now();
                chooseAlgorithms(a,i,DataSize);
                auto end = chrono::high_resolution_clock::now();
                cout << chrono::duration_cast<chrono::microseconds>(end - start).count()
                << " ms" << endl;
                data << chrono::duration_cast<chrono::microseconds>(end - start).count()
                << " ms" << endl;
                delete[] a;
                a = nullptr;
            }
            cout << "==================================================================" << endl;
            data << "==================================================================" << endl;
        }
        cout << "==================================================================" << endl;
        data << "==================================================================" << endl;
    }
    data.close();
    return 0;
}
