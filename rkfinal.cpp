#include <bits/stdc++.h>

using namespace std;

void rabinKarp(string & pattern, string & text, int p) {

  int m = pattern.size();
  int n = text.size();
  int i, j, hash_p = 0, hash_t = 0, h = 1, d = m + n;
//precomputing value of h to calculate the hash values for subsequent substrings of the text
  for (i = 0; i < m - 1; i++) {
    h = (h * d) % p;
  }
   
  // Calculate hash value for pattern and text
  for (i = 0; i < m; i++) {
    hash_p = (pattern[i] + d * hash_p) % p;
    hash_t = (text[i] + d * hash_t) % p;
  }

  // Find the match
  for (i = 0; i <= n - m; i++) {

    // Check the hash values of current windows of text and pattern.
    if (hash_p == hash_t) {

      for (j = 0; j < m; j++) {

        if (text[i + j] != pattern[j]) break;
      }

      // if pattern == text
      if (j == m) cout << "Pattern is found at index : " << i << "\n";
    }

    // Calculate the hash value for next window : adding trailing digit 
   //and remove leading digit
    if (i < n - m) {
      hash_t = (d * (hash_t - text[i] * h) + text[i + m]) % p;

      //converting negative value of hash_t to positive.
      if (hash_t < 0) hash_t = (hash_t + p);
    }
  }
}

int main() {
  string text = "Lilly was a little girl. Lilly lived in a huge castle, Lilly was all alone";
  string pattern = "Lilly";
  int p = 239;
   clock_t start, end;
 
    // Recording the starting clock tick.
    start = clock();
	
   
rabinKarp(pattern, text, p);
 
    // Recording the end clock tick.
    end = clock();
 
    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " sec " << endl;
  
}