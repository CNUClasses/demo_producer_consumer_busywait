#include <iostream>
#include <thread>
#include <vector>
#include <time.h>
#include <chrono>
#include <atomic>
using namespace std;

const int TOTAL_THREADS		=20;
bool doWork=true;
int global=0;

void produce(int id,int numb){
	while(numb>0){
		global++;
		numb--;
		cout<<"Thread "<<id<<"produced one"<<endl;
	}
}

void consume(int id){
	while(global>0){
		global--;
		cout<<" Thread "<<id<<"consumed one"<<endl;
	}
}

int main() {
	thread t1(produce,1,100);
	thread t2(produce,2,100);
	thread t3(consume,3);
	thread t4(consume,4);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
}


//
//const int TOTAL_THREADS		=20;
//bool doWork=true;
//int global=0;
//
//void produce(int id,int numb){
//	while(numb>0){
//		global++;
//		numb--;
//		cout<<"Thread "<<id<<"produced one"<<endl;
//	}
//}
//
//void consume(int id){
//	while(global>0){
//		global--;
//		cout<<" Thread "<<id<<"consumed one"<<endl;
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
