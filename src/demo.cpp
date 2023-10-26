#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <time.h>
#include <chrono>
#include <atomic>
using namespace std;

bool done=false;
int global=0;
mutex m;

//1.fix the ugly couts
void out1(string s){
	lock_guard<mutex> lck(m);
	cout<<s<<endl;
}

void produce(int id,int numb){
	while(numb>0){
		global++;
		numb--;
		out1("Thd "+to_string(id)+" produced, global="+to_string(global));
//		cout<<"Thread "<<id<<"produced one"<<endl;
		//snooze for a bit to simulate work
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	out1("DONE!");
	done=true;
}

void consume(int id){
	while(!done || global>0){
		if( global>0){
			global--;
			out1("   Thd "+to_string(id)+" consumed, global="+to_string(global));
	//		cout<<" Thread "<<id<<"consumed one"<<endl;
		}else
			out1("WAITING");
	}
}

int main() {
	thread t1(produce,1,100);
//	thread t2(produce,2,100);
	thread t3(consume,3);
//	thread t4(consume,4);

	t1.join();
//	t2.join();
	t3.join();
//	t4.join();
	cout<<" Done! global="<<global<<endl;
}


//
//const int TOTAL_THREADS		=20;
//bool doWork=true;
//int bal=0;
//
//void deposit(int id,int numbdeposits, int amt){
//	while(numbdeposits>0){
//		bal=bal+amt;
//		numbdeposits--;
//		cout<<"Thread "<<id<<"deposited"<<amt<<endl;
//	}
//}
//
//void withdraw(int id,int amt ){
//	while(bal>0){
//		bal--;
//		cout<<" Thread "<<id<<"withdrew "<<amt<<endl;
//	}
//}
//
//int main() {
//	thread t1(produce,1,100);
//	thread t2(produce,2,100);
//	thread t3(consume,3);
//	thread t4(consume,4);
//
//	t1.join();
//	t2.join();
//	t3.join();
//	t4.join();
//}
//
