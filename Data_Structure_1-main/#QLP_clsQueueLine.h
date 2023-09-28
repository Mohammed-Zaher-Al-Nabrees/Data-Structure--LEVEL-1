#pragma once
#include<queue>
#include<stack>
#include<string>
#include"clsDate.h"
#include"clsDrawer.h"
using namespace std;
class clsQueueLine
{
private:
	class clsTicket {
	public:
		string OrderLabel;
		string DateTime;
		short OrderNo;
		int ExpectedServeTime;
	};
	queue <clsTicket> _TicketsQueue;
	string _Prefix;
	int _AvgTime;
	int _TotalTickets;
	int _ServedClients;
	int _WaitingClients;
	void _CreateTicket() {
		clsTicket Ticket;
		Ticket.OrderLabel = _Prefix + to_string(_WaitingClients);
		Ticket.DateTime = clsDate::getSystemDateTimeString();
		Ticket.OrderNo = _WaitingClients - 1;
		Ticket.ExpectedServeTime = Ticket.OrderNo * _AvgTime;

		_TicketsQueue.push(Ticket);
	}
public:
	clsQueueLine(string Prefix, int AvgTime) {
		_Prefix = Prefix;
		_AvgTime = AvgTime;
		_TotalTickets = 0;
		_ServedClients = 0;
		_WaitingClients = 0;
	}
	void IssueTicket() {
		this->_TotalTickets++;
		this->_WaitingClients++;
		_CreateTicket();
	}
	void ServeNextTicket() {
		this->_WaitingClients--;
		this->_ServedClients++;
		_TicketsQueue.pop();
	}
	void PrintTicket(clsTicket& Ticket) {
		cout << clsDrawer::generateTabs(40) << clsDrawer::generateLine(40) << endl;
		cout << clsDrawer::generateTabs(50) << Ticket.OrderLabel << "\n";
		cout << clsDrawer::generateTabs(50) << Ticket.DateTime << "\n";
		cout << clsDrawer::generateTabs(50) << "Waiting Clients : " << Ticket.OrderNo << "\n";
		cout << clsDrawer::generateTabs(50) << "Expected Serve Time\n ";
		cout << clsDrawer::generateTabs(50)<<to_string(Ticket.ExpectedServeTime) << "Minutes \n";
	}
	void PrintAllTickets() {
		queue <clsTicket> _TempQueue = _TicketsQueue;
		cout <<endl<< clsDrawer::generateTabs(50) << "--- Tickets ---\n";
		while (!_TempQueue.empty()) {
			PrintTicket(_TempQueue.front());
			_TempQueue.pop();
		}
		cout << clsDrawer::generateTabs(40) << clsDrawer::generateLine(40) << endl;
	}
	void PrintQueueLineInfo() {
		cout << clsDrawer::generateTabs(30) << clsDrawer::generateLine(50)<<endl ;
		cout << clsDrawer::generateTabs(50) << "Queue Info.\n";
		cout << clsDrawer::generateTabs(30) << clsDrawer::generateLine(50) << endl;
		cout << clsDrawer::generateTabs(50) << "Prefix = " << this->_Prefix << "\n";
		cout << clsDrawer::generateTabs(50) << "Total Tickets = " << this->_TotalTickets << "\n";
		cout << clsDrawer::generateTabs(50) << "Served Clients = " << this->_ServedClients << "\n";
		cout << clsDrawer::generateTabs(50) << "Waiting Clients = " << this->_WaitingClients << "\n";
		cout << clsDrawer::generateTabs(30) << clsDrawer::generateLine(50) << endl;
	}
	void PrintQueueLineRTL() {
		queue <clsTicket> _TempQueue = _TicketsQueue;
		cout << endl;
		cout << clsDrawer::generateTabs(30) << "Tickets : ";
		while (!_TempQueue.empty()) {
			cout << _TempQueue.front().OrderLabel << " <-- ";
			_TempQueue.pop();
		}
		cout << "\n";
	}
	void PrintQueueLineLTR() {
		stack <clsTicket> _TempStack;
		queue <clsTicket> _TempQueue = _TicketsQueue;
		while (!_TempQueue.empty()) {
			_TempStack.push(_TempQueue.front());
			_TempQueue.pop();
		}
		cout <<endl;
		cout << clsDrawer::generateTabs(30)<< "Tickets : ";
		while (!_TempStack.empty()) {
			cout << _TempStack.top().OrderLabel << "  --> ";
			_TempStack.pop();
		}
		cout << "\n";
	}

};

