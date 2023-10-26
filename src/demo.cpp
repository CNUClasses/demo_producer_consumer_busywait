#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <time.h>
#include <chrono>
#include <atomic>
using namespace std;
//use to force failures
//std::this_thread::sleep_for(std::chrono::milliseconds(2));
int bal=0;

void deposit(int id,int numbdeposits, int amt){
	while(numbdeposits>0){
		bal=bal+amt;
		numbdeposits--;
		cout<<"Thread "<<id<<" deposited "<<amt<<" bal="<<bal<<endl;
	}
}

void withdraw(int id,int amt ){
	while(bal>0){
		bal--;
		cout<<" Thread "<<id<<" withdrew "<<amt<<" bal="<<bal<<endl;
	}
}

int main() {
	thread t1(deposit,1,100,1);
	thread t2(withdraw,2,1);

	t1.join();
	t2.join();

	cout<<"DONE! bal="<<bal<<endl;
}

