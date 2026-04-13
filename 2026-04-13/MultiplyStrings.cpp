#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n";


string multiply(string num1, string num2) {
    vector<string> ans1;
    if (num1 == "0" || num2 == "0") return "0";

    if (num1.length() <= 3 && num2.length() <= 3) {
        int ans1 = stoi(num1);
        int ans2 = stoi(num2);
        int prod = ans1 * ans2 * 1LL;
        string ans = to_string(prod);
        return ans;
    }    

    // first taking the number which is larger in length andd keeping them upwards
   
    if (num1.length() < num2.length()) swap(num1 , num2);
    int n1 = num1.length(); int n2 = num2.length();
    int count = 0;

    // multiplying one by one and then carry the nums needed
    for (int i = n2 - 1; i >= 0; i--) {
        int carry = 0;
        int x1 = num2[i] - '0'; string curr_ans;

        for (int j = n1 - 1; j >= 0; j--) {
            int x2 = num1[j] - '0';
            int prod = (x1 * x2) + carry;

            // in case this is non 0th position , only take the last digit
            if (j != 0) {
                int last_dig = prod % 10; carry = prod / 10;
                curr_ans += to_string(last_dig);
            }
            // in case of 0th position , take both the digits
            if (j == 0) {
                string y1 = to_string(prod); reverse(y1.begin() , y1.end());
                curr_ans = curr_ans + y1;
            }
        }
        // then you have the ans for each solution
        reverse(curr_ans.begin() , curr_ans.end());
        for (int j = 0; j < count; j ++) {
            curr_ans += '0';
        }
        count ++;
        ans1.push_back(curr_ans);
    }
    // for (auto i : ans1) cout << i << " ";
    vector<string> ans; 
    int max1 = 0; 
    for (int i = 0; i < ans1.size(); i++) {
        int y = ans1[i].size();
        max1 = max(max1 , y);
    }

    // this is basically insertion of zeros
    for (int i = 0; i < ans1.size(); i++) {
        string ansx = ans1[i];
        if (ansx.size() < max1) {
            for (int j = 0; j < (max1 - ans1[i].size()); j++) {
                ansx.insert(ansx.begin(), '0');
            }
        }
        ans.push_back(ansx);
    }


    int rows = ans.size();
    int cols = ans[0].size();

    string f_ans = "";
    // traversing coloumn wise and then finding the ans by adding them
    int carry = 0;
    for (int j = cols - 1; j >= 0; j--) {
        int sum = 0;
        if (j != 0) {
            for (int i = rows - 1; i >= 0; i--) {
                sum = sum + (ans[i][j] - '0');
            }
            // carrting the necessary nos needed
            sum += carry;
            carry = sum / 10;
            f_ans += ((sum % 10) + '0');
        }

        if (j == 0) {
            int sum = 0;
            // from rows - 1 then you need to traverse
            for (int i = rows - 1; i >= 0; i --) {
                sum = sum + (ans[i][0] - '0');
            }
            sum += carry;
            string z = to_string(sum); reverse(z.begin() , z.end());
            f_ans += z;
        }
    }

    reverse(f_ans.begin() , f_ans.end());
    return f_ans;
}

void solve() {
    string num1 , num2; cin >> num1 >> num2;
    cout << multiply(num1 , num2) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t = 1; 
    // cin >> t;
    while (t --) {
        solve();
    }
}
