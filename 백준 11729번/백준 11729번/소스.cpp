// 백준 11729번
// devide and conquer

#include <iostream>
#include <vector>

using namespace std;

int num_of_move = 0;

vector<char> buffer;

void move(int from, int to) {

	//	printf("%d %d\n", from, to);

	buffer.push_back(from);
	buffer.push_back(to);

	num_of_move++;

}

// 앞으로 n개의 plate 들이 start -> destination 으로 이동해야 한다
void do_hanoi(int n, int from, int to, int bypass) { // n : number of plates that are left

	if (n == 0) // drive code 를 실행시키는 시점
		return; // n == 0 이면 return 하고 나와서 drive code 를 실행해라.


	// divide
	do_hanoi(n - 1, from, bypass, to); // 앞으로 n-1 개의 plate 들이 from -> to 로 이동해야 한다

	// drive code 
	move(from, to); // 1개의 plate 가 from -> to 으로 이동한다


	// conquer
	do_hanoi(n - 1, bypass, to, from); // 남은 1개의 plate 가 bypass -> to 으로 이동한다 !!	



}

// declaration
void print_buffer();

int main() {

	buffer.reserve(1000);

	int num_of_plate = 0; cin >> num_of_plate;

	do_hanoi(num_of_plate, 1, 3, 2);

	cout << num_of_move << endl;

	print_buffer();








}

// definition
void print_buffer() {

	int buffer_size = buffer.size();

	for (int i = 0; i < buffer_size; i += 2)
	{
		int from = buffer[i];
		int to = buffer.at(i + 1);

		cout << from << " " << to << "\n"; // #11729 문제의 특이한 점 -> endl 을 쓰면 시간초과가 나게 된다

	}

}