#include <iostream>
using namespace std;
// Ho Sy The - 20200614

int n;
int X[100], Y[100]; //# Lưu tọa độ các bước di chuyển của quân mã
bool mark[100][100]; //# Đánh dấu vị trí các ô mà quân mã đã di chuyển qua
int board_size;

//# Mảng hx, hy mô tả 8 vị trí quân mã có thể di chuyển kể từ vị trí hiện tại
const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2}; 
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};

//# In ra dãy các di chuyển tìm được
void print_sol(){
    for (int j = 1; j <= n * n; ++j)
        printf("(%d %d)\n", X[j], Y[j]);
    exit(0);
}

bool feasible_move(int x, int y) {
    return (x > 0 and x <= n) and (y > 0 and y <= n);
}

//# Thuật toán quay lui
void TRY(int k){
    for(int i = 0; i < 8; i++){
        int xx = X[k-1] + hx[i];
        int yy = Y[k-1] + hy[i];
        if (!mark[xx][yy] and feasible_move(xx, yy)) {
            mark[xx][yy] = true;
            X[k] = xx;
            Y[k] = yy;
            if (k == board_size) 
                print_sol();
            else TRY(k + 1);
            mark[xx][yy] = false;
        }
    }
}

int main(){
    cin >> n;
    mark[1][1] = true;
    X[1] = Y[1] = 1;
    board_size = n * n;
    TRY(2);
    return 0;
}