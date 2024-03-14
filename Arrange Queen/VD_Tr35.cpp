#include <iostream>
using namespace std;
int n;

void result(int s[][2]);
void re(int s[][2], bool colums[], bool cs[], bool ch[], int i);

int main(){
	cin >> n;
	int s[n+1][2];
	bool colums[n+1], cs[n*2], ch[n*2];

	for (int i = 1; i <= n; i++){
		colums[i] = 1;
		cs[i] = cs[i+n-1] = ch[i] = ch[i+n-1] = 1;
	}

	re(s, colums, cs, ch, 1);

	return 0;
}
void result(int s[][2]){
	cout << "(" << s[1][0] << ", " << s[1][1] << ")";
	for (int i = 2; i <= n; i++){
		cout << ", (" << s[i][0] << ", " << s[i][1] << ")";
	}
}
void re(int s[][2], bool colums[], bool cs[], bool ch[], int i){
	s[i][0] = i;
	for(int j = 1; j <= n; j++){
		if (colums[j] && ch[j-i+n] && cs[i+j-1]){
			s[i][1] = j;
			colums[j] = 0;
			ch[j-i+n] = 0;
			cs[i+j-1] = 0;

			if (i == n){
				result(s);
				cout << ".\n";

			}else{
				re(s, colums, cs, ch, i+1);
			}

			colums[j] = 1;
			ch[j-i+n] = 1;
			cs[i+j-1] = 1;

		}
	}
}