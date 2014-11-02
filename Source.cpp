#include <iostream>
#include <string>

using namespace std;

void main()
{
	string in; 
	bool flag;

	int i =0;

		cin >> in;

	for (int i=0; i < in.size(); i++)
	{
		flag = true;
		if ((in[i] != '1') && (in[i] != '4'))
			flag = false;
	}



	if (flag)
	{
	    flag = true;

	while ( (flag) && (i < in.size() ) )
	{
		if (in[i] == '1') 
			if ((in[i+1] == '1') || (in[i+1]=='4'))
				i++;
			else
				flag = false
		else
			if (in[i] == '4')
				if((in[i+1] == '4') && (in[i-1] == '1'))
					i++;
				else
					if(in[i-1] == '1')
						i++;
					else
						flag = false;


	}
	}
	if (flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;


	
	

	system("pause");
}
