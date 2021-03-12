#include<iostream>
using namespace std;
bool safeToPlaceQueen(int board[][10], int i, int j, int n) {
	// no queen should be present in the current column,j
	for (int row = 0; row <= i; row++) {
		if (board[row][j] == 1) {
			return false;
		}
	}
	// no queen should be present in the left diagonal
	int x = i;
	int y = j;
	while (x >= 0 and y >= 0) {
		if (board[x][y] == 1) {
			return false;
		}
		x--;
		y--;
	}
	// no queen should be present along the right diagonal
	x = i;
	y = j;
	while (x >= 0 and y < n) {
		if (board[x][y] == 1) {
			return false;
		}
		x--;
		y++;
	}
	// If you return false, it will print all the valid CONFIGURATIONS. YES ALL !!
	return true;

}
void NQueen(int board[][10], int i, int n) {
	if (i == n) {
		// you have successfully place dn queen  0...(n-1)
		// print the board
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < n; col++) {
				if (board[row][col] == 1) {
					cout << "Q ";
				}
				else {
					cout << "_ ";
				}
			}
			cout << endl;
		}
		cout << endl;


	}
	// RECURSIVE CASE
	//Try to place the queen in the current row and call on the remaining part which will be solved by recursion
	for (int j = 0; j < n; j++) {
		// I have to check if i,j th position is safe to place the queen or not
		if (safeToPlaceQueen(board, i, j, n)) {
			//Place the queen - assuming it is the right position
			board[i][j] = 1;
			NQueen(board, i + 1, n);
			/*
			ye NextQueenRakhPaye  ka matlab hai, humne i pe queen rakh diya hai,
			ab hum aage function call kar diye hain, ki bhai dekho i pe to humne queen rakh diya hai
			ab tumlog i+1 aur uske aage queen rakho, agli call bhi issi tarah hogi.
			aur agar sab ne true return kiya, iska matlab yehan wala NextQueenRakhpaye pe jo value aayega wo
			bhi true aayega.
			matlab saare queen apni achhi jagah pe rakhi ja chuki hai
			aur jab saare queen achhi jagah pe rakhi ja chuki hai to aap bhi main function ko true return kardo
			aur bol do ki han ji sab sahi hai
			aur agar false aaya, to iska matlab hua ki humlog jo upar queen place kiye hain wo sahi nahi hai,
			but chuki humlog board[i][j]=1, already mark kar chuke the issiliye ab uss mark ko hatana hoga
			matlab wahan phir se 0 likhna hoga, mean board[i][j]=0;
			ab hum ussi row me kisi dusre(j+1) pe queen rakh kar yahi process duhraayenge
			*/

			//chaliye bhai, ab khus :xd


			// if (!NextQueenRakhPaye) {
			// 	// return true;
			// 	board[i][j] = 0;
			// }
			board[i][j] = 0;
		}
	}

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	int board[10][10] = {0};
	NQueen(board, 0, n);


}