// ���� 11729��
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

// ������ n���� plate ���� start -> destination ���� �̵��ؾ� �Ѵ�
void do_hanoi(int n, int from, int to, int bypass) { // n : number of plates that are left

	if (n == 0) // drive code �� �����Ű�� ����
		return; // n == 0 �̸� return �ϰ� ���ͼ� drive code �� �����ض�.


	// divide
	do_hanoi(n - 1, from, bypass, to); // ������ n-1 ���� plate ���� from -> to �� �̵��ؾ� �Ѵ�

	// drive code 
	move(from, to); // 1���� plate �� from -> to ���� �̵��Ѵ�


	// conquer
	do_hanoi(n - 1, bypass, to, from); // ���� 1���� plate �� bypass -> to ���� �̵��Ѵ� !!	



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

		cout << from << " " << to << "\n"; // #11729 ������ Ư���� �� -> endl �� ���� �ð��ʰ��� ���� �ȴ�

	}

}