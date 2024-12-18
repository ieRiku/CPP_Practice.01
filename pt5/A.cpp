#include <bits/stdc++.h>
using namespace std;

int main(void){
    int M, N, R;
    cin >> M >> N;
    int arr1[N][2];
    for(int i=0; i<N; i++){
        cin >> arr1[i][0] >> arr1[i][1];
    }
    cin>>R;
    vector<vector<int>> arr2(M, vector<int>(0));
    int k1=0, k2=0;
    for(int i=0; i<N; i++){
        arr2[arr1[i][0]].push_back(arr1[i][1]);
        arr2[arr1[i][1]].push_back(arr1[i][0]);
    }

    // for(int i=0;i<M;i++){
    //     for(int j=0;j<arr2[i].size();j++){
    //         cout<<arr2[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int arr3[M] = {0};
    for(int i=0; i<R; i++){
        arr3[i] = 1;
    }
    int count = 0;
    int flag = 0;
    while(count < R){
        flag++;
        int temp[M];
        for(int i=0;i<M;i++){
            temp[i] = arr3[i];
        }
        for(int i=0; i<M; i++){
            int wfo=0;
            int wfh=0;
            if(arr3[i] == 1){
                for(vector<int>::size_type j=0;j<arr2[i].size();j++){
                    if(arr3[arr2[i][j]] == 1){
                        wfo++;
                    }
                    else{
                        wfh++;
                    }
                }
                if(wfo == 3){
                    temp[i] = 1;
                }
                else{
                    temp[i] = 0;
                }
            }
            else{
                for(vector<int>::size_type j=0;j<arr2[i].size();j++){
                    if(arr3[arr2[i][j]] == 1){
                        wfo++;
                    }
                    else{
                        wfh++;
                    }
                }
                if(wfo < 3){
                    temp[i] = 1;
                }
                else{
                    temp[i] = 0;
                }
            }
            count+= arr3[i];    // same as i<M loop
        }
        for(int i=0;i<M;i++){
            arr3[i]= temp[i];
        }
    }
    cout<<flag;
    return 0;
}