// Rectangle and square
// #include <iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter a length"<<endl;
//     cin>>n;
//     int y;
//     cout<<"Enter a length"<<endl;
//     cin>>y;
//     for(int i=0; i<n; i++){
//         for(int j=0; j<y; j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }

// Triangle
// #include <iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter a length: ";
//     cin>>n;
//     for(int i=0; i<n; i++){
//         for(int j=0; j<=i; j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }

// Pyramid
// #include <iostream>
// using namespace std;
// int main(){
//     int n;
//     int k = 1;
//     cout<<"Enter a length: ";
//     cin>>n;
//     if (n%2==0)
//     {
//         n=n+1;
//     }
//     for (int i = n; i>0; i--)
//     {
//         for (int j = 1; j<= i; j++)
//             cout<<"  ";
//         for (int j = 1; j<= k; j++)
//           {cout<<"* ";}
//           k = k + 2;
//         cout<<endl;
//     }

// alphabet
// #include <iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter a length: ";
//     cin>>n;
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             cout<<char(j+65)<<" ";
//         }
//         cout<<endl;
//     }
// }

// Plus
// #include <iostream>
// using namespace std;
// int main(){
//     int n;
//     cout << "Enter a length: ";
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (i == n/2 || j == n / 2)
//             {
//                 cout << "* ";
//             }
//             else
//             {
//                 cout << "  ";
//             }
//         }
//         cout << endl;
//     }
// }

// cross
//  #include <iostream>
//  using namespace std;
//  int main(){
//      int n;
//      cout << "Enter a length: ";
//      cin >> n;
//      for (int i = 1; i <= n; i++)
//      {
//          for (int j = 1; j <= n; j++)
//          {
//              if (i==j||j==(n-i)+1)
//              {
//                  cout << "* ";
//              }
//              else
//              {
//                  cout << "  ";
//              }
//          }
//          cout << endl;
//      }
//  }

// Floyd Triangle
//  #include <iostream>
//  using namespace std;
//  int main(){
//      int n;
//      cout << "Enter a length: ";
//      cin >> n;
//      int l=1;
//      for (int i = 1; i <= n; i++)
//      {
//          for (int j = 1; j <=i; j++)
//          {cout<<l<<" ";
//          l++;
//          }
//          cout << endl;
//      }
//  }

// binary Triangle Method1
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cout << "Enter a length: ";
//     cin >> n;
//             bool l = false;
//     for (int i = 1; i <= n; i++)
//     {
//             if(i%2==0){
//             l=false;
//             }
//             else{
//             l=true;
//             }
//         for (int j = 1; j <= i; j++)
//         {
//             cout<<int(l);
//             if(l==true){
//             l=false;
//             }
//             else{
//             l=true;
//             }
//         }
//         cout << endl;
//     }
// }

// binary Triangle Method2
// #include <iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter a length: ";
//     cin>>n;
//     bool b = true;
//     for(int i=0; i<n; i++){
//         for(int j=0; j<=i; j++){
//             if((i-j)%2==0){
//                 b=true;
//                 cout<<b;
//             }
//             else{
//             b=false;
//             cout<<b;
//             }
//         }
//         cout<<endl;
//     }
// }

//Reverse Triangle 1
// #include <iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter a length: ";
//     cin>>n;
//     for(int i=0; i<n; i++){
//         for(int j=0; j<=i; j++){
//             cout<<"  ";
//         }
//         for(int j=n; j>i; j--){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }

//Reverse Triangle 2
// #include <iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter a length: ";
//     cin>>n;
//     for(int i=1; i<=n; i++){
//         for(int j=n; j>i; j--){
//             cout<<"  ";
//         }
//         for(int j=1; j<=i; j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }

//Rhoumbus
// #include <iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter a length: ";
//     cin>>n;
//     for(int i=1; i<n; i++){
//         for(int j=1; j<=(n-i); j++){
//             cout<<"  ";
//         }
//         for(int k=1; k<=n; k++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }

//Pyramid Palidrome
// #include <iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter a length: ";
//     cin>>n;
//     if (n%2==0)
//     {
//         n=n+1;
//     }
//     for (int i = 1; i<=n; i++)
//     {
//         for (int j = 1; j<=n-i; j++)
//             cout<<"  ";
//         for (int j = 1; j<=i; j++)
//           {cout<<j<<" " ;}
//         if(i>=2){
//         for(int k = 1; k<i; k++){
//             cout<<i-k<<" ";
//         }} 
//         cout<<endl;
//     }
// }

//Diamond
// #include <iostream>
// using namespace std;
// int main(){
//     int n;
//     int k = 1;
//     cout<<"Enter a length: ";
//     cin>>n;
//     if (n%2==0)
//     {
//         n=n+1;
//     }
//     for (int i =1; i<=(n/2+1); i++)
//     {
//         for (int j =1; j<=(n/2+1)-i; j++)
//             cout<<"  ";
//         for (int j = 1; j<= k; j++)
//           {cout<<"* ";}
//           k = k + 2;
//         cout<<endl;
//     }
//     k=k-2;
//     for (int i = 1; i<=n/2; i++)
//     {
//         k = k- 2;
//         for (int t = 1; t<=i; t++)
//         {cout<<"  ";}
//         for (int j = 1; j<=k; j++){
//             cout<<"* ";}
//         cout<<endl;
//     }
// }

//Bridge 
// #include <iostream>
// using namespace std;
// int main(){
//     int n;
//     int k = 1;
//     cout<<"Enter a length: ";
//     cin>>n;
//     if (n%2==0)
//     {
//         n=n+1;
//     }
//     for (int i = 0; i < n+(n-1); i++)
//     {
//         cout<<"* ";
//     }
//     cout<<endl;
//     for (int i = n-1; i>0; i--)
//     {
//         for (int j = 1; j<= i; j++)
//             cout<<"* ";
//         for (int j = 1; j<= k; j++)
//           {cout<<"  ";}
//           k = k + 2;
//         for(int j=1;j<=i; j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
// }

//Most Toughest Number Spiral
#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a length: ";
    cin>>n;
    int v = 1;
        for(int i=0;i<n*2-1;i++){
            for(int j=0;j<n*2-1;j++){
                int a=i;
                int b=j;
                if(a<n){a=n-i;}
                if(b<n){b=n-j;}
                cout<<max(a,b)<<" ";
            }
        if(i==n){
            v=1;
        }
        else{
            v++;
        }
        cout<<endl;
        }
}
// #include <iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter a length: ";
//     cin>>n;
//     int a[n][n];
//     int i, j, k = 1, l = 0;
//     int top = 0, bottom = n-1, left = 0, right = n-1;
//     while (k <= n*n) {
//         for (i = left; i <= right && k <= n*n; i++) {
//             a[top][i] = k++;
//         }
//         top++;
//         for (i = top; i <= bottom && k <= n*n; i++) {
//             a[i][right] = k++;
//         }
//         right--;
//         if (k <= n*n && top <= bottom) {
//             for (i = right; i >= left && k <= n*n; i--) {
//                 a[bottom][i] = k++;
//             }
//             bottom--;
//         }
//         if (k <= n*n && left <= right) {
//             for (i = bottom; i >= top && k <= n*n; i--) {
//                 a[i][left] = k++;
//             }
//             left++;
//         }
//     }
//     for (i = 0; i < n; i++) {
//         for (j = 0; j < n; j++) {
//             cout << a[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }







