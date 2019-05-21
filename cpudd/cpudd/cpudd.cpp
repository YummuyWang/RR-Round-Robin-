// cpudd.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<Windows.h>

int jobNum;
int timePiece;
int startTime_h;
int startTime_m;
int endTime_h;
int endTime_m;
char de;
class process {
public:
	int index;
	int Time_h;
	int Time_m;
	int exe_time;
	int priority;
	char mark;
	process() {
		mark = 0;
	}
	
};

using namespace std;
void execpro(process &curpro) {
	if (curpro.exe_time <= timePiece) {
		endTime_m += curpro.exe_time;
		curpro.exe_time = 0;
		if (endTime_m >= 60) {
			endTime_h++;
			endTime_m -= 60;
		}
	}
	else {
		curpro.exe_time -= timePiece;
		endTime_m += timePiece;
		if (endTime_m >= 60) {
			endTime_h++;
			endTime_m -= 60;
		}
		curpro.Time_m =endTime_m;
		curpro.Time_h = endTime_h;
		
	}
	
	
	


}
void RR(queue<process> order)
{
	cout << "RR runing." << endl;
	cout << "任务编号：   " << "开始时间： " << "结束时间：    " << endl;
	process temp;
	temp = order.front();
	queue<process> listque;
	listque.push(order.front());
	startTime_h = order.front().Time_h;
	startTime_m = order.front().Time_m;
	order.pop();
	
	//while (!order.empty()) {                              //order为空所有都进入队列了
	//	
	//	temp = listque.front();
	//	if (listque.front().exe_time > timePiece) {
	//		listque.front().exe_time -= timePiece;
	//		listque.front().Time_m += timePiece;
	//		if (listque.front().Time_m >= 60) {
	//			listque.front().Time_h++;
	//			listque.front().Time_m -= 60;
	//		}
	//		endTime_h = listque.front().Time_h;
	//		endTime_m = listque.front().Time_m;
	//		cout << listque.front().index << "              " << temp.Time_h << ":" << temp.Time_m <<
	//			"         " << endTime_h << ":" << endTime_m << endl;
	//		
	//		temp = listque.front();
	//		listque.pop();

	//		//order.pop();//   该任务时间已经知道 不需要继续在队列
	//		//把到达的任务加入队列     
	//		
	//		//任务执行时有其他的到达
	//		//应该把时间片给新任务
	//		/*if (order.front().time_h * 60 + order.front().time_m < endtime_h * 60 + endtime_m) {
	//			listque.push(order.front());
	//			order.pop();
	//		}*/
	//	
	//		
	//		listque.push(temp);//一个时间片不够用 进队列
	//	}

	//	else if (listque.front().exe_time <= timePiece) {
	//		temp = listque.front();
	//		listque.front().Time_m += listque.front().exe_time;
	//		if (listque.front().Time_m >= 60) {
	//			listque.front().Time_h++;
	//			listque.front().Time_m -= 60;
	//		}
	//		endTime_h = listque.front().Time_h;
	//		endTime_m = listque.front().Time_m;
	//		cout << listque.front().index << "              " << temp.Time_h << ":" << temp.Time_m <<
	//			"         " << endTime_h << ":" << endTime_m<<endl;
	//		
	//		//执行中有到达
	//		
	//		/*if (order.front().Time_h * 60 + order.front().Time_m < endTime_h * 60 + endTime_m) {
	//			listque.push(order.front());
	//			order.pop();
	//		}*/
	//		listque.pop();
	//	}
	//	
	//	if (order.front().Time_h * 60 + order.front().Time_m < endTime_h * 60 + endTime_m) {
	//		cout << "pushing" << order.front().index << endl;
	//		listque.push(order.front());
	//		order.pop();
	//	}
	//	/*else
	//		cout << "ERROR!" << endl;*/





	//}
	//
	//process homo;
	//while (!listque.empty()) {
	//	homo = listque.front();
	//	if (listque.front().exe_time > timePiece) {
	//		listque.front().exe_time -= timePiece;
	//		listque.front().Time_m += timePiece;
	//		if (listque.front().Time_m > 60) {
	//			listque.front().Time_h++;
	//			listque.front().Time_h -= 60;
	//		}
	//		endTime_h = homo.Time_h;
	//		endTime_m = homo.Time_m;
	//		cout << listque.front().index << "              " << homo.Time_h << ":" << homo.Time_m <<
	//			"         " << endTime_h << ":" << endTime_m << endl;
	//		homo = listque.front();
	//		listque.pop();
	//		listque.push(homo);

	//	}
	//	if (listque.front().exe_time <= timePiece) {
	//		listque.front().exe_time = 0;
	//		listque.front().Time_m += timePiece;
	//		if (listque.front().Time_m > 60) {
	//			listque.front().Time_h++;
	//			listque.front().Time_h -= 60;
	//		}
	//		endTime_h = listque.front().Time_h;
	//		endTime_m = listque.front().Time_m;
	//		cout << listque.front().index << "              " << homo.Time_h << ":" << homo.Time_m <<
	//			"         " << endTime_h << ":" << endTime_m << endl;
	//		homo = listque.front();
	//		listque.pop();
	//	}


	//}
}
void nR(queue<process> order) {
	cout << "RR runing." << endl;
	cout << "任务编号：   " << "开始时间： " << "结束时间：    " << endl;
	queue<process> readyQue;
	queue<process> unreachQue=order;
	int timeh, timem;
	readyQue.push(unreachQue.front());
	unreachQue.pop();
	process temp;
	temp = readyQue.front();
	endTime_h = temp.Time_h;
	endTime_m = temp.Time_m;
	readyQue.pop();
	cout << temp.index << "              " << endTime_h << ":" << endTime_m;
	execpro(temp);
	cout <<"         " << endTime_h << ":" << endTime_m << endl;
	while (!readyQue.empty() || !unreachQue.empty()) {
		
		while (!unreachQue.empty())
		{
			
			if (unreachQue.front().Time_h * 60 + unreachQue.front().Time_m <= endTime_h * 60 + endTime_m) {
				readyQue.push(unreachQue.front());
				unreachQue.pop();//进入队列
				
			}
			else
				break;
		}

		if (temp.exe_time > 0) readyQue.push(temp);
		if (!readyQue.empty()) {
			temp = readyQue.front();
			readyQue.pop();
			cout << temp.index << "              " << endTime_h << ":" << endTime_m;
			execpro(temp);
			cout << "         " << endTime_h << ":" << endTime_m << endl;
			
			
		}
		else {
			endTime_h = unreachQue.front().Time_h;
			endTime_m = unreachQue.front().Time_m;
		}
	}

	
}

int main()
{
	ifstream jobFile("E:\\pppp\\job.txt");
	queue<process> pro;
	process temp;
	jobFile >> jobNum;
	jobFile >> timePiece;
	
	
	for (int i = 0; i < jobNum; i++) {
		jobFile >> temp.index;
		jobFile >> temp.Time_h;
		jobFile >> de;
		jobFile >> temp.Time_m;
		jobFile >> temp.exe_time;
		jobFile >> temp.priority;
		pro.push(temp);
	}
	//RR(pro);
	nR(pro);
	
}
/*void RR(queue<process> order)
{
	cout << "RR runing." << endl;
	process temp;
	queue<process> listque;
	listque.push(order.front());
	startTime_h = order.front().Time_h;
	startTime_m = order.front().Time_m;
	while (!order.empty()) {                              //order为空所有都进入队列了
		if (listque.front().exe_time > timePiece) {
			listque.front().exe_time -= timePiece;
			listque.front().Time_m += timePiece;
			if (listque.front().Time_m >= 60) {
				listque.front().Time_h++;
				listque.front().Time_m -= 60;
			}
			cout << listque.front().index << "  " << startTime_h << ":" << startTime_m <<
				"   " << listque.front().Time_h << ":" << listque.front().Time_m << endl;
			endTime_h = listque.front().Time_h;
			endTime_m = listque.front().Time_m;
			temp = listque.front();
			listque.pop();
			order.pop();//   该任务时间已经知道 不需要继续在队列
			//把到达的任务加入队列      改为循环
			if (order.front().Time_h * 60 + order.front().Time_m < temp.Time_h * 60 + temp.Time_m) {
				listque.push(order.front());
				order.pop();
			}
			listque.push(temp);//一个时间片不够用 进队列
		}
		else if (listque.front().exe_time <= timePiece) {
			listque.front().Time_m += listque.front().exe_time;
			cout << listque.front().index << "  " << startTime_h << ":" << startTime_m <<
				"   " << listque.front().Time_h << ":" << listque.front().Time_m;
			endTime_h = listque.front().Time_h;
			endTime_m = listque.front().Time_m;
			listque.pop();
		}
		else
			cout << "ERROR!" << endl;


	}
}
*/
