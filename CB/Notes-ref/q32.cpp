//sanket and string
// dry run jarur kar ke dekhen.

#include<iostream>
using namespace std;
int main() {
	int k;
	cin >> k;
	string s;
	cin >> s;
	int n = s.length();
	// l  and r jo hai wo hai 2 pointers  initially dono 1st element pe point kar raha
	// phir l (matlab left   and r matlab right )
	//l wala ko 0 index pe fix kar dete hain phir right wale ko ek ek shift karte rahenge
	int l = 0;
	//count[]  ek array hai jo 'a' aur 'b'  ka count store karta hai
	//matlab ab tak kitna 'a'  aur kitna 'b' mila
	int count[] = {0, 0};

	//ans jo hai wo length of string dikha raha
	int ans = 0;
	for (int r = 0; r < n; r++) {
		//niche wala jo hai iska matlab ye hai ki agar s[r]  'a' hua to zero ka count badhega
		//agar 'b' hua to 1 ka count badhega
		//matlab ye hua ki count[0] jo hai wo 'a' ko represent kar raha
		//count[1] jo hai wo 'b' ka counting karega
		count[s[r] - 'a'] += 1;

		//ab sawal uthhta hai ki ye min() kyun use kiye ho?
		// wo iss liye ki hum max substring length khoj rahe hain.
		//matlab chuki hame 'k' elements swap (matlab 'a' ko 'b' me aur 'b' ho to use  'a' likhna,
		//likhna matyla literally likhna nahi balki count karna matlab maan
		// liye ki man me change kar diya unn k letters ko :) )
		// hame bas koi 'k' elements swap karna hai
		//jis se bhi max substring ban jaaye
		//maan lo ki 'a' ka count 'k' se jyada ho gaya tab bhi ham aage badhte jaayenge
		//jab tak 'b' ka count 2(k suppose 2 hai) se jyada na mile
		// mil jaayega to 'b' ko swap kar denge aur 'a' character ka string bana denge
		//bas hame kisi tarah max substring chahiye

		// iss meathod se ye kya suvidha hai?
		// maan lo tuhara ichha kar raha ho ki hum b ko swap karenge a me aur
		// a ka string banayege.
		//phir b ka string banayenge k a ko swap karke
		//in dono cases se jo max substring length aayega wo answer hoga.
		//but ye lamba raasta hai.


		// iss wale meathod se ye hua ki jo last me k cross karega usko hi swap karenge
		//aur substring banayenge,  aur jo max aayega use print kar denge

		if (min(count[0], count[1]) > k) {
			//ye if condition kahta hai ki min count dono me se kisi ek ka count 'k' ko cross kar chuka
			//hai, matlab abhi se pahle min count dono me se kisi ek ka 2 tha, matlab jiska count 2 tha
			//usko swap karke dusre waale character me substring bana diya
			//abhi tak 'ans++' karte aaye hai kyun kim abhi se pahle tak min count dono me se kisi ek ka 2 tha
			// matlab abhi tak ek substring ban sakta hai 2 swap kar ke.
			// ab chuki min count 'k' ko cross kar chuka hai to bhai swapping to 'k' elements ki hi karni hai
			//to l++ kar dete hain matlab left waale pointer ko ek aage khiska dete hain
			//iss ye hua ki 1st element ka count ghat gaya issiliye count[s[l]-'a']-- kiya gaya hai
			//agar phir bhi min ka count <=k nahi to phir agle iteration me phir l++ ho jaayega
			// aise humlog left pointer aage kar denge tab tak jab tak <=k ho jaaye ya phir right pointer
			//last element pe na pahunch jaaye.
			//abhi chuki humlog min ko ghata rahe hai matlab ans ka value change nahi ho raha matlab abhi tak ka max store kar rakha hai wo
			//kyun ki ek baar max length jo ho chuka hai wo kam nahi hoga kyun kim jab humlog l++ kar rahe hain tab turant for loop wala r++ kar de raha
			// matlab ab length ya to badhega ya phir abhi tak ka jo hai wahi max hai.
			count[s[l] - 'a']--;
			l++;
		}
		else {

			ans++;
		}
	}

	cout << ans << endl;
}