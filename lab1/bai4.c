// Ho Sy The - 20200614

int counteven(int* arr, int n){
    int ans = 0;
    for(int i = 0; i < n;++i){
        ans += ((*(arr + i) & 1) == 0);
    }
    return ans;
}