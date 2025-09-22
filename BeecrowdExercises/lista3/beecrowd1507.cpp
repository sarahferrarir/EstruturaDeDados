// Title: Subsequences

#include <iostream>
#include <string>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        string S;
        int Q;
        cin >> S >> Q;
        for(int j = 0; j < Q; j++){
            string R;
            cin >> R;
            
            int k = 0;
            for(int l = 0; l < S.size(); l++){
                if(S[l] == R[k]){
                    k++;
                }
                if(k == R.size()){
                    break;   
                }
            }
            if(k == R.size()){
                cout << "Yes" << endl;
            } else{
                cout << "No" << endl;
            }
        }
    }
    
    return 0;
}