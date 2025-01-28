#include <iostream>
#include <stdlib.h>
#include <time.h>
//asdasdasd
using namespace std;

class Randum
{
public:
	int r = 0;

	int R()
	{
		r = rand();

		return r;
	}
};

int main()
{
	srand(time(NULL));

	int succ = 0;
	int fail = 0;
	int h = 0;

	cout << "반복할 횟수 : ";
	cin >> h;

	for (int i = 1; i <= h; i++)
	{
		Randum randum;
		randum.R();
		int ra = randum.R();

		Randum randum1;
		randum1.R();
		int ra1 = randum1.R();



		int* p = new int[3];

		p[0] = NULL;
		p[1] = NULL;
		p[2] = NULL;



		int WinnerRoom = ra % 3;

		if (WinnerRoom == 0)
		{
			p[0] = 1;
			p[1] = 0;
			p[2] = 0;
		}
		else if (WinnerRoom == 1)
		{
			p[0] = 0;
			p[1] = 1;
			p[2] = 0;
		}
		else if (WinnerRoom == 2)
		{
			p[0] = 0;
			p[1] = 0;
			p[2] = 1;
		}
		else
			cout << "W.err";


		int RoomPick = ra1 % 3;

		if (p[RoomPick] == 1)
		{
			cout << "실패";
			fail++;
		}
		else
		{
			cout << "성공";
			succ++;
		}

		delete[] p;
	}

	cout << endl << endl;

	cout << "성공 수 : " << succ << endl;
	cout << "실패 수 : " << fail << endl;

	return 0;
}





