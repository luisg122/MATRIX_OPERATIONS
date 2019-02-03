#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int * matrix_randgen(int n, int a, int b) {
    int * array = new int[n*n];
        for(int i=0; i<n*n; ++i){
            array[i]=rand()%(b-a+1)+a;
    }
    return array;

}

void show_matrix_array(int * array, int n){
    for(int i=0; i<n; i++){
        cout << "[";
        for (int j=0; j<n; j++) {
            int k=j+(i*n);
            cout << array[k];
            if (j<(n-1)) cout << ", ";
        }
        cout << "]" << endl;
    }
}



int * matrix_add( int * m1, int * m2, int n) {
    int* add= new int[n*n];
        for(int i=0; i<(n*n); i++) {
        add[i] = m1[i] + m2[i];
    }
    return add;
}
    
    
    
int * matrix_sub( int * array, int * array2, int n) {
    int *sub = new int[n*n];
        for(int i=0;i<(n*n);++i){
            sub[i] = array[i] - array2[i];
        }
        return sub;
        
}
int * matrix_multi( int * array1, int * array2, int n){
       int * multi= new int[n*n]();   //int * multi= new int[n*n]{}     //declare blank array
       int i=0; //multi[i]
       for (int j=0; j<n; j++) {            //array1 shifts horizontally everytime multi[i] reaches to the end of that row
            for (int l=0; l<n; l++) {       //array2 shifts horizontally everytime multi[i] moves to the next i, note that array1 remains at the same row
                 for (int m=0; m<n; m++) {  //the horizontal shift of array1 always matches the vertical shift of array2, so it increase at the same time
                 multi[i] += array1[m+(j*n)] * array2[l+(m*n)];
                }
            ++i; //prefix operator        
            }
        }
    return multi; 
}
int main() {
    int n=0, a=0, b=9;
    srand(time(0)); //srand(time(NULL))
    cout << "Enter the size n of n*n matrices:";
    cin >> n;
    
    int * arraya = matrix_randgen(n, a, b);
    int * arrayb = matrix_randgen(n, a, b);
    
    /*int arraya[9]={0,1,2,3,4,5,6,7,8};      // array used for testing purposes, ex: show_matrix
    int arrayb[9]={0,1,2,3,4,5,6,7,8};*/      // must test with n=3 ; tested, working
    
    /*int arraya[9]={7,6,4,5,6,4,3,9,3};      // provided by proffesor in project pdf example screenshot1
    int arrayb[9]={8,6,0,0,0,6,3,3,5};*/      // must test with n=3 ; tested, working, matches screenshot
    
    /*int arraya[16]={5,8,1,8,1,2,3,7,1,6,9,1,7,9,1,8};     // provided by proffesor in project pdf example screenshot2
    int arrayb[16]={2,5,9,0,3,5,6,0,2,5,7,7,6,0,3,3};*/     // must test with n=4 ; tested, working, matches screenshot
    
    cout << "Matrix a is" << endl;
    show_matrix_array(arraya, n);
    cout << "Matrix b is" << endl;
    show_matrix_array(arrayb, n);
    
    cout << "Matrix a+b is" << endl;
    int * add = matrix_add(arraya, arrayb, n);
    show_matrix_array(add, n);
    
    cout << "Matrix a-b is" << endl;
    int * sub= matrix_sub(arraya, arrayb, n);
    show_matrix_array(sub, n);
    
    cout << "Matrix ab is" << endl;
    int * multi= matrix_multi(arraya, arrayb, n);
    show_matrix_array(multi, n);
    
    /*cout << "matrix ab2" << endl;
    int * multii= matrix_multii(testarray1, testarray2, n);
    show_matrix_array(multii, n); */
    
     delete[] arraya;
     delete[] arrayb;
     delete[] add;
     delete[] sub;
     delete[] multi;

}
