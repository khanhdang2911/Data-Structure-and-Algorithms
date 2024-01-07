#include<bits/stdc++.h>
using namespace std;
//5 3 1 2 4 6
void quicksort(int a[], int left, int right) {
    int l = left;
    int r = right;
    int pivot = a[(left + right) / 2];
    while (l <= r) {
        while (a[l] < pivot) {
            l++;
        }
        while (a[r] > pivot) {
            r--;
        }
        if (l <= r) {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }

    cout << "After partition: ";
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    
    cout<<endl<<pivot<<endl;
    cout<<"left="<<left<<endl;
    cout<<"r="<<r<<endl;
    cout<<"right="<<right<<endl;
    cout<<"l="<<l<<endl;
    cout << endl;

    if (left < r) {
        quicksort(a, left, r);
    }
    if (l < right) {
        quicksort(a, l, right);
    }
}

int main() {
    int n;
	scanf("%d",&n);
	int a[100];
	for(int i=0;i<n;i++)
	{
	a[i]=rand()%50;
    }
        for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout<<endl;
    quicksort(a, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

//#include<bits/stdc++.h>
//using namespace std;
//void quicksort(int a[],int left,int right)
//{
//  int l=left;
//  int r=right;
//  int pivot=(left+right)/2;
//  while(l<=r)
//  {
//  	while(a[l]<a[pivot])
//  	l++;
//  	while(a[r]>a[pivot])
//  	r--;
//  	if(l<=r)
//	{
//  	swap(a[l],a[r]);
//  	l++;
//  	r--;
//  	}
//  }
//    if (left < r)
//        quicksort(a, left, r);
//    if (l < right)
//        quicksort(a, l, right);
//}
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	int a[100];
//	for(int i=0;i<n;i++)
//	{
//	a[i]=rand()%100;
//    }
//    quicksort(a,0,n-1);
//    for(int i=0;i<n;i++)
//    printf("%3d",a[i]);
//	
//	
//	return 0;
//}
