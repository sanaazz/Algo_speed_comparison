//
//  Created by Sanaz Gheibuni on 28.04.2023.
//

#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;

//prototype
int maxSubSum1(const int arr[],const int size);
int maxSubSum2(const int arr[],const int size);
int maxSubSum3(const int arr[],const int size);
int maxSubSum4(const int arr[], const int size);
int* generateRandomArray(int n);

int* generateRandomArray(int n) {
  int* arr = new int[n]; // allocate memory for the array
  
  // seed the random number generator with the current time
//srand(time(NULL));
  
  for (int i = 0; i < n; i++) {
    // generate a random number between -100 and 100
    arr[i] = rand() % 2001 - 1000;
  }
  
  return arr;
}

int maxSubSum1(const int arr[], const int size){
    int maxSum = 0;
    for (int i = 0; i < size; i++)
        for(int j = i; j < size; j++){
            int thisSum =0;
            for( int k = i; k <= j; k++)
                thisSum += arr[k];
            
            if (thisSum > maxSum)
                maxSum = thisSum;
        }
    return  maxSum;
}
int maxSubSum2(const int arr[], const int size){
    int maxSum = 0;
    for (int i = 0; i < size; i++){
        int thisSum = 0;
        for (int j = i; j < size; j++){
            thisSum += arr[j];
            
            if(thisSum > maxSum)
                maxSum = thisSum;
        }
    }
    return maxSum;
}
int maxSumRec(const int arr[], int left, int right){
    if (left == right){
        if (arr[left] > 0){
            return arr[left];
        }
        
        else{
            return 0;}
    }
    
    int center = (left + right)/2;
    int maxLeftSum = maxSumRec(arr, left, center);
    int maxRightSum = maxSumRec(arr, center + 1, right);
    
    int maxLeftBorderSum = 0, leftBorderSum = 0;
    for (int i = center; i >= left; i--){
        leftBorderSum += arr[i];
        if (leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }
    
    int maxRightBorderSum = 0, rightBorderSum = 0;
    for (int j = center + 1; j <= right; j++){
        rightBorderSum += arr[j];
        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }
    
    return max(maxLeftSum, max(maxRightSum, maxLeftBorderSum + maxRightBorderSum));
}
int maxSubSum3(const int arr[],const int size){
    return maxSumRec(arr, 0, size - 1);
}
int maxSubSum4(const int arr[], const int size){
    int maxSum = 0, thisSum = 0;
    for (int i = 0; i < size; i++){
        thisSum += arr[i];
        
        if(thisSum > maxSum)
            maxSum = thisSum;
        else if (thisSum < 0)
            thisSum = 0;
    }
    return maxSum;
}


int main(int argc, const char * argv[]) {
    
    // Declare necessary variables
    std::chrono::time_point< std::chrono::system_clock > startTime1;
    std::chrono::time_point< std::chrono::system_clock > startTime2;
    std::chrono::time_point< std::chrono::system_clock > startTime3;
    std::chrono::time_point< std::chrono::system_clock > startTime4;
    std::chrono::duration< double, milli > elapsedTime1;
    std::chrono::duration< double, milli > elapsedTime2;
    std::chrono::duration< double, milli > elapsedTime3;
    std::chrono::duration< double, milli > elapsedTime4;
    
    for(int i = 0; i <= 10000; i+=500){
        if (i == 0){ continue;}
        int *array = generateRandomArray(i);
        
        startTime1 = std::chrono::system_clock::now();
        int sum1 = maxSubSum1(array, i);
        elapsedTime1 = std::chrono::system_clock::now() - startTime1;
        
        startTime2 = std::chrono::system_clock::now();
        int sum2 = maxSubSum2(array, i);
        elapsedTime2 = std::chrono::system_clock::now() - startTime2;
        
        startTime3 = std::chrono::system_clock::now();
        int sum3 = maxSubSum3(array, i);
        elapsedTime3 = std::chrono::system_clock::now() - startTime3;
        
        startTime4 = std::chrono::system_clock::now();
        int sum4 = maxSubSum4(array, i);
        elapsedTime4 = std::chrono::system_clock::now() - startTime4;
        
        cout<< " array Size: \t" << i
            << "\t algo 1: \t"
            <<fixed
            <<setprecision(3)
            << elapsedTime1.count()
            << "\t algo 2: \t"
            <<fixed
            <<setprecision(3)
            << elapsedTime2.count()
            << "\t algo 3: \t"
            <<fixed
            <<setprecision(3)
            << elapsedTime3.count()
            << "\t algo 4: \t"
            <<fixed
            <<setprecision(3)
            << elapsedTime4.count()
            << endl;
    }
    
    for ( int i = 10000;i < 100000; i +=10000 ){
        int *array = generateRandomArray(i);
        
        startTime2 = std::chrono::system_clock::now();
        int sum2 = maxSubSum2(array, i);
        elapsedTime2 = std::chrono::system_clock::now() - startTime2;
        
        startTime3 = std::chrono::system_clock::now();
        int sum3 = maxSubSum3(array, i);
        elapsedTime3 = std::chrono::system_clock::now() - startTime3;
        
        startTime4 = std::chrono::system_clock::now();
        int sum4 = maxSubSum4(array, i);
        elapsedTime4 = std::chrono::system_clock::now() - startTime4;
        
        cout<< " array Size: \t" << i
            << "\t algo 1: \t"
            << "N/A "
            << "\t algo 2: \t"
            <<fixed
            <<setprecision(3)
            << elapsedTime2.count()
            << "\t algo 3: \t"
            <<fixed
            <<setprecision(3)
            << elapsedTime3.count()
            << "\t algo 4: \t"
            <<fixed
            <<setprecision(3)
            << elapsedTime4.count()
            << endl;
    }
    
    for ( int i = 100000;i <= 400000; i +=50000 ){
        int *array = generateRandomArray(i);
        
        startTime2 = std::chrono::system_clock::now();
        int sum2 = maxSubSum2(array, i);
        elapsedTime2 = std::chrono::system_clock::now() - startTime2;
        
        startTime3 = std::chrono::system_clock::now();
        int sum3 = maxSubSum3(array, i);
        elapsedTime3 = std::chrono::system_clock::now() - startTime3;
        
        startTime4 = std::chrono::system_clock::now();
        int sum4 = maxSubSum4(array, i);
        elapsedTime4 = std::chrono::system_clock::now() - startTime4;
        
        cout<< " array Size: \t" << i
            << "\t algo 1: \t"
            << "N/A "
            << "\t algo 2: \t"
            <<fixed
            <<setprecision(3)
            << elapsedTime2.count()
            << "\t algo 3: \t"
            <<fixed
            <<setprecision(3)
            << elapsedTime3.count()
            << "\t algo 4: \t"
            <<fixed
            <<setprecision(3)
            << elapsedTime4.count()
            << endl;
    }
    
    for (int i=1000000 ; i<= 50000000; i += 1000000){
        
        int *array = generateRandomArray(i);
        
        startTime3 = std::chrono::system_clock::now();
        int sum3 = maxSubSum3(array, i);
        elapsedTime3 = std::chrono::system_clock::now() - startTime3;
        
        startTime4 = std::chrono::system_clock::now();
        int sum4 = maxSubSum4(array, i);
        elapsedTime4 = std::chrono::system_clock::now() - startTime4;
        

            cout<< " array Size: \t" << i
                << "\t algo 1: \t"
                << "N/A "
                << "\t algo 2: \t"
                << "N/A "
                << "\t algo 3: \t"
                <<fixed
                <<setprecision(3)
                << elapsedTime3.count()
                << "\t algo 4: \t"
                <<fixed
                <<setprecision(3)
                << elapsedTime4.count()
                << endl;
    }
        
    
    return 0;
}
