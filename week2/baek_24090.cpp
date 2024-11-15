#include<iostream>
#include<string>
#include <vector>
using namespace std;
int K, swapCount = 0;



void swap(int data [], int a, int b){ //배열의 내용을 교환해주는 함수
    int tmp = data[a];
    data[a] = data[b];
    data[b] = tmp;
}

void pivot(int  data[], int start, int end){ // 배열의 시작, 끝 중간값 중 중간값을 중간에 배치
    int mid = (start + end) / 2;

    // start, mid, end 값 중 중위값을 구해 배열의 시작 위치로 이동
    if ((data[start] <= data[mid] && data[mid] <= data[end]) || (data[end] <= data[mid] && data[mid] <= data[start])) {
        swap(data, start, mid);  // mid 값이 중위값인 경우
    } 
    else if ((data[mid] <= data[start] && data[start] <= data[end]) || (data[end] <= data[start] && data[start] <= data[mid])) {
        // start 값이 중위값인 경우 (현재 그대로이므로 스왑 필요 없음)
    } 
    else {
        swap(data, start, end);  // end 값이 중위값인 경우
    }
}

void quick_sort(int  data[], int start, int end){
    int i = start + 1;
    int j = end;
    if(start >= end){
        return;
    }
    while (start < end){
        pivot(data, start, end);
        int pivotValue = data[start]; // pivot을 배열의 처음으로 가져옴

        while (i <= j) {
            while (i <= end && data[i] <= pivotValue) i++;
            while (j > start && data[j] > pivotValue) j--;

        if(i < j){
            swap(data, i ,j);
            swapCount++;
            if(swapCount == K){
            cout << data[i] << " " << data[j] << endl;
            break;
        }   
        }
        }

        
        swap(data, start, j);


         
    }       

quick_sort(data, start , j - 1);
quick_sort(data, j + 1, end);
}
// 전역+ 순환 pivot 함수 elif/ 

int main(){
    int N;
    cin >> N >> K;
    int data[10000] = { 0, };
    

    for(int i = 0; i < N; i++){
        cin >> data[i];
    }

    quick_sort(data , 0 , N - 1);

    if(swapCount < K){
        cout << -1 << endl;
    }

    return 0;
}