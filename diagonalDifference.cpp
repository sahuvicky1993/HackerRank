#include <bits/stdc++.h>

using namespace std;

// Complete the diagonalDifference function below.
int diagonalDifference(vector<vector<int>> a) {
    int sum1=0,sum2=0;
    int n=a[0].size();
for(int i=0,j=0,k=n-1;i<n;i++){// must run only 3 times
    sum1=sum1+a[i][j++];
    sum2=sum2+a[i][k--];
}
return (sum1-sum2 >= 0) ? sum1-sum2 : -(sum1-sum2) ;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        a[i].resize(n);

        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = diagonalDifference(a);

    fout << result << "\n";

    fout.close();

    return 0;
}
