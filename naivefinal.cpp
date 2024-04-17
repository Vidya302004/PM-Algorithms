#include <bits/stdc++.h>
using namespace std;

void naive(string& pat, string txt)
{
	int M = pat.size();
	int N = txt.size();

	//A loop to slide pat[] one by one 
	for (int i = 0; i <= N - M; i++) {
		int j;

		// For current index i, check for pattern match 
		for (j = 0; j < M; j++)
			if (txt[i + j] != pat[j])
				break;
        // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
		if (j == M) 
			cout << "Pattern found at index " << i << endl;
	}
}

int main()
{
     
 string txt ="Lilly was a little girl. Lilly lived in a huge castle, Lilly was all alone";
	string pat = "Lilly";
     clock_t start, end;
 
    // Recording the starting clock tick.
    start = clock();
	naive(pat, txt);
   

 
    // Recording the end clock tick.
    end = clock();
 
    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " sec " << endl;
	
	return 0;
}


