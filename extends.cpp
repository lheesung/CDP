#include <iostream>
#include <cstring>
using namespace std;

class PermanentWorker
{
private:
	char name[100];	
	int salary;
public:
	PermanentWorker(char* name, int money)
		: salary(money)
	{
		strcpy(this->name, name);
	}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		cout<<"name: "<<name<<endl;
		cout<<"salary: "<<GetPay()<<endl<<endl;
	}
};

class EmployeeHandler //컨트롤 클래스 OR 핸들러 클래스(기능의 처리를 실제로 담당)
{
private:
	PermanentWorker* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0) 
	{ }
	void AddEmployee(PermanentWorker* emp)
	{
		empList[empNum++]=emp;
	}
	void ShowAllSalaryInfo() const
	{
		for(int i=0; i<empNum; i++)
			empList[i]->ShowSalaryInfo();
	}
	void ShowTotalSalary() const
	{
		int sum=0;
		for(int i=0; i<empNum; i++)
			sum+=empList[i]->GetPay();
		cout<<"salary sum: "<<sum<<endl;
	}
	~EmployeeHandler()
	{
		for(int i=0; i<empNum; i++)
			delete empList[i];
	}
};

int main(void)
{
	// 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
	EmployeeHandler handler;
	// 직원 등록
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	// 이번 달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();	

	// 이번 달에 지불해야 할 급여의 총합
	handler.ShowTotalSalary();
	return 0;
}

/*
회사가 번창하여 사원을 늘려야 할 때, 정규직과 비정규직을
구분해야하지만, 정규직과 비정규직, 알바, 청소부 등
직업에 따른 월급지급을 구분하는 코드가 따로 없기
때문에 문제가 발생할 것 같다. 
*/