#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int length;
string ans, s, bs;
string alphanum = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:";
string binary[] = { "0000", "0001", "0010", "0011", "0100",
				   "0101", "0110", "0111", "1000", "1001",
				   "0", "0", "0", "0", "0", "0", "0",
				   "1010", "1011", "1100", "1101", "1110", "1111" };

void input() {
	cin >> s;
	length = 0;
	ans = "";
	bs = "";
}

string ascii(int n) {
	string temp = "";
	do {
		temp += alphanum[n % 16];
		n /= 16;
	} while (n);
	reverse(temp.begin(), temp.end());
	int len = temp.size();
	if (len == 1 || len == 3) temp = "0" + temp;
	return temp;
}

void convert_binary() {
	for (int i = 0; i < (int)s.size(); i++) {
		bs += binary[s[i] - '0'];
	}
}

int number(int index) {
	string bits = bs.substr(index, 10);
	index += 10;
	int cnt = stoi(bits, 0, 2);
	string temp = "";
	int _dec = 0;
	while (cnt) {
		if (cnt >= 3) {
			temp = bs.substr(index, 10);
			_dec = stoi(temp, 0, 2);
			if (0 <= _dec && _dec <= 9) ans += ("00" + to_string(_dec));
			else if (10 <= _dec && _dec <= 99) ans += ("0" + to_string(_dec));
			else ans += to_string(_dec);
			cnt -= 3;
			index += 10;
			length += 3;
		}
		else if (cnt == 2) {
			temp = bs.substr(index, 7);
			_dec = stoi(temp, 0, 2);
			if (0 <= _dec && _dec <= 9) ans += ("0" + to_string(_dec));
			else ans += to_string(_dec);
			cnt -= 2;
			index += 7;
			length += 2;
		}
		else if (cnt == 1) {
			temp = bs.substr(index, 4);
			_dec = stoi(temp, 0, 2);
			ans += alphanum[_dec];
			cnt -= 1;
			index += 4;
			length += 1;
		}
	}
	return index;
}

int alpha(int index) {
	string bits = bs.substr(index, 9);
	index += 9;
	int cnt = stoi(bits, 0, 2);
	string temp = "";
	int _dec = 0;
	while (cnt) {
		if (cnt >= 2) {
			temp = bs.substr(index, 11);
			_dec = stoi(temp, 0, 2);
			ans += alphanum[_dec / 45];
			ans += alphanum[_dec % 45];
			cnt -= 2;
			index += 11;
			length += 2;
		}
		else if (cnt == 1) {
			temp = bs.substr(index, 6);
			_dec = stoi(temp, 0, 2);
			ans += alphanum[_dec % 45];
			cnt -= 1;
			index += 6;
			length += 1;
		}
	}
	return index;
}

int eight(int index) {
	string bits = bs.substr(index, 8);
	index += 8;
	int cnt = stoi(bits, 0, 2);
	string temp = "";
	int _dec = 0;
	while (cnt--) {
		temp = bs.substr(index, 8);
		_dec = stoi(temp, 0, 2);
		if (_dec == 0x23) ans += "\\#";
		else if (_dec == 0x5c) ans += "\\\\";
		else if (0x20 <= _dec && _dec <= 0x7e) ans += (char)_dec;
		else ans += ("\\" + ascii(_dec));
		index += 8;
		length += 1;
	}
	return index;
}

int kanji(int index) {
	string bits = bs.substr(index, 8);
	index += 8;
	int cnt = stoi(bits, 0, 2);
	string temp = "";
	int _dec = 0;
	while (cnt--) {
		temp = bs.substr(index, 13);
		_dec = stoi(temp, 0, 2);
		ans += ("#" + ascii(_dec));
		index += 13;
		length += 1;
	}
	return index;
}

void solve(int index) {
	convert_binary();
	while (index < (int)bs.size()) {
		if (bs.compare(index, 4, "0001") == 0) index = number(index + 4);
		else if (bs.compare(index, 4, "0010") == 0) index = alpha(index + 4);
		else if (bs.compare(index, 4, "0100") == 0) index = eight(index + 4);
		else if (bs.compare(index, 4, "1000") == 0) index = kanji(index + 4);
		else if (bs.compare(index, 4, "0000") == 0) return;
		else return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		input();
		solve(0);
		cout << length << ' ' << ans << '\n';
	}
	return 0;
}
